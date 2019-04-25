#pragma once

#include "jsonSerializer.hpp"
#include "../decoder.hpp"

namespace smr {
    class JsonDecoder final : public Decoder {
    DECLARE_DECODER(JsonSerializer, JsonDecoder)

    private:
        Serializable decodeArray();
        Serializable decodeObject();
        Serializable decodeString();
        Serializable decodeNumber();
    };
}