#include "Day09.h"

using namespace std;

Day09::Day09()
	: Day(GetDayString())
{
	Parse();
}

Day09::~Day09()
{

}

int Day09::GetDayInt()
{
	return 13;
}

string Day09::GetDayString()
{
	return "09";
}

void Day09::Parse()
{
	std::pair<int, int> point[10]{ };
	std::pair<int, int> tail{ 0,0 };
	std::map<pair<int,int>, int> visited{};
	std::map<pair<int, int>, int> visited_2{};

	for (int row = 0; row < m_FileContents.size() - 1; row++)
	{
		char direction = m_FileContents[row][0];
		int how_many = stoi(m_FileContents[row].substr(2, m_FileContents[row].size() - 2));

		for (int i = 0; i < how_many; i++)
		{
			// Move the head
			if (direction == 'U')
			{
				point[0].second++;
			}
			else if (direction == 'D')
			{
				point[0].second--;
			}
			else if (direction == 'L')
			{
				point[0].first--;
			}
			else if (direction == 'R')
			{
				point[0].first++;
			}

			for (int i = 0; i < 9; i++ )
			{

				AdjustTail(point[i], point[i+1]);
				visited.insert(pair<pair<int,int>,int>(pair<int,int>(point[1].first, point[1].second), 1));
				visited_2.insert(pair<pair<int, int>, int>(pair<int, int>(point[9].first, point[9].second), 1));
			}
			//int concatenated = stoi(to_string(tail.first).append(to_string(tail.second)));
		}
	}
	m_Part1 = visited.size();
	m_Part2 = visited_2.size();


	//// Part 2
	//struct node
	//{
	//	struct node* prev;
	//	pair<int, int> pos{ 0,0 };
	//	struct node* next;
	//};

	////std::pair<int, int> head{ 0,0 };
	////std::pair<int, int> tail{ 0,0 };
	////struct node* all_nodes = NULL;
	//pair<int, int> head {0,0};
	//pair<int,int> node_1 {0,0};
	//pair<int,int> node_2 {0,0};
	//pair<int,int> node_3 {0,0};
	//pair<int,int> node_4 {0,0};
	//pair<int,int> node_5 {0,0};
	//pair<int,int> node_6 {0,0};
	//pair<int,int> node_7 {0,0};
	//pair<int,int> node_8 {0,0};
	//pair<int,int> node_9 {0,0};

	//vector<pair<int, int>> all_nodes;
	//all_nodes.push_back(head);
	//all_nodes.push_back(node_1);
	//all_nodes.push_back(node_2);
	//all_nodes.push_back(node_3);
	//all_nodes.push_back(node_4);
	//all_nodes.push_back(node_5);
	//all_nodes.push_back(node_6);
	//all_nodes.push_back(node_7);
	//all_nodes.push_back(node_8);
	//all_nodes.push_back(node_9);

	//pair<int, int> curr_node{};
	//std::map<pair<int, int>, int> visited{};

	//for (int row = 0; row < m_FileContents.size() - 1; row++)
	//{
	//	char direction = m_FileContents[row][0];
	//	int how_many = stoi(m_FileContents[row].substr(2, m_FileContents[row].size() - 2));

	//	for (int i = 0; i < how_many; i++)
	//	{
	//		// Move the head
	//		if (direction == 'U')
	//		{
	//			head.second++;
	//		}
	//		else if (direction == 'D')
	//		{
	//			head.second--;
	//		}
	//		else if (direction == 'L')
	//		{
	//			head.first--;
	//		}
	//		else if (direction == 'R')
	//		{
	//			head.first++;
	//		}

	//		AdjustLink(head, all_nodes, visited);
	//		//int concatenated = stoi(to_string(tail.first).append(to_string(tail.second)));
	//		//visited.insert(pair<pair<int, int>, int>(pair<int, int>(tail.first, tail.second), 1));
	//	}
	//}
	//m_Part2 = visited.size();
}

void Day09::AdjustLink(pair<int, int> head, vector<pair<int, int>> &link, map<pair<int, int>, int> &visited)
{
	// Adjust the tail
	for (pair<int, int> curr : link)
	{
		// Check if neighboring
		int delta_x = head.first - curr.first;
		int delta_y = head.second - curr.second;

		if (fabs(delta_x) > 1 || fabs(delta_y) > 1)
		{
			// up/down/left/right moves
			if (delta_x == 0 && delta_y > 0)
			{
				curr.second++;
			}
			if (delta_x == 0 && delta_y < 0)
			{
				curr.second--;
			}
			if (delta_y == 0 && delta_x > 0)
			{
				curr.first++;
			}
			if (delta_y == 0 && delta_x < 0)
			{
				curr.first--;
			}

			//// diagnal moves
			//if (delta_x < 0 && delta_y > 0)
			//{
			//	curr.first--;
			//	curr.second++;
			//}
			//else if (delta_x < 0 && delta_y < 0)
			//{
			//	curr.first--;
			//	curr.second--;
			//}
			//else if (delta_x > 0 && delta_y > 0)
			//{
			//	curr.first++;
			//	curr.second++;
			//}
			//else if (delta_x > 0 && delta_y < 0)
			//{
			//	curr.first++;
			//	curr.second--;
			//}
		}
		else
		{
			// do nothing
			cout << "neighboring" << endl;
		}
		visited.insert(pair<pair<int, int>, int>(pair<int, int>(curr.first, curr.second), 1));
		head = curr;
	}
}

// Part 1
void Day09::AdjustTail(std::pair<int, int> head, std::pair<int, int> &tail)
{

	// Adjust the tail

	// Check if neighboring
	int delta_x = head.first - tail.first;
	int delta_y = head.second - tail.second;

	if (fabs(delta_x) > 1 || fabs(delta_y) > 1)
	{
		// up/down/left/right moves
		if (delta_x == 0 && delta_y > 0)
		{
			tail.second++;
		}
		else if (delta_x == 0 && delta_y < 0)
		{
			tail.second--;
		}
		if (delta_y == 0 && delta_x > 0)
		{
			tail.first++;
		}
		else if (delta_y == 0 && delta_x < 0)
		{
			tail.first--;
		}

		// diagnal moves
		if (delta_x < 0 && delta_y > 0)
		{
			tail.first--;
			tail.second++;
		}
		else if (delta_x < 0 && delta_y < 0)
		{
			tail.first--;
			tail.second--;
		}
		else if (delta_x > 0 && delta_y > 0)
		{
			tail.first++;
			tail.second++;
		}
		else if (delta_x > 0 && delta_y < 0)
		{
			tail.first++;
			tail.second--;
		}
	}
	else
	{
		// do nothing
		cout << "neighboring" << endl;
	}
}