//
//  console_handler.h
//  Prisoners Dilemma II
//
//  Created by Sergey Bogolepov on 11/24/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef __Prisoners_Dilemma_II__console_handler__
#define __Prisoners_Dilemma_II__console_handler__

#include "input_handler.h"

#include <iostream>
#include <vector>
#include <boost/algorithm/string.hpp>

class ConsoleHandler : public InputHandler {
public:
    virtual Command get_command();
    virtual int get_tick();
private:
    int _tick;
    std::vector<std::string> _parts;
    void _split_string(const std::string& input);
};

#endif /* defined(__Prisoners_Dilemma_II__console_handler__) */
