#include <iostream>
#include <string>
#include <sstream>
#include <set>

std::set<int> readSet() {
	std::set<int> nums;
	std::string line;
	getline(std::cin, line);
	std::istringstream stream(line);
	std::string current;

	while (stream >> current)
	{
		nums.insert(stoi(current));
	}

	return nums;
}

void printSet(const std::set<int>& nums) {

	std::string answer;

	for (auto i = nums.begin(); i != nums.end() ; i++)
	{
		answer.append(std::to_string(*i));
		answer.append(" <= ");
	}

	std::cout << answer.substr(0,answer.size()-4);
}


int main() {

	std::set<int> numbers = readSet();
	printSet(numbers);

	return 0;
}