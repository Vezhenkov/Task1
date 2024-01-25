#include <iostream>
#include <boost/program_options.hpp>
#include <chrono>
#include <format>

namespace bpo = boost::program_options;

bpo::variables_map parse_program_arguments(int argc, char** argv);

int main(int argc, char** argv) {
    bpo::variables_map vm = parse_program_arguments(argc, argv);
    const std::string file = vm["file"].as<std::string>();
    const std::time_t time_start = vm["time_start"].as<std::time_t>();
    const std::time_t time_end = vm["time_end"].as<std::time_t>();
    const double latitude = vm["latitude"].as<double>();
    const double longitude = vm["longitude"].as<double>();
    const double height = vm["height"].as<double>();
    const double min_elevation = vm["min_elevation"].as<double>();

    if (vm.count("verbose")) {
        std::clog << std::format("file: \"{}\"", file) << std::endl;
        std::clog << std::format("time: {} - {}", time_start, time_end) << std::endl;
        std::clog << std::format("coordinates: latitude = {}, longitude = {}, height = {}", latitude, longitude, height)
                  << std::endl;
        std::clog << std::format("minimum elevation: {}", min_elevation) << std::endl;
    }

    return 0;
}

bpo::variables_map parse_program_arguments(int argc, char** argv) {
    bpo::options_description general_options("General options");
    general_options.add_options()
        ("verbose,v", "verbose")
        ("help,h", "Show help");

    const time_t time_point = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    bpo::options_description common_options("common_options options");
    common_options.add_options()
        ("file", bpo::value<std::string>()->default_value(""), "TLE file")
        ("time_start", bpo::value<time_t>()->default_value(0), "time start")
        ("time_end", bpo::value<time_t>()->default_value(time_point), "time end")
        ("latitude", bpo::value<double>()->default_value(0), "latitude")
        ("longitude", bpo::value<double>()->default_value(0), "longitude")
        ("height", bpo::value<double>()->default_value(0), "height")
        ("min_elevation", bpo::value<double>()->default_value(0), "minimum elevation");

    bpo::options_description options;
    options.add(common_options).add(general_options);

    bpo::variables_map vm;
    bpo::parsed_options parsed = bpo::command_line_parser(argc, argv).options(options).allow_unregistered().run();
    bpo::store(parsed, vm);
    bpo::notify(vm);

    if (vm.count("help")) {
        std::cout << "Usage: ";
        std::cout << general_options << std::endl;
        std::cout << common_options << std::endl;
        exit(0);
    }

    return vm;
}
