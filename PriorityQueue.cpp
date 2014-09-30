#include "PriorityQueue.hpp"

// Implement the functions here.

#include "PriorityQueue.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

using namespace std;

typedef PriorityQueue::DataType DataType;

PriorityQueue::PriorityQueue(unsigned int capacity){
    
    heap_ =  new DataType[capacity + 1];
    capacity_ = capacity;
    size_ = 0;
}

PriorityQueue::~PriorityQueue(){
    delete [] heap_;
}

bool PriorityQueue::enqueue(DataType val){
    if (size_ >=  capacity_){
        return false;
    }
    
    size_ ++;
    heap_[size_] = val;
    
    int i = size_;
    
    while(heap_[i / 2] < heap_[i] && i != 0){
        DataType temp = heap_[i];
        heap_[i] = heap_[i / 2];
        heap_[i / 2] = temp; 
        i = i / 2;
    }
    return true;
}

bool PriorityQueue::dequeue(){
    if (size_ == 0){
        return false;
    }
    
    heap_[1] = heap_[size_];
    size_--;
    
    int i = 1;
    
    while (true){
        DataType temp = heap_[i];
        
        // if the node is a leaf
        if (size_ < 2 * i){ 
            break;
        }
        // if the node has the left child
        // Note since this is a complete binary tree, no node will have only one right child
        else if (size_ < 2 * i + 1){ 
            if (heap_[2 * i] > heap_[i]){
                heap_[i] = heap_[2 * i];
                heap_[2 * i] = temp;
                i = 2 * i;
            }
            else{
                break;
            }
        }
        //if the node has both a left and right child
        else{
            // if both child are larger than the parent
            if (heap_[i] > heap_[2 * i] && heap_[i] > heap_[2 * i + 1]){
                break;
            }
            // if left parent is larger than right
            else if (heap_[2 * i] >= heap_[2 * i + 1]){
                heap_[i] = heap_[2 * i];
                heap_[2 * i] = temp;
                i = 2 * i;
            } 
            // if right parent is larger than left
            else{
                heap_[i] = heap_[2 * i + 1];
                heap_[2 * i + 1] = temp;
                i = 2 * i + 1;
            }
        }
    }
    return true;
}

bool PriorityQueue::empty() const{
    return size_ == 0;
}

bool PriorityQueue::full() const{
    return size_ == capacity_;
}

unsigned int PriorityQueue::size() const{
    return size_;
}

DataType PriorityQueue::max() const{
    if (empty()){
        return NULL;
    }
    return heap_[1];
}

void PriorityQueue::print() const{
    
    if (size_ == 0){
        cout << "EMPTY HEAP" << endl;
    }
    
    int f = 1, count = 0;
    
    for (int i = 1; i <= size_; i ++){
        cout << setw(6) <<heap_[i];
        count ++;
        
        if (count == f){
            cout << endl;
            f = f * 2;
            count = 0;
        }
    } 
    cout << endl;
}
