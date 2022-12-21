#include "Day18.h"

using namespace std;

Day18::Day18()
	: Day(GetDayString())
{
	Parse();
}

Day18::~Day18()
{

}

int Day18::GetDayInt()
{
	return 18;
}

string Day18::GetDayString()
{
	return "18";
}

void Day18::Parse()
{

	vector<Cube> cubes{};

	vector<Cube> pockets_of_air{};


	for (int row = 0; row < m_FileContents.size() - 1; row++)
	{
		Cube cube;
		int idx{ 0 };
		int grab{ 1 };
		if (m_FileContents[row][idx + 2] == ',')
		{
			grab = 2;
		}
		cube.x = stoi(m_FileContents[row].substr(idx, grab));
		
		idx += (grab + 1);		
		grab = 1;
		if (m_FileContents[row][idx + 2] == ',')
		{
			grab = 2;
		}

		cube.y = stoi(m_FileContents[row].substr(idx, grab));
		idx += (grab + 1);
		grab = 2;
		if (m_FileContents[row][idx + 1] == '\0')
		{
			grab = 1;
		}

		cube.z = stoi(m_FileContents[row].substr(idx, grab));

		cubes.push_back(cube);

		Cube air1;
		air1.x = cube.x + 1;
		air1.y = cube.y;
		air1.z = cube.z;
		Cube air2;
		air2.x = cube.x - 1;
		air2.y = cube.y;
		air2.z = cube.z;
		Cube air3;
		air3.x = cube.x;
		air3.y = cube.y + 1;
		air3.z = cube.z;
		Cube air4;
		air4.x = cube.x;
		air4.y = cube.y - 1;
		air4.z = cube.z;
		Cube air5;
		air5.x = cube.x;
		air5.y = cube.y;
		air5.z = cube.z + 1;
		Cube air6;
		air6.x = cube.x;
		air6.y = cube.y;
		air6.z = cube.z - 1;

		vector<Cube> all_air{};
		all_air.push_back(air1);
		all_air.push_back(air2);
		all_air.push_back(air3);
		all_air.push_back(air4);
		all_air.push_back(air5);
		all_air.push_back(air6);

		for (Cube air : all_air)
		{
			if (pockets_of_air.empty())
			{
				pockets_of_air.push_back(air);
			}
			else
			{
				bool exists = false;
				for (Cube c : pockets_of_air)
				{
					if (c.x == air.x &&
						c.y == air.y &&
						c.z == air.z)
					{
						exists = true;
						break;
					}
				}
				if (!exists)
				{
					pockets_of_air.push_back(air);
				}
			}
		}
		//pockets_of_air.insert(pair<Cube, int>(air1, 6));
		//pockets_of_air.insert(pair<Cube, int>(air2, 6));
		//pockets_of_air.insert(pair<Cube, int>(air3, 6));
		//pockets_of_air.insert(pair<Cube, int>(air4, 6));
		//pockets_of_air.insert(pair<Cube, int>(air5, 6));
		//pockets_of_air.insert(pair<Cube, int>(air6, 6));
	}

	for (Cube &cube1 : cubes)
	{
		for (Cube &cube2 : cubes)
		{
			if (cube1.x == cube2.x &&
				cube1.y == cube2.y &&
				cube1.z == cube2.z)
			{
				continue;
			}

			// Check if in same plane 
			if (cube1.x == cube2.x && cube1.y == cube2.y)
			{
				// Check if adjacent
				if (cube1.z == cube2.z + 1 || cube1.z == cube2.z - 1)
				{
					cube1.sides_uncovered--;
					//cube2.sides_uncovered--;
				}
			}
			else if (cube1.x == cube2.x && cube1.z == cube2.z)
			{
				// Check if adjacent
				if (cube1.y == cube2.y + 1 || cube1.y == cube2.y - 1)
				{
					cube1.sides_uncovered--;
					//cube2.sides_uncovered--;
				}
			}
			else if (cube1.y == cube2.y && cube1.z == cube2.z)
			{
				// Check if adjacent
				if (cube1.x == cube2.x + 1 || cube1.x == cube2.x - 1)
				{
					cube1.sides_uncovered--;
					//cube2.sides_uncovered--;
				}
			}			
		}
	}
	for (Cube cube : cubes)
	{
		m_Part1 += cube.sides_uncovered;
	}


	// Part 2
	m_Part2 = m_Part1;


	/*for (int i = 0; i < pockets_of_air.size(); i++)
	{
		Cube air = pockets_of_air[i];
		for (Cube c : cubes)
		{
			if (c.x == air.x &&
				c.y == air.y &&
				c.z == air.z)
			{
				pockets_of_air.erase(pockets_of_air.begin() + i);
				i--;
				break;
			}
		}
	}*/

	for (Cube& air : pockets_of_air)
	{
		BoundSearch(air, cubes);
		bool is_pocket = true;
		for (Cube& cube : cubes)
		{
			if (air.x == cube.x &&
				air.y == cube.y &&
				air.z == cube.z)
			{
				is_pocket = false;
				break;
			}

			// XY plane 
			if (air.x == cube.x && air.y == cube.y)
			{
				// Check if adjacent
				if (air.z == cube.z + 1 || air.z == cube.z - 1)
				{
					air.sides_uncovered--;
					//cube2.sides_uncovered--;
				}
			}
			// XZ plane 
			else if (air.x == cube.x && air.z == cube.z)
			{
				// Check if adjacent
				if (air.y == cube.y + 1 || air.y == cube.y - 1)
				{
					air.sides_uncovered--;
					//cube2.sides_uncovered--;
				}
			}
			// YZ plane 
			else if (air.y == cube.y && air.z == cube.z)
			{
				// Check if adjacent
				if (air.x == cube.x + 1 || air.x == cube.x - 1)
				{
					air.sides_uncovered--;
					//cube2.sides_uncovered--;
				}
			}
		}
		if (is_pocket && air.sides_uncovered == 0)
		{
			cout << "Coordinate " << air.x << "," << air.y << "," << air.z << " is a pocket of air" << endl;;
			m_Part2 -= 6;
		}
	}

	for (Cube &air : pockets_of_air)
	{
		// Search up / +y axis
		for (Cube &cube : cubes)
		{
			if (cube.x == air.x && cube.z == air.z)
			{

			}
		}
		// Search down / -y axies
		// Search left
		// Search right
	}
	/*for (Cube cube : cubes)
	{
		if (cube.sides_uncovered > 0)
		{
			m_Part2 += cube.sides_uncovered;
		}
	}*/
}

