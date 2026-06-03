#include <iostream>
#include <windows.h>
#include "TaskManager.h"

using namespace std;

void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void header()
{
    system("cls");

    setColor(11);

    cout << "\n";
    cout << "\t#################################################\n";
    cout << "\t#                                               #\n";
    cout << "\t#          TO-DO LIST APPLICATION               #\n";
    cout << "\t#                                               #\n";
    cout << "\t#################################################\n";

    setColor(14);

    cout << "\n\tManage Your Daily Tasks Easily\n";
}

int main()
{
    TaskManager manager;

    int choice;

    do
    {
        header();

        setColor(10);

        cout << "\n\t+  1. Add Task";
        cout << "\n\t*  2. View Tasks";
        cout << "\n\t_/ 3. Mark Completed";
        cout << "\n\t-  4. Delete Task";
        cout << "\n\t#  5. Task Statistics";
        cout << "\n\t$  6. Save Tasks";
        cout << "\n\t@  7. Load Tasks";
        cout << "\n\tX  8. Exit";

        setColor(15);

        cout << "\n\n\tEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                manager.addTask();
                break;

            case 2:
                manager.viewTasks();
                break;

            case 3:
                manager.markCompleted();
                break;

            case 4:
                manager.deleteTask();
                break;

            case 5:
                manager.taskStatistics();
                break;

            case 6:
                manager.saveToFile();
                break;

            case 7:
                 manager.loadFromFile();
                break;

            case 8:
                setColor(12);
                cout << "\n\n\tThank You For Using The Application!\n";
                break;

            default:
                cout << "\n\tInvalid Choice!\n";
        }

        if(choice != 8)
        {
            cout << "\n\n\tPress Any Key To Continue...";
            system("pause>nul");
        }

    }while(choice != 8);

    return 0;
}
