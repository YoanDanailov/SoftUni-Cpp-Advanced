#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

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

std::map<int, int>fillMap(std::vector<int>& order) {
	
	std::map<int, int> numbers{};
	int loopCount = readInt();

	for (int i = 0; i < loopCount; i++)
	{
		int current = readInt();
		pushToVectorIfUnique(order, current);
		numbers[current]++;
	}

	return numbers;
}

void printEvenOccurances(const std::vector<int>& order ,const std::map<int, int>& numbers) {

	for (int i = 0; i < order.size(); i++)
	{
		auto it = numbers.find(order[i]);
		int num = it->first;
		int occur = it->second;
		if (it != numbers.end() || occur %2==0)
		{
			std::cout << num << " ";
		}
	}

}

int main() {

	std::vector<int> order{};
	std::map<int, int> numbers = fillMap(order);
	printEvenOccurances(order,numbers);

	return 0;
}