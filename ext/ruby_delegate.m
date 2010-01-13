#include "ruby_delegate.h"

@implementation RubyDelegate
@synthesize applicationName;

-(NSDictionary *)registrationDictionaryForGrowl {
  if(applicationName == nil) {
    applicationName = @"RealGrowl";
  }
  NSArray *notifications = [NSArray arrayWithObject:REAL_GROWL_NOTIFICATION];
  return [NSDictionary dictionaryWithObjectsAndKeys: [self applicationName], GROWL_APP_ID, [self applicationName], GROWL_APP_NAME, notifications, GROWL_NOTIFICATIONS_ALL, nil];
}

@end