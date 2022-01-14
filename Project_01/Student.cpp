#include "Student.h"

//constructor of student
Student::Student(uint32_t uid, const std::string &name, uint8_t age, uint32_t totalCreditHours, uint32_t numberOfCourses,
                 double gpa):Person(name, age)
{
    set_Name(name);
    set_Age(age);
    this->uid = uid;
    this->totalCreditHours = totalCreditHours;
    this->numberOfCourses = numberOfCourses;
    this->gpa = gpa;
    studNext = nullptr;
    studPrev = nullptr;
    courses = nullptr;

}

void Student::addCourse(std::string a_Code, std::string a_Title, uint8_t a_CreditHour, double a_grade)
{

    //Check to make sure that course exists
    if (!courses)
    {
        std::cout <<"enter";
        courses = new Course;
        courses->setAll(a_Code, a_Title, a_grade, a_CreditHour);
        numberOfCourses = 1;
        return;
    }

    //If the course already exists
    //create pointer p and move it to the end of the list
    //once at the end of the list add the course
    Course *p=courses;
    while(p->getNext() != nullptr)
    {
        p = p->getNext();
    }
    p->setNext(new Course);
    p = p->getNext();
    p->setAll(a_Code, a_Title, a_grade, a_CreditHour);
    numberOfCourses++;

}


void Student::deleteCourse(std::string a_code)
{
    if(!courses)//Checks if there is anything in the linked list
    {
        std::cout << "No course exists for this student" << std::endl;
        return;
    }
        Course *p = courses;
        Course *q = nullptr;

        //If the first course needs to be removed
        //set the head to the next and remove the previous head
        if (courses->getCode()==a_code)
        {
            courses = courses->getNext();
            delete p;
            numberOfCourses--;
            std::cout << "Course " << a_code << " has been removed" << std::endl;
            return;
        }

        //Search through the list to find the course with the given code
        while (p->getNext())
        {

            if(p->getNext()->getCode() == a_code)
            {
                //If the course to be removed is the last in the list
                //set the next of the previous course to null and delete the last
                if(p->getNext()->getNext() == nullptr)
                {
                    q=p->getNext();
                    p->setNext(nullptr);
                    delete q;
                    numberOfCourses--;
                    std::cout << "Course " << a_code << " has been removed" << std::endl;
                    return;
                }

                //course to be deleted is located somewhere in the middle of the list
                //set the next of the course behind the course to be deleted to the course after the course to be deleted
                //and set the previous of the course ahead of the course to be deleted to the previous
                q = p->getNext();
                p->setNext(q->getNext());
                delete q;
                std::cout << "Course " << a_code << " has been removed" << std::endl;
                numberOfCourses--;
                return;
            }
            p = p->getNext();
        }

   std::cout << "No course exists with the title " << a_code << " in this student" << std::endl;
}

//overload of the << operator
//pass all the information of a single student to cout
//and prints it all in a format
std::ostream& operator<< (std::ostream &os, Student& student) {
    os << "UID: " << student.getUid() << std::endl;
    os << "Name: " << student.get_Name() << std::endl;
    os << "Credit Hours: " << student.getTotalCreditHours() << std::endl;
    os << "Age: " << +student.get_Age() <<std::endl;
    os << "Number of Courses: " << student.getNumberOfCourses() << std::endl;
    os << "Gpa: " << student.getGpa() << std::endl;
    os << "courses" << std::endl;

    Course *p = student.courses;
    while(p)
    {
        os << *p;
        p=p->getNext();
    }

    os << std::endl;
    return os;

}

//Setter and getter methods
unsigned int Student::getTotalCreditHours() const {
    return totalCreditHours;
}

void Student::setTotalCreditHours(unsigned int totalCreditHours) {
    Student::totalCreditHours = totalCreditHours;
}

unsigned int Student::getNumberOfCourses() const {
    return numberOfCourses;
}

void Student::setNumberOfCourses(unsigned int numberOfCourses) {
    Student::numberOfCourses = numberOfCourses;
}

unsigned int Student::getUid() const {
    return uid;
}

void Student::setUid(unsigned int uid) {
    Student::uid = uid;
}

double Student::getGpa() const {
    return gpa;
}

void Student::setGpa(double gpa) {
    Student::gpa = gpa;
}

Student *Student::getStudNext() const {
    return studNext;
}

void Student::setStudNext(Student *studNext) {
    Student::studNext = studNext;
}

Student *Student::getStudPrev() const {
    return studPrev;
}

void Student::setStudPrev(Student *studPrev) {
    Student::studPrev = studPrev;
}

