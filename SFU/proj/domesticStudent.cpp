using namespace std;
#include "domesticStudent.hpp"
#include <iostream>
#include <string>
#include <cmath>

//constructors
DomesticStudent::DomesticStudent(string firstName, string lastName, float CGPA, int researchScore, int applicationID, string province):Student(firstName,lastName,CGPA,researchScore,applicationID){
	this->province = province;
}
DomesticStudent::DomesticStudent():Student(),province(""){
}


//set functoins
string DomesticStudent::getProvince(){
	return province;
}
void DomesticStudent::setProvince(string province){
	this->province = province;
}
	

//friend functions
//comparing the province between two students
int compareProvince(DomesticStudent student1, DomesticStudent student2){
	return student1.province.compare(student2.province);
}


//swaping the the values between two DomesticStudent variables (for quicksort)
void swap(DomesticStudent* a, DomesticStudent* b){
	DomesticStudent temp = *a;
	*a = *b;
	*b = temp;
}


//partition function for quicksort in terms of research score
int partitionResearch (DomesticStudent stuArr[], int low, int high){
	
	//pivot variable to compare research score with
	DomesticStudent pivot = stuArr[high];
	
	//i is the index of the item less than pivot
	int i = low - 1;

	for (int j = low; j <= high -1; j++)  { 
		//if stuArr[j]'s research score is greater than pivot, swap with an item has a lower research score than pivot (at i)
		if (compareResearchScore(stuArr[j],pivot) > 0){
			i++;
			swap(&stuArr[i], &stuArr[j]);
		}
	}
	//swap the pivot item into the correct position in the array
	swap(&stuArr[i+1], &stuArr[high]);
	return(i + 1);
}

//partition function for quicksort in terms of CGPA
int partitionCGPA (DomesticStudent stuArr[], int low, int high){
	DomesticStudent pivot = stuArr[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++)  { 
		if (compareCGPA(stuArr[j],pivot) > 0){
		i++;
		swap(&stuArr[i], &stuArr[j]);
		}
	}
	swap(&stuArr[i+1], &stuArr[high]);
	return (i + 1);
}
//partition function for quicksort in terms of first name
int partitionFirstName (DomesticStudent stuArr[], int low, int high){
	DomesticStudent pivot = stuArr[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++)  { 
		if (compareFirstName(stuArr[j],pivot) < 0){
		i++;
		swap(&stuArr[i], &stuArr[j]);
		}
	}
	swap(&stuArr[i+1], &stuArr[high]);
	return (i + 1);
}
//partition function for quicksort in terms of last name
int partitionLastName(DomesticStudent stuArr[], int low, int high){
	DomesticStudent pivot = stuArr[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++)  { 
		if (compareLastName(stuArr[j],pivot) < 0){
		i++;
		swap(&stuArr[i], &stuArr[j]);
		}
	}
	swap(&stuArr[i+1], &stuArr[high]);
	return (i + 1);
}

//partition function for quicksort in terms of overall
int partitionOverall(DomesticStudent stuArr[], int low, int high){
	
	//pivot variable to compare research score with
	DomesticStudent pivot = stuArr[high];
	
	//i is the index of the item less than pivot
	int i = low - 1;

	for (int j = low; j <= high - 1; j++)  { 
		//if stuArr[j]'s research score is greater than pivot, swap with an item that had a lower research score than than pivot (at i)
		if(compareResearchScore(stuArr[j],pivot) > 0){
			i++;
			swap(&stuArr[i], &stuArr[j]);
		}
		//if stuArr[j] has the same research score as pivot then do the same checks for CGPA and province
		else if(compareResearchScore(stuArr[j],pivot) == 0){
			if(compareCGPA(stuArr[j],pivot) > 0){
				i++;
				swap(&stuArr[i], &stuArr[j]);
			}
			else if(compareCGPA(stuArr[j],pivot) == 0){
				if(compareProvince(stuArr[j],pivot) < 0){
					i++;
					swap(&stuArr[i], &stuArr[j]);
				}
			}
		}
	}
	//swap the pivot item into the correct position in the array
	swap(&stuArr[i+1], &stuArr[high]);
	return (i + 1);
}


//sorting function using quicksort in terms of research score 
void sortResearchScore(DomesticStudent stuArr[], int low, int high){   
	if (low < high) {  
		//pIndex is the index of where the pivot is
		int pIndex = partitionResearch(stuArr, low, high);  

		//recursively sorts the elements less than the pivot and geator than the pivot
		sortResearchScore (stuArr, low, pIndex - 1);  
		sortResearchScore (stuArr, pIndex + 1, high);  
	}  
}
//sorting function using quicksort in terms of CGPA
void sortCGPA(DomesticStudent stuArr[], int low, int high){
  if(low < high) {
    int pIndex = partitionCGPA(stuArr, low, high);
    sortCGPA(stuArr, low, pIndex - 1);
    sortCGPA(stuArr, pIndex + 1, high);
  }
}
//sorting function using quicksort in terms of first name
void sortFirstName(DomesticStudent stuArr[], int low, int high){
  if(low < high) {
    int pIndex = partitionFirstName(stuArr, low, high);
    sortFirstName(stuArr, low, pIndex - 1);
    sortFirstName(stuArr, pIndex + 1, high);
  }
}
//sorting function using quicksort in terms of last name
void sortLastName(DomesticStudent stuArr[], int low, int high){
  if(low < high) {
    int pIndex = partitionLastName(stuArr, low, high);
    sortLastName(stuArr, low, pIndex - 1);
    sortLastName(stuArr, pIndex + 1, high);
  }
}
//sorting function using quicksort in terms of overall
void sortOverall(DomesticStudent stuArr[], int low, int high){
  if(low < high) {
    int pIndex = partitionOverall(stuArr, low, high);
    sortOverall(stuArr, low, pIndex - 1);
    sortOverall(stuArr, pIndex + 1, high);
  }
}

//overloading the output operator for DomesticStudent objects
ostream& operator<<(ostream& outs, DomesticStudent& student){
	outs<<student.firstName<<" "<<student.lastName<<endl;
	outs<<"Research Score: "<<student.researchScore<<endl;
	//ie. if CGPA is 4, print out 4.0
	if((student.CGPA - floor(student.CGPA)) == 0){
		outs<<"CGPA: "<<student.CGPA<<".0"<<endl;
	}
	else{
		outs<<"CGPA: "<<student.CGPA<<endl;
	}
	outs<<"Province: "<<student.province<<endl;
	outs<<"Application ID: "<<student.applicationID<<endl;
	return outs;
}

//prints out the entire list of DomesticStudent objects
void print(DomesticStudent stuArr[]){
	for(int i = 0; i < 100; i++){
		cout<<i+1<<" ";
		cout<<stuArr[i]<<endl;
	}
}