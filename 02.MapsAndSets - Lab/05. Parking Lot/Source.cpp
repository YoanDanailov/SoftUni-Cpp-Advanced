#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>

std::string readLine() {
	std::string line;
	getline(std::cin, line);
	return line;
}

void pushPlateToVectorIfUnique(std::vector<std::string>& platesOrder,const std::string& plate) {
	bool exist = false;

	for (int i = 0; i < platesOrder.size(); i++)
	{
		if (plate == platesOrder[i]) {
			exist = true;
		}
	}
	if (!exist)
	{
		platesOrder.push_back(plate);
	}
}

void removePlateFromVector(std::vector<std::string>& platesOrder, const std::string& plate) {

	for (int i = 0; i < platesOrder.size(); i++)
	{
		if (plate == platesOrder[i]) {
			platesOrder.erase(std::remove(platesOrder.begin(), platesOrder.end(), platesOrder[i]), platesOrder.end());
		}
	}
}

std::map<std::string, std::string> fillPlates(std::vector<std::string>& platesOrder) {
	std::map<std::string, std::string> plates{};
	std::string command = readLine();
	std::string direction;
	std::string plate;

	while (command != "END")
	{
		std::istringstream stream(command);
		stream >> direction;
		stream >> plate;
		if (direction == "IN,")
		{
			pushPlateToVectorIfUnique(platesOrder, plate);
		}
		else {
			removePlateFromVector(platesOrder, plate);
		}
		std::string current = plates[plate];

		if (current == "")
		{
			plates[plate] = direction;
		}
		else if (current == "IN," && direction == "OUT,")
		{
			plates[plate] = "";
		}

		command = readLine();
	}

	return plates;
}

void printRemainingCars(const std::vector<std::string>& platesOrder, const std::map<std::string, std::string>& carPlates) {

	bool empty = true;

	for (int i = 0; i < platesOrder.size(); i++)
	{
		auto it = carPlates.find(platesOrder[i]);
		if (it != carPlates.end())
		{
			if (it->second == "IN,") {
				std::cout << it->first << std::endl;
				empty = false;
			}
		}
	}

	if (empty)
	{
		std::cout << "Parking Lot is Empty" << std::endl;
	}
}

int main() {

	std::vector<std::string> platesOrder{};
	std::map<std::string, std::string> carPlates = fillPlates(platesOrder);
	printRemainingCars(platesOrder,carPlates);

	return 0;
}