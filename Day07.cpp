#include "Day07.h"

using namespace std;

Day07::Day07()
	: Day(GetDayString())
{
	Parse();
}

Day07::~Day07()
{

}

int Day07::GetDayInt()
{
	return 13;
}

string Day07::GetDayString()
{
	return "07";
}

struct node
{
	string name;
	string type; // dir, file
	std::vector<struct node> list;
	int size;
};

void Day07::Parse()
{

	string name{};
	string cmd{};
	std::vector<struct node> directory{};

	for (int row = 0; row < m_FileContents.size(); row++)
	{
		for (int col = 0; col < m_FileContents[row].size(); col++)
		{
			if (col == 0 && m_FileContents[row][col] == '$')
			{
				cmd = m_FileContents[row].substr(2, 2); 

				if (cmd == "cd")
				{
					name = m_FileContents[row].substr(5, m_FileContents[row].size()-5);
					node n;
					n.name = name;
					n.type = "dir";
					n.size = 0;
				}
				else if (cmd == "ls")
				{

				}
			}
		}
	}
}
