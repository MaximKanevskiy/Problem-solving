#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> towerBuilder(unsigned nFloors) 
{
	std::vector<std::string> pyramid(nFloors);
	char block = '*';
	int count = 1;
	int space = nFloors - 1;

	for (int i = 0; i < nFloors; i++)
	{
		pyramid[i] = std::string(space, ' ') + std::string(count, '*') + std::string(space, ' ');
		count += 2;
		space--;		
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