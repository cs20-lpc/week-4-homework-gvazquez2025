// TODO:  Student class methods implementation here.
#include "Student.hpp"
#include <iostream>
using namespace std;

Student::Student(int id, string name, double gpa) {
    this->id = id;
    this->name = name;
    this->gpa = gpa;
    this->courses = nullptr;
}

Student::~Student() {
    CourseNode* temp;
    while (courses != nullptr) {
        temp = courses;
        courses = courses->next;
        delete temp;
    }
}

int Student::getId() const { return id; }
string Student::getName() const { return name; }
double Student::getGpa() const { return gpa; }

void Student::addCourse(const Course& c) {
    CourseNode* newNode = new CourseNode(c);
    if (!courses) {
        courses = newNode;
    } else {
        CourseNode* temp = courses;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
}

void Student::display() const {
    cout << id << " " << name << " " << gpa;
    if (!courses) {
        cout << " None" << endl;
    } else {
        cout << endl << "Courses:" << endl;
        CourseNode* temp = courses;
        while (temp != nullptr) {
            cout << "   ";
            temp->course.display();
            cout << endl;
            temp = temp->next;
        }
    }
}

// LinkedList Implementation
LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::insertStudent(Student s) {
    Node* newNode = new Node(s);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

bool LinkedList::deleteStudent(int id) {
    if (!head) return false;
    if (head->student.getId() == id) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
    Node* curr = head;
    Node* prev = nullptr;
    while (curr && curr->student.getId() != id) {
        prev = curr;
        curr = curr->next;
    }
    if (!curr) return false;
    prev->next = curr->next;
    delete curr;
    return true;
}

Student* LinkedList::searchStudent(int id) {
    Node* temp = head;
    while (temp) {
        if (temp->student.getId() == id) {
            return &(temp->student);
        }
        temp = temp->next;
    }
    return nullptr;
}

void LinkedList::displayAll() const {
    if (!head) {
        cout << "No students in the list." << endl;
        return;
    }
    Node* temp = head;
    cout << "Students in List:" << endl;
    while (temp) {
        temp->student.display();
        temp = temp->next;
    }
}

int LinkedList::countStudents() const {
    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}
