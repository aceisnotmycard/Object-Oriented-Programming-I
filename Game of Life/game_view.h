//
//  game_view.h
//  Game of Life
//
//  Created by Sergey Bogolepov on 10/21/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef __Game_of_Life__game_view__
#define __Game_of_Life__game_view__

#include <string>
#include <iostream>
#include <unistd.h>
#include <cstdlib>

#include "view.h"
#include "game_controller.h"


class GameController;

class GameView : public View<GameController> {
public:
    
    void show();
    void show_message(const std::string& message);
private:
    bool** field;
    void clear_field();
};

#endif /* defined(__Game_of_Life__game_view__) */
