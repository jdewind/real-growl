#include "ruby_delegate.h"
#include "ruby.h"
#include <objc/runtime.h>
#include <Growl/Growl.h>
#include <Foundation/Foundation.h>

static NSString* build_nsstring(VALUE string);
static NSData* get_icon_data(VALUE pathOrUrl);
static NSAutoreleasePool* create_autorelease_pool();
static void free_delegate(id delegate);
static VALUE alloc_delegate(VALUE klass);