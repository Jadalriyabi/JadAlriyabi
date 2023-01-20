#ifndef HASHTABLE_H
#define HASHTABLE_H
using namespace std;
class HashTable
{
    public:
    	HashTable(int size);
    	int insert(int key);
    	int find(int key);
    	~HashTable();
    	
    private:
    
    	int* map;
    	int table_size;
    	
};

#endif // HASHTABLE_H
