#include "pch.h"
using namespace std;

//struct to keep record of employee expenditure
typedef struct employeExpense {
	string name = "";
	float foodExpense = 0;
	float travelExpense = 0;
	float taxiExpense = 0;
	float miscExpense = 0;
}expense;

void prettyPrintTotal(CSVParser &parser)
{
	map<string, expense> mapEmpExpense;
	int rowCount = parser.getRowCount();
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

	}
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	cout << TBL_NAME << "\t" << "TOTAL EXPENSE" << endl;

	for (auto rec : mapEmpExpense) {
		float totalExpense = rec.second.foodExpense + rec.second.miscExpense + rec.second.taxiExpense + rec.second.travelExpense;
		cout << rec.second.name << "\t" << totalExpense << endl;;
	}
}

void prettyPrintTable(CSVParser &parser)
{
	map<string, expense> mapEmpExpense;
	int rowCount = parser.getRowCount();
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

	}
	std::cout << std::fixed;
	std::cout << std::setprecision(1);

	cout << TBL_NAME << "\t" << TBL_FOOD << "\t" << TBL_TAXI << "\t" << TBL_TRAV << "\t" << TBL_MISC << endl;

	for (auto rec : mapEmpExpense) {

		cout << rec.second.name << "\t" << rec.second.foodExpense << "\t"<<rec.second.taxiExpense<<"\t";
		cout << rec.second.travelExpense << "\t" << rec.second.miscExpense << endl;
	}
}

void prettyPrintHigh(CSVParser &parser)
{
	string empTravelExpense = "";
	string empMiscExpense = "";
	string empTaxiExpense = "";
	string empFoodExpense = "";

	float  f_h_travel = 0;
	float  f_h_misc = 0;
	float  f_h_taxi = 0;
	float  f_h_food = 0;
	int rowCount = parser.getRowCount();
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
		if (mapEmpExpense[parser[i][EMPID]].miscExpense > f_h_misc)
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
	std::cout << std::setprecision(1);

	cout << TBL_NAME << "\t" << TBL_FOOD << "\t" << TBL_TAXI << "\t" << TBL_TRAV << "\t" << TBL_MISC << endl;
	
	for (auto rec : mapEmpExpense) {
		string str;
		ostringstream strExpense;
		//strExpense << std::fixed;
		//strExpense << std::setprecision(1);

		if (rec.first == empFoodExpense)
			strExpense << "*" << rec.second.foodExpense << "\t";
		else
			strExpense << rec.second.foodExpense << "\t";

		if (rec.first == empTaxiExpense)
			strExpense << "*" << rec.second.taxiExpense << "\t";
		else
			strExpense << rec.second.taxiExpense << "\t";

		if (rec.first == empTravelExpense)
			strExpense << "*" << rec.second.travelExpense << "\t";
		else
			strExpense << rec.second.travelExpense << "\t";

		if (rec.first == empMiscExpense)
			strExpense << "*" << rec.second.miscExpense << "\t";
		else
			strExpense << rec.second.miscExpense << "\t";


		cout << rec.second.name << "\t" << strExpense.str() << endl;
	}
}


void prettyPrint(CSVParser &parser, string summaryType) {

	int rowCount = parser.getRowCount();
	int colCount = parser.getColumnCount();
	
	if (summaryType == TOTAL) {
		prettyPrintTotal(parser);
	}

	if (summaryType == TABLE) {
		prettyPrintTable(parser);
	}

	if (summaryType == HIGH) {
		prettyPrintHigh(parser);
	}

}


int main(int argc, char** argv)
{
	string filename, summType;
	if (argc > 2) {
		filename = argv[1];
		summType = argv[2];
		//cout << "Filename -> " << filename << " Summary Type -> " << summType << endl;
		std::transform(summType.begin(), summType.end(), summType.begin(), ::tolower);
		try {
			CSVParser cs(filename, ',');
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


