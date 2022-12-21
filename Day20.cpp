#include "Day20.h"

using namespace std;

Day20::Day20()
	: Day(GetDayString())
{
	Parse();
}

Day20::~Day20()
{

}

int Day20::GetDayInt()
{
	return 20;
}

string Day20::GetDayString()
{
	return "20";
}

void Day20::Parse()
{
	if (__cplusplus == 201703L) std::cout << "C++17\n";
	else if (__cplusplus == 201402L) std::cout << "C++14\n";
	else if (__cplusplus == 201103L) std::cout << "C++11\n";
	else if (__cplusplus == 199711L) std::cout << "C++98\n";
	else std::cout << "pre-standard C++\n";
	
	struct node
	{
		int value{ 0 };
		struct node *next{ nullptr };
		struct node *prev{ nullptr };
		struct node *orig{ nullptr };
	};

	node main_list;
	node* curr_node = &main_list;
	node* head = &main_list;
	node* zero = nullptr;

	curr_node->value = stoi(m_FileContents[0].substr(0, m_FileContents[0].size()));
	int size{};

	for (int row = 1; row < m_FileContents.size() - 1; row++)
	{
		/*int val = stoi(m_FileContents[row].substr(0, m_FileContents[row].size()));
		original.push_back(val);
		list_to_play.push_back(row);*/
		
		node* new_node = new node();
		new_node->value = stoi(m_FileContents[row].substr(0, m_FileContents[row].size()));
		new_node->prev = curr_node;

		curr_node->next = new_node;
		curr_node->orig = new_node;
		curr_node = curr_node->next;

		if (new_node->value == 0)
		{
			zero = new_node;
		}

		size = row + 1;
	}

	head->prev = curr_node;
	curr_node->next = head;
	curr_node->orig = nullptr;
	struct node *to_switch = &main_list;

	while (true)
	{
		int how_many = to_switch->value;

		if (how_many < 0)
		{
			how_many = size % how_many; //(((size % how_many) + how_many) % how_many);
			//how_many--;
		}

		struct node* curr = to_switch;

		if (how_many == 0)
		{
			zero = curr;
		}


		while (how_many)
		{
			if (how_many > 0)
			{
				curr = curr->next;
				how_many--;
			}
			else
			{
				curr = curr->prev;
				how_many++;
			}

			if (how_many == 0)
			{
				to_switch->next->prev = to_switch->prev;
				to_switch->prev->next = to_switch->next;

				to_switch->next = curr->next;
				to_switch->prev = curr->next->prev;
				to_switch->next->prev = to_switch;
				to_switch->prev->next = to_switch;

				/*curr->next = temp.prev->next;
				curr->prev = temp.prev;*/

				/*temp->next->prev = temp->prev;
				temp->prev->next = temp->next;*/
			}
		}

		to_switch = to_switch->orig;

		if (to_switch == nullptr)
		{
			break;
		}
	}

	int how_many = 3000;
	struct node* curr = zero;

	while (how_many)
	{
		curr = curr->next;
		how_many--;

		if (how_many == 0 || how_many == 1000 || how_many == 2000)
		{				
			m_Part1 += curr->value;			
		}
	}


	//for (int i = 0, int counter = 0; counter < 3000; i++, counter++)
	//{
	//	if (i >= original.size())
	//	{
	//		i = 0;
	//	}

	//	int how_much = original[i];

	//	if (how_much > 0)
	//	{
	//		// handle
	//	}
	//	else if (how_much == 0)
	//	{
	//		// do nothing
	//		continue;
	//	}
	//	else
	//	{
	//		for (int j = 0; j < list_to_play.size(); j++)
	//		{
	//			if (list_to_play[j] == i)
	//			{
	//				if (j + how_much >= list_to_play.size())
	//				{
	//					list_to_play.
	//				}
	//			}
	//		}
	//	}
	//}
}
