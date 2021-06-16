#include <iostream>
#include <sstream>
#include <vector>
#include <string>

int readInt() {
	int num;
	std::cin >> num;
	std::cin.ignore();
	return num;
}

char readChar() {
	char el;
	std::cin >> el;
	std::cin.ignore();
	return el;
}

std::vector<std::vector<char>> readCharMatrix() {
	
	std::vector<std::vector<char>> charMatrix{};
	int num = readInt();

		for (int j = 0; j < num; ++j) {

			std::vector<char> charRow{};
			
			std::string line{};getline(std::cin, line);
			std::istringstream stream(line);
			char current;

			while (stream >> current)
			{
				charRow.push_back(current);
			}

		charMatrix.push_back(charRow);
	}

	return charMatrix;
}

bool findMagicCharInMatrix(const std::vector<std::vector<char>>& charMatrix, char magicChar) {

	bool found = false;

	for (int i = 0; i < charMatrix.size(); i++)
	{
		std::vector<char> row = charMatrix[i];
		for (int j = 0; j < row.size(); j++)
		{
			char current = row[j];
			if (magicChar == current)
			{
				std::cout << "(" << i << ", " << j << ")" << std::endl;
				return true;
			}
		}
	}

	std::cout << magicChar << " does not occur in the matrix" << std::endl;
	return false;
}

int main() {

	std::vector<std::vector<char>> charMatrix = readCharMatrix();
	char magicChar = readChar();
	bool found = findMagicCharInMatrix(charMatrix,magicChar);

	return 0;
}