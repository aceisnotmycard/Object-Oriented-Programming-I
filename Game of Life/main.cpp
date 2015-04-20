//
//  main.cpp
//  Game of Life
//
//  Created by Sergey Bogolepov on 10/18/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#include <iostream>

#include "game.h"

int main(int argc, char** argv) {
    
    Game game;
    game.run(argc, argv);
    
    return 0;
}
