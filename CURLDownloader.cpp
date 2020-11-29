#include "CURLDownloader.hpp"

using namespace rapidjson;

Weather CURLDownloader::parse(const std::string& json_string)
{
		Document document;
		const char *json_chars = json_string.c_str();
		document.Parse(json_chars);
		auto main = document["main"].GetObject();
		auto temp = main["temp"].GetFloat();
		auto city = document["name"].GetString();
		auto sys = document["sys"].GetObject();
		auto country = sys["country"].GetString();
		auto wind = document["wind"].GetObject();
		auto wind_speed = wind["speed"].GetFloat();
		auto wind_direction = wind["deg"].GetFloat();
		auto it = document["weather"].GetArray();
		auto first = it[0].GetObject();
		auto cat = first["description"].GetString();
		Weather w;
		w.temp = temp;
		w.city = city;
		w.country = country;
		w.wind_speed = wind_speed;
		w.wind_direction = wind_direction;
		w.category = cat;
		return w;
}

URLResult CURLDownloader::makeURL(int argc, const char * argv[])
{
    if(argc > 1)
    {
        // make a single string from all CLI input
        std::string input;
        for(int i = 1; i < argc; i++) {
            input += argv[i];
        }
        
        std::string url = "http://api.openweathermap.org/data/2.5/weather?q="
        + input
        + "&appid=d21991d7851f849bfe8cc24d12c795d0&units=metric&lang=fr";
        
        return URLResult(true, url);
    }
    return URLResult(false, "");
}

std::string CURLDownloader::download(const std::string &url)
{
    std::string result;
    std::string cmd = "curl -s \"" + url + "\"";
    const char *cstr = cmd.c_str();
    result = exec(cstr);
    return result;
}
