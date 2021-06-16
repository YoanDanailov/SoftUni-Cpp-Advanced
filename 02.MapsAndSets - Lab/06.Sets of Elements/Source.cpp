#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>

int readInt() {
	int num = 0;
	std::cin >> num;
	std::cin.ignore();
	return num;
}

void pushToVectorIfUnique(std::vector<int>& order, int num) {

	bool exist = false;

	for (int i = 0; i < order.size(); i++)
	{
		int current = order[i];
		if (current == num)
		{
			exist = true;
			break;
		}
	}

	if (!exist)
	{
		order.push_back(num);
	}
}


std::set<int> readSet(int length,std::vector<int>& order) {
	std::set<int> elements{};

	for (int i = 0; i < length; i++)
	{
		int currentNum = readInt();
		pushToVectorIfUnique(order, currentNum);
		elements.insert(currentNum);
	}

	return elements;
}

std::set<int> readSet(int length) {
	std::set<int> elements{};

	for (int i = 0; i < length; i++)
	{
		int currentNum = readInt();
		elements.insert(currentNum);
	}

	return elements;
}

std::set<int> fillSetWithUniqueElements(const std::set<int>& one , const std::set<int>& two , std::vector<int>& order) {
	
	std::set<int> unique{};

	for (auto i = one.begin(); i != one.end(); ++i)
	{
		int currentOne = *i;
		for (auto j = two.begin(); j != two.end(); ++j)
		{
			int currentTwo = *j;
			if (currentOne == currentTwo)
			{
				unique.insert(currentOne);
			}
		}
	}

	return unique;
}

void printEquivalentElements(const std::set<int>& uniqueElements, std::vector<int>& order) {

	for (int i = 0; i < order.size(); i++)
	{
		int current = order[i];
		auto it = uniqueElements.find(current);
		if (it != uniqueElements.end())
		{
			std::cout << order[i] << " ";
		}
	}
}

int main() {

	int lengthOne = readInt();
	int lengthTwo = readInt();
	std::vector<int> order{};
	std::set<int> elementsOne = readSet(lengthOne ,order);
	std::set<int> elementsTwo = readSet(lengthTwo);
	std::set<int> uniqueElements = fillSetWithUniqueElements(elementsOne, elementsTwo, order);
	
	printEquivalentElements(uniqueElements, order);

	return 0;
}