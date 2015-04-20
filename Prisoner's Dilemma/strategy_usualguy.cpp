//
//  strategy_usualguy.cpp
//  Prisoners Dilemma II
//
//  Created by Sergey Bogolepov on 11/25/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#include "strategy_usualguy.h"
#include "factory.h"

#include <fstream>
#include <boost/algorithm/string.hpp>


Decision StrategyUsualguy::make_decision() {
    _analyse();
    return _current_decision;
}

void StrategyUsualguy::remember_decision(std::string name, Decision decision) {
    _opponents_history[name].push_back(decision);
}


//
void StrategyUsualguy::_analyse() {
    int result = 0;
    for (auto opponent : _current_opponents) {
        int count = 0;
        for (auto decision : _opponents_history[opponent]) {
            decision == DEFECT ? count++ : count--;
        }
        count >= 0 ? result-- : result++;
    }
    _current_decision = result <= 0 ? DEFECT : COOPERATE;
}

void StrategyUsualguy::notify_start(std::string name) {
    _load();
    _current_opponents.push_back(name);
}

void StrategyUsualguy::notify_end() {
    _store();
}

// Storing all experience to file
// Not optimal, because we load and store whole data every round
void StrategyUsualguy::_store() {
    std::ofstream ofs;
    ofs.open(_filename, std::ofstream::out | std::ofstream::trunc);
    
    for (auto opponent : _opponents_history) {
        ofs << opponent.first;
        for (auto decision : opponent.second) {
            if (decision == DEFECT) {
                ofs << " D";
            } else {
                ofs << " C";
            }
        }
        ofs << "\n";
    }
    
    ofs.close();
}

// Loading previous experience from file
void StrategyUsualguy::_load() {
    std::ifstream file(_filename);
    
    // file format
    // <NAME> <DECISIONS...>
    if (file.good()) {
        _parts.clear();
        while (std::getline(file, _line)) {
            _split_string(_line);
            for (int i = 1; i < _parts.size(); i++) {
                if (_parts[i] == "D") {
                    _opponents_history[_parts[0]].push_back(DEFECT);
                } else {
                    _opponents_history[_parts[0]].push_back(COOPERATE);
                }
            }
        }
        file.close();
    }
}


void StrategyUsualguy::_split_string(const std::string& input) {
    boost::split(_parts, input, boost::is_any_of("\t "));
}

namespace {
    bool b = Factory<std::string, Strategy>::init()->add<StrategyUsualguy>("usualguy");
}