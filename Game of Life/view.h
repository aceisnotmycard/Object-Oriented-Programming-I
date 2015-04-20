//
//  view.h
//  Game of Life
//
//  Created by Sergey Bogolepov on 10/19/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef Game_of_Life_view_h
#define Game_of_Life_view_h


template <class Controller>
class View {
public:
    // Showing current state of Universe
    virtual void show() = 0;
    
    // Showing message with useful (or not ) information
    virtual void show_message(const std::string& message) = 0;
    
    
    View(): controller(0) {}
    //Use it to bind view with controller
    void init(Controller* c) {
        controller = c;
    }
    
    
protected:
    Controller* controller;
};

#endif
