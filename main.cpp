//including the required libraries
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>

// including std in the current namespace
using namespace std;



int main() {
	// defining local variables
	string user,name;
	fstream file;
	bool repeat=0;

	while (!repeat) {

		repeat = 1;
		cout << "Enter Name of the file you want to open \n";
		cin >> user;
		name = user + ".txt";
		file.open(name);
		if (file) {
			cout << endl << "**** File Found ****\n";
		}
		else {
			cout << endl << "**** File not Found ****\n";
			cout << endl << "Would You like to try again(Y/N)?\n";
			char selection_variable;
			cin >> selection_variable;
			if (selection_variable == 'Y')
			{
				repeat = 0;
			}

		}
	}
	if (file.is_open()) {   
		cout << endl << "*** Colours found in the file are ***\n";
		string tp;
		while (getline(file, tp)) { 
			cout << "\t";
			cout << tp << "\n";  
		}
		cout << "\n\n*** Exiting File ***\n";
		file.close(); 
	}

}