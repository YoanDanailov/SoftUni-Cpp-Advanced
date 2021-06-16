#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <vector>

int readInt() {
	int num;
	std::cin >> num;
	std::cin.ignore();
	return num;
}

std::string readLine() {
	std::string line;
	getline(std::cin, line);
	return line;
}

void fillWithInputElemets(std::set<std::string>& elements) {

	std::string line = readLine();
	std::string current{};
	std::istringstream stream(line);
	
	while (stream >> current) {
		elements.insert(current);
	}
	

}

void printElements(const std::set<std::string>& elements) {

	for (auto i = elements.begin() ; i != elements.end() ; i++)
	{
		std::cout << *i << " ";
	}

}

int main() {
	int num = readInt();
	std::set<std::string> elements{};

	for (int i = 0; i < num; i++)
	{
		fillWithInputElemets(elements);
	}

	printElements(elements);

	return 0;
}