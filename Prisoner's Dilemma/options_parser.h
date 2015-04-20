//
//  options_parser.h
//  Prisoners Dilemma II
//
//  Created by Sergey Bogolepov on 11/24/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef Prisoners_Dilemma_II_options_parser_h
#define Prisoners_Dilemma_II_options_parser_h

#include <string>
#include <vector>

enum GameMode {
    DETAILED,
    FAST,
    TOURNAMENT
};


// Interface for all game options.
// It will be given as argument for Game.
class OptionsParser {
public:
    virtual int get_steps() const = 0;
    virtual std::string get_configs_path() const = 0;
    virtual std::string get_matrix_path() const = 0;
    virtual std::vector<std::string> get_strategies() const = 0;
    virtual GameMode get_mode() const = 0;
    
    virtual ~OptionsParser() {}
private:
};

#endif
