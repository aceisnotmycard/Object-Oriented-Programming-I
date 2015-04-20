//
//  strings.h
//  Game of Life
//
//  Created by Sergey Bogolepov on 10/25/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef Game_of_Life_strings_h
#define Game_of_Life_strings_h

#include <string>

// String constants
// Will be either deleted or extended
namespace Strings {
    
    inline auto const &help_arguments() {
        static std::string ret =
"Following arguments for different modes are allowed:\n\
*USUAL MODE.\n\
Add file with universe in Life 1.06 format.\n\n\
*DEMO MODE.\n\
Just hit enter.\n\n\
*OFFLINE MODE.\n\
[input] [output] [iterations]\n\
where:\n\
[input]: same as in USUAL.\n\
[output]: --output=file (-o file)\n\
[iterations]: --iterations=x (-i x)\n";
        return ret;
    }
    
    inline auto const &help_ingame() {
        static std::string ret =
"Following commands are allowed:\n\
dump <file> – save universe in file.\n\
tick <n=1> (t <n=1>) – calculate n iterations and show result.\n\
exit – end game.\n\
play <n=1> same as tick, but showing all steps.\n\
help – show this message.\n\
settings - show current game rules.\n";
        return ret;
    }

}

#endif
