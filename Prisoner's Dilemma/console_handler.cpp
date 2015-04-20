//
//  console_handler.cpp
//  Prisoners Dilemma II
//
//  Created by Sergey Bogolepov on 11/24/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#include "console_handler.h"

InputHandler::Command ConsoleHandler::get_command() {
    std::cout << "> ";
    std::string command;
    getline(std::cin, command);
    _split_string(command);
    
    if ("quit" == _parts[0]) {
        return QUIT;
    } else if ("tick" == _parts[0]) {
        if (2 == _parts.size()) {
            try {
                _tick = std::stoi(_parts[1]);
            } catch (std::out_of_range e) {
                _tick = 1;
            } catch (std::invalid_argument e) {
                _tick = 1;
            }
        } else {
            _tick = 1;
        }
        return TICK;
    } else {
        return UNKNOWN;
    }
}

int ConsoleHandler::get_tick() {
    return _tick;
}

void ConsoleHandler::_split_string(const std::string& input) {
    boost::split(_parts, input, boost::is_any_of("\t "));
}