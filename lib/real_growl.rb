require 'real_growl_api'
require 'pp'

module Kernel
  class<<self
    attr_accessor :rg_sticky, :rg_priority, :rg_icon
  end
  
  def rg(*args)
    Kernel.rg_priority ||= 0
    Kernel.rg_sticky = true if Kernel.rg_sticky.nil?
    icon = Kernel.rg_icon
    
    @__growl_app ||= RealGrowl::Application.new("RealGrowl")
    
    if args.last.is_a?(Hash) and args.last[:icon]
      icon = args.last[:icon]
      args.pop
    end
    
    if RealGrowl.running?
      notifications = args.map { |x| x.pretty_inspect }
      notifications.each do |x|
        @__growl_app.notify(
          :title        => 'rg', 
          :description  => x, 
          :priority     => Kernel.rg_priority, 
          :sticky       => Kernel.rg_sticky, 
          :icon         => icon
        )
      end
    end
        
    nil
  end
end
