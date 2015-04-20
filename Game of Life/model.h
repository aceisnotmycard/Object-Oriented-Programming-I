//
//  model.h
//  Game of Life
//
//  Created by Sergey Bogolepov on 10/18/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef Game_of_Life_model_h
#define Game_of_Life_model_h


class Model {
public:
    
    // Getting current state of field
    virtual int get_field_size() = 0;
    virtual bool** get_field() = 0;
    
    // Moving to the next step
    virtual void update() = 0;
};

#endif
