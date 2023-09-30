
using namespace std;
#include "internationalStudent.hpp"
#include "toefl.hpp"
#include <iostream>
#include <string>
#include <cmath>

//Constructors
InternationalStudent::InternationalStudent(string firstName, string lastName, float CGPA, int researchScore, int applicationID, string country, Toefl toeflScore):Student(firstName,lastName,CGPA,researchScore,applicationID){
		this->country = country;
		this->toeflScore = toeflScore;
}
InternationalStudent::InternationalStudent():Student(),country(""),toeflScore(){
}

//Member functions
string InternationalStudent::getCountry(){
	return country;
}
Toefl InternationalStudent::getToeflScore(){
	return toeflScore;
}
void InternationalStudent::setCountry(string country){
	this->country = country;
}
void InternationalStudent::setToeflScore(Toefl toeflScore){
	this->toeflScore = toeflScore;
}


//friend functions
int copmareCountry(InternationalStudent student1, InternationalStudent student2){
	return student1.country.compare(student2.country);
}


//swaping the the values between two InternationalStudent variables (for quicksort)
void swap(InternationalStudent* a, InternationalStudent* b){
  InternationalStudent temp = *a;
  *a = *b;
  *b = temp;
}


//partition function for quicksort in terms of research score
int partitionResearch (InternationalStudent stuArr[], int low, int high){
  
  //pivot variable to compare research score with
  InternationalStudent pivot = stuArr[high];
  
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
int partitionCGPA (InternationalStudent stuArr[], int low, int high){
  InternationalStudent pivot = stuArr[high];
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
int partitionFirstName (InternationalStudent stuArr[], int low, int high){
  InternationalStudent pivot = stuArr[high];
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
int partitionLastName(InternationalStudent stuArr[], int low, int high){
  InternationalStudent pivot = stuArr[high];
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
int partitionOverall(InternationalStudent stuArr[], int low, int high){
	
    //pivot variable to compare research score with
    InternationalStudent pivot = stuArr[high];
    
    //i is the index of the item less than pivot
    int i = low - 1;
    
    for (int j = low; j <= high - 1; j++)  { 
      if(stuArr[j].getToeflScore().passed()){
        //if stuArr[j]'s research score is greater than pivot, swap with an item that had a lower research score than than pivot (at i)
        if(compareResearchScore(stuArr[j],pivot) > 0){
          i++;
          swap(&stuArr[i], &stuArr[j]);
        }
        //if stuArr[j] has the same research score as pivot then do the same checks for CGPA and country
        else if(compareResearchScore(stuArr[j],pivot) == 0){
          if(compareCGPA(stuArr[j],pivot) > 0){
            i++;
            swap(&stuArr[i], &stuArr[j]);
          }
          else if(compareCGPA(stuArr[j],pivot) == 0){
            if(copmareCountry(stuArr[j],pivot) < 0){
              i++;
              swap(&stuArr[i], &stuArr[j]);
            }
          }
        }
      }
    }
    //swap the pivot item into the correct position in the array
    swap(&stuArr[i+1], &stuArr[high]);
    return (i + 1);
}


//sorting function using quicksort in terms of research score 
void sortResearchScore(InternationalStudent stuArr[], int low, int high){   
  if (low < high) {  
    //pIndex is the index of where the pivot is
    int pIndex = partitionResearch(stuArr, low, high);  

    //recursively sorts the elements less than the pivot and geator than the pivot  
    sortResearchScore (stuArr, low, pIndex - 1);  
    sortResearchScore (stuArr, pIndex + 1, high);  
  }  
}
//sorting function using quicksort in terms of CGPA
void sortCGPA(InternationalStudent stuArr[], int low, int high){
  if(low < high) {
    int pIndex = partitionCGPA(stuArr, low, high);
    sortCGPA(stuArr, low, pIndex - 1);
    sortCGPA(stuArr, pIndex + 1, high);
  }
}
//sorting function using quicksort in terms of first name
void sortFirstName(InternationalStudent stuArr[], int low, int high){
  if(low < high) {
    int pIndex = partitionFirstName(stuArr, low, high);
    sortFirstName(stuArr, low, pIndex - 1);
    sortFirstName(stuArr, pIndex + 1, high);
  }
}
//sorting function using quicksort in terms of last name
void sortLastName(InternationalStudent stuArr[], int low, int high){
  if(low < high) {
    int pIndex = partitionLastName(stuArr, low, high);
    sortLastName(stuArr, low, pIndex - 1);
    sortLastName(stuArr, pIndex + 1, high);
  }
}
//sorting function using quicksort in terms of overall
void sortOverall(InternationalStudent stuArr[], int low, int high){
  if(low < high) {
    int pIndex = partitionOverall(stuArr, low, high);
    sortOverall(stuArr, low, pIndex - 1);
    sortOverall(stuArr, pIndex + 1, high);
  }
}

//overloading the output operator for InternationalStdents
ostream& operator<<(ostream& outs, InternationalStudent& student){
	outs<<student.firstName<<" "<<student.lastName<<endl;
	outs<<"Research Score: "<<student.researchScore<<endl;
	//ie. if CGPA is 4, print out 4.0
  if((student.CGPA - floor(student.CGPA)) == 0){
		outs<<"CGPA: "<<student.CGPA<<".0"<<endl;
	}
	else{
		outs<<"CGPA: "<<student.CGPA<<endl;
	}
	outs<<"Country: "<<student.country<<endl;
	outs<<"Total Toefl Score: "<<student.getToeflScore().getTotalScore()<<endl;
	outs<<"Application ID: "<<student.applicationID<<endl;
	return outs;
}

//prints out the entire list of InternationalStudent objects
void print(InternationalStudent stuArr[]){
	for(int i = 0; i < 100; i++){
		cout<<i+1<<" ";
		cout<<stuArr[i]<<endl;
	}
}

//only prints InternationalStudent objects if they passed their toefl exam
void printValidStudents(InternationalStudent stuArr[]){
	int counter = 1;
	for(int i = 0; i < 100; i++){
		if(stuArr[i].getToeflScore().passed()){
			cout<<counter<<" ";
			cout<<stuArr[i]<<endl;
			counter++;
		}
		// else{
		// 	cout<<"INVALID TOEFL";
    //   cout<<stuArr[i];
    //   cout<<stuArr[i].toeflScore<<endl;
		// }	
	}
}



































