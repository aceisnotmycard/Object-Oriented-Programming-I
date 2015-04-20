//
//  main.cpp
//  HashTable
//
//  Created by Sergey Bogolepov on 16/09/14.
//  Copyright (c) 2014 Religion. All rights reserved.
//

#include <gtest/gtest.h>
#include <iostream>
#include "hashtable.h"




int main(int argc, const char * argv[])
{
    HashTable<std::string> table1, table2;
    
    table1.insert("One", "At one");
    table1.insert("Two", "At one");
    
    table1["Fivfdsfsdfsde"] = "Hello";
    
    table2 = table1;
    table1.insert("Three", "At two");
    table2.insert("Three", "t two");
    table2.at("Three") = "Lalala";
    table2.show_table();
    try {
        std::cout << table2.at("Four") << std::endl;
    } catch (std::exception e) {
        std::cout << "Cannot assign!" << std::endl;
    }
        
    if (table1 == table2) {
        std::cout << "Equal" << std::endl;
    } else {
        std::cout << "Not equal" << std::endl;
    }
}

