//
//  console_view.cpp
//  Prisoners Dilemma II
//
//  Created by Sergey Bogolepov on 11/24/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#include "console_view.h"
#include <iostream>


void ConsoleView::show_message(const std::string& message) const {
    std::cout << message << std::endl;
}

void ConsoleView::show_results(const std::vector<Prisoner*>& prisoners) const {
    for (auto& prisoner: prisoners) {
        std::cout << prisoner->get_name() << ": " << prisoner->get_points() << std::endl;
    }
    std::cout << "====================" << std::endl;
}