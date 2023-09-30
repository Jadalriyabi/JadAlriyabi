#ifndef TOEFL
#define TOEFL

using namespace std;
#include <iostream>

class Toefl{
	private:
		int reading;
		int listening;
		int speaking;
		int writing;
		int totalScore;
	public:
		//Constructors
		Toefl(int reading, int listening, int speaking, int writing);
		Toefl();
		
		//Member functions
		int getReading();
		int getListening();
		int getSpeaking();
		int getWriting();
		int getTotalScore();
		void setReading(int reading);
		void setListening(int listening);
		void setSpeaking(int speaking);
		void setWriting(int writing);
		void setTotalScore(int totalScore);
		bool passed();
		
		//friend function
		friend ostream& operator <<(ostream& outs, Toefl& toefl);
};

#endif