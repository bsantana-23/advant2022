#include "Day12.h"

using namespace std;

Day12::Day12()
	: Day(GetDayString())
{
	Parse();
}

Day12::~Day12()
{

}

int Day12::GetDayInt()
{
	return 13;
}

string Day12::GetDayString()
{
	return "12";
}

void Day12::Parse()
{
	pair<int, int> start_pos{ 0,0 };
	pair<int, int> end_pos{ 0,0 };

	// find start (and end?) positions
	for (int row = 0; row < m_FileContents.size() - 1; row++)
	{
		for (int col = 0; col < m_FileContents[row].size(); col++)
		{
			if (m_FileContents[row][col] == 'S')
			{
				start_pos = { row, col };
			}
			else if (m_FileContents[row][col] == 'E')
			{
				end_pos = { row, col };
			}
		}
	}

	bool done = false;
	pair<int, int> curr_pos = start_pos;
	int steps{ 0 };
	map<pair<int, int>, int> visited{};
	
	while (!done)
	{
		if (SearchPath(start_pos, end_pos, steps, visited))
		{
			cout << "found it" << endl;
		}
		else
		{
			cout << "could not find it" << endl;
		}

		if (curr_pos == end_pos)
		{
			done = true;
		}

		if (curr_pos.first == 0)
		{

		}
		if (curr_pos.second == 0)
		{

		}
		if (curr_pos.first == m_FileContents.size()-1)
		{

		}
		if (curr_pos.second == m_FileContents[curr_pos.first].size()-1)
		{

		}

	}

	m_Part1 = steps;
}

bool Day12::SearchPath(pair<int, int> pos, pair<int, int> end, int &steps, map<pair<int, int>, int> &visited)
{
	bool found = false;

	if (pos == end)
	{
		return true;
	}

	visited.insert(pair<pair<int, int>,int>(pair<int,int>(pos.first, pos.second), 1));

	// Loop down
	if (pos.first < m_FileContents.size() - 1)
	{
		int c = int(m_FileContents[pos.first + 1][pos.second]);
		int curr = int(m_FileContents[pos.first][pos.second]);

		if (curr == int('S'))
		{
			curr = int('a');
		}

		// If we have not visited this before
		if (visited.find(pair<int, int>{pos.first + 1, pos.second}) == visited.end())
		{
			if (c == curr || c == curr + 1)
			{
				steps++;
				found = SearchPath(pair<int, int>{pos.first + 1, pos.second}, end, steps, visited);
			}
		}
	}

	// Loop right
	if (pos.second < m_FileContents[pos.first].size() - 1)
	{
		int c = int(m_FileContents[pos.first][pos.second + 1]);
		int curr = int(m_FileContents[pos.first][pos.second]);
		if (curr == int('S'))
		{
			curr = int('a');
		}

		// If we have not visited this before
		if (visited.find(pair<int, int>{pos.first, pos.second + 1}) == visited.end())
		{
			if (c == curr || c == curr + 1)
			{
				steps++;
				found = SearchPath(pair<int, int>{pos.first, pos.second + 1}, end, steps, visited);
			}
		}
	}

	// Loop left
	if (pos.first > 0)
	{
		int c = int(m_FileContents[pos.first][pos.second - 1]);
		int curr = int(m_FileContents[pos.first][pos.second]);
		if (curr == int('S'))
		{
			curr = int('a');
		}

		// If we have not visited this before
		if (visited.find(pair<int, int>{pos.first, pos.second - 1}) == visited.end())
		{
			if (c == curr || c == curr + 1)
			{
				steps++;
				found = SearchPath(pair<int, int>{pos.first, pos.second - 1}, end, steps, visited);
			}
		}
	}

	// Loop up
	if (pos.first > 0)
	{
		int c = int(m_FileContents[pos.first - 1][pos.second]);
		int curr = int(m_FileContents[pos.first][pos.second]);
		if (curr == int('S'))
		{
			curr = int('a');
		}

		// If we have not visited this before
		if (visited.find(pair<int, int>{pos.first - 1, pos.second}) == visited.end())
		{			
			if (c == curr || c == curr + 1)
			{
				steps++;
				found = SearchPath(pair<int, int>{pos.first - 1, pos.second}, end, steps, visited);
			}
		}
	}

	return found;
}