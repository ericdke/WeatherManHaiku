#include "URLResult.hpp"
#include "CURLDownloader.hpp"
#include "Utils.hpp"
#include "Weather.hpp"

int main(int argc, const char * argv[])
{
	CURLDownloader dl;
	URLResult result = dl.makeURL(argc, argv);	
	if (result.success) {
		clear_screen();
		print("Downloading data...");
		std::string json_string = dl.download(result.url);
		Weather w = dl.parse(json_string);
		clear_screen();
		print(w.description());
		exit(0);
	} else {
		print("\nOops, that didn't work out very well...");	
		exit(1);
	}
}




