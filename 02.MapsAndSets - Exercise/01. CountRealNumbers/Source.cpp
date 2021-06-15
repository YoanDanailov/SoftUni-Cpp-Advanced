#include <iostream>
#include <map>
#include <string>
#include <sstream>

std::map<double, int> readMap() {
	
	std::map<double, int> nums{};
	
	std::string line;
	getline(std::cin, line);
	std::istringstream stream(line);
	std::string current;
	
	while (stream >> current)
	{
		double dbl = stod(current);
		++nums[dbl];
	}

	return nums;
}

void printMap(const std::map<double, int>& nums) {

	for (auto i = nums.begin(); i != nums.end(); i++)
	{
		std::cout << i->first << " -> " << i->second << std::endl;
	}

}

int main() {

	const std::map<double , int> numbers = readMap();
	printMap(numbers);

	return 0;
}