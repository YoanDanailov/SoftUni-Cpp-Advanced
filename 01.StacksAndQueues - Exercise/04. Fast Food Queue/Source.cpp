#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <limits>

std::string readLine() {
	std::string line;
	getline(std::cin, line);
	return line;
}

std::queue<int> createQueueOfOrders() {
	std::string line = readLine();
	std::queue<int> orders{};
	std::istringstream stream(line);
	std::string current;

	while (stream>>current)
	{
		orders.push(std::stoi(current));
	}

	return orders;
}

void processOrders(int food, std::queue<int>& orders , bool& isEnough) {

	while (!orders.empty() && food !=0 )
	{
		int currentOrder = orders.front();
		if (currentOrder<=food)
		{
			
			food -= currentOrder;
			orders.pop();
		}
		else {
			food = 0;
			isEnough = false;
		}
	}
}

int getMaxOrder(const std::queue<int>& orders) {

	int maxOrder = std::numeric_limits<int>::min();
	std::queue<int> ordersCopy = orders;
	
	while (!ordersCopy.empty())
	{
		int currentOrder = orders.front();
		
			if (maxOrder < currentOrder){
				maxOrder = currentOrder;
			}

			ordersCopy.pop();
	}

	return maxOrder;
}

void printRemaining(std::queue<int>& remaining) {
	while (!remaining.empty())
	{
		std::cout << " " << remaining.front() ;
		remaining.pop();
	}
}


int main() {

	int availableFood = std::stoi(readLine()); // Quantity of available food
	std::queue<int> orders = createQueueOfOrders(); // Queue of orders of food
	
	int maxOrder = getMaxOrder(orders); // Biggest order from queue
	std::cout << maxOrder << std::endl;
	
	bool isEnough = true; // Bool too check if the food is enough for the orders
	processOrders(availableFood, orders , isEnough); 

	if (isEnough) 
	{
		std::cout << "Orders complete"; // If the food is enough the orders are complete
	}
	else {
		std::cout << "Orders left:"; //If the food isnt enough print the remaining orders
		printRemaining(orders);
	}

	return 0;
}