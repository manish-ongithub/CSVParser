#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here



#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <sstream>
#include <iomanip>
#include "CSVParser.h"

constexpr auto EMPID = "EmpId";
constexpr auto NAME = "Name";
constexpr auto TYPE = "Type";
constexpr auto AMOUNT = "Amount";

constexpr auto FOOD = "food";
constexpr auto TRAVEL = "travel";
constexpr auto TAXI = "taxi";
constexpr auto MISC = "misc";

#define TOTAL	"total"
#define TABLE	"table"
#define HIGH	"high"

#endif