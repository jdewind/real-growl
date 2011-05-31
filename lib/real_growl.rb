require 'real_growl_api'
require 'pp'

module RealGrowl    
  class<<self
    attr_accessor :sticky, :priority, :icon
  
    def growl(*args)
      self.priority ||= 0
      self.sticky = true if self.sticky.nil?
      icon = self.icon
      click = nil

      @__growl_app ||= RealGrowl::Application.new("RealGrowl")

      if args.last.is_a?(Hash) and (args.last[:icon] or args.last[:click])
        icon = args.last[:icon]
        click = args.last[:click]
        args.pop
      end

      if RealGrowl.running?
        notifications = args.map { |x| x.pretty_inspect }
        notifications.each do |x|
          @__growl_app.notify(
            :title        => 'rg', 
            :description  => x, 
            :priority     => self.priority, 
            :sticky       => self.sticky, 
            :icon         => icon
          )
        end
      end
      nil
    end
  end
  
  def rg(*args)
    RealGrowl::growl(*args)
  end
end

class Object  
  include RealGrowl
end
