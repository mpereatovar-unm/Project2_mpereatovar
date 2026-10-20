

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Base class   
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
    // Constructor
    Student() {}

    // Destructor
    virtual ~Student() {}

    // Setters and getters for student information
    void setName(string first, string last) {
        firstName = first;
        lastName = last;
    }

    string getName() {
        return firstName + " " + lastName;
    }

    void setGPA(double value) { gpa = value; }
    double getGPA() { return gpa; }

    void setGraduationYear(int year) { graduationYear = year; }
    int getGraduationYear() { return graduationYear; }

    void setGraduationSemester(string semester) {
        graduationSemester = semester;
    }
    string getGraduationSemester() { return graduationSemester; }

    void setEnrollmentYear(int year) { enrollmentYear = year; }
    int getEnrollmentYear() { return enrollmentYear; }

    void setEnrollmentSemester(string semester) {
        enrollmentSemester = semester;
    }
    string getEnrollmentSemester() { return enrollmentSemester; }

    void setLevelOfStudy(string level) { levelOfStudy = level; }
    string getLevelOfStudy() { return levelOfStudy; }

    
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

    // Setter for art emphasis
    void setArtEmphasis(string emphasis) {
        if (emphasis == "Art Studio" ||
            emphasis == "Art History" ||
            emphasis == "Art Education") {
            artEmphasis = emphasis;
        }
        else {
            cout << "Invalid Art emphasis!" << endl;
        }
    }

    // Getter for art emphasis
    string getArtEmphasis() {
        return artEmphasis;
    }
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
        else {
            cout << "Invalid Physics concentration!" << endl;
        }
    }

    // Getter for Physics concentration
    string getConcentration() {
        return concentration;
    }
};


// Main function
int main() {

    // Create vectors to store student pointers
    vector<Art_Student*> art_students;
    vector<Physics_Student*> physics_students;

    // Create 5 Art students and 5 Physics students
    for (int i = 0; i < 5; i++) {

        // Allocate memory for each student
        art_students.push_back(new Art_Student);
        physics_students.push_back(new Physics_Student);

        // Assign information to Art students
        art_students[i]->setName("Art", to_string(i + 1));
        art_students[i]->setGPA(3.0 + i * 0.2);
        art_students[i]->setGraduationYear(2027 + i);
        art_students[i]->setGraduationSemester("Spring");
        art_students[i]->setEnrollmentYear(2023 + i);
        art_students[i]->setEnrollmentSemester("Fall");
        art_students[i]->setLevelOfStudy("Undergraduate");

        // Choose one of the allowed Art emphases
        if (i % 3 == 0)
            art_students[i]->setArtEmphasis("Art Studio");
        else if (i % 3 == 1)
            art_students[i]->setArtEmphasis("Art History");
        else
            art_students[i]->setArtEmphasis("Art Education");

        // Assign information to Physics students
        physics_students[i]->setName("Physics", to_string(i + 1));
        physics_students[i]->setGPA(3.0 + i * 0.2);
        physics_students[i]->setGraduationYear(2027 + i);
        physics_students[i]->setGraduationSemester("Spring");
        physics_students[i]->setEnrollmentYear(2023 + i);
        physics_students[i]->setEnrollmentSemester("Fall");
        physics_students[i]->setLevelOfStudy("Undergraduate");

        // Choose one of the allowed Physics concentrations
        if (i % 2 == 0)
            physics_students[i]->setConcentration("Biophysics");
        else
            physics_students[i]->setConcentration("Earth and Planetary Sciences");
    }

    // Open a file to save student information
    ofstream outfile("student_info.dat");

    // Check if the file opened successfully
    if (outfile.is_open()) {

        // Loop through all 5 students in each vector
        for (int i = 0; i < 5; i++) {

            // Write Art student information
            art_students[i]->writeInfo(outfile);
            outfile << ", "
                    << art_students[i]->getArtEmphasis() << endl;

            // Write Physics student information
            physics_students[i]->writeInfo(outfile);
            outfile << ", "
                    << physics_students[i]->getConcentration() << endl;
        }

        // Close the file
        outfile.close();

        cout << "Student information saved!" << endl;
    }
    else {
        cout << "Error opening file!" << endl;
    }

    // Delete the dynamically allocated students
    // This prevents memory leaks
    for (int i = 0; i < 5; i++) {
        delete art_students[i];
        delete physics_students[i];
    }

    return 0; 
}


/* Personal notes for me about Project 2: 
Student is the base class (parent class).
protected means its variables can be accessed inside the class and its derived classes.
It stores basic student information such as name, GPA, enrollment date, and graduation date.
The constructor Student() gives each variable a starting value.
The destructor virtual ~Student() runs when an object is destroyed and allows safe deletion through a base-class pointer.
Setters (setGPA(), setName(), etc.) assign or change information.
Getters (getGPA(), getName(), etc.) return information.
writeInfo() writes the student's common information to a file.

Art_Student is a derived class (child class).
: public Student means it inherits the public functionality of Student.
It can use functions such as setName() and setGPA() without writing them again.
It adds one new variable called artEmphasis.
The constructor initializes the art emphasis.
setArtEmphasis() assigns an emphasis.
getArtEmphasis() returns the emphasis.
The setter checks that the emphasis is one of three allowed options: Art Studio, Art History, or Art Education.

Physics_Student is another derived class.
It inherits the Student class's variables and functions.
It adds a variable called concentration.
The constructor initializes the concentration.
setConcentration() assigns a concentration.
getConcentration() returns the concentration.
The setter accepts only Biophysics or Earth and Planetary Sciences.

main() is not a class. It is the function where your program starts executing.
Notes
- Creates two vectors: art_students and physics_students.
- Uses new to dynamically create 5 Art students and 5 Physics students.
- Uses a for loop to assign information to each student.
- Uses ofstream to open student_info.dat.
- Calls writeInfo() to save the student information.
- Uses delete to free the memory allocated for the students.
*/