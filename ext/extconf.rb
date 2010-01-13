# Loads mkmf which is used to make makefiles for Ruby extensions
require 'mkmf'


$CFLAGS << ' ' + "-ObjC"
$LDFLAGS << ' ' + "-lobjc -framework Foundation -framework Growl"
$objs = %w(ruby_delegate.o real_growl.o)

# Give it a name
extension_name = 'real_growl'

# The destination
dir_config(extension_name)

# Do the work
create_makefile(extension_name)
