#ifndef TASK_H
#define TASK_H

#include <string>

using namespace std;

class Task
{
public:
    string title;
    string category;
    bool completed;

    Task(string t="", string c="General", bool comp=false)
    {
        title = t;
        category = c;
        completed = comp;
    }
};

#endif
