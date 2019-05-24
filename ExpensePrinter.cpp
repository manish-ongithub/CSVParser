// ExpensePrinter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include "CSVParser.h"

using namespace std;


int main(int argc, char  **argv)
{
	string filename, summType;
	if (argc > 2) {
		filename = argv[1];
		summType = argv[2];
		cout << "Filename -> " << filename << " Summary Type -> " << summType << endl;

		try{ 
			CSVParser cs(filename, ','); 
		}
		catch (CError &e){
			std::cerr << e.what() << std::endl;
		}

	}
	else{
		cout << "insufficient arguments";
		return -1;
	}
	/*
	ifstream fs;
	fs.open(filename.c_str());
	string fileCommand;

	while (fs.good())
	{
		string temp;

		getline(fs, fileCommand, '\n');

		for (unsigned int i = 0; i < fileCommand.length(); i++)
		{
			if (fileCommand[i] != ',')
				temp += fileCommand[i];
			else
				temp += " ";
		}

		if (temp != "\0")
		{
			// Place your code here to run the file.
			cout << temp << endl;
		}
	}
	fs.close();
	*/
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
