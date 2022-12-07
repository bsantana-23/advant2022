#include <fstream>
#include "Day.h"

using namespace std;
using namespace std::chrono;

Day::Day(string day)
	: m_Part1(0)
	, m_Part2(0)
{
	cout << "Day " << day << ":" << endl;
	string file_path = "Input\\Day" + day + ".txt";
	ReadIn(file_path);

	start = high_resolution_clock::now();
}

Day::~Day()
{
	stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	cout << "\tRun Time: " << duration.count() << endl;
	cout << "\tPart 1: " << m_Part1 << endl;
	cout << "\tPart 2: " << m_Part2 << endl;
}

void Day::ReadIn(string fileName)
{
	ifstream infile;
	string myline;

	infile.open(fileName);

	while (infile)
	{
		getline(infile, myline);
		m_FileContents.push_back(myline);
	}
}

vector<int> Day::ParseInt(string line, char delim)
{
	vector<int> numbers;

	string myline = line;
	stringstream stream(myline);
	while (stream.good())
	{
		string value;
		getline(stream, value, delim);
		if (value == "")
		{
			getline(stream, value, delim);
		}
		numbers.push_back(stoi(value));
	}

	return numbers;
}

vector<string> Day::ParseString(string line, char delim)
{
	vector<string> values;

	string myline = line;
	stringstream stream(myline);
	while (stream.good())
	{
		string value;
		getline(stream, value, delim);
		if (value == "")
		{
			getline(stream, value, delim);
		}
		values.push_back(value);
	}

	return values;
}

template<typename T>
void Day::Make2dMap(int x, int y, T**& map)
{
	map = new bool*[x];
	for (int i = 0; i <= x; i++)
	{
		map[i] = new bool[y];
		for (int j = 0; j <= y; j++)
		{
			map[i][j] = false;
		}
	}
}