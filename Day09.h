#include "Day.h"

#pragma once

class Day09 : public Day
{
public:
	/*!
	 * @brief Constructor
	 */
	Day09();

	/*!
	 * @brief Destructor
	 */
	~Day09();

	/*!
	 * @brief Parse through the file contents according the the problem statement
	 */
	void Parse();

	/*!
	 * @brief Gets the Day as an integer
	 * @return the day as an integer
	 */
	int GetDayInt();

	/*!
	 * @brief Gets the Day as a string
	 * @return the day as a string
	 */
	std::string GetDayString();
private:
	void AdjustTail(std::pair<int, int> head, std::pair<int, int>& tail);
	void AdjustLink(std::pair<int, int> head, std::vector<std::pair<int, int>> &link, std::map<std::pair<int, int>, int> &visited);

};