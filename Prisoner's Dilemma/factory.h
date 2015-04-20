//
//  factory.h
//  Prisoners Dilemma II
//
//  Created by Sergey Bogolepov on 11/24/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef Prisoners_Dilemma_II_factory_h
#define Prisoners_Dilemma_II_factory_h

#include "strategy.h"

#include <map>

template <class Key, class Base>
class Factory {
public:
    template <class Derived>
    bool add(const Key& id) {
        _factory[id] = []() { return new Derived(); };
        return true;
    }
    
    Base* create(const Key& id) const {
        return _factory.at(id)();
    }
    
    static Factory* init() {
        static Factory<Key, Base> factory;
        return& factory;
    }
private:
    Factory() {};
    std::map<Key, std::function<Base*()>> _factory;
};

#endif
