#include "Day02.h"

using namespace std;

Day02::Day02()
	: Day(GetDayString())
{
	Parse();
}

Day02::~Day02()
{

}

int Day02::GetDayInt()
{
	return 13;
}

string Day02::GetDayString()
{
	return "02";
}

void Day02::Parse()
{
	std::map<char, std::string> plays =
	{
		{'A', "Rock"},
		{'B', "Paper"},
		{'C', "Scissors"},
		{'X', "Rock"},
		{'Y', "Paper"},
		{'Z', "Scissors"}
	};

	std::map<string, int> score =
	{
		{"Rock", 1},
		{"Paper", 2},
		{"Scissors", 3},
		{"Lost", 0},
		{"Draw", 3},
		{"Won", 6}
	};

	int game_score = 0;


	// Part 1
	for (int i = 0; i < m_FileContents.size() - 1; i++)
	{
		string outcome = "";
		string opponents_play = plays.find(m_FileContents[i][0])->second;
		string your_play = plays.find(m_FileContents[i][2])->second;
		string your_play_p2 = "";

		// Losing scenarios
		if ((your_play == "Rock" && opponents_play == "Paper") ||
			(your_play == "Paper" && opponents_play == "Scissors") ||
			(your_play == "Scissors" && opponents_play == "Rock")) 
		{
			outcome = "Lost";
		}

		// Winning scenarios
		else if ((your_play == "Scissors" && opponents_play == "Paper") ||
			(your_play == "Rock" && opponents_play == "Scissors") ||
			(your_play == "Paper" && opponents_play == "Rock"))
		{
			outcome = "Won";
		}


		// Draw scenarios
		else if (your_play == opponents_play)
		{
			outcome = "Draw";
		}

		game_score += (score.find(outcome)->second + score.find(your_play)->second);
	}
	m_Part1 = game_score;


	// Part 2
	std::map<char, string> part2 =
	{
		{'X', "Lose"},
		{'Y', "Draw" },
		{'Z', "Win" }
	};

	game_score = 0; // reset score

	for (int i = 0; i < m_FileContents.size() - 1; i++)
	{
		string outcome = "";
		string opponents_play = plays.find(m_FileContents[i][0])->second;
		string your_play = "";

		// Lose
		if (m_FileContents[i][2] == 'X') {
			if (opponents_play == "Rock") your_play = "Scissors";
			else if (opponents_play == "Paper") your_play = "Rock";
			else if (opponents_play == "Scissors") your_play = "Paper";
			outcome = "Lost";
		}

		// Draw
		if (m_FileContents[i][2] == 'Y') {
			if (opponents_play == "Rock") your_play = "Rock";
			else if (opponents_play == "Paper") your_play = "Paper";
			else if (opponents_play == "Scissors") your_play = "Scissors";
			outcome = "Draw";
		}

		// Win
		if (m_FileContents[i][2] == 'Z') {
			if (opponents_play == "Rock") your_play = "Paper";
			else if (opponents_play == "Paper") your_play = "Scissors";
			else if (opponents_play == "Scissors") your_play = "Rock";
			outcome = "Won";
		}


		game_score += (score.find(outcome)->second + score.find(your_play)->second);
	}
	m_Part2 = game_score;
}