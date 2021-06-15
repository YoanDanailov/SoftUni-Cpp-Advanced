#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>

int readInt() {
	int num;
	std::cin >> num;
	std::cin.ignore();
	return num;
}

std::string readName() {
	std::string name;
	std::cin >> name;
	std::cin.ignore();
	return name;
}

void pushToVectorIfUnique(std::vector<std::string>& uniqueNames, const std::string& name) {

	bool exist = false;

	for (int i = 0; i < uniqueNames.size() ; i++)
	{
		if (name == uniqueNames[i]) {
			exist = true;
		}
	}

	if (!exist)
	{
		uniqueNames.push_back(name);
	}
}

std::vector<std::string> fillNames() {
	std::vector<std::string> uniqueNames{};
	int loopNum = readInt();

	for (int i = 0; i < loopNum; i++)
	{
		std::string name = readName();
		pushToVectorIfUnique(uniqueNames, name);
	}

	return uniqueNames;
}

void printVector(const std::vector<std::string>& uniqueNames) {

	for (int i = 0; i < uniqueNames.size(); i++)
	{
		std::cout << uniqueNames[i] << std::endl;
	}

}

int main() {

	const std::vector<std::string> uniqueNames = fillNames();
	printVector(uniqueNames);

	return 0;
}