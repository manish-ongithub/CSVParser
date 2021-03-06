// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#ifndef PCH_H
#define PCH_H

// TODO: add headers that you want to pre-compile here
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "CSVParser.h"

constexpr auto EMPID  = "empid";
constexpr auto NAME   = "name";
constexpr auto TYPE   = "type";
constexpr auto AMOUNT = "amount";

constexpr auto FOOD	  = "food";
constexpr auto TRAVEL = "travel";
constexpr auto TAXI   = "taxi";
constexpr auto MISC   = "misc";

constexpr auto TOTAL = "total";
constexpr auto TABLE = "table";
constexpr auto HIGH  = "high";

constexpr auto TBL_NAME = "NAME";
constexpr auto TBL_FOOD = "FOOD";
constexpr auto TBL_TRAV = "TRAV";
constexpr auto TBL_MISC = "MISC";
constexpr auto TBL_TAXI = "TAXI";


#endif //PCH_H
