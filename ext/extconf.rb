# Loads mkmf which is used to make makefiles for Ruby extensions
require 'mkmf'


$CFLAGS << ' ' + "-ObjC "  

if defined?(RUBY_ENGINE) && RUBY_ENGINE == "macruby"
  $CFLAGS << ' ' + "-fobjc-gc"
end

$LDFLAGS << ' ' + "-lobjc -framework Foundation -framework Growl"
$objs = %w(ruby_delegate.o real_growl_api.o)

def growl_framework_paths
  ["/Library/Frameworks/Growl.framework"]
end

if(growl_framework_paths.any? {|x| File.exists?(x)})
  message("checking for framework Growl... yes\n")
  extension_name = 'real_growl_api'
  dir_config(extension_name)
  create_makefile(extension_name)
else
  message("checking for framework Growl... no\n")
end
