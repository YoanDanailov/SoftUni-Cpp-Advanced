#include <iostream>
#include <vector>
#include <sstream>
#include <string>

int readRows() {
	int rows;
	std::cin >> rows;
	std::cin.ignore();

	return rows;
}

std::vector<int> createCurrentVector(){
	std::vector<int> currentVector{};

	std::string line;
	getline(std::cin, line);
	std::istringstream stream(line);
	std::string current;

	while (stream >> current)
	{
		int currentNumber = stoi(current);
		currentVector.push_back(currentNumber);
	}

	return currentVector;
}

std::vector<std::vector<int>> readMatrix() {

	std::vector<std::vector<int>> matrix{};
	int rows = readRows();

	for (int i = 0; i < rows; i++)
	{
		std::vector<int> currentVector = createCurrentVector();
		matrix.push_back(currentVector);
	}

	return matrix;
}

void areEqual(std::vector<std::vector<int>>& matrixOne, std::vector<std::vector<int>>& matrixTwo) {

	if (matrixOne == matrixTwo)
	{
		std::cout << "equal" << std::endl;
	}
	else {
		std::cout << "not equal" << std::endl;
	}

}

int main() {


	std::vector<std::vector<int>> matrixOne = readMatrix();
	std::vector<std::vector<int>> matrixTwo = readMatrix();
	areEqual(matrixOne, matrixTwo);

	return 0;
}