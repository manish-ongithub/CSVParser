// ExpensePrinter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "pch.h"
using namespace std;

typedef struct employeExpense {
	string name = "";
	float foodExpense = 0;
	float travelExpense = 0;
	float taxiExpense = 0;
	float miscExpense = 0;
}expense;

void prettyPrint(CSVParser &parser,string summaryType) {

	int rowCount = parser.getRowCount();
	int colCount = parser.getColumnCount();
	cout << "rowcount " << rowCount << " col count " << colCount << endl;

	if (summaryType == TOTAL) {
		map<string, expense> mapEmpExpense;
		for (int i = 0; i < rowCount; ++i) {

			if (mapEmpExpense.find(parser[i][NAME]) == mapEmpExpense.end()) {
				expense ex;
				if (parser[i][TYPE] == FOOD)
					ex.foodExpense = atof(parser[i][AMOUNT].c_str());
				else if(parser[i][TYPE] == TRAVEL)
					ex.travelExpense = atof(parser[i][AMOUNT].c_str());
				else if (parser[i][TYPE] == TAXI)
					ex.taxiExpense = atof(parser[i][AMOUNT].c_str());
				else if (parser[i][TYPE] == MISC)
					ex.miscExpense = atof(parser[i][AMOUNT].c_str());

				mapEmpExpense[parser[i][NAME]] = ex;
			}
			else
			{
				if (parser[i][TYPE] == FOOD)
					mapEmpExpense[parser[i][NAME]].foodExpense += atof(parser[i][AMOUNT].c_str());
				else if (parser[i][TYPE] == TRAVEL)
					mapEmpExpense[parser[i][NAME]].travelExpense += atof(parser[i][AMOUNT].c_str());
				else if (parser[i][TYPE] == TAXI)
					mapEmpExpense[parser[i][NAME]].taxiExpense += atof(parser[i][AMOUNT].c_str());
				else if (parser[i][TYPE] == MISC)
					mapEmpExpense[parser[i][NAME]].miscExpense += atof(parser[i][AMOUNT].c_str());
			}

		}
		std::cout << std::fixed;
		std::cout << std::setprecision(2);
		for (auto rec : mapEmpExpense) {
			float totalExpense = rec.second.foodExpense + rec.second.miscExpense + rec.second.taxiExpense + rec.second.travelExpense;
			cout << rec.first <<" -> " <<totalExpense << endl;;
		}
	
	}

	if (summaryType == "table") {

		map<string, expense> mapEmpExpense;
		for (int i = 0; i < rowCount; ++i) {
			if (mapEmpExpense.find(parser[i][NAME]) == mapEmpExpense.end()) {
				expense ex;
				if (parser[i][TYPE] == FOOD)
					ex.foodExpense = atof(parser[i][AMOUNT].c_str());
				else if (parser[i][TYPE] == TRAVEL)
					ex.travelExpense = atof(parser[i][AMOUNT].c_str());
				else if (parser[i][TYPE] == TAXI)
					ex.taxiExpense = atof(parser[i][AMOUNT].c_str());
				else if (parser[i][TYPE] == MISC)
					ex.miscExpense = atof(parser[i][AMOUNT].c_str());

				mapEmpExpense[parser[i][NAME]] = ex;
			}
			else
			{
				if (parser[i][TYPE] == FOOD)
					mapEmpExpense[parser[i][NAME]].foodExpense += atof(parser[i][AMOUNT].c_str());
				else if (parser[i][TYPE] == TRAVEL)
					mapEmpExpense[parser[i][NAME]].travelExpense += atof(parser[i][AMOUNT].c_str());
				else if (parser[i][TYPE] == TAXI)
					mapEmpExpense[parser[i][NAME]].taxiExpense += atof(parser[i][AMOUNT].c_str());
				else if (parser[i][TYPE] == MISC)
					mapEmpExpense[parser[i][NAME]].miscExpense += atof(parser[i][AMOUNT].c_str());
			}

		}
		std::cout << std::fixed;
		std::cout << std::setprecision(0);
		for (auto rec : mapEmpExpense) {
			
			cout << rec.first << "\t" << rec.second.foodExpense << "\t" ;
			cout << rec.second.travelExpense<< "\t" << rec.second.miscExpense << endl;
		}

	}

	if (summaryType == "high") {
		string empTravelExpense = "";
		string empMiscExpense = "";
		string empTaxiExpense = "";
		string empFoodExpense = "";
		
		float  f_h_travel = 0;
		float  f_h_misc = 0;
		float  f_h_taxi = 0;
		float  f_h_food = 0;

		map<string, expense> mapEmpExpense;
		for (int i = 0; i < rowCount; ++i) {
			if (mapEmpExpense.find(parser[i][EMPID]) == mapEmpExpense.end()) {
				expense ex;
				ex.name = parser[i][NAME];
				if (parser[i][TYPE] == FOOD)
					ex.foodExpense = atof(parser[i][AMOUNT].c_str());
				else if (parser[i][TYPE] == TRAVEL)
					ex.travelExpense = atof(parser[i][AMOUNT].c_str());
				else if (parser[i][TYPE] == TAXI)
					ex.taxiExpense = atof(parser[i][AMOUNT].c_str());
				else if (parser[i][TYPE] == MISC)
					ex.miscExpense = atof(parser[i][AMOUNT].c_str());

				mapEmpExpense[parser[i][EMPID]] = ex;
			}
			else
			{
				if (parser[i][TYPE] == FOOD)
					mapEmpExpense[parser[i][EMPID]].foodExpense += atof(parser[i][AMOUNT].c_str());
				else if (parser[i][TYPE] == TRAVEL)
					mapEmpExpense[parser[i][EMPID]].travelExpense += atof(parser[i][AMOUNT].c_str());
				else if (parser[i][TYPE] == TAXI)
					mapEmpExpense[parser[i][EMPID]].taxiExpense += atof(parser[i][AMOUNT].c_str());
				else if (parser[i][TYPE] == MISC)
					mapEmpExpense[parser[i][EMPID]].miscExpense += atof(parser[i][AMOUNT].c_str());
			}
			if (mapEmpExpense[parser[i][EMPID]].foodExpense > f_h_food)
			{
				f_h_food = mapEmpExpense[parser[i][EMPID]].foodExpense;
				empFoodExpense = parser[i][EMPID];
			}
			if (mapEmpExpense[parser[i][EMPID]].travelExpense > f_h_travel)
			{
				f_h_travel = mapEmpExpense[parser[i][EMPID]].travelExpense;
				empTravelExpense = parser[i][EMPID];
			}
			if (mapEmpExpense[parser[i][EMPID]].miscExpense> f_h_misc)
			{
				f_h_misc = mapEmpExpense[parser[i][EMPID]].miscExpense;
				empMiscExpense = parser[i][EMPID];
			}
			if (mapEmpExpense[parser[i][EMPID]].taxiExpense > f_h_taxi)
			{
				f_h_taxi = mapEmpExpense[parser[i][EMPID]].taxiExpense;
				empTaxiExpense = parser[i][EMPID];
			}
		}

		std::cout << std::fixed;
		std::cout << std::setprecision(0);
		for (auto rec : mapEmpExpense) {
			string str;
			ostringstream strExpense;
			if (rec.first == empFoodExpense)
			{
				strExpense<<"*";
				strExpense<<rec.second.foodExpense;
				strExpense<<"\t"<<rec.second.travelExpense;
				strExpense<<"\t"<<rec.second.taxiExpense;
				strExpense<<"\t"<<rec.second.miscExpense;
			}
			else if (rec.first == empTravelExpense)
			{
				strExpense<<rec.second.foodExpense;
				strExpense<<"\t"<<"*"<<rec.second.travelExpense;
				strExpense<<"\t"<<rec.second.taxiExpense;
				strExpense<<"\t"<<rec.second.miscExpense;
			}
			else if (rec.first == empTaxiExpense)
			{
				strExpense<<rec.second.foodExpense;
				strExpense<<"\t"<<rec.second.travelExpense;
				strExpense<<"\t"<<rec.second.taxiExpense;
				strExpense<<"\t"<<rec.second.miscExpense;
			}
			else if (rec.first == empMiscExpense)
			{
				strExpense<<rec.second.foodExpense;
				strExpense<<"\t"<<rec.second.travelExpense;
				strExpense<<"\t"<<rec.second.taxiExpense;
				strExpense<<"\t"<<"*"<<rec.second.miscExpense;
			}
			else {
				strExpense<<rec.second.foodExpense;
				strExpense<<"\t"<<rec.second.travelExpense;
				strExpense<<"\t"<<rec.second.taxiExpense;
				strExpense<<"\t"<<rec.second.miscExpense;
			}
			
			cout << rec.first <<"\t"<<rec.second.name << "\t" << strExpense.str() << endl;
		}
	}

}


int main(int argc, char** argv)
{
	string filename, summType;
	if (argc > 2) {
		filename = argv[1];
		summType = argv[2];
		cout << "Filename -> " << filename << " Summary Type -> " << summType << endl;

		try {
			CSVParser cs(filename, ',');
			std::cout << "name -> " << cs[1][NAME] << " amount-> " << cs[1][AMOUNT] << std::endl;
			prettyPrint(cs, summType);
		}
		catch (CError& e) {
			std::cerr << e.what() << std::endl;
		}
		
	}
	else {
		cout << "insufficient arguments";
		return -1;
	}
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