//
//  strategy_usualguy.h
//  Prisoners Dilemma II
//
//  Created by Sergey Bogolepov on 11/25/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef __Prisoners_Dilemma_II__strategy_usualguy__
#define __Prisoners_Dilemma_II__strategy_usualguy__

#include "strategy.h"

#include <vector>
#include <map>

class StrategyUsualguy : public Strategy {
public:
    virtual Decision make_decision();
    virtual void remember_decision(std::string name, Decision decision);
    
    virtual void notify_start(std::string name);
    
    virtual void notify_end();
private:
    const std::string _filename = "usualguy";
    
    Decision _current_decision = COOPERATE;

    std::map<std::string, std::vector<Decision>> _opponents_history;
    std::vector<std::string> _current_opponents;
        
    void _analyse();
    
    void _store();
    void _load();
    
    std::vector<std::string> _parts;
    std::string _line;
    void _split_string(const std::string& input);
};

#endif /* defined(__Prisoners_Dilemma_II__strategy_usualguy__) */
