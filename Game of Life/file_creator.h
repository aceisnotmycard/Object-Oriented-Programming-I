//
//  file_creator.h
//  Game of Life
//
//  Created by Sergey Bogolepov on 10/27/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef __Game_of_Life__file_creator__
#define __Game_of_Life__file_creator__

#include <fstream>
#include <vector>
#include <cstring>

class FileCreator {
public:
    FileCreator(const std::string& filename);
    
    // In current version of program
    // you should use these methods in strict order
    // set_name -> set_rules -> set_poinst
    void set_name(std::string universe_name);
    void set_rules(const std::vector<int>& born, const std::vector<int>& live);
    void set_points(bool** field, int size);
    
    // Close opened file. Maybe it will be moved to destructor
    void save_changes();
    
private:
    std::ofstream file;
};

#endif /* defined(__Game_of_Life__file_creator__) */
