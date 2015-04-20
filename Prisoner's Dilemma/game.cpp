//
//  game.cpp
//  Prisoners Dilemma II
//
//  Created by Sergey Bogolepov on 11/24/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#include "game.h"

void Game::run(std::shared_ptr<OptionsParser> parser, std::shared_ptr<View> view, std::shared_ptr<InputHandler> handler) {
    _mode = parser->get_mode();
    _steps = parser->get_steps();
    _view = view;
    _handler = handler;
    
    // Only for testing. Parameter should be elastic
    if ("" == parser->get_matrix_path()) {
        _matrix.use_default_matrix(3);
    } else {
        try {
            _matrix.use_external_matrix(parser->get_matrix_path());
        } catch (std::invalid_argument e) {
            view->show_message("Invalid matrix format!");
            return;
        }
    }
    // Loading players
    for (auto strategy : parser->get_strategies()) {
        try {
            auto prisoner = new Prisoner(strategy, 0, Factory<std::string, Strategy>::init()->create(strategy));
            _prisoners.emplace_back(prisoner);
        } catch (std::out_of_range e) {
            view->show_message(strategy + " not found!");
            return;
        }
        
    }
    
    for (int i = 0; i < _prisoners.size(); i++) {
        for (int j = i+1; j < _prisoners.size(); j++) {
            for (int k = j+1; k < _prisoners.size(); k++) {
                _participants.push_back(_prisoners.at(i));
                _participants.push_back(_prisoners.at(j));
                _participants.push_back(_prisoners.at(k));
                _play(_steps);
                _participants.clear();
            }
        }
    }
    _view->show_message("FINAL RESULTS");
    _view->show_results(_prisoners);
}

void Game::_play(int times) {
    // tournament or fast mode
    for (int i = 0; i < _participants.size(); i++) {
        for (int j = 0; j < _participants.size(); j++) {
            if (i != j) _participants[i]->notify_start(_participants[j]->get_name());
        }
    }
    
    if (times > 0) {
        for (int i = 0; i < times; i++) {
            _play_round();
        }
        _view->show_results(_participants);
    } else { //detailed
        while(1) {
            auto command = _handler->get_command();
            switch (command) {
                case InputHandler::TICK:
                    for (int i = 0; i < _handler->get_tick(); i++) {
                        _play_round();
                        _view->show_results(_participants);
                    }
                    break;
                case InputHandler::QUIT:
                    return;
                default:
                    _view->show_message("Wrond command!");
                    break;
            }
        }
    }
    for (auto& prisoner: _participants) {
        prisoner->notify_end();
    }
}

void Game::_play_round() {
    std::vector<Decision> decisions;
    for (auto& prisoner : _participants) {
        auto decision = prisoner->make_decision();
        decisions.push_back(decision);
    }
    
    for (int i = 0; i < _participants.size(); i++) {
        _participants.at(i)->add_points(_matrix.get(decisions).at(i));
        for (int j = 0; j < _participants.size(); j++) {
            if (j != i) {
                _participants.at(j)->remember_decision(_participants.at(i)->get_name(),  decisions.at(i));
            }
        }
    }
}
