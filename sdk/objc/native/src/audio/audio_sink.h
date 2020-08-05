#import "sdk/objc/api/peerconnection/RTCAudioSink.h"

namespace webrtc {
    class AudioSourceSink {
        public: 
        AudioSourceSink(RTCAudioSink *sink) {
            sink_ = sink;
        }
        void onAudioFrame(int32_t frame) {
            [sink_ onAudioframe:frame];
        }

        private:
        __weak RTCAudioSink *sink_;
    }
}