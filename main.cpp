//Author: Dhiab almansoori
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  string line = "";
  size_t position;
  string filename;
  ifstream reader;
  string color;

   cout << "Please type the name of the file to open:\n";
   getline(cin, filename);
   reader.open(filename, ios::in);

   if (reader.is_open())  {

      while (!reader.eof()) {
        getline(reader, line);
        position = line.find("#");

        if (line[position]) {
          cout << '#';
          for (char colorvalue = position += 1; (line[colorvalue] >= '0' && line[colorvalue]
          <='9') || (line[colorvalue] >= 'A' && line[colorvalue]  <= 'F'); colorvalue++) {

            cout << line[colorvalue];
          }
        }
        cout << endl;
      }
   }





  return 0;}
