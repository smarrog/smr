#pragma once

#include <map>
#include <functional>
#include <memory>

#include "serialization/serializer.hpp"

namespace smr {
    using SerializerConstructor = std::function<std::shared_ptr<Serializer>(SerializerConfig)>;

    class SerializerFactory final {
    public:
        SerializerFactory(const SerializerFactory&) = delete;
        SerializerFactory& operator = (SerializerFactory const&) = delete;
        SerializerFactory(SerializerFactory&&) noexcept = delete;
        SerializerFactory& operator = (SerializerFactory&&) noexcept = delete;

        static void reg(const std::string& type, SerializerConstructor) noexcept;
        static std::shared_ptr<Serializer> build(const std::string& type, SerializerConfig config = SerializerConfig());

    private:
        SerializerFactory() = default;

        static SerializerFactory& getInstance() {
            static SerializerFactory instance;
            return instance;
        }

        std::map<std::string, SerializerConstructor> _builders;
    };
}