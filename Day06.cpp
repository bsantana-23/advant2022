#include "Day06.h"

using namespace std;

Day06::Day06()
	: Day(GetDayString())
{
	Parse();
}

Day06::~Day06()
{

}

int Day06::GetDayInt()
{
	return 13;
}

string Day06::GetDayString()
{
	return "06";
}

void Day06::Parse()
{
	std::vector<char> marker{};

	for(int i = 0; i < m_FileContents.size(); i++)
	{
		for (int j = 0; j < m_FileContents[i].size(); j++)
		{

			auto c = m_FileContents[i][j];
			//const char* c_const = m_FileContents[i][j].c_str();

			bool found = false;
			int idx = 0;
			for (; idx < marker.size(); idx++)
			{
				if (marker.at(idx) == c)
				{
					found = true;
					break;
				}
			}

			if (found)
			{
				marker.erase(marker.begin(), marker.begin() + idx+1);
			}

			marker.push_back(c);

			// Part 1
			/*if (marker.size() == 4)
			{
				m_Part1 = j + 1;
				return;
			}*/

			// Part 2
			if (marker.size() == 14)
			{
				m_Part2 = j + 1;
				return;
			}
		}

	}
}