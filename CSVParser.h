#pragma once
#include<vector>
#include<string>
#include<fstream>
#include<stdexcept>
#include<iostream>

class CError : public std::runtime_error
{

public:
	CError(const std::string &msg) :
		std::runtime_error(std::string("CSVparser : ").append(msg))
	{
		//std::cout << msg << std::endl;
	}
};

class Record {
public:
	std::vector<std::string> fields;

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

	void insertValue(const std::string &value) {
		fields.push_back(value);
	}
	std::string operator[](int index) {
		return fields[index];
	}
	//std::string operator[](const std::string &valueName);
};

class CSVParser
{
	public:
		std::vector<std::string> headers;
		char m_delimiter;
		std::string m_file;
		std::vector<std::string> m_LineList;
		std::vector<Record *> m_recordList;
	public:
		CSVParser(std::string file, char delm);
		~CSVParser();
		void addHeaderString(std::string headerString);
		void CreateRecordList();
};


