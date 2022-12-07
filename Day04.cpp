#include "Day04.h"

using namespace std;

Day04::Day04()
	: Day(GetDayString())
{
	Parse();
}

Day04::~Day04()
{

}

int Day04::GetDayInt()
{
	return 13;
}

string Day04::GetDayString()
{
	return "04";
}

void Day04::Parse()
{
	m_Part1 = 0;
	m_Part2 = 0;
	int idx1 = 0;
	int idx2 = 0;

	for (int line = 0; line < m_FileContents.size() - 1; line++)
	{
		std::pair<int, int> range1;
		std::pair<int, int> range2;
		
		// Identify the ranges
		for (int i = 0; i < m_FileContents[line].size(); i++)
		{
			if (m_FileContents[line][i] == '-') {
				if (idx1 == 0)
				{
					idx1 = i;
				}
				else
				{
					idx1 = 0;
					range2 = { stoi(m_FileContents[line].substr(idx2+1, i - (idx2+1))), stoi(m_FileContents[line].substr(i + 1, m_FileContents[line].size()-1-idx2)) };

					// Is range within other range
					if ((range1.first >= range2.first && range1.second <= range2.second)
						||
						(range2.first >= range1.first && range2.second <= range1.second))
					{
						m_Part1 += 1;
					}

					if ((range2.second >= range1.first && range1.first >= range2.first)
						||
						(range1.second >= range2.first && range2.first >= range1.first))
					{
						m_Part2 += 1;
					}

					range1 = { 0,0 };
					range2 = { 0,0 };
				}
			}
			else if (m_FileContents[line][i] == ',')
			{
				idx2 = i;

				range1 = { stoi(m_FileContents[line].substr(0, idx1)), stoi(m_FileContents[line].substr(idx1 + 1, (idx2 - (idx1 + 1)))) };
			}
		}

		cout << m_FileContents[line] << endl;
	}
}