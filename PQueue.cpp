/*
 * LaQueue
 *
 *
 * This is part of a series of labs for the Liberal Arts and Science Academy.
 * The series of labs provides a mockup of an POSIX Operating System
 * referred to as LA(SA)nix or LAnix.
 *
 * (c) copyright 2018, James Shockey - all rights reserved
 *
 * */

#include "PQueue.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

/*
 * Class Priority Queue
 */
PQueue::PQueue() {
  arr = (void **)std::malloc(MAX_SIZE * sizeof(void *));

  arrP = (int *)std::malloc(MAX_SIZE * sizeof(int));
}

// push everything forward by one
void PQueue::pushForward(int startIndex) {
  int end = tail;
  while (end != startIndex) {
    int beforeIndex = (end - 1 + MAX_SIZE) % MAX_SIZE;
    arr[end] = arr[beforeIndex];
    arrP[end] = arrP[beforeIndex];
    end = beforeIndex;
  }

  tail = (tail + 1) % MAX_SIZE;
}

void PQueue::print() {
  std::cout << "printing array - push" << std::endl;
  for (int i = 0; i < MAX_SIZE; i++) {
    if (i == front) {
      if (i == tail) {
        std::cout << i << ": " << arrP[i] << " " << arr[i] << " --- front & tail index "
                << std::endl;
      } else {
        std::cout << i << ": " << arrP[i] << " " << arr[i] << " --- front index "
                << std::endl;
      }
      
      continue;
    } else if (i == tail) {
      std::cout << i << ": " << arrP[i] << " " << arr[i] << " --- tail index "
                << std::endl;
      continue;
    }
    std::cout << i << ": " << arrP[i] << " " << arr[i] << std::endl;
  }
}

/*
 * Insert into Priority Queue
 */
void PQueue::push(void *item, int priority) {
  /*int idx = front;
  while (idx < tail && arrP[idx] >= priority) {
    idx = (idx + 1) % MAX_SIZE;
  }

  pushForward(idx);*/

  arr[tail] = item;
  arrP[tail] = priority;

  tail = (tail + 1) % MAX_SIZE;

}

/*
 * Delete from Priority Queue
 */
void *PQueue::top() {
  void *data = arr[front];
  arr[front] = nullptr;
  front = (front + 1) % MAX_SIZE;
  return data;
}
/*
 * Delete from Priority Queue
 */
void PQueue::pop() { arr[front] = nullptr; front = (front + 1) % MAX_SIZE; }

/*
 * Print Priority Queue
 */
void PQueue::display() {

  /* Your code here */

  /* Use the following out command for the data */
  int idx = front;
  while (idx != tail) {
    std::cout << "priority: " << arrP[idx] << " data " << (char*) arr[idx] << std::endl;

    idx = (idx + 1) % MAX_SIZE;
  }
}
