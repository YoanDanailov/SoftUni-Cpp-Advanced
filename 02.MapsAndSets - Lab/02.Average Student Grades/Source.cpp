#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

void pushStudentToVector(std::vector<std::string>& order, std::string name) {

    bool exist = false;

    for (int i = 0; i < order.size(); i++)
    {
        std::string current = order[i];
        if (current == name)
        {
            exist = true;
        }
    }

    if (!exist)
    {
        order.push_back(name);
    }

}

std::map<std::string, std::string> readInputToMap(std::vector<std::string>& order) {

    std::map<std::string, std::string> students;

    int numberOfStudents = 0;
    std::cin >> numberOfStudents;
    std::cin.ignore();

    for (int i = 0; i < numberOfStudents; i++)
    {
        std::string line;
        getline(std::cin, line);
        std::istringstream stream(line);
        std::string current;

        std::string name;
        std::string grade;
        stream >> name;
        stream >> grade;
        students[name].append(" ");
        students[name].append(grade);
        pushStudentToVector(order, name);
    }

    return students;
}

double getAverage(std::string grades) {
    double average = 0.00;

    std::istringstream stream(grades);
    std::string currentGrade;
    int counter = 0;

    while (stream >> currentGrade)
    {
        double current = stod(currentGrade);
        average += current;
        ++counter;
    }

    return average / counter;
}

void printStudentResults(const std::vector<std::string>& order,
    const std::map<std::string, std::string>& students) {

    double average = 0.00;

    for (int i = 0; i < order.size(); i++)
    {
        auto it = students.find(order[i]);
        std::string grades = it->second;
        average = getAverage(grades);
        std::cout << order[i] << " ->";
        /*******************************************/
        std::istringstream reader(grades);
        double grade = 0.0;
        while (reader >> grade) {
            std::cout << " " << grade;
        }
        std::cout << " (avg: " << average << ")" << std::endl;
    }

}

int main() {

    std::vector<std::string> order{};
    std::map<std::string, std::string> students = readInputToMap(order);
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);
    printStudentResults(order, students);

    return 0;
}