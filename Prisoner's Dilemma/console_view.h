//
//  console_view.h
//  Prisoners Dilemma II
//
//  Created by Sergey Bogolepov on 11/24/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef __Prisoners_Dilemma_II__console_view__
#define __Prisoners_Dilemma_II__console_view__

#include "view.h"


class ConsoleView : public View {
public:
    virtual void show_message(const std::string& message) const;
    virtual void show_results(const std::vector<Prisoner*>& prisoners) const;
};

#endif /* defined(__Prisoners_Dilemma_II__console_view__) */
