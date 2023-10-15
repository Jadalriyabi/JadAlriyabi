#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
public:
    Task(const std::string& name) : name(name) {}

    const std::string& getName() const { return name; }

private:
    std::string name;
};

#endif // TASK_H
