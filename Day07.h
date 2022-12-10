#include "Day.h"

#pragma once

class Day07 : public Day
{
public:
	/*!
	 * @brief Constructor
	 */
	Day07();

	/*!
	 * @brief Destructor
	 */
	~Day07();

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
	int countSize(struct node& tree);
	int DeleteSmallest(struct node& tree, int diff);
	std::vector<int> delete_dirs;
};