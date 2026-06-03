#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <vector>
#include "Task.h"

using namespace std;

class TaskManager
{
private:
    vector<Task> tasks;

public:
    void addTask();
    void viewTasks();
    void markCompleted();
    void deleteTask();
    void taskStatistics();
    void saveToFile();
    void loadFromFile();
};

#endif
