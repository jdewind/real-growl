# Loads mkmf which is used to make makefiles for Ruby extensions
require 'mkmf'


$CFLAGS << ' ' + "-ObjC"
$LDFLAGS << ' ' + "-lobjc -framework Foundation -framework Growl"
$objs = %w(ruby_delegate.o real_growl_api.o)

if(have_library("objc"))
  extension_name = 'real_growl_api'
  dir_config(extension_name)
  create_makefile(extension_name)
end