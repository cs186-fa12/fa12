class UsersController < ApplicationController

  before_filter :create_app_query
  def create_app_query
    @aq = AppQuery.new
  end

  def new
    @user = User.new
  end

  def create
    if @aq.create_user(params[:user])
      # auto login
      session[:user_id] = @aq.user.id
      redirect_to root_path
    else
      render :new
    end
  end

end
