//
//  file_parser.h
//  Game of Life
//
//  Parsing file with game setup
//
//  Created by Sergey Bogolepov on 10/20/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef __Game_of_Life__file_parser__
#define __Game_of_Life__file_parser__

#include <fstream>
#include <string>
#include <exception>
#include <vector>
#include <iostream>
#include <regex>

#include <boost/algorithm/string.hpp>

class FileParser {
public:
    FileParser();
    void parse(const std::string& filename);
    
    // Getting parsed information
    auto get_warnings() const {
        return warnings;
    };
    auto get_points() const {
        return points;
    };
    auto get_name() const {
        return name;
    };
    auto get_needed_to_born() const {
        return needed_to_born;
    };
    auto get_needed_to_live() const {
        return needed_to_live;
    };
    auto get_field_size() const {
        return field_size;
    };
    
private:
    
    std::vector<std::string> warnings;
    std::vector<std::pair<int, int>> points;
    std::vector<int> needed_to_born;
    std::vector<int> needed_to_live;
    std::string name;
    int field_size;
    
    int _parse_format(const std::string& format);
    int _parse_name(const std::string& name);
    int _parse_conditions(const std::string& conditions);
};


#endif /* defined(__Game_of_Life__file_parser__) */
