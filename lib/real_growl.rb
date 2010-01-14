require 'real_growl_api'
require 'pp'

module Kernel
  class<<self
    attr_accessor :rg_sticky, :rg_priority
  end
  
  def rg(*args)
    Kernel.rg_priority ||= 0
    Kernel.rg_sticky = true if Kernel.rg_sticky.nil?
    
    @__growl_app ||= RealGrowl::Application.new("RealGrowl")
    
    if RealGrowl.running?
      notifications = args.map { |x| x.pretty_inspect }
      notifications.each do |x|
        @__growl_app.notify('rg', x, Kernel.rg_priority, Kernel.rg_sticky)
      end
    end
        
    nil
  end
end
