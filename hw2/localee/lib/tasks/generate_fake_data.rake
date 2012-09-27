task :generate_fake_data => :environment do
  aq = AppQuery.new
  puts aq

  num_users = 15
  num_locations = 15
  more_follows = 7
  more_posts = 30

  post_counter = 1
  srand(123)
  rng = Random.new(123)

  # create users
  (1..num_users).each do |i|
    uname = "user" + i.to_s
    aq.create_user({:name => uname, :email => uname, :password => uname})
  end

  # create locations
  (1..num_locations).each do |i|
    lname = "location" + i.to_s
    lat = rng.rand * (37.90302207665658 - 37.84882225623786) + 37.84882225623786
    lng = rng.rand * (122.30416958764647 - 122.2011727614746) - 122.30416958764647
    aq.create_location({:name => lname, :latitude => lat, :longitude => lng})
  end

  aq.get_all_users
  user_ids = aq.users.map do |u|
    u[:id]
  end

  aq.get_all_locations
  location_ids = aq.locations.map do |l|
    l[:id]
  end

  # add some follows
  user_ids.each do |u|
    num_follows = rng.rand(more_follows)
    location_ids.sample(num_follows).each do |l|
      aq.follow_location(u, l)
    end
  end

  # add some posts
  user_ids.each do |u|
    num_posts = rng.rand(more_posts)
    (1..num_posts).each do |p|
      lid = location_ids.sample
      aq.create_post(u, {:location_id => lid, :text => "post" + post_counter.to_s})
      post_counter += 1
    end
  end

end
