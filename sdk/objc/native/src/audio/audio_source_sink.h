#ifndef SDK_OBJC_NATIVE_SRC_AUDIO_AUDIO_SOURCE_SINK_H_
#define SDK_OBJC_NATIVE_SRC_AUDIO_AUDIO_SOURCE_SINK_H_

#include "sdk/objc/base/RTCMacros.h"
RTC_FWD_DECL_OBJC_CLASS(RTCAudioSink);

namespace webrtc {
    class AudioSourceSink {
        public: 
        AudioSourceSink(RTCAudioSink* sink);
        void onAudioFrame(int frame);
        
        private:
        __weak RTCAudioSink *sink_;
    };
}

#endif // SDK_OBJC_NATIVE_SRC_AUDIO_AUDIO_SOURCE_SINK_H_
