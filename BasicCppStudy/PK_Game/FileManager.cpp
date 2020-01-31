#include "FileManager.h"

void FileManager::parseLineToVector(string line, vector<string>& v)
{
	int start = 0;
	int pos = 0;
	while (true)
	{
		pos = line.find(",", start);
		if (pos == -1)
		{
			string lastWord = line.substr(start);
			v.push_back(lastWord);
			break;
		}
		string tmp = line.substr(start, pos - start);
		v.push_back(tmp);

		start = pos + 1;
	}
}

void FileManager::loadCSVData(string filepath, map<string, map<string, string>>&m)
{
	std::ifstream ifs(filepath);
	if (!ifs.is_open())
	{
		std::cout << "文件打开失败" << std::endl;
		return;
	}
	std::string first_line;
	vector<string>v;

	ifs >> first_line;
	parseLineToVector(first_line, v);

	string otherLines;
	vector<string>v_otherLines;// why ?
	while (ifs>>otherLines)
	{
		
		parseLineToVector(otherLines, v_otherLines);

		map<string, string>t_mSmall;

		for (int i = 0; i < v.size(); i++)
		{
			t_mSmall.insert(make_pair(v.at(i), v_otherLines.at(i)));
		}

		m.insert(make_pair(v_otherLines.at(0), t_mSmall));
		v_otherLines.clear();
	}
	//
	
}
