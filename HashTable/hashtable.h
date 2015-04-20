//
//  hashtable.h
//  HashTable
//
//  Created by Sergey Bogolepov on 20/09/14.
//  Copyright (c) 2014 Religion. All rights reserved.
//

#ifndef HashTable_hashtable_h
#define HashTable_hashtable_h


#include <vector>
#include <stdexcept>
#include <algorithm>

#include "hashelement.h"


// Simple HashTable implementation based on separate chaining
// Key is a string
// Value is a template
template <typename Value>
class HashTable {
    
public:
    HashTable();
    HashTable(const HashTable& another_table);
    HashTable& operator=(const HashTable& another_table);
    
    ~HashTable();
    
    // Exchanges values of two tables
    void swap(HashTable& another_table);
    
    // Cleans container
    void clear();
    // Removes element with given key.
    // Returns true if there is element with given key.
    // False if not.
    bool erase(const Key& key);
    // Inserts element in container.
    // Returning true if success.
    // False if there is element with given key.
    bool insert(const Key& key, const Value& value);
    // Checks array for element with given key
    bool contains(const Key& key);
    // Returns number of elements in container
    size_t size() const;
    
    // Returns true if there is no elements.
    bool empty() const;
    
    // Returns value by key. Not safe
    // Creates new element if key not found.
    Value& operator[](const Key& key);
    
    // Returns value by key. Throwing exception if failure.
    Value& at(const Key& key);
    const Value& at(const Key& key) const;
    
    template <typename T>
    friend bool operator==(const HashTable<T>& first, const HashTable<T>& second);
    
    template <typename T>
    friend bool operator!=(const HashTable<T>& first, const HashTable<T>& second);
    
    // Only for debug purposes
    void show_table();
    
private:
    size_t elements_count;
    
    // Setters for elements_count
    void increase_count();
    void decrease_count();
    
    static const size_t DEFAULT_TABLE_SIZE = 8;
    size_t table_size;
    size_t get_table_size() const;
    
    void rehash();
    
    std::vector<HashElement<Value>> table;
    unsigned int calculate_hash(const Key& key) const;
    size_t calculate_position(unsigned int hash) const;
};


// Public methods

template <typename Value>
HashTable<Value>::HashTable() {
    table_size = DEFAULT_TABLE_SIZE;
    elements_count = 0;
    table.resize(table_size);
}


template <typename Value>
HashTable<Value>::HashTable(const HashTable& another_table) {
    elements_count = 0;
    table_size = another_table.get_table_size();
    table.resize(table_size);

    for (size_t i = 0; i < table_size; i++) {
        auto this_ptr = &(table.at(i));
        auto another_ptr = &(another_table.table.at(i));
        while (nullptr != another_ptr->getNext()) {
            another_ptr = another_ptr->getNext();
            this_ptr->setNext(new HashElement<Value>(another_ptr->getKey(),
                                                   another_ptr->getValue()));
            this_ptr = this_ptr->getNext();
            increase_count();
        }
    }
}


template <typename Value>
HashTable<Value>& HashTable<Value>::operator=(const HashTable& another_table) {
    
    if(another_table == *this) {
        return *this;
    }
    clear();
    
    table_size = another_table.get_table_size();
    for (size_t i = 0; i < table_size; i++) {
        auto this_ref = &(table.at(i));
        auto another_ref = &(another_table.table.at(i));
        while (nullptr != another_ref->getNext()) {
            another_ref = another_ref->getNext();
            this_ref->setNext(new HashElement<Value>(another_ref->getKey(),
                                                     another_ref->getValue()));
            this_ref = this_ref->getNext();
            increase_count();
        }
    }
    return *this;
}


template <typename Value>
HashTable<Value>::~HashTable() {
    clear();
}


template <typename Value>
void HashTable<Value>::swap(HashTable<Value>& another_table) {
    
    bool another_is_bigger = false;
    if (another_table.get_table_size() > get_table_size()) {
        table.resize(another_table.get_table_size());
        another_is_bigger = true;
    } else {
        another_table.table.resize(get_table_size());
    }
    // swap pointers in tables
    for (int i = 0; i < table_size; i++) {
        auto ptr = table.at(i).getNext();
        table.at(i).setNext(another_table.table.at(i).getNext());
        another_table.table.at(i).setNext(ptr);
    }
    std::swap(table_size, another_table.table_size);
    std::swap(elements_count, another_table.elements_count);
    if (another_is_bigger) {
        another_table.table.resize(another_table.table_size);
    } else {
        table.resize(table_size);
    }
    // Choose larger table
    // Resize table
    // Swap pointers
    // Swap size and table size
}


template <typename Value>
void HashTable<Value>::clear() {
    for (size_t i = 0; i < table_size; i++) {
        while (table.at(i).getNext() != nullptr) {
            auto tmp = table.at(i).getNext();
            table.at(i).setNext(tmp->getNext());
            decrease_count();
            delete tmp;
        }
    }
    table_size = DEFAULT_TABLE_SIZE;
}


template <typename Value>
bool HashTable<Value>::erase(const Key& key) {
    
    auto position = calculate_position(calculate_hash(key));
    auto iterator = &table.at(position);
    
    while (iterator->getNext() != nullptr) {
        //Next element is what we're looking for
        if (iterator->getNext()->getKey().compare(key) == 0) {
            auto tmp = iterator->getNext();
            iterator->setNext(tmp->getNext());
            delete tmp;
            decrease_count();
            return true;
        } else {
            iterator = iterator->getNext();
        }
    }
    
    return false;
}


