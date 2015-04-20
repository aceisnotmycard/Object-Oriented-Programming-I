//
//  main.cpp
//  Prisoners Dilemma II
//
//  Created by Sergey Bogolepov on 11/24/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#include "game.h"
#include "console_parser.h"
#include "console_view.h"
#include "console_handler.h"
#include "factory.h"
#include "strategy_goodguy.h"

int main(int argc, const char** argv) {
    std::shared_ptr<ConsoleParser> parser(new ConsoleParser(argc, argv));
    parser->parse_arguments();
    
    std::shared_ptr<ConsoleView> console_view(new ConsoleView());
    std::shared_ptr<InputHandler> hanlder(new ConsoleHandler());
    Game game;
    game.run(parser, console_view, hanlder);
}