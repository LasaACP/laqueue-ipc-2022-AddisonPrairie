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

class PQueue {

public:
  int MAX_SIZE = 20;
  int front = 0;
  int tail = 0;

  void ** arr;
  int * arrP;

public:
  PQueue();

  void push(void *item, int priority);
  void *top();
  void pop();
  void display();

  void print();

  void pushForward(int startIndex);
};
