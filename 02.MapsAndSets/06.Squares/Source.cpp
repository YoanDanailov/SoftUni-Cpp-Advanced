#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <stack>
#include <math.h>

bool checkIfPerfectSquare(int num) {

	int square = sqrt(num);
	if (square * square == num)
	{
		return true;
	}

	return false;
}

std::map<int,int> readInts() {

	std::map<int,int> nums;

	std::string line;
	getline(std::cin, line);
	std::istringstream stream(line);
	std::string current;

	while (stream >> current)
	{
		bool square = checkIfPerfectSquare(stoi(current));
		if (square)
		{
			++nums[stoi(current)];
		}
	}

	return nums;

}

std::stack<int> fillStack(std::map<int,int>& nums) {
	std::stack<int> stack{};

	for (auto i = nums.begin(); i != nums.end(); i++)
	{
		int time = i->second;
		for (int j = 0; j < time ; j++)
		{
			stack.push(i->first);
		}
	}

	return stack;
}

void printNums(std::stack<int>& nums) {

	while (!nums.empty())
	{
		std::cout << nums.top() << " ";
		nums.pop();
	}

}

int main() {

	std::map<int,int> numbers = readInts();
	std::stack<int> nums = fillStack(numbers);
	printNums(nums);

	return 0;
}