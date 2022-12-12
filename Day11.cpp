#include "Day11.h"

using namespace std;

Day11::Day11()
	: Day(GetDayString())
{
	Parse();
}

Day11::~Day11()
{

}

int Day11::GetDayInt()
{
	return 13;
}

string Day11::GetDayString()
{
	return "11";
}

void Day11::Parse()
{
	struct Monkey
	{
		int num{};
		vector<unsigned int> items;
		string op{};
		string worry_level{};
		int test{};
		int if_true{};
		int if_false{};
		unsigned int counter{ 0 };
	};

	vector<struct Monkey> monkeys{};
	int i = 0;
	for (int row = 0; row < m_FileContents.size() - 1; row++)
	{
		if (m_FileContents[row].substr(0, 6) == "Monkey")
		{
			int idx = 18;
			struct Monkey m;
			m.num = i++;
			row++;

			// Get starting items.num
			while (idx < m_FileContents[row].size())
			{
				int val = stoi(m_FileContents[row].substr(idx, 2));
				m.items.push_back(val);
				idx += 4;
			}
			row++;

			// Get operation and worry level
			idx = 23;
			m.op = m_FileContents[row].substr(idx, 1);
			idx += 2;
			m.worry_level = m_FileContents[row].substr(idx, m_FileContents[row].size()-idx); //m.worry_level 
			row++;

			// Get test value
			idx = 21;
			m.test = stoi(m_FileContents[row].substr(idx, m_FileContents[row].size() - idx));
			row++;

			// Get if true value
			idx = 29;
			m.if_true = stoi(m_FileContents[row].substr(idx, m_FileContents[row].size() - idx));
			row++;

			// Get if false value
			idx++;
			m.if_false = stoi(m_FileContents[row].substr(idx, m_FileContents[row].size() - idx));
			row++;

			monkeys.push_back(m);
		}
	}

	// Part 1
	//int rounds = 20;
	// Part 2
	int rounds = 10000;
	for (int round = 0; round < rounds; round++)
	{
		for (struct Monkey &monkey : monkeys)
		{
			if (monkey.items.empty())
			{
				continue;
			}

			for (unsigned int item : monkey.items)
			{				
				monkey.counter++;

				// Inspect the item
				if (monkey.op == "+")
				{									
					item = item + stoi(monkey.worry_level);
				}
				else if (monkey.op == "*")
				{
					if (monkey.worry_level[0] == 'o')
					{
						item *= item;
					}
					else
					{
						item *= stoi(monkey.worry_level);
					}
				}
				else
				{
					cout << "who you?" << endl;
				}

				// Divide by 3 and floor it
				//item = floor(item / 3);

				// Test it
				if (item % monkey.test == 0)
				{
					monkeys[monkey.if_true].items.push_back(item);
				}
				else
				{
					monkeys[monkey.if_false].items.push_back(item);
				}
			}
			monkey.items.clear();
		}
	}

	unsigned long long top{ 0 };
	unsigned long long second{ 0 };

	for (struct Monkey monkey : monkeys)
	{
		if (monkey.counter > top)
		{
			top = monkey.counter;
		}
	}
	for (struct Monkey monkey : monkeys)
	{
		if (monkey.counter == top)
		{
			continue;
		}
		if (monkey.counter > second)
		{
			second = monkey.counter;
		}
	}

	unsigned long long monkey_business = top * second;
	m_Part1 = monkey_business;
}