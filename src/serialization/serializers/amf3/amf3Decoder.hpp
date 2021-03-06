#pragma once

#include "serialization/decoder.hpp"
#include "amf3Context.hpp"

namespace smr {
    class Amf3Decoder final : public Decoder {
    public:
        explicit Amf3Decoder(std::istream& is, const SerializerConfig& config)
            : Decoder(is, config) {}

        Amf3Decoder(const Amf3Decoder&) = delete;
        Amf3Decoder& operator = (Amf3Decoder const&) = delete;
        Amf3Decoder(Amf3Decoder&&) noexcept = delete;
        Amf3Decoder& operator = (Amf3Decoder&&) noexcept = delete;

        Serializable decode();

    private:
        Amf3Context _context;

        void decodeHeaders();
        void decodeMessages();

        Serializable decodeInteger();
        Serializable decodeDouble();
        Serializable decodeString();
        Serializable decodeObject();
        Serializable decodeXML();
        Serializable decodeDate();
        Serializable decodeArray();
        Serializable decodeByteArray();
        Serializable decodeVectorInt();
        Serializable decodeVectorUint();
        Serializable decodeVectorDouble();
        Serializable decodeVectorObject();
        Serializable decodeDictionary();

        int decodeHeadlessInteger();
        std::string decodeHeadlessString();
    };
}