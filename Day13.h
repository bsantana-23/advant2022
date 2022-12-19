#include "Day.h"

#pragma once

class Day13 : public Day
{
public:
	/*!
	 * @brief Constructor
	 */
	Day13();

	/*!
	 * @brief Destructor
	 */
	~Day13();

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

	std::vector<int> FindPair(std::string &row, std::vector<std::vector<int>>& main_list);
};