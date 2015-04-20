//
//  strategy_player.cpp
//  Prisoners Dilemma II
//
//  Created by Sergey Bogolepov on 11/25/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#include "strategy_player.h"

Decision StrategyPlayer::make_decision() {
    std::string decision;
    while (decision != "c" && decision != "d" && decision != "C" && decision != "D") {
        std::cout << "What is your decision? (C/D): ";
        std::cin >> decision;
    }
    if (decision == "c" || decision == "C") {
        return COOPERATE;
    } else {
        return DEFECT;
    }
}

void StrategyPlayer::remember_decision(std::string name, Decision decision) {
    
}

namespace {
    bool b = Factory<std::string, Strategy>::init()->add<StrategyPlayer>("player");
}