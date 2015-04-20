//
//  edge.h
//  Graph
//
//  Created by Sergey Bogolepov on 12/16/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef Graph_edge_h
#define Graph_edge_h

#include <memory>

template <class Vertex, class Distance>
class Edge {
public:
    Edge() : length_(0), startVertex_(nullptr), endVertex_(nullptr) {}
    
    Edge(const Vertex& start, const Vertex& end, Distance distance) {
        setVerticies(start, end);
        setLength(distance);
    }
    
    Edge(const Edge& edge) {
        setVerticies(edge.getStartVertex(), edge.getEndVertex());
        setLength(edge.getLength());
    }
    
    static Edge make_edge(const Vertex& start, const Vertex& end, Distance distance) {
        return Edge(start, end, distance);
    }

    void setLength(const Distance& length) {
        length_ = length;
    }
    
    Distance getLength() const {
        return length_;
    }
    
    Distance getLength() {
        return length_;
    }
    
    void setVerticies(const Vertex& start, const Vertex& end) {
        startVertex_ = std::make_unique<Vertex>(start);
        endVertex_ = std::make_unique<Vertex>(end);
    }
    
    void setStartVertex(const Vertex& start) {
        startVertex_ = std::make_unique<Vertex>(start);
    }
    
    void setEndVertex(const Vertex& end) {
        endVertex_ = std::make_unique<Vertex>(end);
    }
    
    Vertex& getStartVertex() const {
        return *startVertex_;
    }
    
    Vertex& getStartVertex() {
        return *startVertex_;
    }
    
    Vertex& getEndVertex() const {
        return *endVertex_;
    }
    
    Vertex& getEndVertex() {
        return *endVertex_;
    }
    
    friend bool operator<(const Edge& a, const Edge& b) {
        return a.getLength() < b.getLength();
    }
    
    friend bool operator==(const Edge& a, const Edge& b) {
        return ((a.getStartVertex() == b.getStartVertex()) && (a.getEndVertex() == b.getEndVertex()));
    }
    
    friend bool operator!=(const Edge& a, const Edge& b) {
        return a != b;
    }
private:
    std::unique_ptr<Vertex> startVertex_;
    std::unique_ptr<Vertex> endVertex_;
    Distance length_;
};

#endif
