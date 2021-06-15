#include <iostream>
#include <stack>
#include <limits>
#include <string>

int readInt() {
	int num;
	std::cin >> num;
	return num;
}

void pushNumbers(std::stack<int>& numbers, int numbersToPush) {
	
	for (int i = 0; i < numbersToPush; ++i)
	{
		numbers.push(readInt());
	}

}

void popNumbers(std::stack<int>& numbers, int numbersToPop) {

	if (numbers.size() < numbersToPop)
	{
		numbersToPop = numbers.size();
	}
	
	for (int i = 0; i < numbersToPop; ++i)
	{
		numbers.pop();
	}

}

bool checkIfContainsNum(std::stack<int>& numbers, int numberToFind) {
	std::stack<int> copy = numbers;

	while (!copy.empty())
	{
		if (copy.top() == numberToFind) {
			return true;
		}
		copy.pop();
	}
	return false;
}

std::string findSmallesNum(std::stack<int>& numbers) {
	std::string answer;
	int smallest = std::numeric_limits<int>::max();

	while (!numbers.empty()) {
		if (numbers.top() < smallest)
		{
			smallest = numbers.top();
		}
		numbers.pop();
	}
	
	answer = std::to_string(smallest);
	return answer;
}

std::string findAnswer(std::stack<int>& numbers, int numberToFind) {
	
	if (numbers.empty())
	{
		return "0";
	}
	else {
		bool found = checkIfContainsNum(numbers, numberToFind);
		if (found)
		{
			return "true";
		}
		else {
			return findSmallesNum(numbers);
		}
	}
	

}

int main() {

	int numbersToPush = readInt();
	int numbersToPop = readInt();
	int numberToFind = readInt();

	std::stack <int> numbers{}; 
	pushNumbers(numbers,numbersToPush); 
	popNumbers(numbers,numbersToPop);
	std::cout << findAnswer(numbers, numberToFind);

	return 0;
}