#include <iostream>
#include <string>
#include <fstream>
#include "FileInput.h"
#include "GenStack.h"
using namespace std;
/*
  This main fail is to test the file input class to see if
  it the FindLine function will return the correct line of the
  input file based on the filename and the index
*/
int main()
{
  string fileName = "TESTER.txt";
  FileInput theFile;
  cout << theFile.FindLine(fileName, 2) << endl;
  int num = theFile.findNumLines(fileName);
  GenStack s(num);
  int rightBrackets = 0, leftBrackets = 0;
  int rightPara = 0, leftPara = 0, rightBrack = 0, leftBrack = 0;
  for(int i = 0; i < num; i++)
  {
    rightPara = 0, leftPara = 0, rightBrack = 0, leftBrack = 0;
    string currLine = theFile.FindLine(fileName, 1);
    for(int ii = 0; ii < currLine.length(); ii++)
    {
      cout << currLine << endl;
      if(currLine[i] == '{')
      {
        ++rightBrackets;
      } else if (currLine[i] == '}') {
        ++leftBrackets;
      } else if (currLine[i] == '(') {
        ++rightPara;
      } else if (currLine[i] == ')') {
        ++leftPara;
      } else if (currLine[i] == '[') {
        ++rightBrack;
      } else if (currLine[i] == ']') {
        ++leftBrack;
      }
    }
    if(rightPara != leftPara) {
      cout << "Missing ')' Line: " << i << endl;
    } else if (rightBrack != leftBrack) {
      cout << "Missing ']' Line: " << i << endl;
    }
  }
  if(rightBrackets != leftBrackets){
    cout << "Missing '}' Line: " << num << endl;
  }

  return 0;
}
