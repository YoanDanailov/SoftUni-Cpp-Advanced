#include <iostream>
#include <sstream>
#include <string>
#include <queue>

std::queue<int>fillQueue(int number) {

	std::queue<int> queue{};
	
	for (int i = 0; i < number; i++)
	{
		std::string line;
		getline(std::cin, line);
		std::istringstream stream(line);
		std::string current;

		while (stream >> current)
		{
			queue.push(std::stoi(current));
		}
	}

	return queue;
}

bool checkIfPointIsValid(const std::queue<int>& queueOfPoint) {

	std::queue<int> queueCopy = queueOfPoint;
	int tank = 0;

	while (!queueCopy.empty() && tank>=0)
	{
		int currentFuel = queueCopy.front();
		queueCopy.pop();
		int currentKilometers = queueCopy.front();
		queueCopy.pop();
		tank += currentFuel;
		tank -= currentKilometers;
	}

	if (tank>=0)
	{
		return true;
	}
	else {
		return false;
	}

}

void getNextPoint(std::queue<int>& queue , int& index ) {
	
	std::queue<int> copy{};
	std::queue<int> passed{};
	
	for (int i = 0; i < 1; i++)
	{
		passed.push(queue.front());
		queue.pop();
		passed.push(queue.front());
		queue.pop();
	}

	while (!queue.empty())
	{
		copy.push(queue.front());
		queue.pop();
		copy.push(queue.front());
		queue.pop();
	}

	while (!passed.empty())
	{
		copy.push(passed.front());
		passed.pop();
		copy.push(passed.front());
		passed.pop();
	}

	queue = copy;
}

int main() {

	int number = 0;
	std::cin >> number;
	std::cin.ignore();

	std::queue<int> queueOfPoints{}; 
	queueOfPoints = fillQueue(number);

	int index = 0;
	bool pointIsValid = false;

	while (index<=number)
	{
		pointIsValid = checkIfPointIsValid(queueOfPoints);
		if (pointIsValid)
		{
			std::cout << index;
			break;
		}
		else {
			getNextPoint(queueOfPoints, index);
			++index;
		}
	}
	return 0;
}
