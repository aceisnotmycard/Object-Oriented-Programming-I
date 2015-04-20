//
//  console_parser.h
//  Prisoners Dilemma II
//
//  Created by Sergey Bogolepov on 11/24/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef __Prisoners_Dilemma_II__console_parser__
#define __Prisoners_Dilemma_II__console_parser__

#include "options_parser.h"

#include <fstream>
#include <map>


class ConsoleParser : public OptionsParser {
public:
    ConsoleParser(int argc, const char** argv);
    virtual ~ConsoleParser();
    
    virtual int get_steps() const;
    virtual std::string get_configs_path() const;
    virtual std::string get_matrix_path() const;
    virtual std::vector<std::string> get_strategies() const;
    virtual GameMode get_mode() const;
    
    void parse_arguments();
private:
    GameMode _mode;
    std::map<std::string, GameMode> _modes;
    std::vector<std::string> _strategies;
    std::string _path_to_matrix;
    std::string _path_to_configs;
    int _steps;
    
    int _argc;
    const char** _argv;
    
    inline bool _file_exists (const std::string& name) {
        std::ifstream f(name.c_str());
        if (f.good()) {
            f.close();
            return true;
        } else {
            f.close();
            return false;
        }   
    }
};

#endif /* defined(__Prisoners_Dilemma_II__console_parser__) */
