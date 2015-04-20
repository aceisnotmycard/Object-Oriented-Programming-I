//
//  prisoner.cpp
//  Prisoners Dilemma II
//
//  Created by Sergey Bogolepov on 11/24/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#include "prisoner.h"

std::string Prisoner::get_name() const {
    return _name;
}

int Prisoner::get_points() const {
    return _points;
}

void Prisoner::add_points(int points) {
    _points += points;
}

Decision Prisoner::make_decision() const {
    return _strategy->make_decision();
}

void Prisoner::remember_decision(const std::string& name, const Decision& decision) {
    _strategy->remember_decision(name, decision);
}

void Prisoner::notify_end() {
    _strategy->notify_end();
}

void Prisoner::notify_start(std::string name) {
    _strategy->notify_start(name);
}