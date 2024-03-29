/*
 *  Copyright 2019 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef API_TRANSPORT_RTP_RTP_SOURCE_H_
#define API_TRANSPORT_RTP_RTP_SOURCE_H_

#include <stdint.h>

#include "absl/types/optional.h"
#include "api/rtp_headers.h"
#include "api/units/time_delta.h"
#include "api/units/timestamp.h"
#include "rtc_base/checks.h"

namespace webrtc {

enum class RtpSourceType {
  SSRC,
  CSRC,
};

class RtpSource {
 public:
  struct Extensions {
    absl::optional<uint8_t> audio_level;

    // Fields from the Absolute Capture Time header extension:
    // http://www.webrtc.org/experiments/rtp-hdrext/abs-capture-time
    absl::optional<AbsoluteCaptureTime> absolute_capture_time;

    // Clock offset between the local clock and the capturer's clock.
    // Do not confuse with `AbsoluteCaptureTime::estimated_capture_clock_offset`
    // which instead represents the clock offset between a remote sender and the
    // capturer. The following holds:
    //   Capture's NTP Clock = Local NTP Clock + Local-Capture Clock Offset
    absl::optional<TimeDelta> local_capture_clock_offset;
  };

  RtpSource() = delete;

  RtpSource(Timestamp timestamp,
            uint32_t source_id,
            RtpSourceType source_type,
            uint32_t rtp_timestamp,
            const RtpSource::Extensions& extensions)
      : timestamp_(timestamp),
        source_id_(source_id),
        source_type_(source_type),
        extensions_(extensions),
        rtp_timestamp_(rtp_timestamp) {}

  // TODO(bugs.webrtc.org/13757): deprecate when chromium stop using this
  // and remove after 2023-09-18
  RtpSource(int64_t timestamp_ms,
            uint32_t source_id,
            RtpSourceType source_type,
            uint32_t rtp_timestamp,
            const RtpSource::Extensions& extensions)
      : timestamp_(Timestamp::Millis(timestamp_ms)),
        source_id_(source_id),
        source_type_(source_type),
        extensions_(extensions),
        rtp_timestamp_(rtp_timestamp) {}

  RtpSource(const RtpSource&) = default;
  RtpSource& operator=(const RtpSource&) = default;
  ~RtpSource() = default;

  Timestamp timestamp() const { return timestamp_; }

  // TODO(bugs.webrtc.org/13757): deprecate when chromium stop using this
  // and remove after 2023-09-18
  int64_t timestamp_ms() const { return timestamp_.ms(); }
  [[deprecated]] void update_timestamp_ms(int64_t timestamp_ms) {
    RTC_DCHECK_LE(timestamp_.ms(), timestamp_ms);
    timestamp_ = Timestamp::Millis(timestamp_ms);
  }

  // The identifier of the source can be the CSRC or the SSRC.
  uint32_t source_id() const { return source_id_; }

  // The source can be either a contributing source or a synchronization source.
  RtpSourceType source_type() const { return source_type_; }

  absl::optional<uint8_t> audio_level() const {
    return extensions_.audio_level;
  }

  void set_audio_level(const absl::optional<uint8_t>& level) {
    extensions_.audio_level = level;
  }

  uint32_t rtp_timestamp() const { return rtp_timestamp_; }

  absl::optional<AbsoluteCaptureTime> absolute_capture_time() const {
    return extensions_.absolute_capture_time;
  }

  absl::optional<TimeDelta> local_capture_clock_offset() const {
    return extensions_.local_capture_clock_offset;
  }

  bool operator==(const RtpSource& o) const {
    return timestamp_ == o.timestamp() && source_id_ == o.source_id() &&
           source_type_ == o.source_type() &&
           extensions_.audio_level == o.extensions_.audio_level &&
           extensions_.absolute_capture_time ==
               o.extensions_.absolute_capture_time &&
           rtp_timestamp_ == o.rtp_timestamp();
  }

 private:
  Timestamp timestamp_;
  uint32_t source_id_;
  RtpSourceType source_type_;
  RtpSource::Extensions extensions_;
  uint32_t rtp_timestamp_;
};

}  // namespace webrtc

#endif  // API_TRANSPORT_RTP_RTP_SOURCE_H_
