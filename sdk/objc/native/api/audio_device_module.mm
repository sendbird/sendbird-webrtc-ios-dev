/*
 *  Copyright 2018 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include "audio_device_module.h"

#include "rtc_base/logging.h"
#include "rtc_base/ref_counted_object.h"

#include "sdk/objc/native/src/audio/audio_device_module_ios.h"

namespace webrtc {

#if defined(WEBRTC_IOS)
rtc::scoped_refptr<ios_adm::AudioDeviceModuleIOS> CreateAudioDeviceModule(RTCAudioSink *sink) {
  RTC_LOG(INFO) << __FUNCTION__;
  return new rtc::RefCountedObject<ios_adm::AudioDeviceModuleIOS>(sink);
}
#else
rtc::scoped_refptr<AudioDeviceModule> CreateAudioDeviceModule() {
  RTC_LOG(INFO) << __FUNCTION__;
  RTC_LOG(LERROR)
      << "current platform is not supported => this module will self destruct!";
}
#endif
}
