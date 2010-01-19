#include "ruby_delegate.h"

@implementation RubyDelegate
@synthesize applicationName, callbackProc;

-(id)init {
  if(self = [super init]) {
    applicationName = [@"RealGrowl" retain];
    return self;
  }
  
  return nil;
}

-(NSDictionary *)registrationDictionaryForGrowl {
  NSArray *notifications = [NSArray arrayWithObject:REAL_GROWL_NOTIFICATION];
  return [NSDictionary dictionaryWithObjectsAndKeys: [self applicationName], GROWL_APP_ID, [self applicationName], GROWL_APP_NAME, notifications, GROWL_NOTIFICATIONS_ALL, nil];
}

-(void)growlNotificationWasClicked:(id)clickContext {
  if(callbackProc != Qnil) {
    rb_funcall(callbackProc, rb_intern("call"), 0);
  }
}

-(void)dealloc {
  [applicationName release];
  [super dealloc];
}

@end