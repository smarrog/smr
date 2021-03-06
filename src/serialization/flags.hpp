#pragma once

namespace smr::serialization::flags {
    static const uint32_t STRICT = 1u << 0;
    static const uint32_t PRETTY = 1u << 1;
    static const uint32_t ESCAPED_UNICODE = 1u << 2;
    static const uint32_t HEADLESS = 1u << 3;
}