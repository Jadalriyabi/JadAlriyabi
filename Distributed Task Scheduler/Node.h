#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include "Task.h"

class Node {
public:
    Node(int id) : id(id) {}

    void executeTask(const Task& task) {
        std::cout << "Node " << id << " executing task: " << task.getName() << std::endl;
        // Simulate task execution
    }

    int getId() const { return id; }

private:
    int id;
};

#endif // NODE_H
