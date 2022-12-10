#include "Day10.h"

using namespace std;

Day10::Day10()
	: Day(GetDayString())
{
	Parse();
}

Day10::~Day10()
{

}

int Day10::GetDayInt()
{
	return 13;
}

string Day10::GetDayString()
{
	return "10";
}

void Day10::Parse()
{
	int register_x{ 1 };
	int cycle{ 1 };
	int signal_strength{ 0 };
	int target_cycle = 20;
	int crt_counter{ 0 };
	int sprite_pos = { 1 };

	for (int row = 0; row < m_FileContents.size() - 1; row++)
	{
		string instruction = m_FileContents[row].substr(0, 4);

		if (instruction == "addx")
		{
			int val = stoi(m_FileContents[row].substr(5, m_FileContents[row].size() - 5));
			int temp = register_x + val;

			for (int i = 0; i < 2; i++)
			{
				if ((register_x - 1 <= crt_counter) && (crt_counter <= register_x + 1))
				{
					if (crt_counter >= 40)
					{
						crt_counter = 0;
						cout << "" << endl;
					}
					cout << "#";
					crt_counter++;
				}				
				else
				{
					if (crt_counter >= 40)
					{
						crt_counter = 0;
						cout << "" << endl;
					}
					cout << ".";
					crt_counter++;
				}
			}

			// Part 1
			//if(target_cycle <= 220)
			//{ 
			//	if (cycle == target_cycle || cycle == target_cycle-1)
			//	{
			//		//cout << "adding for target cycle " << target_cycle << endl;
			//		signal_strength += (target_cycle * register_x);
			//		target_cycle += 40;
			//	}
			//}
			//cycle += 2;


			register_x += val;
		}
		else if (instruction == "noop")
		{
			// Part 1
			/*if (cycle == target_cycle)
			{
				signal_strength += (target_cycle * register_x);
			}
			cycle += 1;*/

			// Part 2
			if ((register_x - 1 <= crt_counter) && (crt_counter <= register_x + 1))
			{
				if (crt_counter >= 40)
				{
					crt_counter = 0;
					cout << "" << endl;
				}
				cout << "#";
				crt_counter++;
			}
			else
			{
				if (crt_counter >= 40)
				{
					crt_counter = 0;
					cout << "" << endl;
				}
				cout << ".";
				crt_counter++;
			}
		}
		else
		{
			cout << "who you?" << endl;
		}
	}
	m_Part1 = signal_strength;
}