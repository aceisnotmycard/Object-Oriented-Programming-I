//
//  input_handler.h
//  Prisoners Dilemma II
//
//  Created by Sergey Bogolepov on 11/24/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef Prisoners_Dilemma_II_input_handler_h
#define Prisoners_Dilemma_II_input_handler_h

class InputHandler {
public:
    enum Command {
        TICK,
        QUIT,
        UNKNOWN
    };
    
    virtual Command get_command() = 0;
    virtual int get_tick() = 0;
};

#endif
