#include "pch.h"
#include "CSVParser.h"




CSVParser::CSVParser(std::string file, char delm)
{
	m_delimiter = delm;
	std::ifstream ifile(file);
	std::string line;
	int i = 0;
		
	if (ifile.is_open())
	{
		while (ifile.good())
		{
			getline(ifile, line);
			if (line != "")
			{
				if (i == 0) {
					addHeaderString(line);
					i++;
				}
				else
					m_LineList.push_back(line);
			}
				
		}
		ifile.close();
		CreateRecordList();
	}
	else
		throw CError(std::string("Failed to open ").append(file));
}


CSVParser::~CSVParser()
{
	std::vector<Record *>::iterator it;

	for (it = m_recordList.begin(); it != m_recordList.end(); it++)
		delete *it;
}

void CSVParser::addHeaderString(std::string headerString) {
	headers.clear();
	for (size_t i = 0; i < headerString.length(); i++)
	{
		std::string tempString = "";
		while ((headerString[i] != m_delimiter) && (i < headerString.length()))
		{
			tempString += headerString[i];
			i++;
		}		
		headers.push_back(tempString);
	}

}

void CSVParser::CreateRecordList() 
{

	for (auto & element : m_LineList) {
		Record *row = new Record(&headers);
		std::string temp;
		for (int i = 0; i != element.length(); i++)
		{
			if (element[i] != ',')
				temp += element[i];
			else {
				row->insertValue(temp);
				temp = "";
			}

		}
		m_recordList.push_back(row);
	}
}

Record &CSVParser::getRow(unsigned int rowPosition) const
{
	if (rowPosition >= 0 && rowPosition < m_recordList.size())
		return *(m_recordList[rowPosition]);

	throw CError("can't return this row (doesn't exist)");
}

Record &CSVParser::operator[](unsigned int rowPosition) const
{
	return CSVParser::getRow(rowPosition);
}