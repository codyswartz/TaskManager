#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string title;
    string description;
};

int main() {
    vector<Task> tasks;

    while (true) {
        cout << "Task Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Remove Task" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    Task newTask;
                    cin.ignore();
                    cout << "Enter task title: ";
                    getline(cin, newTask.title);
                    cout << "Enter task description: ";
                    getline(cin, newTask.description);
                    tasks.push_back(newTask);
                    cout << "Task added successfully!" << endl;
                }
                break;
            case 2:
                if (tasks.empty()) {
                    cout << "No tasks to display." << endl;
                } else {
                    cout << "Tasks:" << endl;
                    for (size_t i = 0; i < tasks.size(); ++i) {
                        cout << "Task " << i + 1 << ": " << tasks[i].title << endl;
                        cout << "Description: " << tasks[i].description << endl;
                    }
                }
                break;
            case 3:
                if (tasks.empty()) {
                    cout << "No tasks to remove." << endl;
                } else {
                    cout << "Enter the task number to remove: ";
                    int taskNumber;
                    cin >> taskNumber;

                    if (taskNumber >= 1 && static_cast<size_t>(taskNumber) <= tasks.size()) {
                        tasks.erase(tasks.begin() + taskNumber - 1);
                        cout << "Task removed successfully!" << endl;
                    } else {
                        cout << "Invalid task number." << endl;
                    }
                }
                break;
            case 4:
                cout << "Exiting." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}