using namespace std;
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include "student.hpp"
#include "domesticStudent.hpp"
#include "internationalStudent.hpp"

int main(){
  
  //Getting data from the .txt files

  //Reading the domestic-stu.txt file and exit if failed
  DomesticStudent domesticArr[100];
  string firstName, lastName, province, s_CGPA, s_researchScore, line;
  float CGPA;
  int researchScore, index = 0;

  ifstream domesticFile("domestic-stu.txt");
  if(!domesticFile.is_open()) {
    cout << "Unable to open file domestic-stu.txt" << endl;
    return -1;
  }
  getline(domesticFile, line);
  cout << "File format: " << line << endl;

  //inputing data into domesitcArr
  while( getline(domesticFile, line) ) {

    istringstream ss(line);

    //get firstName separated by comma
    getline(ss, firstName, ',');
    domesticArr[index].setFirstName(firstName);

    //get lastName separated by comma
    getline(ss, lastName, ',');
    domesticArr[index].setLastName(lastName);

    //get province separated by comma
    getline(ss, province, ',');
    domesticArr[index].setProvince(province);

    //get cpga separated by comma, and convert string to float
    getline(ss, s_CGPA, ',');
    CGPA = atof(s_CGPA.c_str());
    domesticArr[index].setCGPA(CGPA);

    //get researchScore separated by comma, and convert it to int
    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());
    domesticArr[index].setResearchScore(researchScore);

    //setting application ID
    domesticArr[index].setApplicationID(20200000 + index);

    //print the student info to the screen
    cout << "Domestic student " << index + 1 << " ";
    cout << domesticArr[index].getFirstName() << " ";
	  cout << domesticArr[index].getLastName() << " from ";
    cout << domesticArr[index].getProvince() << " province has CGPA of ";
    cout << domesticArr[index].getCGPA() << ", and research score of ";
    cout << domesticArr[index].getResearchScore() << endl;
    index++;
  }
  //closing the file
  domesticFile.close();





  
  //Reading the international-stu.txt file and exit if failed
  InternationalStudent internationalArr[100];
  string country,s_reading,s_listening,s_speaking,s_writing;
  int reading, listening, speaking, writing;
  index = 0;

  ifstream internationalFile("international-stu.txt");
  if(!internationalFile.is_open()) {
    cout << "Unable to open file international-stu.txt" << endl;
    return -1;
  }
  getline(internationalFile, line);
  cout << "File format: " << line << endl;

  while( getline(internationalFile, line) ) {

    istringstream ss(line);

    //get firstName separated by comma
    getline(ss, firstName, ',');
    internationalArr[index].setFirstName(firstName);

    //get lastName separated by comma
    getline(ss, lastName, ',');
    internationalArr[index].setLastName(lastName);

    //get country separated by comma
    getline(ss, country, ',');
    internationalArr[index].setCountry(country);

    //get cpga separated by comma, and convert string to float
    getline(ss, s_CGPA, ',');
    CGPA = atof(s_CGPA.c_str());
    internationalArr[index].setCGPA(CGPA);

    //get researchScore separated by comma, and convert it to int
    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());
    internationalArr[index].setResearchScore(researchScore);

    //get reading separated by comma, and convert it to int
    getline(ss, s_reading, ',');
    reading = atoi(s_reading.c_str());

    //get listening separated by comma, and convert it to int
    getline(ss, s_listening, ',');
    listening = atoi(s_listening.c_str());

    //get speaking separated by comma, and convert it to int
    getline(ss, s_speaking, ',');
    speaking = atoi(s_speaking.c_str());

    //get writing separated by comma, and convert it to int
    getline(ss, s_writing, ',');
    writing = atoi(s_writing.c_str());

    //setting toefl scores
    Toefl toeflScore(reading,listening,speaking,writing);
    internationalArr[index].setToeflScore(toeflScore);

    //setting application ID
    internationalArr[index].setApplicationID(20200100 + index);

    //print the student info to the screen
    cout << "International student " << index + 1 << " ";
    cout << internationalArr[index].getFirstName() << " ";
	  cout << internationalArr[index].getLastName() << " from ";
    cout << internationalArr[index].getCountry() << " has CGPA of ";
    cout << internationalArr[index].getCGPA() << ", research score of ";
    cout << internationalArr[index].getResearchScore() << ", and a total toefl score of ";
    cout << internationalArr[index].getToeflScore().getTotalScore() << endl;

    index++;
  }
  //closing file
  internationalFile.close();




  // M E N U 
  
  int studentType;
  int userInput; 
  cout << "G R A D U A T E   A D M I S S I O N   S Y S T E M" << endl;
  while(true){
    //asking user for which array to sort
    while(true){
      cout << " Input one of the following";
      cout << "\n****************************************************************\n";
      cout << " (0) - Exit the program\n";
      cout << " (1) - Domestic students\n";
      cout << " (2) - International students\n";
      cout << "****************************************************************\n";
      cout << "Input: ";
      cin >> studentType;
      cout << "\n\n";

      //exits while loop
      if(studentType == 0){
        cout<<"(0) Exiting program\n";
        break;
      }
      //asking user for which sorting method to use
      cout << " Input one of the following for";
      if(studentType == 1){
        cout<<" Domestic students";
        break;
      }
      else if(studentType == 2){
        cout<<" International students";
        break;
      }
      //if input is not 1 or 2 it's an invalid input
      else{
        cout<<"Invalid input\n";
      }
    }

    //exits program
    if(studentType == 0)
    {
      break;
    }
    

    //MENU
		cout << "\n****************************************************************\n";
    cout << " (0) - Exit the program\n";
    cout << " (1) - Sort by CGPA\n";
    cout << " (2) - Sort by research score\n";
    cout << " (3) - Sort by first name\n";
    cout << " (4) - sort by last name\n";
    cout << " (5) - sort by overall performance\n";
    cout << "****************************************************************\n";
    cout << "Input: ";
    cin >> userInput;
    cout << "\n\n";

    if(userInput == 0){
      cout<<"(0) Exiting program\n";
      break;
    }

    //sorting by CGPA 
    else if(userInput == 1){
      cout << "\n\n(1) Sort by CGPA\n";
			cout << "****************************************************************\n";
      
      if(studentType == 1){
        sortCGPA(domesticArr, 0, 99);
        print(domesticArr);
      }
      else if(studentType == 2){
        sortCGPA(internationalArr, 0, 99);
        print(internationalArr);
      }
    }
    
    //sorting by research score
    else if (userInput == 2){
      cout << "\n\n(2) Sort by research score\n";
			cout << "****************************************************************\n";
      if(studentType == 1){
        sortResearchScore(domesticArr, 0, 99);
        print(domesticArr);
      }
      else if(studentType == 2){
        sortResearchScore(internationalArr, 0, 99);
        print(internationalArr);
      }
    }

    //sorting by first name
    else if (userInput == 3){
      cout << "\n\n(3) Sort by first name\n";
			cout << "****************************************************************\n";
      if(studentType == 1){
        sortFirstName(domesticArr, 0, 99);
        print(domesticArr);
      }
      else if(studentType == 2){
        sortFirstName(internationalArr, 0, 99);
        print(internationalArr);
      }
    }

    //sorting by last name
    else if (userInput == 4){
      cout << "\n\n(4) Sort by last name\n";
			cout << "****************************************************************\n";
      if(studentType == 1){
        sortLastName(domesticArr, 0, 99);
        print(domesticArr);
      }
      else if(studentType == 2){
        sortLastName(internationalArr, 0, 99);
        print(internationalArr);
      }
    }

    //sorting by overall
    else if (userInput == 5){
      cout << "\n\n(5) Sort by overall\n";
			cout << "****************************************************************\n";
      if(studentType == 1){
        sortOverall(domesticArr, 0, 99);
        print(domesticArr);
      }
      else if(studentType == 2){
        sortOverall(internationalArr, 0, 99);
        printValidStudents(internationalArr);
      }
    }
  }
}
