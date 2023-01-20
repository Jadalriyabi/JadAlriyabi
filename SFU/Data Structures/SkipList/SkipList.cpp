#include "SkipList.h"
#include <iostream>

using namespace std;

SkipList::SkipList() : listHeads()
{
    makeNewLevelList();
    makeNewLevelList();
}

// makes a new list on the top level of existing list.
// call only when top list is NULL or just the two sentinels.
void SkipList::makeNewLevelList()
{
    SkipList::Entry *minusInfinity = new Entry("!!", ""); // "!!" < any other string.
    SkipList::Entry *plusInfinity = new Entry("}}", "");  // "}}" > any other key.

    Quad *first = new Quad(minusInfinity);
    Quad *last = new Quad(plusInfinity);

    int numLists = listHeads.size();
    Quad *oldFirst = numLists == 0 ? NULL : listHeads[numLists - 1];
    Quad *oldLast = numLists == 0 ? NULL : oldFirst->next;

    first->prev = NULL;
    first->next = last;
    first->above = NULL;
    first->below = oldFirst;

    last->prev = first;
    last->next = NULL;
    last->above = NULL;
    last->below = oldLast;

    if (oldFirst != NULL)
    {
        oldFirst->above = first;
        oldLast->above = last;
    }
    listHeads.push_back(first);
}

void SkipList::printOneList(int listNum)
{
    Quad *bottomCurrent = listHeads[0];
    Quad *current = listHeads[listNum];

    while (bottomCurrent->next != NULL)
    {
        std::string toPrint;
        if (current->entry->getKey() == bottomCurrent->entry->getKey())
        {
            toPrint = current->entry->getKey();
            current = current->next;
        }
        else
        {
            toPrint = "--";
        }
        cout << "--" << toPrint;
        bottomCurrent = bottomCurrent->next;
    }
    cout << "--" << bottomCurrent->entry->getKey() << "--" << endl;
}

void SkipList::print()
{
    int numLists = listHeads.size();
    for (int i = numLists - 1; i >= 0; i--)
    {
        printOneList(i);
    }
}

SkipList::Entry *SkipList::find(Key k)
{
    int numLists = listHeads.size();
    Quad *current = listHeads[numLists - 1];

    while (current->below != NULL)
    {
        current = current->below; // drop down
        while (k >= current->next->entry->getKey())
        { // scan forward
            current = current->next;
        }
    }

    if (current->entry->key == k)
    {
        return current->entry;
    }
    else
    {
        return NULL;
    }
}

// the "trail" is a vector of the last node visited on each list
// the last element of trail is on the lowest list; the first is on the highest.
std::vector<SkipList::Quad *> *SkipList::findWithTrail(Key k)
{
    std::vector<SkipList::Quad *> *trail = new std::vector<Quad *>();

    int numLists = listHeads.size();
    Quad *current = listHeads[numLists - 1];

    while (current != NULL)
    {
        while (k >= current->next->entry->getKey())
        { // scan forward
            current = current->next;
        }
        trail->push_back(current);
        current = current->below; // drop down
    }
    return trail;
}


// to insert an entry (x, o) into a skip list, we use a randomized
// algorithm:
void SkipList::insert(Key k, Value v){
    int count = 1;
    while(std::rand()%2 != 1)
    {
        count++; 
    }
    
    int levels = listHeads.size();
    
    while(levels <= count)
    {
        makeNewLevelList(); 
        levels = listHeads.size(); //Make new list levels
    }
    
    std::vector<SkipList::Quad*>* trail = findWithTrail(k);
    if(trail->back()->entry->getKey() == k){
        return; // k already exists within the skiplist
    } 
    
    cout << count << " " << k<<endl;
    Quad* new_quad;
    SkipList::Quad* temp = NULL;
    for(int i =0; i<count;i++){
        new_quad = new Quad(new Entry(k,v));
        new_quad->prev = trail->back();
        new_quad->next = trail->back()->next;
        new_quad->below = temp;
        if(i!=0){
            temp->above = new_quad;
        }

        new_quad->above = NULL;
        new_quad->next->prev = new_quad;
        trail->back()->next = new_quad;
        trail->pop_back();
        temp = new_quad;
    }
}

