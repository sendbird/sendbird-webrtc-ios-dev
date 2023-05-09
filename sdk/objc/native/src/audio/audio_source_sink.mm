#import "sdk/objc/native/src/audio/audio_source_sink.h"
#import "sdk/objc/api/peerconnection/RTCAudioSink.h"
#import "base/RTCLogging.h"
#import "rtc_base/logging.h"

namespace webrtc {
  AudioSourceSink::AudioSourceSink(RTCAudioSink *sink) {
    sink_ = sink;
  }

  void AudioSourceSink::OnLocalAudioFrame(AudioUnitRenderActionFlags* flags,
                                          const AudioTimeStamp* time_stamp,
                                          UInt32 bus_number,
                                          UInt32 num_frames,
                                          AudioBufferList* io_data) {
    [sink_ onLocalAudioFrameWithFlags:flags timeStamp:time_stamp busNumber:bus_number numFrames:num_frames ioData:io_data];
  }

  void AudioSourceSink::OnRemoteAudioFrame(AudioUnitRenderActionFlags* flags,
                                          const AudioTimeStamp* time_stamp,
                                          UInt32 bus_number,
                                          UInt32 num_frames,
                                          AudioBufferList* io_data) {
    [sink_ onRemoteAudioFrameWithFlags:flags timeStamp:time_stamp busNumber:bus_number numFrames:num_frames ioData:io_data];
  }
}