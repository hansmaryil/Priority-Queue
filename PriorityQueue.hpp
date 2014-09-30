#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

// This class defines a priority queue, implemented as a heap. A higher value
// indicates a higher priority (e.g. an element with value 5 has a higher
// priority than an element with value 1).
//
// The elements in the heap are represented using a sequential array, as 
// explained in the textbook. For simplicity, this array does not grow or
// shrink. Note that if you are given a capacity of 16, this indicates the
// heap should store 16 elements. So, your array should be of size 17, since we
// do not use index 0.
//
// Keep in mind that we don't use index 0 in the sequential representation of a
// tree (heap) when manipulating/using your class instance variables.
class PriorityQueue
{
  friend class PriorityQueueTest;
  friend int main();
public:
  // Can be seen externally as PriorityQueue::DataType
  typedef int DataType;
  
public:
  // Constructor initializes heap_ to an array of size "capacity + 1", so that
  // there are at most "capacity" elements in the heap.
  PriorityQueue(unsigned int capacity);
  // Destructor.
  ~PriorityQueue();
  
  // Enqueues "val" into the priority queue. Returns false if failed, true
  // otherwise. Assume no duplicate entries will be entered.
  bool enqueue(DataType val);
  // Dequeues the top element with the maximum value (priority) and rearranges
  // the resulting heap. Returns false if failed, true otherwise.
  bool dequeue();
  
  // Returns the max element of the priority queue, but does not remove it.
  DataType max() const;
  // Returns true if the priority queue is empty; false otherwise.
  bool empty() const;
  // Returns true if the priority queue is full; false otherwise.
  bool full() const;
  // Returns the number of elements in the priority queue.
  unsigned int size() const;
  // Print the contents of the priority queue.
  void print() const;
  
private:
  // Sequential representation of the heap tree (i.e. heap_ is a dynamic array;
  // see textbook).
  DataType* heap_;

  // Total number of elements that the heap can store (that is, the size of the
  // array heap_ will be initialized as size (capacity_ + 1) ).
  unsigned int capacity_;
  
  // Current number of items in heap_. Remember, we don't use the first element
  // (i.e. index 0) of heap_.
  unsigned int size_;
  
private:
  // Override copy constructor and assignment operator in private so we can't
  // use them.
  PriorityQueue(const PriorityQueue& other) {}
  PriorityQueue& operator=(const PriorityQueue& other) {}
};


#endif  //PRIORITY_QUEUE_HPP
