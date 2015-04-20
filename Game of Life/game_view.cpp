//
//  game_view.cpp
//  Game of Life
//
//  Created by Sergey Bogolepov on 10/21/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#include "game_view.h"


void GameView::show() {
    auto field = controller->get_field();
    clear_field();
    for (int i = 0; i < controller->get_field_size(); i++) {
        std::cout << "|";
        for (int j = 0; j < controller->get_field_size(); j++) {
            if (field[i][j]) {
                std::cout << "O" << " ";
            } else {
                std::cout << " " << " ";
            }
        }
        std::cout << "|" << std::endl;
    }
    usleep(130000);
}



void GameView::show_message(const std::string& message) {
    std::cout << message << std::endl;
}


void GameView::clear_field() {
    //system("clear");
    std::cout << std::string(100, '\n');
}