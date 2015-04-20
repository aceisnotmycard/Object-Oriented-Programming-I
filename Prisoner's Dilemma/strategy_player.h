//
//  strategy_player.h
//  Prisoners Dilemma II
//
//  Created by Sergey Bogolepov on 11/25/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef __Prisoners_Dilemma_II__strategy_player__
#define __Prisoners_Dilemma_II__strategy_player__

#include "strategy.h"
#include "factory.h"

#include <iostream>
#include <string>

class StrategyPlayer : public Strategy {
public:
    virtual Decision make_decision();
    
    virtual void remember_decision(std::string name, Decision decision);
    
    virtual void notify_start(std::string name) {}
    
    virtual void notify_end() {}
    
    virtual ~StrategyPlayer() {}
};

#endif /* defined(__Prisoners_Dilemma_II__strategy_player__) */
