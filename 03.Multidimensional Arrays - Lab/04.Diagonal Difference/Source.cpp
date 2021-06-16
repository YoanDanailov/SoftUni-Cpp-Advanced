#include <iostream>
#include <vector>

int readInt() {
	int num = 0;
	std::cin >> num;
	std::cin.ignore();
	return num;
}

std::vector<std::vector<int>> readMatrix() {
	std::vector<std::vector<int>> matrix{};
	int num = readInt();

	for (int i = 0; i < num; i++)
	{
		std::vector<int> currentRow{};
		for (int j = 0; j < num; j++)
		{
			currentRow.push_back(readInt());
		}
		matrix.push_back(currentRow);
	}

	return matrix;
}

int diagonalOne(const std::vector<std::vector<int>>& matrix) {
	int sum = 0;
	int startCol = 0; int endCol = matrix.size() - 1;
	int startRow = 0; int endRow = matrix.size() - 1;

	while ( startCol <= endCol && startRow <= endRow )
	{
		int num = matrix[startRow][startCol];
		sum += num;
		++startRow; ++startCol;
	}

	return sum;
}

int diagonalTwo(const std::vector<std::vector<int>>& matrix) {
	int sum = 0;
	int row = matrix.size() - 1;
	int col = 0;
	int endRow = 0;
	int endCol = matrix.size() - 1;

	while (row>=endRow && col <= endCol)
	{
		sum += matrix[row][col];
		--row; ++col;
	}

	return sum;
}

int main() {

	const std::vector<std::vector<int>> matrix = readMatrix();
	int sumOne = diagonalOne(matrix);
	int sumTwo = diagonalTwo(matrix);

	std::cout << abs(sumOne - sumTwo);

	return 0;
}