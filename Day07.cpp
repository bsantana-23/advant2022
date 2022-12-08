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
	string parent;
	std::vector<struct node> list;
	int size;
};

void Day07::Parse()
{
	string home{ '/' };
	string name{};
	string cmd{};
	std::vector<struct node> directory{};
	node curr_node{};
	node head{};

	for (int row = 0; row < m_FileContents.size(); row++)
	{
		if (row == m_FileContents.size() - 1)
		{
			cout << "l" << endl;
		}
		for (int col = 0; col < m_FileContents[row].size(); col++)
		{
			if (col == 0 && m_FileContents[row][col] == '$')
			{
				cmd = m_FileContents[row].substr(2, 2); 

				if (cmd == "cd")
				{
					name = m_FileContents[row].substr(5, m_FileContents[row].size()-5);
					
					if (curr_node.name == "")
					{
						node n;
						n.name = name;
						n.type = "dir";
						n.size = 0;
						curr_node = n;
						head = n;
					}

					if (name == home)
					{
						break;
					}
					else if (name == "..")
					{
						for (int i = 0; i < curr_node.list.size(); i++)
						{
							if (curr_node.parent == curr_node.list[i].name)
							{
								curr_node = curr_node.list[i];
								break;
							}
						}
						break;
					}
					else
					{
						for (int i = 0; i < curr_node.list.size(); i++)
						{
							if (name == curr_node.list[i].name)
							{
								curr_node = curr_node.list[i];
								break;
							}
							else 
							{
								cout << "node not in list" << endl;
							}
						}
						break;
					}
				}
				else if (cmd == "ls")
				{
					int i = row+1;
					for (; i < m_FileContents.size() - 1 && m_FileContents[i][0] != '$'; i++)
					{
						// if it ls a dir
						if (m_FileContents[i][0] == 'd')
						{
							name = m_FileContents[i].substr(4, m_FileContents[i].size() - 4);
							
							node n;
							n.name = name;
							n.type = "dir";
							n.size = 0;
							n.parent = curr_node.name;

							curr_node.list.push_back(n);
						}

						// if it ls a file
						else
						{
							int idx = 0;
							for (; m_FileContents[i][idx] != ' '; idx++)
							{

							}
							node n;
							n.type = "file";
							n.size = stoi(m_FileContents[i].substr(0, idx));
							n.name = m_FileContents[i].substr(idx, m_FileContents[i].size() - idx);
							n.parent = curr_node.name;

							curr_node.list.push_back(n);
						}
					}
					row = i-1;
					break;
				}
			}
		}
		cout << m_FileContents[row] << endl;
	}
}