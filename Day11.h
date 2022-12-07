#include "Day.h"

#pragma once

class Day11 : public Day
{
public:
	/*!
	 * @brief Constructor
	 */
	Day11();

	/*!
	 * @brief Destructor
	 */
	~Day11();

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
};