//
//  input_handler.h
//  Game of Life
//
//  Created by Sergey Bogolepov on 10/22/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef __Game_of_Life__input_handler__
#define __Game_of_Life__input_handler__

#include <string>
#include <vector>
#include <iostream>

#include <boost/algorithm/string.hpp>

class InputHandler {
public:
    int parse_input();
    
    std::string get_output_file() const;
    int get_tick_count() const;
    
    //Use this constants to know current user's command
    enum Command {
        HELP = 0,
        TICK = 1,
        EXIT = 2,
        DUMP = 3,
        WRONG = 4,
        SETTINGS = 5,
        PLAY = 6
    };
    
    Command get_current_command() const;
private:
    Command current_command;
    int tick = 1;
    std::string output_file;
    std::vector<std::string> parts;
    
    void _parse_command(const std::string& command);
    void _split_string(const std::string& input);
};

#endif /* defined(__Game_of_Life__input_handler__) */