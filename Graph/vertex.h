//
//  vertex.h
//  Graph
//
//  Created by Sergey Bogolepov on 12/16/14.
//  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
//

#ifndef Graph_vertex_h
#define Graph_vertex_h

#include <memory>

template <class Tag, class Content>
class Vertex {
public:
    
    Vertex() : tag_(nullptr), content_(nullptr) {}
    
    Vertex(const Content& content) : tag_(nullptr) {
        setContent(content);
    }
    
    Vertex(const Tag& tag, const Content& content) {
        setTag(tag);
        setContent(content);
    }
    
    Vertex(const Vertex& v) {
        setTag(v.getTag());
        setContent(v.getContent());
    }
    
    static Vertex make_vertex(const Tag& tag, const Content& content) {
        return Vertex(tag, content);
    }
    
    void setTag(const Tag& tag) {
        tag_ = std::make_unique<Tag>(tag);
    }
    
    Tag getTag() const {
        return *tag_;
    }
    
    Tag* removeTag() {
        if (nullptr != tag_) {
            return tag_.release();
        }
        return nullptr;
    }
    
    void setContent(const Content& content) {
        content_ = std::make_unique<Content>(content);
    }
    
    Content& getContent() const {
        return *content_;
    }
    
    Content& getContent() {
        return *content_;
    }
    
    Content* removeContent() {
        if (nullptr != content_) {
            return content_.release();
        }
        return nullptr;
    }
    
    friend bool operator==(const Vertex& a, const Vertex& b) {
        return a.getTag() == b.getTag();
    }
    
    friend bool operator!=(const Vertex& a, const Vertex& b) {
        return !(a == b);
    }
private:
    std::unique_ptr<Tag> tag_;
    std::unique_ptr<Content> content_;
};

#endif
