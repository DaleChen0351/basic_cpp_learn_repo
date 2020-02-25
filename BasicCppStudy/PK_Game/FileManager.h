#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


class FileManager
{
public:
	void parseLineToVector(string line, vector<string>&v);
	void loadCSVData(string filepath, map<string, map<string,string>>&m);
};
