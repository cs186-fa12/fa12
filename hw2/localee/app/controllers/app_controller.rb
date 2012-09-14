class AppController < ApplicationController

  before_filter :create_app_query
  def create_app_query
    @aq = AppQuery.new
  end

  def locations_index
    @aq.get_following_locations(current_user.id)
    @following_locations = @aq.following_locations
    render "locations/index"
  end

  def location_show
    @aq.get_posts_for_location(params[:id])
    @posts = @aq.posts
    @location = @aq.location
    render "locations/show"
  end

  def nearby_locations_index
    @aq.get_nearby_locations(params[:nelat], params[:nelng], params[:swlat], params[:swlng], current_user.id)
    @locations = @aq.locations
    render :json => @locations
  end

  def dashboard
    @aq.get_stream_for_user(current_user.id)
    @posts = @aq.posts
    render "home/dashboard"
  end

  def locations_create
    @aq.create_location(params[:location])
    redirect_to locations_path
  end

  def location_follow
    @aq.follow_location(current_user.id, params[:id])
    redirect_to locations_path
  end

  def location_unfollow
    @aq.unfollow_location(current_user.id, params[:id])
    redirect_to locations_path
  end

  def posts_create
    @aq.create_post(current_user.id, params[:post])
    redirect_to :back
  end

  def reports_index
    @users_most_posts = ActiveRecord::Base.connection.execute(@aq.top_users_posts_sql)
    @locations_most_posters = ActiveRecord::Base.connection.execute(@aq.top_locations_unique_users_sql)
    @users_most_locations = ActiveRecord::Base.connection.execute(@aq.top_users_locations_sql)
    render "reports/index"
  end

end
