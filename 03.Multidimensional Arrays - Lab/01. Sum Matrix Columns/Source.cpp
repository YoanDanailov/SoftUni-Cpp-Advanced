#include <iostream>
#include <vector>

int readInt() {
	int num;
	std::cin >> num;
	std::cin.ignore();
	return num;
}

std::vector<std::vector<int>> readMatirx(int rows,int cols) {
	
	std::vector<std::vector<int>> numbersMatrix{};
	
	for (int i = 0; i < rows; i++)
	{
		std::vector<int> currentRow{};
		for (int i = 0; i < cols; i++)
		{
			int element = readInt();
			currentRow.push_back(element);
		}
		numbersMatrix.push_back(currentRow);
	}
		
	return numbersMatrix;
}

void printSumOfColumns(const std::vector<std::vector<int>>& numbersMatrix, int cols) {

	for (int i = 0; i < cols; i++)
	{
		int sum = 0;
		for (int j = 0; j < numbersMatrix.size(); j++)
		{
			std::vector<int> currentRow = numbersMatrix[j];
			sum += currentRow[i];
		}
		std::cout << sum << std::endl;
	}

}

int main() {

	int rows = readInt();
	int cols = readInt();
	std::vector<std::vector<int>> numbersMatrix = readMatirx(rows,cols);
	printSumOfColumns(numbersMatrix, cols);

	return 0;
}