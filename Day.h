#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <chrono>
#include <map>
#include <bitset>

#pragma once

class Day
{
public:
	/*!
	 * @brief Constructor
	 */
	Day(std::string day);

	/*!
	 * @brief Destructor
	 */
	~Day();

	/*!
	 * @brief Parse through the file contents according the the problem statement
	 */
	virtual void Parse() = 0;

	/*!
	 * @brief Gets the Day as an integer
	 * @return the day as an integer
	 */
	virtual int GetDayInt() = 0;

	/*!
	 * @brief Gets the Day as a string
	 * @return the day as a string
	 */
	virtual std::string GetDayString() = 0;

	/*! 
	 * @brief Read in text from the given file and store the lines in m_FileContents 
	 * @param name [in] the name of the file
	 */
	void ReadIn(std::string name);

	/*!
	 * @brief Parse intergers from a given line of text using the given deliminator
	 * @param line [in] line of text to parse
	 * @param delim [in] the deliminator
	 * @return a vector of ints that was parsed
	 */
	std::vector<int> ParseInt(std::string line, char delim);
	
	/*!
	 * @brief Parse text from a given line of text using the given deliminator
	 * @param line [in] line of text to parse
	 * @param delim [in] the deliminator
	 * @return a vector of strings that was parsed
	 */
	std::vector<std::string> ParseString(std::string line, char delim);

	/*!
	 * @brief Makes a 2d map for the given template
	 * @param x [in] x size
	 * @param y [in] y size
	 * @param map [out] the empty map that was produced
	 */
	template<typename T>
	void Make2dMap(int x, int y, T**& map);

protected:
	/// The contents of the input file
	std::vector<std::string> m_FileContents;

	/// Part 1 answer
	int m_Part1;

	/// Part 2 answer
	unsigned long long int m_Part2;

	/// start time for execution
	std::chrono::steady_clock::time_point start;

	/// stop time for execution
	std::chrono::steady_clock::time_point stop;
};