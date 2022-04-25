///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-animal-farm - EE 205 - Spr 2022
///
/// @file SinglyLinkedList.cpp
/// @version 1.0
///
/// @author Jaeden Chang <jaedench@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <iostream>

#include "config.h"
#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList() {
    assert( SinglyLinkedList::validate() );
}

// insert newNode to the beginning of list.
void SinglyLinkedList::push_front(Node *newNode) {
    if( newNode == nullptr ) {
        return;
    }
    if( head != nullptr ) {
        newNode->next = head;
        head = newNode;
    } else {
        newNode->next = nullptr;
        head = newNode;
    }
    count++;
    SinglyLinkedList::validate();
}

// remove and return first node.
Node* SinglyLinkedList::pop_front() noexcept {
    if( head == nullptr ) {
        return nullptr;
    }
    Node* oldFirstNode = head;
    head = head->next;
    count--;
    SinglyLinkedList::validate();
    return oldFirstNode;
}

// insert newNode after currentNode.
void SinglyLinkedList::insert_after(Node *currentNode, Node *newNode) {
    // validation before inserting
    if(List::empty()) {
        throw std::logic_error(PROGRAM_NAME ": List is empty, so newNode cannot be inserted after currentNode.");
    }
    if( currentNode == nullptr ) {
        throw std::invalid_argument(PROGRAM_NAME ": Cannot imsert a newNode after nullpter.");
    }
    if( newNode == nullptr ) {
        throw std::invalid_argument(PROGRAM_NAME ": Cannot insert a nullptr into the list.");
    }
    // check if currentNode is even in the list
    if( !isIn(currentNode) ) {
        throw std::logic_error(PROGRAM_NAME ": currentNode is not in list.");
    }
    // check for duplicate nodes
    if( isIn(newNode) ) {
        throw std::logic_error(PROGRAM_NAME ": newNode already exists in the list.");
    }
    // validate newNode before adding to list
    if( !newNode->validate() ) {
        throw std::invalid_argument(PROGRAM_NAME ": newNode is not valid. Cannot be added to list.");
    }

    newNode->next = currentNode->next;
    currentNode->next = newNode;
    count++;

    SinglyLinkedList::validate();
}

// iterate over list and dump at each node
void SinglyLinkedList::dump() const noexcept {
    Node* currentNode = head;
    while( currentNode != nullptr ) {
        currentNode->dump();
        currentNode = currentNode->next;
    }
}

// validate container
bool SinglyLinkedList::validate() const noexcept {
    if( !List::validate() ) {
        return false;
    }

    unsigned int lCount = 0;
    Node* currentNode = head;
    while( currentNode != nullptr ) {
        assert(currentNode->validate());
        lCount++;
        currentNode = currentNode->next;
    }

    assert(size() == lCount );

    return true;
}

