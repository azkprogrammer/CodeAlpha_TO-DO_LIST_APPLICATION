#include "TaskManager.h"
#include <iostream>
#include <fstream>

using namespace std;

void TaskManager::addTask()
{
    string title;
    string category;

    cin.ignore();

    cout << "\n\t+ Enter Task Name: ";
    getline(cin,title);

    cout << "\t> Enter Category: ";
    getline(cin,category);

    tasks.push_back(Task(title,category,false));

    cout << "\n\tTask Added Successfully!\n";
}

void TaskManager::viewTasks()
{
    if(tasks.empty())
    {
        cout << "\n\t No Tasks Available!\n";
        return;
    }

     cout << "\n\t\tTASKS";
   
       vector<string> shownCategories;

    for(int i = 0; i < tasks.size(); i++)
    {
        string currentCategory = tasks[i].category;

        bool alreadyShown = false;

        for(int j = 0; j < shownCategories.size(); j++)
        {
            if(shownCategories[j] == currentCategory)
            {
                alreadyShown = true;
                break;
            }
        }

        if(alreadyShown)
            continue;

        shownCategories.push_back(currentCategory);
         cout<<"\n\t-----------------------------<<"<<endl;
        cout << "\n\tCATEGORY : " << currentCategory;
       
       for(int k = 0; k < tasks.size(); k++)
        {
            if(tasks[k].category == currentCategory)
            {
                cout << "\n\n\tTask #" << k + 1;

                if(tasks[k].completed)
                    cout << "  [? COMPLETED]";
                else
                    cout << "  [? PENDING]";

                cout << "\n\tTitle    : " << tasks[k].title<<endl;
                }
        }
    }

    cout << endl;
}
void TaskManager::markCompleted()
{
    if(tasks.empty())
    {
        cout << "\n\t No Tasks Available!\n";
        return;
    }

    viewTasks();

    int num;

    cout << "\n\t Enter Task Number: ";
    cin >> num;

    if(num>=1 && num<=tasks.size())
    {
        tasks[num-1].completed=true;

        cout << "\n\t Task Completed Successfully!\n";
    }
    else
    {
        cout << "\n\t Invalid Task Number!\n";
    }
}

void TaskManager::deleteTask()
{
    if(tasks.empty())
    {
        cout << "\n\t No Tasks Available!\n";
        return;
    }

    viewTasks();

    int num;

    cout << "\n\t- Enter Task Number To Delete: ";
    cin >> num;

    if(num>=1 && num<=tasks.size())
    {
        tasks.erase(tasks.begin()+num-1);

        cout << "\n\t Task Deleted Successfully!\n";
    }
    else
    {
        cout << "\n\t Invalid Task Number!\n";
    }
}

void TaskManager::taskStatistics()
{
    int completed=0;
    int pending=0;

    for(int i=0;i<tasks.size();i++)
    {
        if(tasks[i].completed)
            completed++;
        else
            pending++;
    }

    cout << "\n\t\tTASK STATISTICS";
    cout << "\n\t================================";

    cout << "\n\t Total Tasks     : " << tasks.size();
    cout << "\n\t Completed Tasks : " << completed;
    cout << "\n\t Pending Tasks   : " << pending;
}

void TaskManager::saveToFile()
{
	if(tasks.empty())
    {
        cout << "\n\t No Tasks Available!\n";
        return;
    }
    ofstream file("tasks.txt");

    for(int i=0;i<tasks.size();i++)
    {
        file << tasks[i].title << "|"
             << tasks[i].category << "|"
             << tasks[i].completed << endl;
    }

    file.close();

    cout << "\n\t Tasks Saved Successfully!\n";
}

void TaskManager::loadFromFile()
{
    if(tasks.empty())
    {
        cout << "\n\t No Tasks Available!\n";
        return;
    }
	ifstream file("tasks.txt");

    if(!file)
    {
        cout << "\n\t No Saved File Found!\n";
        return;
    }

    tasks.clear();

    string title;
    string category;
    bool status;

    while(getline(file,title,'|'))
    {
        getline(file,category,'|');

        file >> status;
        file.ignore();

        tasks.push_back(Task(title,category,status));
    }

    file.close();

    cout << "\n\t Tasks Loaded Successfully!\n";
}
