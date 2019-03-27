#include "GenStack.h"
#include <iostream>
using namespace std;

GenStack::GenStack(int maxSize)
{
  myArray = new char[maxSize];
  size = maxSize;
  top = -1;
}

GenStack::~GenStack()
{
}

void GenStack::push(char d)
{
  if(top !=(size-1))
  {
    myArray[++top] = d;
  }
}

char GenStack::pop()
{
  int temp = top;
  if(top != -1)
  {
    top = top-1;
    return myArray[temp--];
  }
  else
  {
    cout << "Error: Stack Empty. " << endl;
  }
}

char GenStack::peek()
{
  //check if empt
  if (size == 0)
  {
    cout << "Error: Stack Empty. ";
  }
  return myArray[top];
}

bool GenStack::isFull()
{
  return (top == size-1);
}

bool GenStack::isEmpty()
{
  return (top == -1);
}

int GenStack::getSize()
{
  return size;
}
