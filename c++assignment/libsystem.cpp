#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
using namespace std;


class UniversitySystemException : public exception {
protected:
    string message;
public:
    UniversitySystemException(const string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

class EnrollmentException : public UniversitySystemException {
public:
    EnrollmentException(const string& msg) : UniversitySystemException("Enrollment Error: " + msg) {}
};

class GradeException : public UniversitySystemException {
public:
    GradeException(const string& msg) : UniversitySystemException("Grade Error: " + msg) {}
};

class PaymentException : public UniversitySystemException {
public:
    PaymentException(const string& msg) : UniversitySystemException("Payment Error: " + msg) {}
};

// ---------- Logger ----------
void logError(const string& error) {
    ofstream log("error_log.txt", ios::app);
    log << error << endl;
}

// ---------- Base Person Class ----------
class Person {
protected:
    string name;
    int age;
    string ID;
    string contact;

public:
    Person() {}
    Person(string n, int a, string id, string c) {
        setName(n);
        setAge(a);
        setID(id);
        setContact(c);
    }

    void setName(string n) { if (!n.empty()) name = n; }
    void setAge(int a) {
        if (a <= 0 || a >= 150) throw UniversitySystemException("Invalid age: " + to_string(a));
        age = a;
    }
    void setID(string id) {
        if (id.empty()) throw UniversitySystemException("Invalid ID");
        ID = id;
    }
    void setContact(string c) {
        if (c.empty()) throw UniversitySystemException("Invalid contact information");
        contact = c;
    }

    string getName() const { return name; }
    int getAge() const { return age; }
    string getID() const { return ID; }
    string getContact() const { return contact; }

    virtual void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << ", ID: " << ID << ", Contact: " << contact << endl;
    }

    virtual float calculatePayment() { return 0.0; }
};

// ---------- Student Base Class ----------
class Student : public Person {
protected:
    string program;
    string enrollmentDate;
    float GPA;
    vector<string> enrolledCourses;

public:
    Student(string n, int a, string id, string c, string prog, string date, float g)
        : Person(n, a, id, c), program(prog), enrollmentDate(date) {
        setGPA(g);
    }

    void setGPA(float g) {
        if (g < 0.0 || g > 4.0) throw GradeException("Invalid GPA");
        GPA = g;
    }
    float getGPA() const { return GPA; }

    void enrollInCourse(const string& courseCode) {
        enrolledCourses.push_back(courseCode);
    }

    void displayDetails() override {
        Person::displayDetails();
        cout << "Program: " << program << ", GPA: " << GPA << endl;
    }

    float calculatePayment() override {
        return 1000.0;
    }
};

// ---------- UndergraduateStudent ----------
class UndergraduateStudent : public Student {
private:
    string major;
    string minor;
    string expectedGradDate;

public:
    UndergraduateStudent(string n, int a, string id, string c, string prog, string date, float g,
                         string maj, string min, string gradDate)
        : Student(n, a, id, c, prog, date, g), major(maj), minor(min), expectedGradDate(gradDate) {}

    void displayDetails() override {
        Student::displayDetails();
        cout << "Major: " << major << ", Minor: " << minor << ", Graduation: " << expectedGradDate << endl;
    }
};

// ---------- GraduateStudent ----------
class GraduateStudent : public Student {
private:
    string researchTopic;
    string advisorID;
    string thesisTitle;
    int teachingHours;
    int researchHours;

public:
    GraduateStudent(string n, int a, string id, string c, string prog, string date, float g,
                    string topic, string advisor, string thesis)
        : Student(n, a, id, c, prog, date, g), researchTopic(topic), advisorID(advisor), thesisTitle(thesis), teachingHours(0), researchHours(0) {}

    void displayDetails() override {
        Student::displayDetails();
        cout << "Research: " << researchTopic << ", Advisor: " << advisorID << ", Thesis: " << thesisTitle << endl;
    }

    void logTeachingHours(int hours) { teachingHours += hours; }
    void logResearchHours(int hours) { researchHours += hours; }
};

// ---------- Professor Base Class ----------
class Professor : public Person {
protected:
    string department;
    string specialization;
    string hireDate;
    int yearsOfService;
    double baseSalary;
    double researchGrants;

public:
    Professor(string n, int a, string id, string c, string dept, string spec, string date, int years, double salary, double grants)
        : Person(n, a, id, c), department(dept), specialization(spec), hireDate(date), yearsOfService(years), baseSalary(salary), researchGrants(grants) {}

    void displayDetails() override {
        Person::displayDetails();
        cout << "Dept: " << department << ", Spec: " << specialization << endl;
    }

