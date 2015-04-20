//
//  field_controller.cpp
//  Game of Life
//
//  Created by Sergey Bogolepov on 10/18/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#include "field_controller.h"

FieldController::FieldController() {
    field = fi
}

FieldController::~FieldController() {
    delete field;
}

bool** FieldController::show() {
    return field->get_field();
}


//Add exceptions
int FieldController::iterate(int steps) {
    for (int i = 0; i < steps; i++) {
        field->update();
    }
    return 0;
}

int FieldController::setup(std::vector<std::pair<int, int>> points) {
    field = new FieldModel(points);
    return 0;
}

int FieldController::exit() {
    delete field;
    return 0;
}