bool Day18::BoundSearch(Cube& air, vector<Cube>& cubes)
{
	bool bounded = false;

	// Search up / +y axis
	Cube search;
	search.x = air.x;
	search.z = air.z;
	search.y = air.y + 1;

	//// Check to see if it's another pocket of air
	//if (! find(cubes.beign(), cubes.end(), ))
	//{
	//	// If we have not visited this location, check if bounded
	//	if (!path.find())
	//	{
	//		bool b = BoundSearch(search, cubes);
	//		if (!b)
	//		{
	//			return false;
	//		}
	//	}
	//}


	for (Cube cube : cubes)
	{		
		if (cube.x == air.x && cube.z == air.z && cube.y > air.y)
		{
			int space_up{ 0 };
			space_up = fabs(cube.y - air.y);
			space_up = cube.y;
			// Search down / -y axies
			for (Cube cube2 : cubes)
			{
				if (cube.x == air.x && cube.z == air.z && cube.y < air.y)
				{
					int space_down{ 0 };				
					space_down = fabs(cube.y - air.y);
					// Search left
					for (Cube cube2 : cubes)
					{
						if (cube.y == air.y && cube.z == air.z && cube.x < air.x)
						{
							int space_left{ 0 };
							space_left = fabs(cube.x - air.x);
							// Search right							
							for (Cube cube2 : cubes)
							{
								if (cube.y == air.y && cube.z == air.z && cube.x > air.x)
								{
									int space_right{ 0 };
									space_right = fabs(cube.x - air.x);
								}
							}
						}
					}
				}
			}
		}
	}
	return bounded;
}
