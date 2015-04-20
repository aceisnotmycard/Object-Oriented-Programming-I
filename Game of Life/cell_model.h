//
//  cell.h
//  Game of Life
//
//  Created by Sergey Bogolepov on 10/18/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef __Game_of_Life__cell__
#define __Game_of_Life__cell__

class Cell {
public:
    Cell() : current_state(DEAD), next_state(DEAD) {};
    
    auto get_current_state() const {
        return current_state;
    };
    
    void set_next_state(bool new_state) {
        next_state = new_state;
    };
    
    void set_current_state(bool new_state) {
        current_state = new_state;
    };
    
    void update() {
        current_state = next_state;
        next_state = DEAD;
    };
    
    static const bool ALIVE = true;
    static const bool DEAD = false;
    
private:
    bool current_state;
    bool next_state;
};

#endif /* defined(__Game_of_Life__cell__) */
