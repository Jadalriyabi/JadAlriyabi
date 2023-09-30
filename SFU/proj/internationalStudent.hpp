#ifndef INTERNATIONAL_STUDENT
#define INTERNATIONAL_STUDENT

using namespace std;
#include <string>
#include "student.hpp"
#include "toefl.hpp"

class InternationalStudent:public Student{
	private:
		string country;
		Toefl toeflScore;
	public:
		//Constructors
		InternationalStudent(string firstName, string lastName, float CGPA, int researchScore, int applicationID, string country, Toefl toeflScore);
		InternationalStudent();
				
		//Member functions
		string getCountry();
		Toefl getToeflScore();
		void setCountry(string country);
		void setToeflScore(Toefl toeflScore);

		//friend functions
		friend int copmareCountry(InternationalStudent student1, InternationalStudent student2);
		friend void swap(InternationalStudent* a, InternationalStudent* b);
		friend int partitionResearch(InternationalStudent stuArr[], int low, int high);
		friend int partitionCGPA(InternationalStudent stuArr[], int low, int high);
		friend int partitionOverall(InternationalStudent stuArr[], int low, int high);
		friend void sortResearchScore(InternationalStudent stuArr[], int low, int high);
		friend void sortCGPA(InternationalStudent stuArr[], int low, int high);
		friend void sortFirstName(InternationalStudent stuArr[], int low, int high);
		friend void sortLastName(InternationalStudent stuArr[], int low, int high);
		friend void sortOverall(InternationalStudent stuArr[], int low, int high);
		friend ostream& operator<<(ostream& outs, InternationalStudent& student);
		friend void print(InternationalStudent stuArr[]);
		friend void printValidStudents(InternationalStudent stuArr[]);
};

#endif