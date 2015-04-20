//
//  strategy_recomendations.h
//  Prisoners Dilemma II
//
//  Created by Sergey Bogolepov on 12/24/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef __Prisoners_Dilemma_II__strategy_recomendations__
#define __Prisoners_Dilemma_II__strategy_recomendations__

#include "strategy.h"
#include "strategy_usualguy.h"

class StrategyRecomendations : Strategy {
public:
    virtual Decision make_decision();
    
    virtual void remember_decision(std::string name, Decision decision);
    
    virtual void notify_start(std::string name);
    
    virtual void notify_end();
    
    virtual ~StrategyRecomendations() {}
private:
    StrategyUsualguy guy;
};

#endif /* defined(__Prisoners_Dilemma_II__strategy_recomendations__) */
