require 'real_growl_api'
require 'pp'

module Kernel
  def rg(*args)
    @__growl_app ||= RealGrowl::Application.new("RealGrowl")
    notifications = args.map { |x| x.pretty_inspect }
    notifications.each do |x|
      @__growl_app.notify('rg', x, 0, true)
    end
    nil
  end
end
