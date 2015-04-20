//
//  game.h
//  Game of Life
//
//  Created by Sergey Bogolepov on 10/22/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef __Game_of_Life__game__
#define __Game_of_Life__game__

#include <cstdlib>

#include <boost/program_options.hpp>
namespace po = boost::program_options;

#include "game_view.h"
#include "game_controller.h"
#include "field_model.h"
#include "file_parser.h"


// Main class, entry point of the Game.
class Game {
public:
    
    // Running game.
    // argc and argv are usual console parameters.
    void run(int argc, char** argv);

private:
    FieldModel model;
    GameView view;
    GameController controller;
    
    std::string output_filename = "";
    std::string input_filename = "";

    int iterations = -1;
    
    int _parse_arguments(int argc, char** argv);
    

};

#endif /* defined(__Game_of_Life__game__) */
