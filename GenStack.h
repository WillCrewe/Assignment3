#include <iostream>
using namespace std;

class GenStack
{
public:
  GenStack(); //constructor
  GenStack(int maxSize); //Overloaded constructor
  ~GenStack();//destructor

  void push(char d);
  char pop();
  char peek();

  bool isFull();
  bool isEmpty();

  int getSize();

  int size;
  int top;
  int maxSize;

  char* myArray;
};
