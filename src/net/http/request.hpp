#pragma once

#include <string>
#include <unordered_map>
#include <sstream>

namespace smr {
    class HttpRequest {
        HttpRequest(std::string method, std::string uri, std::string host, std::string version = "HTTP1.1")
            : _method(std::move(method))
            , _uri(std::move(uri))
            , _version(std::move(version))
            , _headers({ { "Host", std::move(host) } }) { }

        void addHeader(std::string name, std::string body);
        std::string serialize() const;

    private:
        std::string _method;
        std::string _uri;
        std::string _version;
        std::unordered_map<std::string, std::string> _headers;
    };
}
