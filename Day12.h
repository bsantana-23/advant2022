#include "Day.h"

#pragma once

class Day12 : public Day
{
public:
	/*!
	 * @brief Constructor
	 */
	Day12();

	/*!
	 * @brief Destructor
	 */
	~Day12();

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
	bool SearchPath(std::pair<int, int> pos, std::pair<int, int> end, int& steps, std::map<std::pair<int, int>, int>& visited);
};