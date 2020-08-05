#import <Foundation/Foundation.h>

#import "RTCMacros.h"

NS_ASSUME_NONNULL_BEGIN

RTC_OBJC_EXPORT
@interface RTC_OBJC_TYPE (RTCAudioSink) : NSObject

- (instancetype)init;
- (void)onAudioFrame:(int32_t)frame;

@end

NS_ASSUME_NONNULL_END
