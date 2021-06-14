#include <iostream>
#include <string>
#include <sstream>
#include <stack>

std::string readLine() {
	std::string line;
	getline(std::cin, line);
	return line;
}

std::stack<int> createStack() {

	std::stack<int> clothes;
	std::string line = readLine();
	std::istringstream stream(line);
	std::string current;

	while (stream >> current)
	{
		clothes.push(std::stoi(current));
	}

	return clothes;
}

void addClothesToRack(int capacity , std::stack<int>& clothes) {
	int rack = capacity;
	while (rack != 0 && !clothes.empty())
	{
		int current = clothes.top();
		if (current <= rack)
		{
			rack -= current;
			clothes.pop();
		}
		else {
			rack = 0;
		}
	}
}

int main() {

	std::stack<int> clothes = createStack();
	int capacity = std::stoi(readLine());
	int counterRacks = 0;

	while (!clothes.empty()) {
		addClothesToRack(capacity , clothes);
		++counterRacks;
	}

	std::cout << counterRacks;

	return 0;
}