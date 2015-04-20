//
//  field.cpp
//  Game of Life
//
//  Created by Sergey Bogolepov on 10/18/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#include "field_model.h"

FieldModel::FieldModel() : field_size(1) {
    init_field();
}

FieldModel::~FieldModel() {
    for (int i = 0; i < field_size; i++) {
        delete[] field[i];
    }
    delete[] field;
}

void FieldModel::set_field(const std::vector<std::pair<int, int>>& points) {
    init_field();
    for(auto &point : points) {
        field[point.first][point.second].set_current_state(Cell::ALIVE);
    }
}

bool** FieldModel::get_field() {
    auto bool_field = new bool*[field_size]; // bool**
    for (int i = 0; i < field_size; i++) {
        bool_field[i] = new bool[field_size];
    }
    for (int i = 0; i < field_size; i++)
        for (int j = 0; j < field_size; j++)
            bool_field[i][j] = field[i][j].get_current_state();
    return bool_field;
}

void FieldModel::update() {
    for (int i = 0; i < field_size; i++) {
        for (int j = 0; j < field_size; j++) {
            if (can_be_alive(i, j)) {
                field[i][j].set_next_state(Cell::ALIVE);
            } else {
                field[i][j].set_next_state(Cell::DEAD);
            }
        }
    }
    
    for (int i = 0; i < field_size; i++) {
        for (int j = 0; j < field_size; j++) {
            field[i][j].update();
        }
    }
}

auto FieldModel::can_be_alive(int i, int j) -> bool {
    bool status = false;
    int sum = count_neighbours_sum(i, j);
    if (Cell::ALIVE == field[i][j].get_current_state()) {
        if (std::find(needed_to_live.begin(), needed_to_live.end(), sum) != needed_to_live.end()) {
            status = true;
        }
    } else if (std::find(needed_to_born.begin(), needed_to_born.end(), sum) != needed_to_born.end()) {
        status = true;
    }
    return status;
}

void FieldModel::set_needed_to_live(const std::vector<int>& arg) {
    needed_to_live = arg;
}

void FieldModel::set_needed_to_born(const std::vector<int>& arg) {
    needed_to_born = arg;
}

void FieldModel::set_field_size(const int size) {
    field_size = size;
    init_field();
}

auto FieldModel::count_neighbours_sum(int i, int j) -> int {
    int sum = 0;
    
    sum += field[calc_pos(i)]  [calc_pos(j+1)].get_current_state();
    sum += field[calc_pos(i+1)][calc_pos(j+1)].get_current_state();
    sum += field[calc_pos(i+1)][calc_pos(j)].get_current_state();
    sum += field[calc_pos(i+1)][calc_pos(j-1)].get_current_state();
    sum += field[calc_pos(i)]  [calc_pos(j-1)].get_current_state();
    sum += field[calc_pos(i-1)][calc_pos(j-1)].get_current_state();
    sum += field[calc_pos(i-1)][calc_pos(j)].get_current_state();
    sum += field[calc_pos(i-1)][calc_pos(j+1)].get_current_state();
    
    return sum;
}