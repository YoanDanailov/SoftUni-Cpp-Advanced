#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

std::string  readLine() {
	std::string line;
	getline(std::cin, line);
	return line;
}

void addUniqueName(std::string line, std::vector<std::string>& names) {
	bool exists = false;
	for (int i = 0; i < names.size(); i++)
	{
		std::string current = names[i];
		if (current == line)
		{
			exists = true;
		}
	}

	if (!exists)
	{
		names.push_back(line);
	}

}

std::map<std::string, int> fillWithResources(std::vector<std::string>& names) {
	std::map<std::string, int> resources;

	std::string line = readLine();
	while (line != "stop")
	{
		int quantity = stoi(readLine());
		resources[line] += quantity;
		addUniqueName(line,names);
		line = readLine();
	}

	return resources;
}

void printResources(std::map<std::string,int>& resources, std::vector < std::string>& nums) {

	for (int i = 0; i < nums.size(); i++)
	{
		std::string current = nums[i];
		auto it = resources.find(current);
		std::cout << it->first << " -> " << it->second << std::endl;
	}

}

int main() {

	std::vector<std::string> resourcesNames{};
	std::map<std::string, int> resources = fillWithResources(resourcesNames);
	printResources(resources, resourcesNames);

	return 0;
}