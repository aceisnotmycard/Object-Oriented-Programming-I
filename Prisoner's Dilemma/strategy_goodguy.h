//
//  strategy_goodguy.h
//  Prisoners Dilemma II
//
//  Created by Sergey Bogolepov on 11/24/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef __Prisoners_Dilemma_II__strategy_goodguy__
#define __Prisoners_Dilemma_II__strategy_goodguy__

#include "strategy.h"
#include "factory.h"

class StrategyGoodguy : public Strategy {
public:
    StrategyGoodguy() {};
    
    virtual Decision make_decision() override;
    virtual void remember_decision(std::string name, Decision decision) override;
    
    virtual void notify_start(std::string name) {}
    
    virtual void notify_end() {}
};

#endif /* defined(__Prisoners_Dilemma_II__strategy_goodguy__) */
