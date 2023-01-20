#include "HashTable.h"

HashTable::HashTable(int size = 100){
	table_size = size;
	map = new int [table_size];
	for (int i=0; i<table_size; i++)
		map[i] = -1;
}

int HashTable::insert(int key){
	int ind = key%table_size, step = 1;
	while (map[ind] != -1){
		ind ++;
		ind %= table_size;
		step ++;
	}
	map[ind] = key;
	return step;
}

int HashTable::find(int key){
	int ind = key%table_size, step = 1;
	while (map[ind] != -1){
		if (map[ind] == key)
			return step;
		else{
			ind++;
			ind %= table_size;
			step ++;
		}
	}
	return -step;
}

HashTable::~HashTable(){
	delete[] map;
}

