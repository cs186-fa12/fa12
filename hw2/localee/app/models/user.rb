class User < ActiveRecord::Base

  ################################
  #  DO NOT MODIFY THIS SECTION  #
  ################################

  # Use Rails internal password digesting
  has_secure_password
  
  # Validations
  validates :name, :presence => true
  validates :email, :presence => true, :uniqueness => true
  validates :password, :presence => true, :on => :create, :length => {:minimum => 5}
  
  ############################################
  #  TODO: you may optionally add code here  #
  ############################################
  
  def to_hash
    {
      :id => self.id,
      :name => self.name,
      :email => self.email
    }
  end

end
