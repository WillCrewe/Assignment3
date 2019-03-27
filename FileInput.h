#include <iostream>
#include <string>
using namespace std;
/*
  Header for the file input class to assist with reading lines and characters of lines
*/
class FileInput
{
  public:
    string FindLine(string fileName, int idx);
    int findNumLines(string fileName);
    int findLineLength(string fileName, int idx);
};
