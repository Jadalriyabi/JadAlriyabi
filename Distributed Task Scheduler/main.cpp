// main.cpp
#include <iostream>
#include <memory>
#include "Node.h"
#include "Task.h"
#include "Scheduler.h"

int main() {
    // Create nodes
    std::shared_ptr<Node> node1 = std::make_shared<Node>(1);
    std::shared_ptr<Node> node2 = std::make_shared<Node>(2);

    // Create scheduler and add nodes
    Scheduler scheduler;
    scheduler.addNode(node1);
    scheduler.addNode(node2);

    // Schedule tasks
    Task task1("TaskA");
    Task task2("TaskB");

    scheduler.scheduleTask(task1);
    scheduler.scheduleTask(task2);

    return 0;
}
