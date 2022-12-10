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
	struct node *parent;
	std::vector<struct node> list;
	int size;
};

struct directory_tree
{
	string name;
	string type; // dir, file
	std::vector<struct directory_tree> parent;
	std::vector<struct directory_tree> list;
	int size;
};

void Day07::Parse()
{
	string home{ '/' };
	string name{};
	string cmd{};
	std::vector<struct directory_tree> directory{};
	struct node *curr_node = new node;
	//directory_tree n;
	struct node *head{};
	struct node n;

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
					
					if (curr_node->name == "")
					{						
						n.name = name;
						n.type = "dir";
						n.size = 0;
						n.parent = NULL;
						curr_node = &n;
						head = &n;
					}

					if (name == home)
					{
						break;
					}
					else if (name == "..")
					{
						curr_node = (curr_node->parent);
						/*for (int i = 0; i < curr_node.list.size(); i++)
						{
							if (curr_node.parent.name == curr_node.list[i].name)
							{
								curr_node = curr_node.list[i];
								break;
							}
						}*/
						break;
					}
					else
					{
						for (int i = 0; i < curr_node->list.size(); i++)
						{
							if (name == curr_node->list[i].name)
							{
								curr_node = &(curr_node->list[i]);
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
							struct node n;
							n.name = name;
							n.type = "dir";
							n.size = 0;
							//if(n.parent.size() > 0) n.parent.pop_back();
							//n.parent.push_back(curr_node);
							n.parent = curr_node;
							curr_node->list.push_back(n);
						}

						// if it ls a file
						else
						{
							int idx = 0;
							for (; m_FileContents[i][idx] != ' '; idx++)
							{

							}
							struct node n;
							n.type = "file";
							n.size = stoi(m_FileContents[i].substr(0, idx));
							n.name = m_FileContents[i].substr(idx, m_FileContents[i].size() - idx);
							/*if (n.parent.size() > 0) n.parent.pop_back();
							n.parent.push_back(curr_node);*/
							n.parent = curr_node;
							curr_node->list.push_back(n);
						}
					}
					row = i-1;
					break;
				}
			}
		}
		cout << m_FileContents[row] << endl;
	}
	cout << " Finished building tree" << endl;
	
	m_Part2 = 100000000;
	int used_space{ countSize(*head) };
	
	// Part 2
	int total_space{ 70000000 };
	int update_size{ 30000000 };
	int free_space{ total_space - used_space };
	int need_space{ update_size - free_space };
	DeleteSmallest(*head, need_space);
	
}
int Day07::countSize(struct node &tree)
{
	unsigned int used_space{ 0 };

	for (struct node file : tree.list)
	{
		if (file.type == "file")
		{
			// Part 1
			/*if (used_space > 100000)
			{
				continue;
			}
			else
			{
				used_space += file.size;
			}*/

			// Part 2
			used_space += file.size;
		}
		else if (file.type == "dir")
		{
			used_space += countSize(file);
		}
		else
		{
			cout << "who the hell are you" << endl;
		}
	}

	if (used_space <= 100000)
	{
		m_Part1 += used_space;
	}

	return used_space;
}

int Day07::DeleteSmallest(struct node &tree, int diff)
{
	unsigned int used_space{ 0 };
	
	for (struct node file : tree.list)
	{
		if (file.type == "file")
		{
			used_space += file.size;
		}
		else if (file.type == "dir")
		{
			used_space += DeleteSmallest(file, diff);
		}
		else
		{
			cout << "who the hell are you" << endl;
		}
	}

	if (used_space >= diff)
	{
		if (used_space < m_Part2)
		{
			m_Part2 = used_space;
		}
	}

	return used_space;
}
