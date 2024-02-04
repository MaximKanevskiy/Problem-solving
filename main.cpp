#include <iostream>
#include <vector>

static bool isValidWalk(std::vector<char> walk) 
{
	if (walk.size() != 10)
	{
		return false;
	}

	int vertical_balance = 0;
	int horizontal_balance = 0;

	for (const auto& direction : walk)
	{
		switch (direction)
		{
		case 'n':
			vertical_balance++;
			break;
		case 's':
			vertical_balance--;
			break;
		case 'w':
			horizontal_balance++;
			break;
		case 'e':
			horizontal_balance--;
			break;
		}
	}

	return vertical_balance == 0 && horizontal_balance == 0;
}

int main()
{
	std::vector correct_walk = { 'e','e','e','w','n','s','n','s','e','w' };
	std::cout << isValidWalk(correct_walk) << std::endl;
}