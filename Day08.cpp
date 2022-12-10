#include "Day08.h"

using namespace std;

Day08::Day08()
	: Day(GetDayString())
{
	Parse();
}

Day08::~Day08()
{

}

int Day08::GetDayInt()
{
	return 13;
}

string Day08::GetDayString()
{
	return "08";
}

void Day08::Parse()
{
	int height = m_FileContents.size()-1;
	int width = m_FileContents[0].size();
	m_Part1 += height * 2;
	m_Part1 += (width - 2) * 2;

	//for (int row = 1; row < m_FileContents.size() - 2; row++)
	//{
	//	for (int col = 1; col < m_FileContents[row].size() - 1; col++)
	//	{
	//		int curr = int(m_FileContents[row][col]) - 48;
	//		bool showing = true;

	//		// Part 1
	//		// Search above
	//		for (int above = row-1; above >= 0; above--)
	//		{
	//			//int val = int(m_FileContents[above][col]) - 48;
	//			if (int(m_FileContents[above][col]) - 48 >= curr)
	//			{
	//				showing = false;
	//				break;
	//			}
	//		}

	//		if (showing)
	//		{
	//			m_Part1++;
	//			continue;
	//		}
	//		showing = true;

	//		// Search below
	//		for (int below = row+1; below <= m_FileContents.size()-1; below++)
	//		{
	//			if (int(m_FileContents[below][col]) - 48 >= curr)
	//			{
	//				showing = false;
	//				break;
	//			}
	//		}

	//		if (showing)
	//		{
	//			m_Part1++;
	//			continue;
	//		}
	//		showing = true;

	//		// Search left
	//		for (int left = col-1; left >= 0; left--)
	//		{
	//			if (int(m_FileContents[row][left]) - 48 >= curr)
	//			{
	//				showing = false;
	//				break;
	//			}
	//		}

	//		if (showing)
	//		{
	//			m_Part1++;
	//			continue;
	//		}
	//		showing = true;
	//		
	//		// Search right
	//		for (int right = col + 1; right <= m_FileContents.size() - 1; right++)
	//		{
	//			if (int(m_FileContents[row][right]) - 48 >= curr)
	//			{
	//				showing = false;
	//				break;
	//			}
	//		}

	//		if (showing)
	//		{
	//			m_Part1++;
	//			continue;
	//		}
	//	}
	//}

	// Part 2
	for (int row = 1; row < m_FileContents.size() - 2; row++)
	{
		for (int col = 1; col < m_FileContents[row].size() - 1; col++)
		{
			int curr = int(m_FileContents[row][col]) - 48;
			int u{ 0 };
			int d{ 0 };
			int l{ 0 };
			int r{ 0 };
			int highest_score{ 0 };

			// Search above
			for (int above = row - 1; above >= 0; above--)
			{
				//int val = int(m_FileContents[above][col]) - 48;
				u++;
				if (int(m_FileContents[above][col]) - 48 >= curr)
				{
					break;
				}
			}

			// Search below
			for (int below = row + 1; below < m_FileContents.size() - 1; below++)
			{
				d++;
				if (int(m_FileContents[below][col]) - 48 >= curr)
				{
					break;
				}				
			}

			// Search left
			for (int left = col - 1; left >= 0; left--)
			{
				l++;
				if (int(m_FileContents[row][left]) - 48 >= curr)
				{
					break;
				}				
			}

			// Search right
			for (int right = col + 1; right < m_FileContents.size() - 1; right++)
			{
				r++;
				if (int(m_FileContents[row][right]) - 48 >= curr)
				{
					break;
				}				
			}

			unsigned int scenic_score = l * r * u * d;
			if (scenic_score > m_Part2)
			{
				m_Part2 = scenic_score;
			}
		}
	}
}