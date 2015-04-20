//
//  file_creator.cpp
//  Game of Life
//
//  Created by Sergey Bogolepov on 10/27/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#include "file_creator.h"

FileCreator::FileCreator(const std::string& filename) {
    file = std::ofstream(filename);
    if (file.good()) {
        file << "#Life 1.06\n";
    } else {
        file.close();
        throw std::ofstream::failure("Error opening file.");
    }
}

void FileCreator::set_rules(const std::vector<int>& born, const std::vector<int>& live) {
    file << "#R B";
    for (auto r: born) {
        file << r;
    }
    file << "/S";
    for (auto r: live) {
        file << r;
    }
    file << "\n";
}

void FileCreator::set_name(std::string universe_name) {
    file << "#N " << universe_name << "\n";
}

void FileCreator::set_points(bool **field, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (field[i][j]) {
                file << i << " " << j << "\n";
            }
        }
    }
}

void FileCreator::save_changes() {
    file.close();
}