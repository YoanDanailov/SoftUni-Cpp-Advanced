#include <iostream>
#include <vector>

int readInt() {
	int num = 0;
	std::cin >> num;
	std::cin.ignore();
	return num;
}

std::vector<std::vector<int>> readMatrix() {
	
	std::vector<std::vector<int>> squareMatrix{};
	int n = readInt();

	for (int i = 0; i < n; i++)
	{
		std::vector<int> currentRow{};
		for (int j = 0; j < n; j++)
		{
			currentRow.push_back(readInt());
		}
		squareMatrix.push_back(currentRow);
	}

	return squareMatrix;
}

void printDiagonalSum(const std::vector<std::vector<int>>& matrix) {

	int sum = 0;
	int row = 0; int col = 0;
	int maxSize = matrix.size();

	while (row<maxSize && col < maxSize)
	{
		sum += matrix[row][col];
		row++; col++;
	}

	std::cout << sum;
}

int main() {

	std::vector<std::vector<int>> squareMatrix = readMatrix();
	printDiagonalSum(squareMatrix);

	return 0;
}