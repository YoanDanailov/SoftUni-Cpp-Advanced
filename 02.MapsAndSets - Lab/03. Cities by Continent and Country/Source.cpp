#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

std::map<std::string, std::string> fillCountries() {
	std::map<std::string, std::string> countries{};


	return countries;
}

int readInt() {
	int num;
	std::cin >> num;
	std::cin.ignore();
	return num;
}

std::string readLine() {
	std::string line;
	getline(std::cin, line);
	return line;
}

void pushContinentToVector(std::vector<std::string>& continentOrder,const std::string continent) {

	bool exist = false;

	for (int i = 0; i < continentOrder.size(); i++)
	{
		if (continent == continentOrder[i]) {
			exist = true;
		}
	}

	if (!exist)
	{
		continentOrder.push_back(continent);
	}
}

std::map<std::string,std::map<std::string, std::string>> fillContinents(std::vector<std::string>& continentOrder, 
	std::vector<std::string>& countriesOrder) {
	std::map<std::string,std::map<std::string, std::string>> continents{};
	std::map<std::string, std::string> current{};
	int loopCount = readInt();
	std::string continent;
	std::string country;
	std::string city;
	
	for (int i = 0; i < loopCount; i++)
	{
		std::string line = readLine();
		std::istringstream stream(line);
		stream >> continent;
		pushContinentToVector(continentOrder,continent);
		stream >> country;
		pushContinentToVector(countriesOrder,country);
		stream >> city;
		continents[continent][country].append(city);
		continents[continent][country].append(", ");
	}

	return continents;
}

void printContinents(const std::map<std::string, std::map<std::string, std::string>>& continents,
	const std::vector<std::string>& continentOrder, const std::vector<std::string>& countryOrder) {

	for (auto i = 0 ; i < continentOrder.size() ; i++)
	{
		auto it = continents.find(continentOrder[i]);
		std::cout << it->first << ":" << std::endl;
		std::map<std::string, std::string> currentCountry = it->second;
		for (auto j = 0; j < countryOrder.size(); j++)
		{
			auto itt = currentCountry.find(countryOrder[j]);
			if (itt != currentCountry.end())
			{
				std::cout << "\t" << itt->first << " -> " << itt->second.substr(0, itt->second.size() - 2) << std::endl;
			}
		}
	}
}

int main() {

	std::vector<std::string> continentOrder{};
	std::vector<std::string> countriesOrder{};
	const std::map<std::string ,std::map<std::string, std::string>> continents = fillContinents(continentOrder, countriesOrder);
	printContinents(continents, continentOrder, countriesOrder);

	return 0;
}