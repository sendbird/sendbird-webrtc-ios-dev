#import "sdk/objc/native/src/audio/audio_source_sink.h"
#import "sdk/objc/api/peerconnection/RTCAudioSink.h"
#import "base/RTCLogging.h"
#import "rtc_base/logging.h"

namespace webrtc {
  AudioSourceSink::AudioSourceSink(RTCAudioSink *sink) {
    sink_ = sink;
  }

  void AudioSourceSink::OnAudioFrame(int frame) {
    RTC_LOG(LS_VERBOSE) << __FUNCTION__;
    [sink_ onAudioFrame:frame];
  }
}