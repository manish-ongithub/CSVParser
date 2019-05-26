#pragma once
#include<vector>
#include<string>
#include<fstream>
#include<stdexcept>
#include<iostream>

class CError : public std::runtime_error
{

public:
	CError(const std::string& msg) :
		std::runtime_error(std::string("CSVparser : ").append(msg))
	{
		//std::cout << msg << std::endl;
	}
};

class Record {
public:
	std::vector<std::string> fields;
	std::vector<std::string>* header;
	Record(std::vector<std::string>* pheader) :header(pheader) {}
	~Record() {

	}
	template <typename T>
	const T getValue(int index)
	{
		if (index >= 0 && index < fields.size())
		{
			T value;
			std::stringstream ss(fields[index]);
			//ss << fields[index];
			ss >> value;
			return value;
		}
		else
			throw CError("value not found at index");
	}

	void insertValue(const std::string& value) {
		fields.push_back(value);
	}
	
	std::string operator[](int index) {
		return fields[index];
	}
	
	std::string operator[](const std::string& valueName) {
		for (int i = 0; i < header->size(); ++i) {
			if (header->at(i) == valueName) {
				return fields[i];
			}
		}
		throw CError("'" + valueName + "' field not found");
	}

};

class CSVParser
{
public:
	std::vector<std::string> headers;
	char m_delimiter;
	std::string m_file;
	std::vector<std::string> m_LineList;
	std::vector<Record*> m_recordList;
public:
	CSVParser(std::string file, char delm);
	~CSVParser();
	void addHeaderString(std::string headerString);
	void CreateRecordList();
	Record& getRow(unsigned int rowPosition) const;
	Record& operator[](unsigned int rowPosition) const;
	int getRowCount();
	int getColumnCount();
};
