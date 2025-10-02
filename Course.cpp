// TODO:  Course class methods implementation here.
#include "Course.hpp"
#include <iostream>
using namespace std;

Course::Course(string cName, string loc) {
    courseName = cName;
    location = loc;
}

string Course::getCourseName() const {
    return courseName;
}

string Course::getLocation() const {
    return location;
}

void Course::setCourseName(const string& cName) {
    courseName = cName;
}

void Course::setLocation(const string& loc) {
    location = loc;
}

void Course::display() const {
    cout << courseName << " " << location;
}
