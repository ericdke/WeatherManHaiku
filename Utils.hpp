#ifndef Utils_hpp
#define Utils_hpp

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <stdexcept>
#include <string>
#include <array>

void clear_screen();
std::string exec(const char* cmd);
std::string float_to_string(float const& f, int const& p);
void print(std::string const& s);

#endif /* Utils_hpp */
