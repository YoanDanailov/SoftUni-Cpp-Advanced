#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>
#include <string>
#include <stack>
#include <vector>

std::map<double,int> fillSet() {
	std::map<double,int> nums;
	std::string line;
	getline(std::cin, line);
	std::istringstream stream(line);
	std::string current;

	while (stream >> current)
	{
		double num = stod(current);
		++nums[num];
	}

	return nums;
}

void printStack( std::stack<double>& largest) {

	int counter = 0;

	while (!largest.empty() && counter < 3)
	{
		std::cout << largest.top() << " ";
		largest.pop();
		counter++;
	}
	
}

void printLargestThree(std::map<double,int>& nums) {

	std::stack<double> largest{};

	for (auto i = nums.begin() ; i != nums.end() ; i++)
	{
		int end = i->second;
		for (int j = 0; j < end  ; j++)
		{
			largest.push(i->first);
		}
	}
	
	printStack(largest);

}


int main() {
	
	std::map<double,int> nums = fillSet();
	printLargestThree(nums);
	
}