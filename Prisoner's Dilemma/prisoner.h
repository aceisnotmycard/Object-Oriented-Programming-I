//
//  prisoner.h
//  Prisoners Dilemma II
//
//  Created by Sergey Bogolepov on 11/24/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef __Prisoners_Dilemma_II__prisoner__
#define __Prisoners_Dilemma_II__prisoner__

#include "strategy.h"
#include "factory.h"

#include <iostream>

class Prisoner {
public:
    Prisoner(std::string name, int points, Strategy* strategy) : _points(points), _name(name), _strategy(strategy) {}
    
    int get_points() const;
    void add_points(int points);
    std::string get_name() const;
    
    Decision make_decision() const;
    void remember_decision(const std::string& name, const Decision& decision);
    
    void notify_start(std::string name);
    
    void notify_end();
    
private:
    int _points;
    std::string _name;
    std::unique_ptr<Strategy> _strategy;
};

#endif /* defined(__Prisoners_Dilemma_II__prisoner__) */
