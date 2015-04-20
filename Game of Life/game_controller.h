//
//  game_controller.h
//  Game of Life
//
//  Created by Sergey Bogolepov on 10/20/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef __Game_of_Life__game_controller__
#define __Game_of_Life__game_controller__

#include <string>
#include <vector>

#include "controller.h"
#include "field_model.h"
#include "game_view.h"
#include "input_handler.h"
#include "strings.h"
#include "file_creator.h"

class GameView;

class GameController : public Controller<GameView, FieldModel> {
public:
    
    // Main game cycle
    void run();
    
    // Setters for everything
    void set_name(std::string name);
    void set_points(std::vector<std::pair<int, int>> points);
    void set_field_size(int size);
    void set_needed_to_live(std::vector<int> arg);
    void set_needed_to_born(std::vector<int> arg);
    void set_iterations(int count);
    // Used only in offline mode
    void set_output_file(std::string name);
    
    // Getting current status of the universe
    int get_field_size();
    bool** get_field();
    
private:
    int iterations = -1;
    InputHandler input_handler;
    std::string output_filename;
    std::string game_name;
    
    void _dump(std::string filename);
    void _tick(int steps);

};

#endif /* defined(__Game_of_Life__game_controller__) */
