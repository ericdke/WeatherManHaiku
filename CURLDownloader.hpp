#ifndef CURLDOWNLOADER_HPP
#define CURLDOWNLOADER_HPP

#include "URLResult.hpp"
#include "Utils.hpp"
#include "Weather.hpp"
#include "rapidjson/document.h"

class CURLDownloader {
public:
	Weather parse(const std::string& json_string);
    std::string download(const std::string& url);
    URLResult makeURL(int argc, const char * argv[]);
};

#endif  /* CURLDOWNLOADER_HPP */
