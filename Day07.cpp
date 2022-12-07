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
	struct node *list;
	int size;
};

void Day07::Parse()
{

}