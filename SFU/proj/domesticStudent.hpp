#ifndef DOMESTIC_STUDENT
#define DOMESTIC_STUDENT

using namespace std;
#include <string>
#include "student.hpp"

class DomesticStudent:public Student{
	private:
		string province;
	public:
		//Constructors
		DomesticStudent(string firstName, string lastName, float CGPA, int researchScore, int applicationID, string province);
		DomesticStudent();
		
		//Member functions
		string getProvince();
		void setProvince(string province);

		//friend functions
		friend int compareProvince(DomesticStudent student1, DomesticStudent student2);
		friend void swap(DomesticStudent* a, DomesticStudent* b);
		friend int partitionResearch (DomesticStudent stuArr[], int low, int high);
		friend int partitionCGPA (DomesticStudent stuArr[], int low, int high);
		friend int partitionOverAll(DomesticStudent stuArr[], int low, int hight);
		friend void sortResearchScore(DomesticStudent stuArr[], int low, int high);
		friend void sortCGPA(DomesticStudent stuArr[], int low, int high);
		friend void sortFirstName(DomesticStudent stuArr[], int low, int high);
		friend void sortLastName(DomesticStudent stuArr[], int low, int high);
		friend void sortOverall(DomesticStudent stuArr[], int low, int high);
		friend ostream& operator <<(ostream& outs, DomesticStudent& student);
		friend void print(DomesticStudent stuArr[]);
};

#endif