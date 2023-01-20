#include <time.h>
#include <vector>
#include <string>
#include <iostream>

#include "SkipList.h"

std::string randomKey() {
    char letter1 = (rand()%26) + 'A';
    char letter2 = (rand()%26) + 'a';
    return {letter1, letter2};
}
std::string randomValue() {
    char letter1 = (rand()%26) + 'a';
    char letter2 = (rand()%26) + 'a';
    char letter3 = (rand()%26) + 'a';
    char letter4 = (rand()%26) + 'a';

    return {letter1, letter2, letter3, letter4};
}

int main(int argc, char** argv) {
	unsigned seed = (unsigned)time(NULL);
	std::srand(seed);
	std::cout << "seed: " << seed << std::endl << std::endl;

	SkipList map;

	map.print();
	std::cout << std::endl;

	int n = 10;
	std::string key[n];

	for(int i=0; i<10; i++) {
	    key[i] = randomKey();
        //std::cout << i << " " << key[i] << std::endl;
	    map.insert(key[i], randomValue());
	}

	map.print();
	std::cout << std::endl;

    //Entry
    SkipList::Entry* newEntry;

    int index = rand() % n;
    Key testKey = randomKey(); 

	std::cout<< "test key: "<< testKey <<std::endl;
	newEntry = map.ceilingEntry(testKey);
	std::cout << "ceilingEntry Index = " << index << "  KeyValue = "  << newEntry->getKey() <<  std::endl;

	newEntry = map.floorEntry(testKey);
	std::cout << "floorEntry Index = " << index << "  KeyValue = "  << newEntry->getKey() << std::endl;

    newEntry = map.greaterEntry(testKey);
	std::cout << "greaterEntry Index = " << index << "  KeyValue = "  << newEntry->getKey() << std::endl;
 
    newEntry = map.lesserEntry(testKey);
	std::cout << "lesserEntry Index = " << index << "  KeyValue = "  << newEntry->getKey() <<  std::endl<<std::endl;

	for(int i=0; i<2; i++) {
		index = rand() % n;
		map.remove(key[index]);
		key[index] = key[n-1];
		n--;
	}
	
	map.print();
	std::cout<<std::endl;

	// for(int i=0; i<33; i++) {
	// 	int index = rand() % n;
	// 	map.remove(key[index]);
	// 	key[index] = key[n-1];
	// 	n--;
	// }

	// map.print();
	return 0;
}
