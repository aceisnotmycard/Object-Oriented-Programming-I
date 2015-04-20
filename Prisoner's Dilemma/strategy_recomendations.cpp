//
//  strategy_recomendations.cpp
//  Prisoners Dilemma II
//
//  Created by Sergey Bogolepov on 12/24/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#include "strategy_recomendations.h"
#include "factory.h"

#include <iostream>
#include <string>

Decision StrategyRecomendations::make_decision() {
    std::string decision;
    auto guy_decision = guy.make_decision();
    while (decision != "c" && decision != "d" && decision != "C" && decision != "D") {
        std::cout << "It's better to ";
        if (guy_decision == COOPERATE) {
            std::cout << "cooperate." << std::endl;
        } else {
            std::cout << "defect." << std::endl;
        }
        std::cout << "What is your decision? (C/D): ";
        std::cin >> decision;
    }
    if (decision == "c" || decision == "C") {
        return COOPERATE;
    } else {
        return DEFECT;
    }
}

void StrategyRecomendations::remember_decision(std::string name, Decision decision) {
    guy.remember_decision(name, decision);
}

void StrategyRecomendations::notify_start(std::string name) {
    guy.notify_start(name);
}

void StrategyRecomendations::notify_end() {
    guy.Strategy::notify_end();
}

namespace {
    bool b = Factory<std::string, Strategy>::init()->add<StrategyRecomendations>("recomendations");
}