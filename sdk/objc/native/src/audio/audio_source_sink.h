#ifndef SDK_OBJC_NATIVE_SRC_AUDIO_AUDIO_SOURCE_SINK_H_
#define SDK_OBJC_NATIVE_SRC_AUDIO_AUDIO_SOURCE_SINK_H_

#include "sdk/objc/base/RTCMacros.h"
#include <AudioUnit/AudioUnit.h>

RTC_FWD_DECL_OBJC_CLASS(RTCAudioSink);

namespace webrtc {
    class AudioSourceSink {
        public: 
        AudioSourceSink(RTCAudioSink* sink);
        void OnLocalAudioFrame(AudioUnitRenderActionFlags* flags,
                                          const AudioTimeStamp* time_stamp,
                                          UInt32 bus_number,
                                          UInt32 num_frames,
                                          AudioBufferList* io_data);
        void OnRemoteAudioFrame(AudioUnitRenderActionFlags* flags,
                                          const AudioTimeStamp* time_stamp,
                                          UInt32 bus_number,
                                          UInt32 num_frames,
                                          AudioBufferList* io_data);
        private:
        __weak RTCAudioSink *sink_;
    };
}

#endif // SDK_OBJC_NATIVE_SRC_AUDIO_AUDIO_SOURCE_SINK_H_
