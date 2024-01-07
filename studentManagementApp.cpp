#include <iostream>
#include <vector>
#include <unordered_map>

class Course {
public:
    Course(const std::string& course_name, double fees) : course_name(course_name), fees(fees) {}

    std::string getCourseName() const {
        return course_name;
    }

    double getFees() const {
        return fees;
    }

private:
    std::string course_name;
    double fees;
};

class Student {
public:
    Student(const std::string& name, int rollno, long long mobile) : name(name), rollno(rollno), mobile(mobile) {}

    void takeCourse(const Course& course) {
        courses.push_back(course);
    }

    std::string getName() const {
        return name;
    }

    int getRollNo() const {
        return rollno;
    }

    long long getMobile() const {
        return mobile;
    }

    std::vector<Course> getCourses() const {
        return courses;
    }

private:
    std::string name;
    int rollno;
    long long mobile;
    std::vector<Course> courses;
};

class SunbeamApplication {
public:
    void registerStudent() {
        std::string name;
        int rollno;
        long long mobile;

        std::cout << "Enter student's name: ";
        std::cin >> name;

        std::cout << "Enter student's roll number: ";
        std::cin >> rollno;

        std::cout << "Enter student's mobile number: ";
        std::cin >> mobile;

        Student student(name, rollno, mobile);
        students.push_back(student);
    }

    void displayStudentCourses() {
        int rollno;
        std::cout << "Enter student's roll number to display courses: ";
        std::cin >> rollno;

        for (const auto& student : students) {
            if (student.getRollNo() == rollno) {
                std::vector<Course> courses = student.getCourses();
                std::cout << "Courses taken by student " << student.getName() << " (Roll No: " << student.getRollNo() << "):\n";
                for (const auto& course : courses) {
                    std::cout << course.getCourseName() << " - Fees: $" << course.getFees() << std::endl;
                }
                return;
            }
        }
        std::cout << "Student with roll number " << rollno << " not found." << std::endl;
    }

    void displayAllStudentsAndCourses() {
        for (const auto& student : students) {
            std::cout << "Student: " << student.getName() << " (Roll No: " << student.getRollNo() << ")" << std::endl;
            std::vector<Course> courses = student.getCourses();
            if (courses.empty()) {
                std::cout << "   No courses registered\n";
            } else {
                std::cout << "   Courses Registered:\n";
                for (const auto& course : courses) {
                    std::cout << "   - " << course.getCourseName() << " - Fees: Rs." << course.getFees() << std::endl;
                }
            }
            std::cout << std::endl;
        }
    }

    void takeCourse() {
        int rollno;
        std::string courseName;
        double fees;

        std::cout << "Enter student's roll number to take course: ";
        std::cin >> rollno;

        std::cout << "Enter course name: ";
        std::cin >> courseName;

        std::cout << "Enter course fees: ";
        std::cin >> fees;

        Course course(courseName, fees);
        for (auto& student : students) {
            if (student.getRollNo() == rollno) {
                student.takeCourse(course);
                std::cout << "Course " << courseName << " added for student " << student.getName() << std::endl;
                return;
            }
        }
        std::cout << "Student with roll number " << rollno << " not found." << std::endl;
    }

private:
    std::vector<Student> students;
};

int main() {
    SunbeamApplication app;
    int choice;

    do {
        std::cout << "\nMenu:\n"
                     "1. Register Student\n"
                     "2. Take Course\n"
                     "3. Display specific student's taken courses\n"
                     "4. Display all students and their courses registered\n"
                     "5. Exit\n"
                     "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                app.registerStudent();
                break;
            case 2:
                app.takeCourse();
                break;
            case 3:
                app.displayStudentCourses();
                break;
            case 4:
                app.displayAllStudentsAndCourses();
                break;
            case 5:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 5);

    return 0;
}
