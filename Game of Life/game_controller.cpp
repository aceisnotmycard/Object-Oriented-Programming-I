//
//  game_controller.cpp
//  Game of Life
//
//  Created by Sergey Bogolepov on 10/20/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#include "game_controller.h"

void GameController::run() {
    
    if (iterations > -1) {
        _tick(iterations);
        try {
            _dump(output_filename);
        } catch (std::ofstream::failure e) {
            view->show_message("Error writing to file");
        }
        return;
    }
    
    // Main cycle
    std::string input;
    do {
        // Welcome message for input. Move it to another place
        // Reading message from terminal.
        // It's better to refactor InputHanlder and make it part of framework
        // New amazing MIVC (Model-Input-View-Controller) pattern!
        input_handler.parse_input();
        switch (input_handler.get_current_command()) {
            case InputHandler::Command::HELP:
                view->show_message(Strings::help_ingame());
                break;
            case InputHandler::Command::TICK:
                _tick(input_handler.get_tick_count());
                view->show();
                break;
            case InputHandler::Command::PLAY: {
                auto times = input_handler.get_tick_count();
                for (int i = 0; i < times; i++) {
                    _tick(1);
                    view->show();
                }
                break;
            }
            case InputHandler::Command::DUMP:
                try {
                    _dump(input_handler.get_output_file());
                } catch (std::ofstream::failure e) {
                    view->show_message("Error writing to file");
                }
                break;
            case InputHandler::Command::EXIT:
                view->show_message("Bye! :(");
                return;            
            // Do i need it?
            case InputHandler::Command::SETTINGS:
                view->show_message("Come back later");
                break;
            default:
                break;
        }
    } while (true); // while(1)? O RLY?
}

void GameController::_tick(int steps) {
    for (int i = 0; i < steps; i++) {
        model->update();
    }
}

void GameController::_dump(std::string name) {
    FileCreator creator(name);
    creator.set_name(game_name);
    creator.set_rules(model->get_needed_to_born(), model->get_needed_to_live());
    creator.set_points(get_field(), get_field_size());
    creator.save_changes();
}

void GameController::set_points(std::vector<std::pair<int, int>> points) {
    model->set_field(points);
}

void GameController::set_field_size(int size) {
    model->set_field_size(size);
}

void GameController::set_needed_to_born(std::vector<int> arg) {
    model->set_needed_to_born(arg);
}

void GameController::set_needed_to_live(std::vector<int> arg) {
    model->set_needed_to_live(arg);
}

void GameController::set_iterations(int count) {
    if (count >= 0) {
        iterations = count;
    }
}

void GameController::set_name(std::string name) {
    game_name = name;
}

void GameController::set_output_file(std::string name) {
    output_filename = name;
}

int GameController::get_field_size() {
    return model->get_field_size();
}

bool** GameController::get_field() {
    return model->get_field();
}

