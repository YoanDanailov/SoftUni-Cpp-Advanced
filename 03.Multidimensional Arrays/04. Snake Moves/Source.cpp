#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int readInt() {
	int num = 0;
	std::cin >> num;
	std::cin.ignore();
	return num;
}

std::string readLine() {
	std::string line;
	getline(std::cin, line);
	return line;
}

void printMatrix(std::vector<std::vector<char>>& matrix) {

	for (int i = 0; i < matrix.size(); i++)
	{
		std::vector<char> row = matrix[i];
		if (i%2==0)
		{
			for (int j = 0; j < row.size(); j++)
			{
				std::cout << row[j];
			}
		}
		else {
			for (int j = row.size()-1; j >= 0; j--)
			{
				std::cout << row[j];
			}
		}
		std::cout << std::endl;
	}

}

std::vector<char>  createVector(const int cols,const std::string& line , int& wordIndex) {
	std::vector<char> currentVector{};

	for (int i = 0; i < cols; i++)
	{
		currentVector.push_back(line[wordIndex]);
		++wordIndex;
		if (wordIndex >= line.size())
		{
			wordIndex = 0;
		}
	}

	return currentVector;
}

int main() {

	int rows = readInt();
	int cols = readInt();
	int wordIndex = 0;
	std::string line = readLine();

	std::vector<std::vector<char>> matrix{};

	for (int i = 0; i < rows; i++)
	{
		std::vector<char> currentVector = createVector(cols,line, wordIndex);
		matrix.push_back(currentVector);
	}

	printMatrix(matrix);

	return 0; 
}