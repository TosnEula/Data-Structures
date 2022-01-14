#include "Records.h"

Records::Records() {
    averageGpa = 0;
    setNumberOfStudents(0);
    students = nullptr;
}

//Adds a student to the end of the list
void Records::addStudent(uint32_t r_Uid, const std::string r_Name, uint8_t r_Age, uint32_t r_TotalCreditHours,
                         uint32_t r_NumberOfCourses, double r_Gpa) {
    //If there are no students in the list make a new location on the Stack
    if (!students) {
        students = new Student(r_Uid, r_Name, r_Age, r_TotalCreditHours, r_NumberOfCourses, r_Gpa);
        numberOfStudents++;
        return;
    }

    Student *p = students;
    while (p->getStudNext() != nullptr)
    {
            p = p->getStudNext();
    }
    p->setStudNext(new Student(r_Uid, r_Name, r_Age, r_TotalCreditHours, r_NumberOfCourses, r_Gpa));
    p->getStudNext()->setStudPrev(p);
    numberOfStudents++;
    calculateAverageGpa();
};


void Records::deleteStudent(uint32_t r_Uid) {
    //If the student list was never defined escape
    if (!students)
    {
        std::cout << "No student has been added to the records" << std::endl;
        return;
    }

    //if the student is the first on the list move the head forward by one and delete the previous
    if (students->getUid() == r_Uid)
    {
        students = students->getStudNext();
        students->setStudPrev(nullptr);
        delete students->getStudPrev();
        numberOfStudents--;
        return;
    }

    Student *p = students; //pointer defined at head to search through the list

    //Search the list for the student and delete it.
    while (p)
    {

        if(p->getUid() == r_Uid)
        {
            //if the student to be deleted is the last node
            if(p->getStudNext() == nullptr)
            {
                p->getStudPrev()->setStudNext(nullptr);
                delete p;
                numberOfStudents--;
                std::cout << "Student " << r_Uid << " has been removed" << std::endl;
                calculateAverageGpa();
                return;
            }
            else
            {
            //set the node ahead of the node to be deleted previous pointer to the second behind it.
            p->getStudNext()->setStudPrev(p->getStudPrev());
            //set the node behind the node to be deleted next pointer to the second in front.
            p->getStudPrev()->setStudNext(p->getStudNext());
            delete p;
            numberOfStudents--;
            std::cout << "Student " << r_Uid << " has been removed" << std::endl;
            calculateAverageGpa();
            return;
            }
        }
        else
        p = p->getStudNext();
    }

    //Should p exist that means that the student was found

        std::cout << "Cannot find a student with the UID " << r_Uid << std::endl;
        return;


}

//Add a course to a specific student
void Records::addCourse(uint32_t r_uid, std::string r_Code, std::string r_Title, uint8_t r_CreditHour, double r_Grade) {
    Student *p = students;
    while (p->getUid() != r_uid && p != nullptr) {
        p = p->getStudNext();
    }

    if (p->getUid()==r_uid) {
        p->addCourse(r_Code, r_Title, r_CreditHour, r_Grade);
    } else {
        std::cout << "Cannot find student with UID: " << r_uid << std::endl;
    }

}

void Records::deleteCourse(uint32_t r_uid, std::string r_Code) {
    Student *p = students;
    //Finds the student to be deleted
    while (p->getUid() != r_uid && p != nullptr) {
        p = p->getStudNext();
    }

    if (p->getUid()==r_uid)
    {
        p->deleteCourse(r_Code);
    }
    else
    {
        std::cout << "Cannot find student with UID: " << r_uid << std::endl;
    }
}


uint32_t Records::getNumberOfStudents() const {
    return numberOfStudents;
}

void Records::setNumberOfStudents(uint32_t numberOfStudents) {
    Records::numberOfStudents = numberOfStudents;
}

double Records::getAverageGpa() const {
    return averageGpa;
}

//Iterates through all the students and adds all their GPAs and divides it by the amount there are

void Records::calculateAverageGpa() {
    double holder = 0;
    int count = 0;
    Student *p = students;

    while (p) {
        holder += p->getGpa();
        p = p->getStudNext();
        count++;
    }

    averageGpa = holder / count;
}

void Records::printAll() {

    if (!students)//ensures that there are students in the record
    {
        std::cout << "The record is empty" << std::endl;
        return;
    }

    Student *p = students;
    while (p)//while there are still students continue to print.
    {

        std::cout << *(p);
        p = p->getStudNext();

    }


}

//Prints the information of one student
void Records::printSingle(uint32_t r_uid)
{
    if (!students)//ensures that there are students in the record
    {
        std::cout << "The record is empty" << std::endl;
        return;
    }

    Student *p = students;
    while (p->getUid() != r_uid)
    {
        p = p->getStudNext();
    }

    std::cout << *(p);
}

//overloads the << to print the information of a student
// by referring to the previous overloaded function in student.
std::ostream &operator<<(std::ostream &cos, Records &record)
 {
    cos << *record.students;
    return cos;
}