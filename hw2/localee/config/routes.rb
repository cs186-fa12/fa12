Cs186p2::Application.routes.draw do
  
  # Route for /
  root :to => "home#index"
  
  # Misc Routes
  match "login" => "sessions#new", :as => "login"
  match "logout" => "sessions#destroy", :as => "logout"
  match "signup" => "users#new", :as => "signup"
  
  # Resourceful routes
  resources :users, :only => [:new, :create]
  resources :sessions, :only => [:new, :create, :destroy]
  
  # Locations
  match "locations" => "app#locations_index", :as => "locations", :via => :get
  match "locations" => "app#locations_create", :as => "locations", :via => :post
  match "location/:id" => "app#location_show", :as => "location", :via => :get
  match "locations/:id/follow" => "app#location_follow", :as => "follow_location", :via => :post
  match "locations/:id/unfollow" => "app#location_unfollow", :as => "unfollow_location", :via => :post
  match "nearby_locations" => "app#nearby_locations_index", :as => "nearby_locations", :via => :post
  match "reports" => "app#reports_index", :as => "reports", :via => :get
  
  # Posts
  match "posts" => "app#posts_create", :as => "posts", :via => :post
  
  # Dasboard
  match "dashboard" => "app#dashboard", :as => "dashboard", :via => :get
  
  # The priority is based upon order of creation:
  # first created -> highest priority.

  # Sample of regular route:
  #   match 'products/:id' => 'catalog#view'
  # Keep in mind you can assign values other than :controller and :action

  # Sample of named route:
  #   match 'products/:id/purchase' => 'catalog#purchase', :as => :purchase
  # This route can be invoked with purchase_url(:id => product.id)

  # Sample resource route (maps HTTP verbs to controller actions automatically):
  #   resources :products

  # Sample resource route with options:
  #   resources :products do
  #     member do
  #       get 'short'
  #       post 'toggle'
  #     end
  #
  #     collection do
  #       get 'sold'
  #     end
  #   end

  # Sample resource route with sub-resources:
  #   resources :products do
  #     resources :comments, :sales
  #     resource :seller
  #   end

  # Sample resource route with more complex sub-resources
  #   resources :products do
  #     resources :comments
  #     resources :sales do
  #       get 'recent', :on => :collection
  #     end
  #   end

  # Sample resource route within a namespace:
  #   namespace :admin do
  #     # Directs /admin/products/* to Admin::ProductsController
  #     # (app/controllers/admin/products_controller.rb)
  #     resources :products
  #   end

  # You can have the root of your site routed with "root"
  # just remember to delete public/index.html.
  # root :to => 'welcome#index'

  # See how all your routes lay out with "rake routes"

  # This is a legacy wild controller route that's not recommended for RESTful applications.
  # Note: This route will make all actions in every controller accessible via GET requests.
  # match ':controller(/:action(/:id))(.:format)'
end
