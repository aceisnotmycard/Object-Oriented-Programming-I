//
//  field_controller.h
//  Game of Life
//
//  Created by Sergey Bogolepov on 10/18/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef __Game_of_Life__field_controller__
#define __Game_of_Life__field_controller__

#include "field_model.h"
#include "controller.h"

class FieldController : public Controller {
public:
    FieldController();
    ~FieldController();
    
    //return current state of game
    bool** show();
    
    //make steps iterations
    int iterate(int steps);
    
    //Assign starting parameters
    int setup(std::vector<std::pair<int, int>> points);
    
    int exit();
    
private:
    
};

#endif /* defined(__Game_of_Life__field_controller__) */
