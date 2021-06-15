#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

void pushToVectorIfUnique(std::vector<double>& order, double num) {
	
	bool exist = false;

	for (int i = 0; i < order.size(); i++)
	{
		double current = order[i];
		if (current == num)
		{
			exist = true;
		}
	}
	if (!exist)
	{
		order.push_back(num);
	}

}

std::map<double, int> readInputToMap(std::vector<double>& order) {

	std::map<double, int> nums;

	std::string line;
	getline(std::cin, line);
	std::istringstream stream (line);
	std::string current;

	while (stream >> current)
	{
		double num = stod(current);
		pushToVectorIfUnique(order , num);
		++nums[stod(current)];
	}

	return nums;
}

void printMap(const std::map<double, int>& nums , const std::vector<double>& order) {

	for (int i = 0; i < order.size(); i++)
	{
		auto it = nums.find(order[i]);
		std::cout << order[i] << " - " << it->second << " times" << std::endl;
	}

}

int main() {

	std::vector<double> numOrder{};
	std::map<double, int> nums = readInputToMap(numOrder);
	printMap(nums , numOrder);

	return 0;
}