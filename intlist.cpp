// intlist.cpp
// Implements class IntList
// Leher Gulati, Jan 15, 2026

#include "intlist.h"
#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    //IMPLEMENT THIS
    head = nullptr;
    tail = nullptr;

    if (!source.head) {
        return;
    }

    head = new Node;
    head->info = source.head->info;
    head->next = nullptr;

    Node* sourceNode = source.head->next;
    Node* curr = head;
    while (sourceNode) {
        curr->next = new Node;
        curr->next->info = sourceNode->info;
        curr->next->next = nullptr;
        curr = curr->next;
        sourceNode = sourceNode->next;
    }

    tail = curr;
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* curr = head;
    Node* next = head;
    while (curr) {
        next = curr->next;
        delete curr;
        curr = next;
    }
    head = nullptr;
    tail = nullptr;
}


// return sum of values in list
int IntList::sum() const {
    int sum = 0;
    Node* curr = head;

    while (curr) {
        sum += curr->info;
        curr = curr->next;
    }
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* curr = head;

    while (curr) {
        if (curr->info == value) return true;
        curr = curr->next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    int max = 0;
    Node* curr = head;

    while (curr) {
        if (curr->info > max) max = curr->info;
        curr = curr->next;
    }

    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    double sum = 0;
    int count = 0;
    Node *curr = head;

    while (curr) {
        sum += curr->info;
        count++;
        curr = curr->next;
    }

    if (count == 0) return 0;

    return sum/count;
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* n = new Node;
    n->info = value;
    n->next = head;
    head = n;

    if (!tail) {
        tail = n;
    }
}

// append value at end of list
void IntList::push_back(int value) {
    Node* n = new Node;
    n->info = value;
    n->next = nullptr;

    if (!head) head = n;
    if (tail) tail->next = n;
    tail = n;
}

// return count of values
int IntList::count() const {
    int count = 0;
    Node* curr = head;
    
    while (curr) {
        count++;
        curr = curr->next;
    }
    
    return count;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (this == &source) return *this;

    //deleting current list
    Node *curr = head;
    Node *next;
    while (curr) {
        next = curr->next;
        delete curr;
        curr = next;
    }
    tail = nullptr;
    head = nullptr;

    if (!source.head) return *this;

    //making new list
    
    head = new Node;
    head->info = source.head->info;
    head->next = nullptr;
    Node *s = source.head->next;
    Node *n = head;

    while (s) {
        n->next = new Node;
        n->next->info = s->info;
        n->next->next = nullptr;
        n = n->next;
        s = s->next;
    }

    tail = n;

    //return
    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    head = nullptr;
    tail = nullptr;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

