#include <Foundation/Foundation.h>
#include <Growl/Growl.h>
#define REAL_GROWL_NOTIFICATION XSTR("RealGrowlNotification")

@interface RubyDelegate : NSObject<GrowlApplicationBridgeDelegate>
{
  NSString *applicationName;
}

-(NSDictionary *) registrationDictionaryForGrowl;
@property(nonatomic, retain) NSString *applicationName;
@end