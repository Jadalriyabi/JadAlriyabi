// Node.cpp
#include "Node.h"
#include <iostream>

void Node::executeTask(const Task& task) {
    std::cout << "Node " << id << " executing task: " << task.getName() << std::endl;
    // Simulate task execution
}
