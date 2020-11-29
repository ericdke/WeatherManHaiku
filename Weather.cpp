#include "Weather.hpp"

float Weather::wind_speed_kmh()
{
    return floor(((wind_speed * 3.6) * 5 + 0.5) / 5);
}

std::string Weather::wind_direction_compass()
{
    std::vector<std::string> compass = {"Nord","Nord Nord-Est","Nord-Est","Est-Nord-Est","Est","Est-Sud-Est","Sud-Est","Sud-Sud-Est","Sud","Sud-Sud-Ouest","Sud-Ouest","Ouest-Sud-Ouest","Ouest","Ouest-Nord-Ouest","Nord-Ouest","Nord-Nord-Ouest"};
    float wd = (wind_direction / 22.5) + 0.5;
    // % (modulo operator) is not available for floats, use fmod
    int index = fmod(wd, 16);
    return compass[index];
}

std::string Weather::description()
{
    // DateTime is a struct defined in the header
    DateTime dt = date_formatted();
    std::string dts = dt.date + ", " + dt.time;
    std::string cel = float_to_string(temp, 1);
    std::string ci = city + " (" + country + "), le " + dts + ".\n";
    std::string te = "Température: " + cel + "°C.\n";
    std::string ca = ci + te + "Temps: " + category + ".\n";
    // TODO: check if wind exists in API response before using it
    std::string w = float_to_string(wind_speed_kmh(), 1);
    std::string desc = ca + "Vent: " + wind_direction_compass() + " à " + w + " km/h.\n";
    return desc;
}

DateTime Weather::date_formatted()
{
    time_t temps;
    struct tm datetime;
    char format_date[32];
    char format_temps[32];
    time(&temps);
    datetime = *localtime(&temps);
    strftime(format_date, 32, "%d/%m/%Y", &datetime);
    strftime(format_temps, 32, "%Hh%M", &datetime);
    DateTime dt;
    dt.date = (std::string) format_date;
    dt.time = (std::string) format_temps;
    return dt;
}
