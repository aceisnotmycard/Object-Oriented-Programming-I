//
//  controller.h
//  Game of Life
//
//  Created by Sergey Bogolepov on 10/18/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef Game_of_Life_controller_h
#define Game_of_Life_controller_h

template <class View, class Model>
class Controller {
public:

    // Main game cycle
    virtual void run() = 0;
    
    //Returning currenst state of universe in boolean representation
    virtual bool** get_field() = 0;
    virtual int get_field_size() = 0;
    
    Controller(): view(0), model(0) {}
    // Use it in the beginning to bind controller with model and view
    void init(View* v, Model* m) {
        view = v;
        model = m;
    }
protected:
    View* view;
    Model* model;
};

#endif
