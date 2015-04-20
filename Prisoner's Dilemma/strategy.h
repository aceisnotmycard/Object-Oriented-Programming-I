//
//  strategy.h
//  Prisoners Dilemma II
//
//  Created by Sergey Bogolepov on 11/24/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef Prisoners_Dilemma_II_strategy_h
#define Prisoners_Dilemma_II_strategy_h

#include <string>

enum Decision : bool {
    DEFECT = 0,
    COOPERATE = 1
};

class Strategy {
public:
    
    // Returns own decision
    virtual Decision make_decision() = 0;
    
    // Store other's decision
    virtual void remember_decision(std::string name, Decision decision) = 0;
    
    // Makes some preparations before the round
    virtual void notify_start(std::string name) = 0;
    
    // Saves results, sing a song or do something else at the and of the round
    virtual void notify_end() = 0;
    
    virtual ~Strategy() {}
};


#endif
