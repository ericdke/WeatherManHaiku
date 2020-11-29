#include "Utils.hpp"

void clear_screen()
{
	std::string cs = "clear";
	const char *p = cs.c_str();
	auto clear = exec(p);
	print(clear);
}

std::string float_to_string(float const& f, int const& p)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(p) << f;
    return stream.str();
}

void print(std::string const& s)
{
    std::cout << s << std::endl;
}

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}
