#include "amf3Serializer.hpp"
#include "amf3Decoder.hpp"
#include "amf3Encoder.hpp"
#include "serialization/exceptions.hpp"

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>

using namespace smr;

REGISTER_SERIALIZER(amf3, Amf3Serializer)

Serializable Amf3Serializer::decode(std::istream& is) {
    try {
        return Amf3Decoder(is, getConfig()).decode();
    } catch(std::exception& exception) {
        throw DecodeException("amf3", is, exception);
    }
}

void Amf3Serializer::encode(std::ostream& os, const Serializable& value) {
    try {
        return Amf3Encoder(os, getConfig()).encode(value);
    } catch(std::exception& exception) {
        throw EncodeException("amf3", exception);
    }
}