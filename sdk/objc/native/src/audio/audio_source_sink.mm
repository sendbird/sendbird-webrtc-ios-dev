#import "sdk/objc/native/src/audio/audio_source_sink.h"
#import "sdk/objc/api/peerconnection/RTCAudioSink.h"

namespace webrtc {
        // public: 
        AudioSourceSink::AudioSourceSink(RTCAudioSink *sink) {
            sink_ = sink;
        }

        void AudioSourceSink::OnAudioFrame(int frame) {
            [sink_ onAudioFrame:frame];
        }

        // private:
        // __weak RTCAudioSink *sink_;
    // };
}