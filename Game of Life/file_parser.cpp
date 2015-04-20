//
//  file_parser.cpp
//  Game of Life
//
//  Created by Sergey Bogolepov on 10/20/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#include "file_parser.h"

FileParser::FileParser() {}

void FileParser::parse(const std::string& filename) {
    std::ifstream file(filename);
    
    if (file.good()) {
        // Refactor this part. It should not rely on order
        std::string line;
        std::getline(file, line);
        _parse_format(line);
        std::getline(file, line);
        if (0 == _parse_name(line)) {
            name = "Placeholder Game";
        }
        std::getline(file, line);
        if (0 == _parse_conditions(line)) {
            needed_to_live.push_back(2);
            needed_to_live.push_back(3);
            needed_to_born.push_back(3);
        }
        
        // It works fine, but looks like it from 80's
        int x, y;
        int x_min = 0;
        int x_max = 0;
        int y_min = 0;
        int y_max = 0;
        std::pair<int, int> pair;
        while (file >> x >> y) {
            if (x > x_max) x_max = x;
            if (x < x_min) x_min = x;
            if (y > y_max) y_max = y;
            if (y < y_min) y_min = y;
            pair.first = x;
            pair.second = y;
            points.push_back(pair);
        }
        
        // Calculating shift
        int delta = 0;
        if (x_min < y_min && x_min < 0) {
            delta = x_min;
        } else if (y_min < 0) {
            delta = y_min;
        }
        
        if (0 != delta) {
            for (auto& pair : points) {
                pair.first -= delta; // because delta < 0
                pair.second -= delta;
            }
        }
        
        x_max -= delta;
        y_max -= delta;
        
        x_max > y_max ? field_size = x_max + 3 : field_size = y_max + 3;
    } else {
        throw std::ifstream::failure("Error opening file.");
    }
}


int FileParser::_parse_conditions(const std::string& conditions) {
    std::vector<std::string> parts;
    boost::split(parts, conditions, boost::is_any_of("\t "));
    
    if ("#R" != parts[0]) {
        return 0;
    } else {
        std::regex reg("^B\\d{0,9}/S\\d{0,9}$");
        if (std::regex_match(parts[1], reg)) {
            std::vector<std::string> born_stay;
            boost::split(born_stay, parts[1], boost::is_any_of("/"));
            for (auto c : born_stay[0]) {
                if (isdigit(c)) {
                    needed_to_born.push_back(c - '0');
                }
            }
            for (auto c : born_stay[1]) {
                if (isdigit(c)) {
                    needed_to_live.push_back(c - '0');
                }
            }
            return 1;
        } else {
            warnings.push_back("Wrong conditions. Using B3/S23");
        }
    }
    return 0;
}

int FileParser::_parse_format(const std::string& format) {
    if (format != "#Life 1.06") { // Magic string, refactor
        warnings.push_back("Wrong file format. It should be #Life 1.06");
    }
    return 0;
}

int FileParser::_parse_name(const std::string& name) {
    std::vector<std::string> parts;
    boost::split(parts, name, boost::is_any_of("\t "));
    if ("#N" != parts[0]) {
        warnings.push_back("Wrong name. Using default.");
        return 0;
    } else {
        parts.erase(parts.begin());
        this->name = boost::algorithm::join(parts, " ");
        return 1;
    }
}