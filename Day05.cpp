#include "Day05.h"

using namespace std;

Day05::Day05()
	: Day(GetDayString())
{
	Parse();
}

Day05::~Day05()
{

}

int Day05::GetDayInt()
{
	return 13;
}

string Day05::GetDayString()
{
	return "05";
}

void Day05::Parse()
{

	// Initialize all the stacks
	std::vector<char> stack1{};
	std::vector<char> stack2{};
	std::vector<char> stack3{};
	std::vector<char> stack4{};
	std::vector<char> stack5{};
	std::vector<char> stack6{};
	std::vector<char> stack7{};
	std::vector<char> stack8{};
	std::vector<char> stack9{};

	std::map<int, std::vector<char>> stacks = {
		{1, stack1},
		{2, stack2},
		{3, stack3},
		{4, stack4},
		{5, stack5},
		{6, stack6},
		{7, stack7},
		{8, stack8},
		{9, stack9}
	};

	// Burn the boats
	int line_of_stacks = 8;

	cout << m_FileContents[line_of_stacks] << endl;

	for (int col = 0; col < m_FileContents[line_of_stacks].size(); col++)
	{
		if (m_FileContents[line_of_stacks][col] != ' ')
		{
			for (int row = line_of_stacks-1; row >= 0 && m_FileContents[row][col] != ' '; row--)
			{
				int val = int(m_FileContents[line_of_stacks][col] - '0');
				auto stack = stacks.find(val);
				stack->second.push_back(m_FileContents[row][col]);
			}
		}
	}

	int col_how_many{ 5 };
	int how_many{};
	int col_from{ 12 };
	int from{};
	int to{};
	
	// Get important values, then get to work!

	// Part 1
	//for (int line = 10; line < m_FileContents.size() - 1; line++)
	//{
	//	how_many = stoi(m_FileContents[line].substr(col_how_many, 2));
	//	from = stoi(m_FileContents[line].substr(col_from, 2));
	//	to = stoi(m_FileContents[line].substr(m_FileContents[line].size() - 1, 1));

	//	while (how_many > 0)
	//	{
	//		auto from_stack = stacks.find(from);
	//		auto to_stack = stacks.find(to);
	//		char c = from_stack->second.back(); // Get element
	//		from_stack->second.pop_back(); // Remove element
	//		to_stack->second.push_back(c); // Push element
	//		how_many--;
	//	}
	//}

	// Part 2
	for (int line = 10; line < m_FileContents.size() - 1; line++)
	{
		how_many = stoi(m_FileContents[line].substr(col_how_many, 2));
		from = stoi(m_FileContents[line].substr(col_from, 2));
		to = stoi(m_FileContents[line].substr(m_FileContents[line].size() - 1, 1));
		auto from_stack = stacks.find(from);
		auto to_stack = stacks.find(to);
		int left = how_many;
		while (left > 0)
		{			
			char c = from_stack->second.at(from_stack->second.size() - left); // Get element
			to_stack->second.push_back(c); // Push element

			if (left == 1)
			{
				from_stack->second.resize(from_stack->second.size() - how_many); // Remove element(s)
			}
			left--;			
		}
	}

	cout << m_FileContents[line_of_stacks] << endl;

	// Find final answer
	string ans{};
	for (auto& x : stacks) {
		ans.push_back(x.second.back());
	}



	cout << ans << endl;
}