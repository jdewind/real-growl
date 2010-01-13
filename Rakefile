begin
  require 'jeweler'
  Jeweler::Tasks.new do |s|
    s.name = "real-growl"
    s.summary = "Real growl uses C bindings to interact with the Growl Application Bridge Framework"
    s.description = "Real growl uses C bindings to interact with the Growl Application Bridge Framework"
    s.email = "dewind@atomicobject.com"
    s.authors = ["Justin DeWind"]
    s.executables = []
    s.files =  FileList["lib/**/*.rb", "Rakefile", "ext/**/*.h", "ext/**/*.c", "ext/**/*.m"]
    s.extensions = ["ext/extconf.rb"]
  end
  
  Jeweler::GemcutterTasks.new
rescue LoadError
  puts "Jeweler, or one of its dependencies, is not available. Install it with: sudo gem install technicalpickles-jeweler -s http://gems.github.com"
end
