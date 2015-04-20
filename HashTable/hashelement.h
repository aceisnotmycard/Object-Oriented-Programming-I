//
//  hashelement.h
//  HashTable
//
//  Created by Sergey Bogolepov on 20/09/14.
//  Copyright (c) 2014 Religion. All rights reserved.
//

#ifndef HashTable_hashelement_h
#define HashTable_hashelement_h

typedef std::string Key;

//Abstract Data Type for HashTable
//It's very simple but necessary for beautiful and safe implementation
template <typename Value>
class HashElement {
    Key key;
    Value value;
    HashElement *next;
    
public:
    HashElement();
    HashElement(Key key, Value value);
    HashElement(Key key);
    HashElement<Value>& operator=(const HashElement& element);
    
    const Key& getKey() const;
    Key& getKey();
    
    const Value& getValue() const;
    Value& getValue();
    void setValue(Value value);
    
    HashElement<Value>* getNext() const;
    void setNext(HashElement *next);
    
    bool operator==(const HashElement& element);
    bool operator!=(const HashElement& element);
};

template <typename Value>
HashElement<Value>::HashElement() {
    this->key = "";
    this->next = nullptr;
}

template <typename Value>
HashElement<Value>::HashElement(Key key, Value value) {
    this->key = key;
    this->value = value;
    this->next = nullptr;
}

template <typename Value>
HashElement<Value>::HashElement(Key key) {
    this->key = key;
    this->next = nullptr;
}

template <typename Value>
HashElement<Value>& HashElement<Value>::operator=(const HashElement& element) {
    this->key = element.getKey();
    this->value = element.getValue();
    this->next = element.getNext();
    
    return *this;
}

template <typename Value>
const Key& HashElement<Value>::getKey() const {
    return this->key;
}

template <typename Value>
Key& HashElement<Value>::getKey() {
    return this->key;
}

template <typename Value>
const Value& HashElement<Value>::getValue() const {
    return this->value;
}

template <typename Value>
Value& HashElement<Value>::getValue() {
    return this->value;
}

template <typename Value>
void HashElement<Value>::setValue(Value value) {
    this->value = value;
}

template <typename Value>
HashElement<Value>* HashElement<Value>::getNext() const {
    return this->next;
}

template <typename Value>
void HashElement<Value>::setNext(HashElement *next) {
    this->next = next;
}

template<typename Value>
bool HashElement<Value>::operator==(const HashElement& element) {
    return (this->getKey() == element.getKey() && this->getValue() == element.getValue());

}

template<typename Value>
bool HashElement<Value>::operator!=(const HashElement& element) {
    return (this->getKey() != element.getKey() || this->getValue() != element.getValue());
}

#endif
