// intlist.cpp
// Implements class IntList
// Lukas Gucci, 4/16/25

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    head = nullptr;
    tail = nullptr;

    Node* copiedList = source.head;

    while(copiedList != nullptr){
        Node* newNode = new Node;
        newNode->info = copiedList->info;
        newNode->next = nullptr;

        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        copiedList = copiedList->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    Node * curr = head;
    while(curr != nullptr){
        Node* tmp = curr;
        curr = curr->next;
        delete tmp;
    }

}


// return sum of values in list
int IntList::sum() const {
    int sum = 0;
    Node* curr = head;
    while (curr != nullptr){
        sum += curr->info;
        curr = curr->next;
    }
    return sum;

}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* curr = head;
    while (curr != nullptr){
        if(curr->info == value){
            return true;
        }
        curr = curr->next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (!head){
        return 0;
    }
    int max = head->info;
    Node* curr = head->next;
    while (curr != nullptr){
        if(curr->info > max){
            max = curr->info;
        }
        curr = curr->next;
    }
    return max;  
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (!head){
        return 0;
    }
    double average = 0;
    int length = 0;
    Node* curr = head;
    while (curr != nullptr){
        average += curr->info;
        length ++;
        curr = curr->next;
    }
    return average/length;
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
   Node* newNode = new Node;
   newNode->info = value;
   newNode->next = head;
   head = newNode;
   
   if (tail == nullptr){
    tail = newNode;
   }
}

// append value at end of list
void IntList::push_back(int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = nullptr;
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

// return count of values
int IntList::count() const {
    int length = 0;
    Node* curr = head;
    while (curr != nullptr){
        length ++;
        curr = curr->next;
    }
   return length;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (this == &source){
        return *this;
    }

    Node * curr = head;
    while(curr != nullptr){
        Node* tmp = curr;
        curr = curr->next;
        delete tmp;
    }

    head = nullptr;
    tail = nullptr;

    Node* copiedList = source.head;
    while(copiedList != nullptr){
        this->push_back(copiedList->info);
        copiedList = copiedList->next;  
    }
    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    head = nullptr;
    tail= nullptr;
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

