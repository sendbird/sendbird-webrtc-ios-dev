/*
 *  Copyright 2016 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#import "RTCAudioSink.h"
#import "base/RTCLogging.h"

@implementation RTC_OBJC_TYPE (RTCAudioSink) {
}

- (instancetype)init {
  self = [super init];
  return self;
}

- (void)onAudioFrame:(int32_t)frame { }

@end