    float calculatePayment() override {
        if (baseSalary < 0) throw PaymentException("Negative salary");
        return baseSalary + yearsOfService * 200 + researchGrants;
    }
};

class AssistantProfessor : public Professor {
public:
    AssistantProfessor(string n, int a, string id, string c, string dept, string spec, string date)
        : Professor(n, a, id, c, dept, spec, date, 1, 4000, 500) {}
};

class AssociateProfessor : public Professor {
public:
    AssociateProfessor(string n, int a, string id, string c, string dept, string spec, string date)
        : Professor(n, a, id, c, dept, spec, date, 5, 6000, 1500) {}
};

class FullProfessor : public Professor {
public:
    FullProfessor(string n, int a, string id, string c, string dept, string spec, string date)
        : Professor(n, a, id, c, dept, spec, date, 10, 8000, 3000) {}
};

// ---------- Course ----------
class Course {
private:
    string code, title, description;
    int credits;
    Professor* instructor; // Aggregation

public:
    Course(string c, string t, int cr, string d, Professor* instr)
        : code(c), title(t), credits(cr), description(d), instructor(instr) {}
};

// ---------- Classroom ----------
class Classroom {
public:
    string roomNumber;
    int capacity;

    Classroom(string room, int cap) : roomNumber(room), capacity(cap) {}
};

// ---------- Schedule ----------
class Schedule {
private:
    struct Slot {
        string courseCode;
        string day;
        string time;
        Classroom classroom;

        Slot(string c, string d, string t, Classroom cr) : courseCode(c), day(d), time(t), classroom(cr) {}
    };

    vector<Slot> slots;

public:
    void addSlot(string code, string day, string time, Classroom cr) {
        slots.emplace_back(code, day, time, cr);
    }
};

// ---------- Department ----------
class Department {
private:
    string name, location;
    double budget;
    vector<Professor*> professors;

public:
    Department(string n, string l, double b) : name(n), location(l), budget(b) {}

    void addProfessor(Professor* prof) {
        professors.push_back(prof);
    }
};


class University {
private:
    vector<Department> departments;

public:
    void addDepartment(const Department& d) {
        departments.push_back(d);
    }
};


class GradeBook {
private:
    vector<string> studentIDs;
    vector<float> grades;

public:
    void addGrade(string studentID, float grade) {
        studentIDs.push_back(studentID);
        grades.push_back(grade);
    }

    float calculateAverageGrade() {
        float sum = 0;
        for (float g : grades) sum += g;
        return grades.empty() ? 0 : sum / grades.size();
    }

    float getHighestGrade() {
        float highest = 0;
        for (float g : grades) if (g > highest) highest = g;
        return highest;
    }

    void getFailingStudents() {
        cout << "Failing students (grade < 40):\n";
        for (int i = 0; i < grades.size(); i++) {
            if (grades[i] < 40)
                cout << studentIDs[i] << " with grade: " << grades[i] << endl;
        }
    }
};

class CourseEnrollment {
public:
    string courseCode;
    vector<string> studentIDs;
    CourseEnrollment(const string& code) : courseCode(code) {}
};

class EnrollmentManager {
private:
    vector<CourseEnrollment> courses;

public:
    void enrollStudent(const string& courseCode, const string& studentID) {
        for (auto& course : courses) {
            if (course.courseCode == courseCode) {
                course.studentIDs.push_back(studentID);
                return;
            }
        }
        CourseEnrollment newCourse(courseCode);
        newCourse.studentIDs.push_back(studentID);
        courses.push_back(newCourse);
    }

    void dropStudent(const string& courseCode, const string& studentID) {
        for (auto& course : courses) {
            if (course.courseCode == courseCode) {
                for (auto it = course.studentIDs.begin(); it != course.studentIDs.end(); ++it) {
                    if (*it == studentID) {
                        course.studentIDs.erase(it);
                        return;
                    }
                }
            }
        }
    }

    int getEnrollmentCount(const string& courseCode) const {
        for (const auto& course : courses) {
            if (course.courseCode == courseCode)
                return course.studentIDs.size();
        }
        return 0;
    }
};


int main() {
    UndergraduateStudent u("riya",19, "24CSU089", "999000", "CSE", "2023-09-01", 3.4, "CS", "Math", "2027-05");

    GraduateStudent g("Raman", 25, "24CSU077", "888000", "MSc", "2022-09-01", 3.9, "AI", "P001", "Deep Learning Models");

    FullProfessor prof("Dr. Vaishali", 55, "P001", "777000", "CS", "AI", "2000-08-15");

    u.displayDetails();
    g.displayDetails();
    prof.displayDetails();

    cout << "\nProfessor Payment: Rs" << prof.calculatePayment() << endl;
    g.logTeachingHours(10);
    g.logResearchHours(20);

    return 0;
}



