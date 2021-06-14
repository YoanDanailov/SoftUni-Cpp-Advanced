#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int readInt() {
	int num = 0;
	std::cin >> num;
	std::cin.ignore();
	return num;
}
int readChar() {
	char curr;
	std::cin >> curr;
	std::cin.ignore();
	return curr;
}

std::vector<std::vector<char>> createMatrix() {
	std::vector<std::vector<char>> matrix{};
	int row = readInt();
	int column = readInt();

	for (int i = 0; i < row; i++)
	{
		std::vector<char> row{};
		for (int j = 0; j < column; ++j) {
			char curr = readChar();
			row.push_back(curr);
		}
		matrix.push_back(row);
	}

	return matrix;
}


std::vector<std::vector<char>> create2x2Matric(std::vector<std::vector<char>>& matrix , int& startRow, int& startColumn){

	std::vector<char> rowOne = matrix[startRow];
	std::vector<char> rowOne2x2{ rowOne[startColumn] ,rowOne[startColumn + 1] };
	std::vector<char> rowTwo = matrix[startRow +1];
	std::vector<char> rowTwo2x2{ rowTwo[startColumn] ,rowTwo[startColumn + 1] };
	++startColumn;

	return std::vector<std::vector<char>>{ rowOne2x2, rowTwo2x2};
}

bool equalElementsCheck(std::vector<std::vector<char>>& matrix2x2, int& counter) {

	bool allEqual = true;
	char element = matrix2x2[0][0];

	for (int i = 0; i < matrix2x2.size(); i++)
	{
		std::vector<char> row = matrix2x2[i];
		for (int j = 0; j < row.size() ; j++)
		{
			char current = row[j];
			if (current != element)
			{
				return false;
			}
		}
	}

	++counter;
	return true;
}

void count2x2WithEqualElements(std::vector<std::vector<char>>& matrix) {
	
	int counter = 0;
	std::vector<std::vector<char>> matrix2x2{};

	int startRow = 0;
	int startColumn = 0;
	int endColumnIndex = matrix[0].size()-1;

	while (startRow < matrix.size()-1)
	{
		matrix2x2 = create2x2Matric(matrix, startRow, startColumn);
		bool test = equalElementsCheck(matrix2x2, counter);
		
		if (startColumn == endColumnIndex)
		{
			startColumn = 0;
			startRow++;
		}
	}

	std::cout << counter << std::endl;
}

int main() {

	std::vector<std::vector<char>> matrix = createMatrix();
	count2x2WithEqualElements(matrix);

	return 0;
}