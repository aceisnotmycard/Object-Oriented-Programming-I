//
//  field.h
//  Game of Life
//
//  Created by Sergey Bogolepov on 10/18/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef __Game_of_Life__field__
#define __Game_of_Life__field__

#include <vector>
#include <iostream>
#include <algorithm>

#include "cell_model.h"
#include "model.h"

class FieldModel : public Model {
public:
    FieldModel();
    FieldModel(std::vector<std::pair<int, int>> points);
    ~FieldModel();
    
    void set_field(const std::vector<std::pair<int, int>>& points);
    void set_needed_to_live(const std::vector<int>& arg);
    void set_needed_to_born(const std::vector<int>& arg);
    void set_field_size(const int size);
    
    
    virtual bool** get_field();
    
    auto get_needed_to_live() const {
        return needed_to_live;
    }
    auto get_needed_to_born() const {
        return needed_to_born;
    }
    virtual int get_field_size() {
        return field_size;
    }
    
    virtual void update();
        
private:
    int field_size;
    std::vector<int> needed_to_live;
    std::vector<int> needed_to_born;
    auto count_neighbours_sum(int i, int j) -> int;
    
    auto can_be_alive(int i, int j) -> bool;
    
    Cell** field;
    
    inline auto calc_pos(int i) {
        if (field_size == i) {
            return 0;
        } else if (-1 == i) {
            return field_size - 1;
        } else {
            return i;
        }
    }
    
    inline void init_field() {
        field = new Cell*[field_size];
        for (int i = 0; i < field_size; i++) {
            field[i] = new Cell[field_size];
        }
    }
};



#endif /* defined(__Game_of_Life__field__) */
