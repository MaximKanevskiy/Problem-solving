#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> towerBuilder(unsigned nFloors) 
{
	char block = '*';
	int count = 1;
	int space = nFloors - 1;
	std::vector<std::string> pyramid;

	for (int i = 0; i < nFloors; i++)
	{
		std::string floor = "";

		for (int k = 0; k < space; k++)
		{
			floor += " ";
		}

		for (int j = 0; j < count; j++)
		{
			floor += block;
		}

		for (int k = 0; k < space; k++)
		{
			floor += " ";
		}
		
		count += 2;
		space--;
		pyramid.push_back(floor);
	}
	return pyramid;
}

int main()
{
	auto pyramid = towerBuilder(10);

	for (const auto& floor : pyramid)
	{
		std::cout << floor << std::endl;
	}
}