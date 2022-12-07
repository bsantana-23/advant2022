#include "Day03.h"

using namespace std;
#include <algorithm>

Day03::Day03()
	: Day(GetDayString())
{
	Parse();
}

Day03::~Day03()
{

}

int Day03::GetDayInt()
{
	return 13;
}

string Day03::GetDayString()
{
	return "03";
}

void Day03::Parse()
{
	// Part 1
	m_Part1 = 0;

	for (int i = 0; i < m_FileContents.size() - 1; i++)
	{
		cout << m_FileContents[i] << endl;
		int line_len = m_FileContents[i].size();
		std::vector<char> left{};
		std::vector<char> right{};

		// Split in half
		for (int j = 0; j < line_len; j++)
		{
			if (j < line_len / 2)
			{
				left.push_back(m_FileContents[i][j]);
			}
			else
			{
				right.push_back(m_FileContents[i][j]);
			}
		}

		std::map<char, int> values = {};

		// Build map
		for (char x : left)
		{
			values.insert(std::pair<char, int>(x, 1));
		}

		// Check for duplicates
		for (char x : right)
		{
			if (values.count(x))
			{
				if (isupper(x))
				{
					m_Part1 += (int(x) - 38);
				}
				else
				{
					m_Part1 += (int(x) - 96);
				}

				break;
			}
		}
	}
	

	// Part 2
	m_Part2 = 0;
	std::map<char, int> values = {};

	for (int i = 0, group = 0; i < m_FileContents.size() - 1; i++, group++)
	{
		if (group == 3)
		{
			group = 0;
			values.clear();
		}

		for (auto& x : m_FileContents[i])
		{
			if (group == 0)
			{
				values.insert(std::pair<char, int>(x, 1));
			}
			else
			{
				if (values.count(x))
				{
					auto val = values.find(x);
					
					if (group == 1)
					{
						val->second = 2;
					}

					else if (group == 2 && val->second == 2)
					{
						if (isupper(x))
						{
							m_Part2 += (int(x) - 38);
						}
						else
						{
							m_Part2 += (int(x) - 96);
						}
						cout << "The type is " << x << " for group " << ceil(double(i)/3.0) << endl;
						break;
					}
				}
			}
		}

	}
}