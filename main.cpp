
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

//Class for all students
class Student {
protected:
    string firstName = "";
    string lastName = "";
    double gpa = 0.0;
    int graduationYear = 0;
    string graduationSemester = "";
    int enrollmentYear = 0;
    string enrollmentSemester = "";
    string levelOfStudy = "";

    
public:
    // Default constructor
    Student() {}

    // Destructor
    virtual ~Student() {}

    // Setters and getters for student information
    void setName(string first, string last) {
        firstName = first;
        lastName = last;
    }

    string getName() { return firstName + " " + lastName; }

    void setGPA(double value) { gpa = value; }
    double getGPA() { return gpa; }

    void setGraduationYear(int year) { graduationYear = year; }
    int getGraduationYear() { return graduationYear; }

    void setGraduationSemester(string semester) { graduationSemester = semester; }
    string getGraduationSemester() { return graduationSemester; }

    void setEnrollmentYear(int year) { enrollmentYear = year; }
    int getEnrollmentYear() { return enrollmentYear; }

    void setEnrollmentSemester(string semester) { enrollmentSemester = semester; }
    string getEnrollmentSemester() { return enrollmentSemester; }

    void setLevelOfStudy(string level) { levelOfStudy = level; }
    string getLevelOfStudy() { return levelOfStudy; }

    // Write common student information to a file
    void writeInfo(ofstream& file) {
        file << getName() << ", " << gpa << ", "
             << graduationYear << ", " << graduationSemester << ", "
             << enrollmentYear << ", " << enrollmentSemester << ", "
             << levelOfStudy;
    }
};


// Derived class for Art students
class Art_Student : public Student {
protected:
    string artEmphasis = "";

public:
    // Constructor and destructor
    Art_Student() {}
    ~Art_Student() {}

    // Setter for Art emphasis
    void setArtEmphasis(string emphasis) {
        if (emphasis == "Art History" ||
            emphasis == "Art Education" ||
            emphasis == "Art Studio") {
            artEmphasis = emphasis;
        }
    }

    // Getter for Art emphasis
    string getArtEmphasis() { return artEmphasis; }
};


// Derived class for Physics students
class Physics_Student : public Student {
protected:
    string concentration = "";

public:
    // Constructor and destructor
    Physics_Student() {}
    ~Physics_Student() {}

    // Setter for Physics concentration
    void setConcentration(string value) {
        if (value == "Biophysics" ||
            value == "Earth and Planetary Sciences") {
            concentration = value;
        }
    }

    // Getter for Physics concentration
    string getConcentration() { return concentration; }
};

