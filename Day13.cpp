#include "Day13.h"

using namespace std;

Day13::Day13()
	: Day(GetDayString())
{
	Parse();
}

Day13::~Day13()
{

}

int Day13::GetDayInt()
{
	return 13;
}

string Day13::GetDayString()
{
	return "13";
}

void Day13::Parse()
{
	m_Part1 = 0;
	int pair{ 0 };
	for (int row = 0; row < m_FileContents.size() - 1; row+=3)
	{
		pair++;
		int list1_size{ 0 };
		int lists_found{ 0 };
		vector<vector<int>> list1{};
		vector<int> temp{};
		string curr_row = m_FileContents[row];
		curr_row = curr_row.substr(1, curr_row.size() - 1);
		FindPair(curr_row, list1);

		int list2_size{ 0 };
		vector<vector<int>> list2{};
		curr_row = m_FileContents[row+1];
		curr_row = curr_row.substr(1, curr_row.size() - 1);
		FindPair(curr_row, list2);

		bool valid = true;
		for (int i = 0; i <= list1.size() && i <= list2.size(); i++)
		{
			if (!valid)
			{
				break;
			}
			if (i == list1.size() && i != list2.size() )
			{
				//m_Part1 += pair;
				break;
			}
			else if (i != list1.size() && i == list2.size() )
			{
				// out of order
				valid = false;
				break;
			}
			else if (i == list1.size() && i == list2.size())
			{
				break;
			}

			vector<int> l1 = list1[i];
			vector<int> l2 = list2[i];

			for (int j = 0; j <= l1.size() && j <= l2.size(); j++)
			{
				if (j == l1.size() && j == l2.size())
				{
					break;
				}
				else if ( j == l1.size() && j != l2.size() )
				{
					//m_Part1 += pair;
					//cout << "pair " << pair << " is valid" << endl;
					break;
				}
				else if (j != l1.size() && j == l2.size() )
				{
					// out of order
					valid = false;
					break;
				}

				if (l1[j] == l2[j])
				{
					continue;
				}
				if (l1[j] < l2[j])
				{
					//m_Part1 += pair;
					//cout << "pair " << pair << " is valid" << endl;
					break;
				}
				else if (l1[j] > l2[j])
				{
					// out of order
					valid = false;
					break;
				}

			}
		}

		if (valid) {
			cout << "pair " << pair << " is valid" << endl;
			m_Part1 += pair;
		}
	}

}

vector<int> Day13::FindPair(string &row, vector<vector<int>> &main_list)
{
	vector<int> found{};
	for (int col = 0; col < row.size(); col++)
	{
		if (row[col] == ']')
		{
			// Save the list			
			row = row.substr(col + 1, row.size() - col + 1);
			main_list.push_back(found);
			return found;
		}
		else if (row[col] == ',')
		{
			continue;
		}
		else if (row[col] == '[')
		{
			row = row.substr(col + 1, row.size() - col + 1);
			FindPair(row, main_list);
			col = 0;
		}
		else
		{
			if (row[col + 1] == ',')
			{
				found.push_back(int(row[col]) - 48);
			}
			else if (row[col + 1] != ']')
			{
				found.push_back(stoi(row.substr(col, 2)));
				col++;
			}
		}
	}
	return found;
}