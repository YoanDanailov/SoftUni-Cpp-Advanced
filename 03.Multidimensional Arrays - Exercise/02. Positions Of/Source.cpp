#include <vector>
#include <iostream>
#include <string>
#include <sstream>

int readNumber() {
	int number;
	std::cin >> number;
	std::cin.ignore();

	return number;
}

std::vector<int> fillVector(){
	std::vector<int> currentVector{};

	std::string line;
	std::string current;
	getline(std::cin, line);
	std::istringstream stream(line);

	while (stream >> current)
	{
		int num = stoi(current);
		currentVector.push_back(num);
	}

	return currentVector;
}

std::vector<std::vector<int>> readMatrix() {
	
	int rows = readNumber();
	int columns = readNumber();

	std::vector<std::vector<int>> matrix{};
	
	std::string line;
	std::string current;

	for (int i = 0; i < rows; i++)
	{
		std::vector<int> currentVector = fillVector();
		matrix.push_back(currentVector);
	}

	return matrix;
}

void printAllNumberLocations(std::vector<std::vector<int>>& matrix ,int magicNumber) {

	bool found = false;

	for (int i = 0; i < matrix.size(); i++)
	{
		std::vector<int> current = matrix[i];
		for (int j = 0; j < current.size(); j++)
		{
			int num = current[j];
			if (num == magicNumber)
			{
				std::cout << i << " " << j << std::endl;
				found = true;
			}
		}
	}

	if (!found)
	{
		std::cout << "not found";
	}
}

int main() {

	std::vector<std::vector<int>> matrix = readMatrix();
	int magicNumber = readNumber();
	printAllNumberLocations(matrix,magicNumber);

	return 0;
}