//
//  graph.h
//  Graph
//
//  Created by Sergey Bogolepov on 12/16/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef __Graph__graph__
#define __Graph__graph__

#include "vertex.h"
#include "edge.h"

#include <vector>
#include <map>
#include <algorithm>
#include <limits.h>

// VertexContainer – one of STL containers (or similiar) to store set of verticies.
// EdgeContainer – structure to store set of edges
// Container - UNIFIED. Equal to std::vector
// Tag - unique identifier
// Distance - measure of edge's length
// Content – making our nodes matter
// defaultContent -
template <template<typename T, typename=std::allocator<T>> class Container=std::vector, class Tag=std::string, class Distance = int, Distance minLength = 0, Distance maxLength = INT_MAX, class Content = int, Content defaultContent = 0>
class Graph {
    typedef Vertex<Tag, Content> V;
    typedef Edge<V, Distance> E;
    
public:
    Graph() {};
    
    
    // Starting DFS from vertex with tag and doing f with every accessable vertex
    template<typename Function>
    void Dfs(const Tag& tag, Function f) {
        if (!contains(tag)) {
            return;
        }
        
        dfs_(tag, f);
    }
    
    auto dijkstra(const Tag& tag) {
        // We don't know max distance value. Instead, we use bool trigger
        std::map<Tag, Distance> distances;
        std::map<Tag, bool> visited;
        
        Distance minWeight = maxLength;
        Tag minTag;
        
        for (auto v : vertexContainer_) {
            distances[v.getTag()] = tag == v.getTag() ? 0 : maxLength;
            visited[v.getTag()] = false;
        }
        
        for (auto v : getVerticies()) {
            minWeight = maxLength;
            for (auto u : getVerticies()) {
                if (!visited[u.getTag()] && (distances[u.getTag()] < minWeight)) {
                    minWeight = distances[u.getTag()];
                    minTag = u.getTag();
                }
            }
            for (auto u : getNeighbours(minTag)) {
                if (!visited[u.getTag()] && (distances[minTag] + findEdge(minTag, u.getTag()).getLength() < distances[u.getTag()])) {
                    distances[u.getTag()] = distances[minTag] + findEdge(minTag, u.getTag()).getLength();
                }
            }
            visited[minTag] = true;
        }
        
        return distances;
    }
    
    void addVertex(const Tag& tag, const Content& content=defaultContent) {
        vertexContainer_.push_back(V(tag, content));
    }
    
    void addVertex(const V& vertex) {
        addVertex(vertex.getTag(), vertex.getContent());
    }
    
    void addEdge(const V& a, const V& b, Distance length) {
        if (!contains(a.getTag())) {
            addVertex(a);
        }
        if (!contains(b.getTag())) {
            addVertex(b);
        }
        if (!contains(a.getTag(), b.getTag())) {
            edgeContainer_.push_back(E(a, b, length));
        }
    }
    
    void addEdge(const Tag& a, const Tag& b, Distance length) {
        addEdge(V(a, defaultContent), V(b, defaultContent), length);
    }
    
    auto removeEdge(const Tag& a, const Tag& b) {
        auto edge = findEdge_(a, b);
        if (edge != edgeContainer_.end()) {
            edgeContainer_.erase(edge);
            return true;
        }
        return false;
    }
    
    bool removeVertex(const Tag& tag) {
        auto a = findVertex_();
        if (a != vertexContainer_.end()) {
            vertexContainer_.erase(a);
            return true;
        }
        return false;
    }
    
    // Searching for vertex with tag
    bool contains(const Tag& tag) {
        return findVertex_(tag) != vertexContainer_.end();
    }
    
    // Searching for edge that connects a and b
    bool contains(const Tag& a, const Tag& b) {
        return findEdge_(a, b) != edgeContainer_.end();
    }
    
    auto findEdge(const Tag& a, const Tag& b) {
        return *findEdge_(a, b);
    }
    
    auto findVertex(const Tag& tag) {
        return *findVertex_(tag);
    }
    
    auto getNeighbours(const Tag& tag) const {
        Container<V> neighbours;
        for (auto edge : edgeContainer_) {
            if (edge.getStartVertex().getTag() == tag) {
                neighbours.push_back(edge.getEndVertex());
            }
        }
        return neighbours;
    }
    
    auto getVerticies() const {
        return vertexContainer_;
    }
    
private:
    Container<V, std::allocator<V>> vertexContainer_;
    Container<E, std::allocator<E>> edgeContainer_;
    
    
    auto findEdge_(const Tag& a, const Tag& b) {
        auto tmpA = V(a, defaultContent);
        auto tmpB = V(b, defaultContent);
        return std::find(begin(edgeContainer_), end(edgeContainer_), E(tmpA, tmpB, minLength));
    }
    
    auto findVertex_(const Tag& tag) {
        return std::find(begin(vertexContainer_), end(vertexContainer_), V(tag, defaultContent));
    }
    
    // For DFS purposes
    std::map<Tag, bool> visited;
    
    template<typename Function>
    void dfs_(const Tag& tag, Function f) {
        visited[tag] = true;
        f(findVertex_(tag));
        for (auto neighbour : getNeighbours(tag)) {
            if (!visited[neighbour.getTag()]) {
                dfs_(neighbour.getTag(), f);
            }
        }
    }
};
#endif /* defined(__Graph__graph__) */
