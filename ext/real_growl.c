#include "real_growl.h"

#include <objc/runtime.h>
#include <Growl/Growl.h>
#include <Foundation/Foundation.h>

VALUE rb_mRealGrowl;
VALUE rb_cRealGrowlApplication;

VALUE
classMethod_installed(VALUE self) {
  NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
  BOOL installed = [GrowlApplicationBridge isGrowlInstalled];
  [pool release];
  
  if(installed) {
    return Qtrue;
  } else {
    return Qfalse;
  }
}

VALUE
classMethod_running(VALUE self) {
  NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
  BOOL running = [GrowlApplicationBridge isGrowlRunning];
  [pool release];
  
  if(running) {
    return Qtrue;
  } else {
    return Qfalse;
  }
}

VALUE
method_notify(VALUE self, VALUE title, VALUE description, VALUE sticky) {
  NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
  BOOL nsSticky;
  
  if(sticky == Qtrue) {
    nsSticky = YES;
  } else {
    sticky == NO;
  }
  
  NSString *nsTitle = [NSString stringWithCString:STR2CSTR(title) encoding: NSASCIIStringEncoding];
  NSString *nsDescription = [NSString stringWithCString:STR2CSTR(description) encoding: NSASCIIStringEncoding];
  [GrowlApplicationBridge notifyWithTitle: nsTitle description: nsDescription notificationName: REAL_GROWL_NOTIFICATION iconData: nil priority: 0 isSticky:nsSticky clickContext:nil];
  
  [pool release];
  
  return Qnil;
}

VALUE 
method_init(VALUE self, VALUE applicationName) {
  NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
  id delegate = NULL;
  
  Data_Get_Struct(self, RubyDelegate, delegate);
  
  NSString *nsAppName = [NSString stringWithCString:STR2CSTR(applicationName) encoding: NSASCIIStringEncoding];
  [(RubyDelegate *)delegate setApplicationName: nsAppName];
  [GrowlApplicationBridge setGrowlDelegate: delegate];
  
  [pool release];
  return self;
}

static void
free_delegate(id delegate) {
  [delegate release];
}

static VALUE
alloc_delegate(VALUE klass) {
  return Data_Wrap_Struct(klass, 0, free_delegate, [[RubyDelegate alloc] init]);  
}


void
Init_real_growl() {
  
  rb_mRealGrowl = rb_define_module("RealGrowl");
  rb_define_singleton_method(rb_mRealGrowl, "installed?", classMethod_installed, 0);
  rb_define_singleton_method(rb_mRealGrowl, "running?", classMethod_running, 0);
  
  rb_cRealGrowlApplication = rb_define_class_under(rb_mRealGrowl, "Application", rb_cObject);
  rb_define_alloc_func(rb_cRealGrowlApplication, alloc_delegate);
  rb_define_method(rb_cRealGrowlApplication, "initialize", method_init, 1);
  rb_define_method(rb_cRealGrowlApplication, "notify", method_notify, 3);  
}

