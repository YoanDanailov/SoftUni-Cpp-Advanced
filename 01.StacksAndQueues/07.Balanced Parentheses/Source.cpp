#include <iostream>
#include <string>
#include <deque>

std::deque<char> fillLineFromInput() {
	
	std::deque<char> line{};
	std::string input;
	getline(std::cin, input);

	for (int i = 0; i < input.size(); i++)
	{
		line.push_back(input[i]);
	}

	return line;
}

bool checkIfMatch(char front , char back) {
	if (front == '{' && back == '}')
	{
		return true;
	}
	else if (front == '[' && back == ']') {
		return true;
	}
	else if (front == '(' && back == ')') {
		return true;
	}
	else {
		return false;
	}

}

bool checkIfLineIsBalanced( std::deque<char>& line) {


	while (!line.empty())
	{
		char currentFront = line.front();
		char currentBack = line.back();

		if (checkIfMatch(currentFront,currentBack)){
			line.pop_back();
			line.pop_front();
		}
		else {
			return false;
		}
	}
	return true;
}

void printResult(bool balanced) {
	if (balanced)
	{
		std::cout << "YES";
	}
	else {
		std::cout << "NO";
	}
}

int main() {

	std::deque<char> line = fillLineFromInput();
		bool balanced = checkIfLineIsBalanced(line);
		printResult(balanced);

	return 0;
}