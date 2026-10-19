#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Student {
    protected:
        string firstName;
        string lastName;
        double gpa;
        int graduationYear;
        string graduationSemester;
        int enrollmentYear;
        string enrollmentSemester;
        string levelOfStudy;

    public:
// constructor (runs automatically when an object is created)
        Student()
        {
            firstName = "";
            lastName = "";
            gpa = 0.0;
            graduationYear = 0;
            graduationSemester = "";
            enrollmentYear = 0;
            enrollmentSemester = "";
            levelOfStudy = "";
        }
    
        //Destructor (runs automatically when an object is destroyed)
        virtual ~Student() {

        } 

        void setName(string first, string last) {
            firstName = first;
            lastName = last; 
        }


        void setGPA(double value) {
            
            gpa = value;    

        }

        string getName() {
            return firstName + " " + lastName;
        }   

        double getGPA() {
            return gpa;
        }

    };

    //getters for graduation year
    int getGraduationYear() {
        return graduationYear;
    }   

    void setGraduationSemester(string semester) {
        
        graduationSemester = semester;      
    }

    string getGraduationSemester() {
        return graduationSemester;
    }   

    void setEnrollmentYear(int year) {
        enrollmentYear = year;
    }

    int getEnrollmentYear() {
        return enrollmentYear;
    }   

    void getEnrollmentSemester() {
        enrollmentSemester = semester;

    }

    


