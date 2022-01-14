#include "Course.h"

void Course::setAll(std::string code, std::string title, double grade, uint8_t creditHour)
{
    this->code=code;
    this->title=title;
    this->grade=grade;
    this->creditHour=creditHour;
    next = nullptr;
}

const std::string &Course::getCode() const {
    return code;
}

void Course::setCode(const std::string &code) {
    Course::code = code;
}

const std::string &Course::getTitle() const {
    return title;
}

void Course::setTitle(const std::string &title) {
    Course::title = title;
}

double Course::getGrade() const {
    return grade;
}

void Course::setGrade(double grade) {
    Course::grade = grade;
}

uint8_t Course::getCreditHour() const {
    return creditHour;
}

void Course::setCreditHour(uint8_t creditHour) {
    Course::creditHour = creditHour;
}

Course *Course::getNext() const {
    return next;
}

void Course::setNext(Course *next) {
    Course::next = next;
}

//Overload the << operator to make cout print all the data about a course
std::ostream &operator<<(std::ostream &os, Course &course) {
    os << course.getCode() << ": " << course.getTitle() << "(Grade: " << course.getGrade() << ") " << +course.creditHour << " Credit Hours" << std::endl;
}
