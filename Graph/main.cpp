//
//  main.cpp
//  Graph
//
//  Created by Sergey Bogolepov on 12/16/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#include "graph.h"

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <limits.h>

int main(int argc, const char * argv[]) {
    Graph<std::vector, std::string, int, 1, INT_MAX, int, 0> graph;
    
    graph.addVertex("a", 14);
    graph.addEdge("a", "b", 13);
    graph.addEdge("c", "f", 1);
    graph.addEdge("a", "c", 14);
    graph.addEdge("c", "d", 15);
    graph.addEdge("d", "e", 1);
    graph.addEdge("b", "f", 11);
    
    graph.Dfs("a", [](auto v) { std::cout << (*v).getTag() << std::endl; });
    
    auto x = graph.dijkstra("a");
    
    for(auto i : x) {
        std::cout << i.first << ": " << i.second << std::endl;
    }
    
    return 0;
}
