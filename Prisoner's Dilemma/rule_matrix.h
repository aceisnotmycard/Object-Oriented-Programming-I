//
//  rule_matrix.h
//  Prisoners Dilemma II
//
//  Created by Sergey Bogolepov on 11/24/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef __Prisoners_Dilemma_II__matrix_matrix__
#define __Prisoners_Dilemma_II__matrix_matrix__

#include "strategy.h"

#include <vector>
#include <map>


class RuleMatrix {
public:
    std::vector<int> get(const std::vector<Decision>& decisions) {
        return _matrix.at(decisions);
    }
    
    void use_default_matrix(size_t size);
    
    void use_external_matrix(const std::string& path);
private:
    std::map<std::vector<Decision>, std::vector<int>> _matrix;
    
    void _split_string(const std::string& input);
    std::vector<std::string> _parts;
    std::string _line;
    std::vector<Decision> _decision;
    std::vector<int> _score;
};

#endif /* defined(__Prisoners_Dilemma_II__matrix_matrix__) */
