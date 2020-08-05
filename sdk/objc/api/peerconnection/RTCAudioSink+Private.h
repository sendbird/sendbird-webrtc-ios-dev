// #import "RTCAudioSink.h"
// #include "api/media_stream_interface.h"
// #include "pc/audio_track.h"
// #include <stddef.h>
// #import "base/RTCLogging.h"
// #include <memory>
// #import "RTCMacros.h"
#import "RTCAudioSink.h"
// NS_ASSUME_NONNULL_BEGIN

namespace webrtc {
class AudioSourceSink {
 public:
   AudioSourceSink(RTCAudioSink* sink) {
       sink_ = sink;
   }

  void OnData(int32_t bits_per_sample) {
        // RTCLog(@"MINI: CALLED ONDATA.");
        [sink_ onAudioBuffer:bits_per_sample];
  }

 private:
  __weak RTCAudioSink *sink_;
};
}

// NS_ASSUME_NONNULL_END