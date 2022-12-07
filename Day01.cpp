#include "Day01.h"

using namespace std;

Day01::Day01()
	: Day(GetDayString())
{
	Parse();
}

Day01::~Day01()
{

}

int Day01::GetDayInt()
{
	return 1;
}

string Day01::GetDayString()
{
	return "01";
}

void Day01::Parse()
{
	std::map<int, int, greater<int>> cals_per_elf = {};
	int elf = 1;
	int calories = 0;
	int daddy_elf = 0;
	int max_cals = 0;

	for (int i = 0; i < m_FileContents.size() - 1; i++)
	{
		if (m_FileContents[i] == "" || i == m_FileContents.size() - 2)
		{
			cals_per_elf.emplace(calories, elf);
			if (calories > max_cals)
			{
				max_cals = calories;
				daddy_elf = elf;
			}
			calories = 0; 
			elf += 1; // Let's count the next elf, yay!
		}
		else
		{
			calories += stoi(m_FileContents[i]);
		}
	}
	m_Part1 = max_cals;
	cout << "Fattest elf is Elf " << daddy_elf << ", carrying " << max_cals << " calories!" << endl;


	// Part 2
	int idx = 0;
	for (auto& x : cals_per_elf)
	{
		if (idx > 2) break;
		m_Part2 += x.first;
		idx++;
	}
}