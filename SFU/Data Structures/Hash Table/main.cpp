#include <iostream>
#include "HashTable.h"
using namespace std;

int main()
{
	int n;
	cout << "Enter the size of the table" << endl;
	cin >> n;
	HashTable table(n);
	int size = min (5, n);
	cout << "now insert " << size << " numbers:" << endl;
	for (int i=0; i<size; i++){
		int a;
		cin>>a;
		cout << "inserted the key in " << table.insert(a) << " steps" << endl;
	}
	cout << "insert successful. What are you trying to look up?" << endl;
	int a;
	cin >> a;
	while (a!=-1){
		int x = table.find(a);
		if (x > 0)
			cout << "Found in " << x << " steps" << endl;
		else
			cout << "Not Found. checked in " << -x << " steps"  << endl;
		cin >> a;
	}
	return 0;
}
