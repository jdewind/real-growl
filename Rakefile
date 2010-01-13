begin
  require 'jeweler'
  Jeweler::Tasks.new do |s|
    s.name = "real-growl"
    s.summary = "RealGrowl uses C bindings to interact with GrowlApplicationBridge rather than using Growl's network API."
    s.email = "dewind@atomicobject.com"
    s.authors = ["Justin DeWind"]
    s.files =  FileList["README.rdoc", "lib/**/*.rb", "Rakefile", "ext/**/*.h", "ext/**/*.c", "ext/**/*.m"]
    s.extensions = ["ext/extconf.rb"]
  end
  
  Jeweler::GemcutterTasks.new
rescue LoadError
  puts "Jeweler, or one of its dependencies, is not available. Install it with: sudo gem install technicalpickles-jeweler -s http://gems.github.com"
end