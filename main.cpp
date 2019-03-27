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
  //cout << theFile.FindLine(fileName, 2) << endl;
  int num = theFile.findNumLines(fileName);
  int rightBrackets = 0, leftBrackets = 0;
  int rightPara = 0, leftPara = 0, rightBrack = 0, leftBrack = 0;
  for(int i = 0; i < num; i++)
  {
    rightPara = 0, leftPara = 0, rightBrack = 0, leftBrack = 0;
    string currLine = theFile.FindLine(fileName, i);
    int length = theFile.findLineLength(fileName, i);
    GenStack s(length);
    for(int ii = 0; ii < currLine.length(); ii++)
    {
      s.push(currLine[ii]);
      char temp = s.pop();
      //cout << "temp: " << temp << endl;
      if(temp == '{')
      {
        ++rightBrackets;
      } else if (temp == '}') {
        ++leftBrackets;
      } else if (temp == '(') {
        ++rightPara;
      } else if (temp == ')') {
        ++leftPara;
      } else if (temp == '[') {
        ++rightBrack;
      } else if (temp == ']') {
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
