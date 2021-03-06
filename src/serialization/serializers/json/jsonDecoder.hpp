#pragma once

#include "serialization/decoder.hpp"

namespace smr {
    class JsonDecoder final : public Decoder {
    public:
	    explicit JsonDecoder(std::istream& is, const SerializerConfig& config)
	        : Decoder(is, config) {}

	    JsonDecoder(const JsonDecoder&) = delete;
	    JsonDecoder& operator = (JsonDecoder const&) = delete;
	    JsonDecoder(JsonDecoder&&) noexcept = delete;
	    JsonDecoder& operator = (JsonDecoder&&) noexcept = delete;

	    Serializable decode();

    private:
	    Serializable decodeSerializable();
        Serializable decodeArray();
        Serializable decodeObject();
        Serializable decodeString();
        Serializable decodeNumber();
    };
}