begin
  require 'jeweler'
  Jeweler::Tasks.new do |s|
    s.name = "real-growl"
    s.summary = "Growl notification library that was built using native c bindings."
    s.description = "A Growl notification library that uses native c bindings to interact with GrowlApplicationBridge rather than Growl's network API."
    s.email = "dewind@atomicobject.com"
    s.authors = ["Justin DeWind"]
    s.files =  FileList["README.rdoc", "lib/**/*.rb", "Rakefile", "ext/**/*.h", "ext/**/*.c", "ext/**/*.m"]
    s.extensions = ["ext/extconf.rb"]
    s.executables = ["realgrowl"]
    s.homepage = "http://github.com/dewind/real-growl"
    s.add_dependency "slop"
  end
  
  Jeweler::GemcutterTasks.new
rescue LoadError
  puts "Jeweler, or one of its dependencies, is not available. Install it with: sudo gem install technicalpickles-jeweler -s http://gems.github.com"
end
