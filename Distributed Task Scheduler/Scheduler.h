#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include <memory>
#include "Node.h"
#include "Task.h"

class Scheduler {
public:
    Scheduler() {}

    void addNode(std::shared_ptr<Node> node) {
        nodes.push_back(node);
    }

    void scheduleTask(const Task& task) {
        // Implement load balancing logic (for simplicity, randomly choose a node)
        int nodeIndex = rand() % nodes.size();
        nodes[nodeIndex]->executeTask(task);
    }

private:
    std::vector<std::shared_ptr<Node>> nodes;
};

#endif // SCHEDULER_H
