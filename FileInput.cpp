#include <iostream>
#include <string>
#include <fstream>
#include "FileInput.h"
using namespace std;
/*
  The FindLine method recieves a filename and an index
  and returns the input line of the index.
*/
string FileInput::FindLine(string fileName, int idx)
{
  string inputLine;
  string empty;
  ifstream file;
  file.open(fileName);
  for(int i = 0; i < idx; i++)
  {
    getline(file, empty);
    if(i == idx - 1){
      getline(file, inputLine);
    }
  }
  return inputLine;
}

int FileInput::findNumLines(string fileName)
{
  ifstream file;
  string inputLine;
  int counter = 0;
  file.open(fileName);
  while(getline(file, inputLine))
  {
    counter++;
  }
  return counter;
}

int FileInput::findLineLength(string fileName, int idx)
{
  ifstream file;
  string inputLine;
  string empty;
  int counter = 0;
  file.open(fileName);
  for(int i = 0; i < idx; i++)
  {
    getline(file, empty);
    if(i == idx - 1){
      getline(file, inputLine);
      return inputLine.length();
    }
  }
}
