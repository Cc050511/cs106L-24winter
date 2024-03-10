/* 
Assignment 4: Weather Forecast

This assignment works with template functions and lambdas to become the best weather forecaster
at the Stanford Daily. Be sure to read the assignment details in the PDF.

Submit to Paperless by 11:59pm on 2/16/2024.
*/

// TODO: import anything from the STL that might be useful!
#include <iostream>
#include <vector>
#include <concepts>
#include <fstream>
#include <algorithm>

// TODO: write convert_f_to_c function here. Remember it must be a template function that always returns
// a double.
// [function definition here]
template<typename T>
requires std::is_arithmetic_v<T>
double convert_f_to_c(T temp) {
    return (temp - 32) * 5. / 9;
}

template<typename Function>
std::vector<double> get_forecast(std::vector<std::vector<int>> readings, Function fn) {
    // TODO: write get_forecast here!
    return fn(readings);
}

int main() {
    std::vector<std::vector<int>> readings = {
        {70, 75, 80, 85, 90},
        {60, 65, 70, 75, 80},
        {50, 55, 60, 65, 70},
        {40, 45, 50, 55, 60},
        {30, 35, 40, 45, 50},
        {50, 55, 61, 65, 70},
        {40, 45, 50, 55, 60}
    };

    // TODO: Convert temperatures to Celsius and output to output.txt
    std::for_each(readings.begin(), readings.end(), [](std::vector<int> &day) {
        std::transform(day.begin(), day.end(), day.begin(), convert_f_to_c<int>);
    });
    // TODO: Find the maximum temperature for each day and output to output.txt
    std::ofstream ofs("output.txt");
    ofs << "max temperatures: \n";
    std::for_each(readings.begin(), readings.end(), [&ofs](std::vector<int> &day) {
        ofs << *std::max_element(day.begin(), day.end()) << std::endl;
    });
    // TODO: Find the minimum temperature for each day and output to output.txt
    ofs << "min temperatures: \n";
    std::for_each(readings.begin(), readings.end(), [&ofs](std::vector<int> &day) {
        ofs << *std::min_element(day.begin(), day.end()) << std::endl;
    });
    // TODO: Find the average temperature for each day and output to output.txt
    ofs << "average temperatures: \n";
    std::for_each(readings.begin(), readings.end(), [&ofs](std::vector<int> &day) {
        double sum = 0;
        for (const auto &temp : day) {
            sum += temp;
        }
        sum = sum / day.size();
        ofs << sum << std::endl;
    });
    return 0;
}