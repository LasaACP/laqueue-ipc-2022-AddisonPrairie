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

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "PQueue.h"



/*
 * Class Priority Queue
 */

		
/*
* Insert into Priority Queue
*/
void PQueue::push(void *item, int priority)
{
	//perror("before");
  node* ptr = front;
  node* newNode = new node();
  newNode->data = item;
  newNode->priority = priority;
  newNode->link = nullptr;

  //higher priority means sooner in the queue
  node* last = nullptr;
  while (ptr != nullptr && ptr->priority >= priority) {
    last = ptr;
    ptr = ptr->link;
  }
  //perror("after");
  if (last != nullptr) {
    newNode->link = last->link;
    last->link = newNode;
  } else {
    newNode->link = front;
    front = newNode;
  }
  /*std::cout << "front " << front << std::endl;
  std::cout << "next " << front->link << std::endl;
  std::cout << "data " << front->data << std::endl;
  std::cout << "priority " << front->priority << std::endl;*/
  
  //perror("after 2");
}

/*
 * Delete from Priority Queue
 */
void* PQueue::top()
{
	void* returned = front != nullptr ? front->data : nullptr;
  node* l = front;
  front = front != nullptr ? front->link : nullptr;
  return returned;
}
/*
 * Delete from Priority Queue
 */
void PQueue::pop()
{
	node* l = front;
  front = front != nullptr ? front->link : nullptr;
  delete l;
}

/*
 * Print Priority Queue
 */
void PQueue::display()
{

	/* Your code here */
	
	/* Use the following out command for the data */
  node* ptr = front;
  while (ptr != nullptr) {
    std::cout << "priority: " << ptr->priority << " data: " << (char*) ptr->data << std::endl;
    ptr = ptr->link;
  }
}
	