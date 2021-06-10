#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <cctype>

void lowerCaseWord(std::string& word) {

	for (int i = 0; i < word.size() ; i++)
	{
		char current = word[i];
		if (isupper(current))
		{
			word[i] = current += 32;
		}
	}

}

void checkIfWordIsShort(std::string& word , std::set<std::string>& shortWords) {

	if (word.size() < 5)
	{
		lowerCaseWord(word);
		shortWords.insert(word);
	}

}

std::set<std::string> fillSet() {
	std::set<std::string> shortWords;

	std::string line;
	getline(std::cin, line);
	std::istringstream stream(line);
	std::string current;

	while (stream >> current)
	{
		checkIfWordIsShort(current, shortWords);
	}

	return shortWords;
}

void printWords(std::set<std::string>& shortWords) {
	std::string answer;
	for (auto i = shortWords.begin(); i != shortWords.end() ; i++)
	{
		answer.append(*i);
		answer.append(", ");
	}

	std::cout << answer.substr(0, answer.size() - 2);
}

int main() {

	std::set<std::string> shortWords = fillSet();
	printWords(shortWords);

	return 0;
}