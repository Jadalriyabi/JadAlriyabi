// Scheduler.cpp
#include "Scheduler.h"
#include <cstdlib> // for rand()

void Scheduler::addNode(std::shared_ptr<Node> node) {
    nodes.push_back(node);
}

void Scheduler::scheduleTask(const Task& task) {
    // Implement load balancing logic (for simplicity, randomly choose a node)
    int nodeIndex = rand() % nodes.size();
    nodes[nodeIndex]->executeTask(task);
}
