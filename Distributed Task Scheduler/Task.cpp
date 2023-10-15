// Task.cpp
#include "Task.h"

Task::Task(const std::string& name) : name(name) {}

const std::string& Task::getName() const {
    return name;
}
