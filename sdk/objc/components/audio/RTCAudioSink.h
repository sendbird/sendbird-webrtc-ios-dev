/*
 *  Copyright 2016 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

// #if defined(WEBRTC_IOS)
#import <Foundation/Foundation.h>

#import "RTCMacros.h"

NS_ASSUME_NONNULL_BEGIN

@class RTC_OBJC_TYPE(RTCAudioSink);

RTC_OBJC_EXPORT
@interface RTC_OBJC_TYPE (RTCAudioSink) : NSObject

- (instancetype)init;
- (void)onAudioBuffer:(int32_t)buffer;

@end

NS_ASSUME_NONNULL_END
// #endif