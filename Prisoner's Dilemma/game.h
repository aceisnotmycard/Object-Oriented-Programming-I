//
//  game.h
//  Prisoners Dilemma II
//
//  Created by Sergey Bogolepov on 11/24/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef __Prisoners_Dilemma_II__game__
#define __Prisoners_Dilemma_II__game__

#include "options_parser.h"
#include "strategy.h"
#include "factory.h"
#include "view.h"
#include "prisoner.h"
#include "input_handler.h"
#include "rule_matrix.h"


//TODO: Switch from Singleton pattern to usual class
class Game {
public:
    Game() {}
    
    void run(std::shared_ptr<OptionsParser> parser, std::shared_ptr<View> view, std::shared_ptr<InputHandler> handler);
    
private:
    
    // Strategies names and points
    std::vector<Prisoner*> _prisoners;
    std::vector<Prisoner*> _participants;
    GameMode _mode;
    int _steps;
    
    std::shared_ptr<View> _view;
    std::shared_ptr<InputHandler> _handler;
    
    RuleMatrix _matrix;
    
    void _play_round();
    void _play(int times);
};

#endif /* defined(__Prisoners_Dilemma_II__game__) */
