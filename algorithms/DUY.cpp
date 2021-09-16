/*
Thong tin ca nhan:
MSSV: 20110060
Ho va ten: Dang Quoc Duy
*/

#include <iostream>
#include <fstream>
#include <string>
#include <list>

typedef struct Subject {
    std::string code;
    std::string name;
    int credits;
    float mark;
} Subject;

typedef struct Student {
    std::string code;
    std::string fullName;
    int age;
    int numberOfSubjects;
    std::list<Subject> subjects;
    int creditsSum, creditsTotal;
    float averageMark, averageMarkTotal;
} Student;

void readStudent(std::ifstream *file, Student *stdptr) {
    std::string line;

    stdptr->creditsSum = 0;
    stdptr->creditsTotal = 0;
    stdptr->averageMark = 0.0;
    stdptr->averageMarkTotal = 0.0;

    *file >> stdptr->code;
    file->ignore();
    std::getline(*file, stdptr->fullName);
    *file >> stdptr->age >> stdptr->numberOfSubjects;

    Subject sbj;
    for(int i = 0; i != stdptr->numberOfSubjects; i++) {
        std::getline(*file, line);
        std::getline(*file, line);
        *file >> sbj.code;
        file->ignore();
        std::getline(*file, sbj.name);
        *file >> sbj.credits >> sbj.mark;

        stdptr->creditsSum += sbj.credits;
        stdptr->averageMark += sbj.credits * sbj.mark;
        if(sbj.mark >= 5.0) {
            stdptr->creditsTotal += sbj.credits;
            stdptr->averageMarkTotal += sbj.credits * sbj.mark;
        }
        stdptr->subjects.push_back(sbj);
    }
    stdptr->averageMark /= stdptr->creditsSum;
    stdptr->averageMarkTotal /= stdptr->creditsTotal;
}

void writeStudent(Student *stdptr) {
    std::cout << "Student Code: " << stdptr->code << std::endl;
    std::cout << "Full Name: " << stdptr->fullName << std::endl;
    std::cout << "Age: " << stdptr->age << std::endl;
    std::cout << "Number of Subjects: " << stdptr->numberOfSubjects << std::endl;
    std::cout << "Total Credits: " << stdptr->creditsSum << std::endl;
    std::cout << "Total Credits (Tich Luy): " << stdptr->creditsTotal << std::endl;
    std::cout << "Average Mark: " << stdptr->averageMark << std::endl;
    std::cout << "Average Mark (Tich Luy): " << stdptr->averageMarkTotal << std::endl;
    std::cout << "====================================================" << std::endl;
    std::cout << "Subject Code\t\tSubject Name\t\tCredits\t\tMarks" << std::endl;
    for(decltype(stdptr->subjects.cbegin()) it = stdptr->subjects.cbegin(); it != stdptr->subjects.cend(); it++) {
        std::cout << it->code << "\t\t\t" << it->name << "\t" << it->credits << "\t\t" << it->mark << std::endl;
    }
}

int main() {
    Student std;
    std::ifstream input("D:/QUOCANH.txt");
    if(input.is_open()) {
        readStudent(&input, &std);
        writeStudent(&std);
        input.close();
    } else {
        std::cout << "Cannot open the specified file." << std::endl;
    }
    return 0;
}
