#ifndef STUDENT
#define STUDENT

using namespace std; 
#include <string> 

class Student{
	protected:
		string firstName;
		string lastName;
		float CGPA;
		int researchScore;
		int applicationID;

	public:
		//Constructors
		Student(string firstName, string lastName, float CGPA, int researchScore, int applicationID);
		Student();

		//Member functions
		string getFirstName();
		string getLastName();
		float  getCGPA();
		int getResearchScore();
		int getApplicationID();
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setCGPA(float CGPA);
		void setResearchScore(int researchScore);
		void setApplicationID(int applicationID);

		//Friend functions
		friend int compareCGPA(Student student1, Student student2);
		friend int compareResearchScore(Student student1, Student student2);
		friend int compareFirstName(Student student1, Student student2);
		friend int compareLastName(Student student1, Student student2);
		friend ostream& operator <<(ostream& outs, Student& student);
};
//rounding function for CGPA
float round1f(float num);



#endif