//To remove an entry with key k from a skip list
void SkipList::remove(Key k){
    if(listHeads.size() - 1 == 0) {
        return;
    }

    Quad* remove = listHeads[listHeads.size()-1];
    while (remove->below != NULL) {
        remove = remove->below;			// drop down
        while(k >= remove->next->entry->getKey()) {	// scan forward
            remove = remove->next;
        }
    } 

    cout<<"removing this key: "<< k <<endl;
    if(remove->entry->getKey() != k){
        return; // k doesn't exist within the skiplist
    } 
    // std::vector<SkipList::Quad*>* v;
    
    while(remove!=NULL){
        Quad* temp =NULL;
        temp =  remove;
        remove->next->prev = remove->prev;
        remove->prev->next = remove->next;
        remove = remove->above;
        delete(temp);
    }
    
    if(listHeads.size()==2)
    {
        return;
    }
    
    while(listHeads[listHeads.size()-2]->next->entry->getKey() == "}}") 
    {
        listHeads.pop_back();

    } 
    
    return;
}


// Return an iterator to the entry with the least key
// value greater than or equal to k; if there is no such entry, it returns
// NULL.
SkipList::Entry *SkipList::ceilingEntry(Key k)
{
    if(listHeads.size()-1 == 0){ 
        return NULL;
    }
    
    Quad* current = listHeads[listHeads.size() - 1];
    while (current->below != NULL) 
    {
        current = current->below;			// drop down
        while(k > current->next->entry->getKey() ) 
        {	// scan forward
            current = current->next;
        }
    } 

    Entry* endEntry = new Entry("end", "");
    if (current->entry->getKey() == "}}")
    {
        return endEntry;
    }
    
    return current->next->entry; 
}

// Return an iterator to the entry with the greatest key
// value less than or equal to k; if there is no such entry, it returns
// end or NULL.
SkipList::Entry *SkipList::floorEntry(Key k)
{
    if(listHeads.size()-1 == 0){ 
        return NULL;
    }
    Quad* current = listHeads[listHeads.size() - 1 ];
    while (current->below != NULL) 
    {
        current = current->below;			// drop down
        while(k >= current->next->entry->getKey() ) 
        {	// scan forward
            current = current->next;
        }
    } 

    Entry* startEntry = new Entry("Start", "");
    if (current->entry->getKey() == "!!")
    {
        return startEntry;
    }
    
    return current->entry; 
}

//Return an iterator the entry with the least key
//value greater than k; if there is no such entry, it returns end.
SkipList::Entry *SkipList::greaterEntry(Key k)
{
    SkipList::Quad *current = listHeads[0];
    while (current != NULL)
    {
        if (current->entry->getKey() > k)
        {
            return current->entry;
        }
        current = current->next;
    }

    Entry* endEntry = new Entry("end", "");
    if (current->entry->getKey() == "}}")
    {
        return endEntry;
    }
    

    return current->entry;
}

//: Return an iterator to the entry with the greatest key
// value less than k; if there is no such entry, it returns end.
SkipList::Entry *SkipList::lesserEntry(Key k)
{
     SkipList::Quad *current = listHeads[0];
    bool found = false;

    while (current != NULL)
    {
        if (current->entry->getKey() == k)
        {
            found = true;
        }
        if (current->entry->getKey() > k && found)
        {
            return current->prev->prev->entry;
        }
        else if (current->entry->getKey() > k && !found)
        {
            return current->prev->entry;
        }
        current = current->next;
    }

    Entry* startEntry = new Entry("Start", "");
    if (current->entry->getKey() == "}}")
    {
        return startEntry;
    }
    
    return current->prev->entry;
}

//Skip list destructor
SkipList::~SkipList(){
    Quad *temp = NULL;
    for(int i = 0;i < listHeads.size(); i++){
        SkipList::Quad *current = listHeads[i];
        while(current->next != NULL){ 
            temp = current->next;
            // delete current->entry; 
            // delete current;
            current = temp; 
        }
    }
    listHeads.clear();
}

//Quad node destructor
SkipList::Quad::~Quad(){
    delete entry;
}

//Entry destructor
SkipList::Entry::~Entry(){}