template <typename Value>
bool HashTable<Value>::insert(const Key& key, const Value& value) {
    
    if(contains(key)) {
        return false;
    }
    increase_count();
    
    auto position = calculate_position(calculate_hash(key));
    auto iterator = &table.at(position);
    
    while (nullptr != iterator->getNext()) {
        iterator = iterator->getNext();
    }
    iterator->setNext(new HashElement<Value>(key, value));
    
    return true;
}


template <typename Value>
bool HashTable<Value>::contains(const Key& key) {
    
    auto position = calculate_position(calculate_hash(key));
    auto iterator = table.at(position).getNext();
    
    while (iterator != nullptr) {
        //Next element is what we're looking for
        if (iterator->getKey().compare(key) == 0) {
            return true;
        } else {
            iterator = iterator->getNext();
        }
    }
    
    return false;
}


template <typename Value>
size_t HashTable<Value>::size() const {
    return elements_count;
}


template <typename Value>
bool HashTable<Value>::empty() const {
    return size() == 0;
}


template <typename Value>
Value& HashTable<Value>::operator[](const Key& key) {
    
    auto position = calculate_position(calculate_hash(key));
    auto element = &table.at(position);
    
    while (0 != element->getKey().compare(key)) {
        //There is no element with given key. So be it.
        if(element->getNext() == nullptr) {
            element->setNext(new HashElement<Value>(key));
            increase_count();
        }
        element = element->getNext();
    }
    
    return element->getValue();
}


template <typename Value>
const Value& HashTable<Value>::at(const Key& key) const {
    
    auto position = calculate_position(calculate_hash(key));
    auto element = &table.at(position);
    
    while(element != nullptr && element->getKey().compare(key) != 0) {
        element = element->getNext();
    }
    
    if (element == nullptr) {
        throw std::invalid_argument("Element with given key is not found");
    }
    
    return element->getValue();
}


//Unite with const version
template <typename Value>
Value& HashTable<Value>::at(const Key& key) {
    
    auto position = calculate_position(calculate_hash(key));
    auto element = &table.at(position);
    
    while ((nullptr != element) && (0 != element->getKey().compare(key))) {
        element = element->getNext();
    }
    
    if (nullptr == element) {
        throw std::invalid_argument("Element with given key is not found");
    }
    
    return element->getValue();
}


template <typename Value>
bool operator==(const HashTable<Value>& first, const HashTable<Value>& second) {
    if(first.size() != second.size()) {
        return false;
    }
    
    HashElement<Value>* first_iterator;
    HashElement<Value>* second_iterator;
    
    //If size() are similiar then table_size are similiar too.
    for(int i = 0; i < first.table_size; i++) {
        first_iterator = first.table.at(i).getNext();
        second_iterator = second.table.at(i).getNext();
        while(nullptr != first_iterator) {
            if (*first_iterator != *second_iterator) {
                return false;
            }
            first_iterator = first_iterator->getNext();
            second_iterator = second_iterator->getNext();
        }
    }
    return true;
}


template <typename Value>
bool operator!=(const HashTable<Value>& first, const HashTable<Value>& second) {
    return !(first == second);
}


template<typename Value>
void HashTable<Value>::show_table() {
    std::cout << "TABLE. LOOK AND SUFFER." << std::endl;
    
    HashElement<Value>* iterator;
    for(int i = 0; i < get_table_size(); i++) {
        std::cout << i << "ROW" << std::endl;
        iterator = &table.at(i);
        if (iterator->getNext() != nullptr) {
            while(iterator != nullptr) {
                std::cout << "{" << std::endl;
                std::cout << "\tKey: " << iterator->getKey() << std::endl;
                std::cout << "\tValue: " << iterator->getValue() << std::endl;
                std::cout << "}" << std::endl;
                iterator = iterator->getNext();
            }
        }
    }
    std::cout << "STOP SUFFERING." << std::endl;
}


//Private methods





// Rot13 algorithm
// Copypasted from http://habrahabr.ru
template <typename Value>
unsigned int HashTable<Value>::calculate_hash(const Key& key) const {
    unsigned int hash = 0;
    for (int i = 0; i < key.length(); i++) {
        hash += (unsigned char)(key[i]);
        hash -= (hash << 13) | (hash >> 19);
    }
    
    return hash;
}


template <typename Value>
size_t HashTable<Value>::get_table_size() const {
    return table_size;
}


template <typename Value>
size_t HashTable<Value>::calculate_position(unsigned int hash) const {
    return hash % get_table_size();
}


template <typename Value>
void HashTable<Value>::increase_count() {
    elements_count++;
    if(elements_count > get_table_size()) {
        //rehash();
    }
    
}


template <typename Value>
void HashTable<Value>::decrease_count() {
    elements_count--;
}


template <typename Value>
void HashTable<Value>::rehash() {
    table_size *= 2;
    table.resize(table_size);
    
    // Not perfect. Probably there is an element that will be rehashed to
    // second quarter. So it will be rehashed twice.
    for (size_t i = 0; i < table_size / 2; i++) {
        HashElement<Value>* iterator = &table.at(i);
        while (nullptr != iterator->getNext()) {
            // Do nothing if we're staying at same position
            if (calculate_position(calculate_hash(iterator->getNext()->getKey())) == i) {
                iterator = iterator->getNext();
            } else {
                HashElement<Value> tmp(iterator->getNext()->getKey(), iterator->getNext()->getValue());
                HashElement<Value>* ptr = iterator->getNext();
                iterator->setNext(ptr->getNext());
                delete ptr;
                decrease_count();
                insert(tmp.getKey(), tmp.getValue());
            }
        }
    }
}

#endif
