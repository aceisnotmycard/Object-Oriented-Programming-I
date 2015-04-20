//
//  console_parser.cpp
//  Prisoners Dilemma II
//
//  Created by Sergey Bogolepov on 11/24/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#include "console_parser.h"

#include <iostream>
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>

namespace po = boost::program_options;


ConsoleParser::ConsoleParser(int argc, const char** argv) : _argc(argc), _argv(argv) {
    _modes["detailed"] = DETAILED;
    _modes["fast"] = FAST;
    _modes["tournament"] = TOURNAMENT;

}

ConsoleParser::~ConsoleParser() {}

void ConsoleParser::parse_arguments() {
    po::options_description desc("Allowed options");
    desc.add_options()
    ("help", "produce help message")
    ("steps", po::value<int>(), "set number of steps in competition")
    ("mode", po::value<std::string>(), "set game mode: [detailed|fast|tournament]")
    ("configs", po::value<std::string>(), "directory with strategies configuration files")
    ("matrix", po::value<std::string>(), "path to file with rules matrix")
    ("strategies", po::value<std::vector<std::string>>(), "strategies names")
    ;
    
    po::positional_options_description p;
    p.add("strategies", -1);
    
    po::variables_map vm;
    po::store(po::command_line_parser(_argc, _argv).options(desc).positional(p).run(), vm);
    po::notify(vm);
    
    
    if (vm.count("strategies")) {
        _strategies = vm["strategies"].as<std::vector<std::string>>();
        if (3 > _strategies.size()) {
            std::cout << "You should choose at least 3 strategies!" << std::endl;
            return;
        } else if (3 ==_strategies.size()) {
            _mode = DETAILED;
        } else {
            _mode = TOURNAMENT;
        }
    } else {
        std::cout << "You should choose at least 3 strategies!" << std::endl;
    }
    if (vm.count("help")) {
        std::cout << desc << std::endl;
        return;
    }
    if (vm.count("steps")) {
        _steps = vm["steps"].as<int>();
        if (_steps < 1) {
            std::cout << "Number of steps should be more than 0!" << std::endl;
            return;
        }
    } else {
        std::cout << "Switching into manual mode" << std::endl;
        _steps = 0;
    }
    if (vm.count("mode")) {
        try {
            _mode = _modes.at(vm["mode"].as<std::string>());
        } catch (std::out_of_range e) {
            std::cout << desc << std::endl;
            return;
        }
    }
    if (vm.count("matrix")) {
        if (_file_exists(vm["matrix"].as<std::string>())) {
            _path_to_matrix = vm["matrix"].as<std::string>();
        } else {
            std::cout << vm["matrix"].as<std::string>() << " not found!" << std::endl;
            return;
        }
    } else {
        _path_to_matrix = "";
    }
    if (vm.count("configs")) {
        // TODO: Check it
        if (!(boost::filesystem::exists(vm["configs"].as<std::string>()))) {
            _path_to_configs = vm["configs"].as<std::string>();
        } else {
            std::cout << vm["configs"].as<std::string>() << " not found!" << std::endl;
            return;
        }
    } else {
        _path_to_configs = "";
    }
}

int ConsoleParser::get_steps() const {
    return _steps;
}

std::string ConsoleParser::get_configs_path() const {
    return _path_to_configs;
}

std::string ConsoleParser::get_matrix_path() const {
    return _path_to_matrix;
}

std::vector<std::string> ConsoleParser::get_strategies() const {
    return _strategies;
}

GameMode ConsoleParser::get_mode() const {
    return _mode;
}