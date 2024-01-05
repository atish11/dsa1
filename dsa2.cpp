



#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    int rollNumber;
    string name;
    string division;
    string address;
};

void addStudent() {
    ofstream file("students.txt", ios::app);
    Student student;

    cout << "Enter Roll Number: ";
    cin >> student.rollNumber;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, student.name);
    cout << "Enter Division: ";
    getline(cin, student.division);
    cout << "Enter Address: ";
    getline(cin, student.address);

    file << student.rollNumber << " " << student.name << " " << student.division << " " << student.address << endl;

    file.close();
}

void displayStudent(int rollNumber) {
    ifstream file("students.txt");
    Student student;
    bool found = false;

    while (file >> student.rollNumber >> student.name >> student.division >> student.address) {
        if (student.rollNumber == rollNumber) {
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with Roll Number " << rollNumber << " not found." << endl;
    }

    file.close();
}

void deleteStudent(int rollNumber) {
    ifstream inputFile("students.txt");
    ofstream outputFile("temp.txt");

    Student student;
    bool found = false;

    while (inputFile >> student.rollNumber >> student.name >> student.division >> student.address) {
        if (student.rollNumber != rollNumber) {
            outputFile << student.rollNumber << " " << student.name << " " << student.division << " " << student.address << endl;
        } else {
            found = true;
        }
    }

    inputFile.close();
    outputFile.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (!found) {
        cout << "Student with Roll Number " << rollNumber << " not found." << endl;
    } else {
        cout << "Student with Roll Number " << rollNumber << " deleted." << endl;
    }
}

int main() {
    int choice, rollNumber;

    while (true) {
        cout << "Menu:\n1. Add Student\n2. Display Student\n3. Delete Student\n4. Quit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                cout << "Enter Roll Number: ";
                cin >> rollNumber;
                displayStudent(rollNumber);
                break;
            case 3:
                cout << "Enter Roll Number: ";
                cin >> rollNumber;
                deleteStudent(rollNumber);
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}

