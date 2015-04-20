//
//  strategy_goodguy.cpp
//  Prisoners Dilemma II
//
//  Created by Sergey Bogolepov on 11/24/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#include "strategy_goodguy.h"

Decision StrategyGoodguy::make_decision() {
    return COOPERATE;
}

void StrategyGoodguy::remember_decision(std::string name, Decision decision) { }

namespace {
    bool b = Factory<std::string, Strategy>::init()->add<StrategyGoodguy>("goodguy");
}