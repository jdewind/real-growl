#include <Foundation/Foundation.h>
#include <Growl/Growl.h>
#include "ruby.h"

#define REAL_GROWL_NOTIFICATION XSTR("RealGrowlNotification")

@interface RubyDelegate : NSObject<GrowlApplicationBridgeDelegate>
{
  NSString *applicationName;
  VALUE callbackProc;
}

-(NSDictionary *) registrationDictionaryForGrowl;
-(void) growlNotificationWasClicked:(id)clickContext;

@property(nonatomic, assign) VALUE callbackProc;
@property(nonatomic, retain) NSString *applicationName;
@end