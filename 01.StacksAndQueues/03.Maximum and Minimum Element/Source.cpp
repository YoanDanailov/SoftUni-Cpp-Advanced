#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <vector>
#include <limits>

std::vector<std::string> fillVectorWithOperations() {
	int numberOfOperations = 0;
	std::cin >> numberOfOperations;
	std::cin.ignore();

	std::vector<std::string> operations(numberOfOperations);
	
	for (std::string& operation : operations)
	{
		getline(std::cin, operation);
	}

	return operations;
}

void pushNumber(std::stack<int>& numbers, int number) {
	numbers.push(number);
}

void printMax(const std::stack<int>& numbers) {
	
	if (!numbers.empty())
	{
		std::stack<int> copy = numbers;
		int max = std::numeric_limits<int>::min();
		while (!copy.empty())
		{
			int current = copy.top();
			if (current > max) {
				max = current;
			}
			copy.pop();
		}
		std::cout << max << std::endl;
	}

}

void printMin(const std::stack<int>& numbers) {

	if (!numbers.empty())
	{
		std::stack<int> copy = numbers;
		int min = std::numeric_limits<int>::max();
		while (!copy.empty())
		{
			int current = copy.top();
			if (current < min) {
				min = current;
			}
			copy.pop();
		}
		std::cout << min << std::endl;
	}

}

void processOperations(const std::vector<std::string>& operations, std::stack<int>& numbers) {
	
	std::string current = "";

	for (const std::string& string : operations)
	{
		std::istringstream stream(string);
		stream >> current;
		std::string number;

		switch (std::stoi(current))
		{
		case 1:
			stream >> number;
			numbers.push(std::stoi(number));
			break;
		case 2:
			if (!numbers.empty())
			{
				numbers.pop();
			}
			break;
		case 3:
			printMax(numbers);
			break;
		case 4:
			printMin(numbers);
			break;
		default:
			break;
		}
	}

}

 void printRemaining( std::stack<int>& stack) {

	 std::string answer = "";

	 while (!stack.empty())
	 {
		 answer.append(std::to_string(stack.top()));
		 stack.pop();
		 answer.append(", ");
	 }

	 int size = answer.size();
	 answer = answer.substr(0, size - 2);
	 std::cout << answer;
}

int main() {

	std::vector<std::string> operations = fillVectorWithOperations();
	std::stack<int> numbers{};
	processOperations(operations, numbers);
	printRemaining(numbers);

	return 0;
}