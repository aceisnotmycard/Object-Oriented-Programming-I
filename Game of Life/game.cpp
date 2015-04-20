//
//  game.cpp
//  Game of Life
//
//  Loading resources and giving it to controller
//
//  Created by Sergey Bogolepov on 10/22/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#include "game.h"

void Game::run(int argc, char** argv) {
    controller.init(&view, &model);
    view.init(&controller);
    
    iterations = -1;
    
    try {
        // Return if there was --help argument
        if (_parse_arguments(argc, argv)) {
            return;
        }
    } catch (std::exception e) {
        view.show_message(Strings::help_arguments());
        return;
    }
    // 0 arguments => demo mode
    if (argc == 1) {
        // Load demo
        view.show_message("WIP. Please, come back later.");
    } else {
        try {
            FileParser file_parser;
            file_parser.parse(input_filename);
            for (auto warning: file_parser.get_warnings()) {
                view.show_message(warning);
            }
            controller.set_field_size(file_parser.get_field_size());
            controller.set_points(file_parser.get_points());
            controller.set_needed_to_born(file_parser.get_needed_to_born());
            controller.set_needed_to_live(file_parser.get_needed_to_live());
            // If iterations != -1 then we're in offline mode
            controller.set_iterations(iterations);
            controller.set_name(file_parser.get_name());
            controller.set_output_file(output_filename);

        } catch (std::ifstream::failure e) {
            view.show_message("Error opening/reading input file");
        }
    }
    controller.run();
}


int Game::_parse_arguments(int argc, char** argv) {
    po::options_description desc("Allowed options");
    desc.add_options()
    ("help,h", "Show help message")
    ("iterations,i", po::value<int>(), "Set number of iterations")
    ("output,o", po::value<std::string>(), "Specify output file")
    ("file,f", po::value<std::string>(), "File with universe")
    ;
    
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);
    
    // NOT USING VIEW!!!
    if (vm.count("help")) {
        std::cout << desc << std::endl;
        return 1;
    }
    if (vm.count("file")) {
        input_filename = vm["file"].as<std::string>();
    }
    if (vm.count("iterations") && vm.count("output")) {
        iterations = vm["iterations"].as<int>();
        output_filename = vm["output"].as<std::string>();
    }
    return 0;
}