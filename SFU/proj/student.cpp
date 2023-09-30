//student.cpp to implement your classes
using namespace std;
#include "student.hpp"
#include <stdlib.h> //exit
#include <iostream> //cout
#include <string> //strings, compare()
#include <cmath>

//Constructors
Student::Student(string firstName, string lastName, float CGPA, int researchScore, int applicationID){
	//error checking CGPA, researchScore, applicationID
	if(CGPA < 0 || round1f(CGPA) > (float)4.3){
		std::cout<<"Error (Student): CGPA"<<CGPA<<" is in valid.\n";
		this->CGPA = 0;
	}
	else{
		this->CGPA = round1f(CGPA);
	}
	if(researchScore < 0 || researchScore > 100){
		std::cout<<"Error (Student): researchScore cannot be a negative number.\n";
		this->researchScore = 0;
	}
	else{
		this->researchScore = researchScore;
	}
	if(applicationID < 0 || applicationID > 20210000){
		std::cout<<"Error (Student): applicationID cannot be a negative number.\n";
		this->applicationID = 0;
	}
	else{
		this->applicationID = applicationID;
	}
	this->firstName = firstName;
	this->lastName = lastName;
}
Student::Student():firstName(""),lastName(""),CGPA(0),researchScore(0),applicationID(0){
}

//Get functions
string Student::getFirstName(){
	return firstName;
}
string Student::getLastName(){
	return lastName;
}
float Student::getCGPA(){
	return CGPA;
}
int Student::getResearchScore(){
	return researchScore;
}
int Student::getApplicationID(){
	return applicationID;
}

//Set functions
void Student::setFirstName(string firstName){
	this->firstName = firstName;
}
void Student::setLastName(string lastName){
	this->lastName = lastName;
}
void Student::setCGPA(float CGPA){
	//error checking 
	if(CGPA < 0 || round1f(CGPA) > (float)4.3){
		std::cout<<"Error (setCGPA): CGPA"<<round1f(CGPA)<<" is invalid.\n";
	}
	else{
		this->CGPA = round1f(CGPA);
	}
}
void Student::setResearchScore(int researchScore){
	//error checking
	if(researchScore < 0 || researchScore > 100){
		std::cout<<"Error (setResearchScore): researchScore cannot be a negative number.\n";
	}
	else{
		this->researchScore = researchScore;
	}
}
void Student::setApplicationID(int applicationID){
	//error checking
	if(applicationID < 0 || applicationID > 20210000){
		std::cout<<"Error (setApplicationID): applicationID cannot be a negative number.\n";
	}
	else{
		this->applicationID = applicationID;
	}
}

//Friend functions
//comparing the CGPA between two students
int compareCGPA(Student student1, Student student2){
	if(student1.CGPA < student2.CGPA){
		return -1;
	}else if(student1.CGPA == student2.CGPA){
		return 0;
	}
	return 1;
}

//comparing the research score between two students
int compareResearchScore(Student student1, Student student2){
	if(student1.researchScore < student2.researchScore){
		return -1;
	}else if(student1.researchScore == student2.researchScore){
		return 0;
	}
	return 1;
}

//comparing the first names between two students
int compareFirstName(Student student1, Student student2){
	return student1.firstName.compare(student2.firstName);
}

//comparing the last names between two students
int compareLastName(Student student1, Student student2){
	return student1.lastName.compare(student2.lastName);
}

//overloading the output operator
ostream& operator<<(ostream& outs, Student& student){
	outs<<student.firstName<<" "<<student.lastName<<endl;
	//ie. if CGPA is 4, print out 4.0
	if((student.CGPA - floor(student.CGPA)) == 0){
		outs<<"CGPA: "<<student.CGPA<<".0"<<endl;
	}
	else{
		outs<<"CGPA: "<<student.CGPA<<endl;
	}
	outs<<"Research Score: "<<student.researchScore<<endl;
	outs<<"Application ID: "<<student.applicationID<<endl;
	return outs;
}


//round function to the first decimal. Used to round the CGPA 
float round1f(float num){
	return roundf(num * 10)/10;
}
