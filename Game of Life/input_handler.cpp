//
//  input_handler.cpp
//  Game of Life
//
//  Created by Sergey Bogolepov on 10/22/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#include "input_handler.h"

int InputHandler::parse_input() {
    std::string command;
    getline(std::cin, command);
    _parse_command(command);
    return get_current_command();
}

InputHandler::Command InputHandler::get_current_command() const {
    return current_command;
}

std::string InputHandler::get_output_file() const {
    return output_file;
}

int InputHandler::get_tick_count() const {
    return tick;
}

void InputHandler::_parse_command(const std::string& command) {
    parts.clear();
    tick = 1;
    
    _split_string(command);
    
    if (parts.size() > 2) {
        current_command = HELP;
    } else if ("help" == parts[0]) {
        current_command = HELP;
    } else if ("tick" == parts[0] || "t" == parts[0]) {
        current_command = TICK;
        if (2 == parts.size()) {
            try {
                tick = std::stoi(parts[1]);
            } catch (std::out_of_range e) {
                tick = 1;
            }
        }
    } else if ("dump" == parts[0]) {
        current_command = DUMP;
        output_file = parts[1];
    } else if ("exit" == parts[0] || "quit" == parts[0]) {
        current_command = EXIT;
    } else if ("settings" == parts[0]) {
        current_command = SETTINGS;
    } else if ("play" == parts[0]) {
        current_command = PLAY;
        if (2 == parts.size()) {
            try {
                tick = std::stoi(parts[1]);
            } catch (std::out_of_range e) {
                tick = 1;
            }
        }
    } else {
        current_command = HELP;
    }
}

void InputHandler::_split_string(const std::string& input) {
    boost::split(parts, input, boost::is_any_of("\t "));
}
