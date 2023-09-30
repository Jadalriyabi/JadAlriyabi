using namespace std;

#include "toefl.hpp"
#include <iostream>

//constructors
Toefl::Toefl(int reading, int listening, int speaking, int writing){
    this->reading = reading;
    this->listening = listening;
    this->speaking = speaking;
    this->writing = writing;
    this->totalScore = reading + listening + speaking + writing;
}
Toefl::Toefl():reading(0),listening(0),speaking(0),writing(0),totalScore(0){
}

//get functions
int Toefl::getReading(){
    return reading;
}
int Toefl::getListening(){
    return listening;
}
int Toefl::getSpeaking(){
    return speaking;
}
int Toefl::getWriting(){
    return writing;
}
int Toefl::getTotalScore(){
    return totalScore;
}

//set functions
void Toefl::setReading(int reading){
    //error checking
    if(reading < 0){
        cout<<"Error: Reading cannot be a negative number.\n";
    }
    else{
        totalScore = totalScore - this->reading + reading;
        this->reading = reading;
    }
}
void Toefl::setListening(int listening){
    //error checking
    if(listening < 0){
        cout<<"Error: Listening cannot be a negative number.\n";
    }
    else{
        totalScore = totalScore - this->listening + listening;
        this->listening = listening;
    }
}
void Toefl::setSpeaking(int speaking){
    //error checking
    if(speaking < 0){
        cout<<"Error: Speaking cannot be a negative number.\n";
    }
    else{
        totalScore = totalScore - this->speaking + speaking;
        this->speaking = speaking;
    }
}
void Toefl::setWriting(int writing){
    //error checking
    if(writing < 0){
        cout<<"Error: Writing cannot be a negative number.\n";
    }
    else{
        totalScore = totalScore - this->writing + writing;
        this->writing = writing;
    }
}

//checks if the Toefl has a passing score
bool Toefl::passed(){
    if(totalScore < 93){
        return false;
    }
    else if(reading < 20){
        return false;
    }
    else if(listening < 20){
        return false;   
    }
    else if(speaking < 20){
        return false;
    }
    else if(writing < 20){
        return false;
    }
    return true;
}

//overloading the output operator for Toefl
ostream& operator<<(ostream& outs, Toefl& toefl){
	outs<<"Total Score: "<<toefl.totalScore<<endl;
    outs<<"Reading Score: "<<toefl.reading<<endl;
    outs<<"Listening Score: "<<toefl.listening<<endl;
    outs<<"Speaking Score: "<<toefl.speaking<<endl;
    outs<<"Writing Score: "<<toefl.writing<<endl;
    return outs;
}


