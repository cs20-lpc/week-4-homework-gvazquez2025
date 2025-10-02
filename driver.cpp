#include <iostream>
#include <string>
#include "Student.hpp"
#include "Course.hpp"
using namespace std;

int main() {
    LinkedList list;
    int choice;

    do {
        cout << "\n1. Insert Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Search Student\n";
        cout << "4. Display All\n";
        cout << "5. Count Students\n";
        cout << "6. Add a Course\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id; string name; double gpa;
            cout << "Enter ID: "; cin >> id;
            cout << "Enter Name: "; cin.ignore(); getline(cin, name);
            cout << "Enter GPA: "; cin >> gpa;
            Student s(id, name, gpa);
            list.insertStudent(s);
        }
        else if (choice == 2) {
            int id;
            cout << "Enter ID to delete: "; cin >> id;
            if (list.deleteStudent(id))
                cout << "Deleted student with ID " << id << endl;
            else
                cout << "Student not found." << endl;
        }
        else if (choice == 3) {
            int id;
            cout << "Enter ID to search: "; cin >> id;
            Student* s = list.searchStudent(id);
            if (s) {
                cout << "Found: ";
                s->display();
            } else {
                cout << "Student not found." << endl;
            }
        }
        else if (choice == 4) {
            list.displayAll();
        }
        else if (choice == 5) {
            cout << "Total students: " << list.countStudents() << endl;
        }
        else if (choice == 6) {
            int id; string cname, loc;
            cout << "Enter ID: "; cin >> id;
            cin.ignore();
            cout << "Enter Course Name: "; getline(cin, cname);
            cout << "Enter Location: "; getline(cin, loc);
            Student* s = list.searchStudent(id);
            if (s) {
                s->addCourse(Course(cname, loc));
                cout << "Course added!" << endl;
            } else {
                cout << "Student not found." << endl;
            }
        }
    } while (choice != 7);

    return 0;
}
