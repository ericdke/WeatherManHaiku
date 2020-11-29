#ifndef URLResult_hpp
#define URLResult_hpp

#include <string>

struct URLResult {
    URLResult(bool s, std::string r) : success(s), url(r) {};
    bool success;
    std::string url;
};

#endif /* URLResult_hpp */
