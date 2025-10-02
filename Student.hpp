// TO DO:  Student class definition  here.
#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "Course.hpp"
#include <string>
#include <iostream>
using namespace std;

// Singly linked list of courses inside each student
struct CourseNode {
    Course course;
    CourseNode* next;
    CourseNode(Course c) : course(c), next(nullptr) {}
};

// Student class
class Student {
private:
    int id;
    string name;
    double gpa;
    CourseNode* courses; // head of course list

public:
    Student(int id = 0, string name = "", double gpa = 0.0);
    ~Student();

    int getId() const;
    string getName() const;
    double getGpa() const;

    void addCourse(const Course& c);
    void display() const;
};

// Node for student linked list
struct Node {
    Student student;
    Node* next;
    Node(Student s) : student(s), next(nullptr) {}
};

// LinkedList class
class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    ~LinkedList();
    void insertStudent(Student s);
    bool deleteStudent(int id);
    Student* searchStudent(int id);
    void displayAll() const;
    int countStudents() const;
};

#endif
