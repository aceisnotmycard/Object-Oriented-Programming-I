//
//  view.h
//  Prisoners Dilemma II
//
//  Created by Sergey Bogolepov on 11/24/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef Prisoners_Dilemma_II_view_h
#define Prisoners_Dilemma_II_view_h

#include "prisoner.h"

#include <string>
#include <vector>

class View {
public:
    virtual void show_message(const std::string& message) const = 0;
    virtual void show_results(const std::vector<Prisoner*>& prisoners) const = 0;
};

#endif
