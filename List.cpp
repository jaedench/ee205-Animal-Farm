///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-animal-farm - EE 205 - Spr 2022
///
/// @file List.cpp
/// @version 1.0
///
/// @author Jaeden Chang <jaedench@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cassert>

#include "List.h"
#include "config.h"

Node *List::get_next(const Node *currentNode) {
    return currentNode->next;
}

// true of list is empty
bool List::empty() const noexcept {
    if( head == nullptr ) {
        return true;
    }
    if(count < 0 ) {
        std::cout << PROGRAM_NAME << ": Count cannot be less than 0." << std::endl;
    }
    return false;
}

// number of node objects in the list
unsigned int List::size() const noexcept {
    return count;
}

bool List::isIn(Node *aNode) const {
    Node* currentNode = head;
    while( currentNode != nullptr ){
        if( aNode == currentNode ) {
            return true;
        }
        currentNode = currentNode->next;
    }
    return false;
}

bool List::isSorted() const noexcept {
    return false; // list is not required to be sorted yet.
}

Node *List::get_first() const noexcept {
    if( !empty() ) {
        return head;
    }
    return nullptr;
}

void List::deleteAllNodes() noexcept {
    assert( validate() );

    while( head != nullptr ) {
        pop_front();
    }

    #ifdef DEBUG
        std::cout << PROGRAM_NAME << ": All Nodes have been deleted" << std::endl;
    #endif

    assert( validate() );

    std::cout << "SinglyLinkedList: head=[" << count << "]" << std::endl;
}

bool List::validate() const noexcept {
    if( head == nullptr ) {
        assert(size() == 0);
    } else {
        assert(size() != 0);
    }
    return true;
}
