#include <iostream>
#include <string>
#include<stdio.h>
#include<ctype.h>
#include <sstream>
#include <map>
#include <vector>


void decapitalizeString(std::string& string) {
	

	for (int i = 0; i < string.size(); i++)
	{
		if (isupper(string[i]))
		{
			string[i] += 32;
		}
	}
}

void pushIfUnique(std::vector<std::string>& nums, std::string word) {

	bool isUnique = false;

	for (int i = 0; i < nums.size(); i++)
	{
		std::string current = nums[i];
		if (current == word)
		{
			isUnique = true;
		}
	}

	if (!isUnique)
	{
		nums.push_back(word);
	}

}

std::map<std::string, int> fillMap(std::vector<std::string>& nums) {

	std::map<std::string, int> strings{};
	std::string line;
	getline(std::cin, line);
	std::istringstream stream(line);
	std::string current;

	while (stream >> current) {
		decapitalizeString(current);
		pushIfUnique(nums, current);
		++strings[current];
	}

	return strings;
}

void printOdd(const std::vector<std::string>& nums ,const std::map<std::string, int>& strings ) {

	std::string final;

	for (int i = 0; i < nums.size(); i++)
	{
		auto it = strings.find(nums[i]);
		if (it->second %2 != 0)
		{
			final.append(it->first).append(", ");
		}
	}
	std::cout << final.substr(0, final.size() - 2);
}

int main() {

	std::vector<std::string> names{};
	const std::map<std::string, int> strings = fillMap(names);
	printOdd(names, strings);

	return 0;
}