//
//  rule_matrix.cpp
//  Prisoners Dilemma II
//
//  Created by Sergey Bogolepov on 11/24/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#include "rule_matrix.h"

#include <fstream>
#include <boost/algorithm/string.hpp>

void RuleMatrix::use_default_matrix(size_t size) {
    _matrix[{DEFECT, DEFECT, DEFECT}] = {1, 1, 1};
    _matrix[{DEFECT, DEFECT, COOPERATE}] = {3, 3, 0};
    _matrix[{DEFECT, COOPERATE, DEFECT}] = {3, 0, 3};
    _matrix[{DEFECT, COOPERATE, COOPERATE}] = {5, 2, 2};
    _matrix[{COOPERATE, DEFECT, DEFECT}] = {0, 3, 3};
    _matrix[{COOPERATE, DEFECT, COOPERATE}] = {2, 5, 2};
    _matrix[{COOPERATE, COOPERATE, DEFECT}] = {2, 2, 5};
    _matrix[{COOPERATE, COOPERATE, COOPERATE}] = {4, 4, 4};
}

void RuleMatrix::use_external_matrix(const std::string& path) {
    std::ifstream file(path);
    
    //file format
    // DECISIONS SCORES
    // D D C 3 3 0
    if (file.good()) {
        while (std::getline(file, _line)) {
            _parts.clear();
            _decision.clear();
            _score.clear();
            
            _split_string(_line);
            for (auto part: _parts) {
                if (part == "D") {
                    _decision.push_back(DEFECT);
                } else if (part == "C") {
                    _decision.push_back(COOPERATE);
                } else {
                    _score.push_back(std::stoi(part));
                }
            }
            _matrix[_decision] = _score;
        }
        file.close();
    }
}


void RuleMatrix::_split_string(const std::string& input) {
    boost::split(_parts, input, boost::is_any_of("\t "));
}