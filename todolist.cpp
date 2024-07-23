#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct todolist{
    string task;
    int id;
};

int ID =0 ;  
void banner();
void AddTask();
void ShowTask();
void SearchTask();
void DeleteTask();
void UpdateTask();

int main(){
    system("cls");
    while (true){
        banner();
        cout << "1. Add Task" << endl;
        cout << "2. Show Task" <<endl;
        cout << "3. Search Task" <<endl;
        cout << "4. Delete Task" << endl;
        cout << "5. Update Task" <<endl;

        int choice;
        cout<<"Enter choice "<<endl;
        cin>> choice;

        switch (choice)
        {
            case 1:
              AddTask();
              break;

            case 2:
              ShowTask();
              break;
            
            case 3:
             SearchTask();
              break;

            case 4:
              DeleteTask();
              break;
            
            case 5:
              UpdateTask();
              break;
            
            default:
              cout<<"Invalid choice"<<endl;
               break;
                    }
    }
    return 0;
}

void banner(){
    cout<<"___________________"<<endl;
    cout<<"|  TO DO LIST APP |"<<endl;
    cout<<"___________________"<<endl;
}
void AddTask(){
    banner();
    todolist todo;
    cout<<"Enter new Task"<<endl;
    cin.get();
    getline(cin, todo.task);
    char save;
    cout<<"Do you want to save this task? (y/n)"<<endl;
    cin>>save;
    if(save=='y'){
        ID++;
        ofstream fount;
        fount.open("todo.txt");
        fount<<ID<<endl;
        fount<<todo.task<<endl;
        fount.close();

        char more;
        cout<<"Do you want to add more tasks? (y/n)"<<endl;
        cin>> more;
        if(more=='y'){
            AddTask();
          }
        else{
        cout<<"Added suceedfully"<<endl;
        }
    }
}
    void ShowTask(){
    banner();
    ifstream file("todo.txt");
    string line;
    int count = 0;
    cout << "ID\tTask" << endl;
    while (getline(file, line)) {
        if (count % 2 == 0) {
            cout << line << "\t";
        } else {
            cout << line << endl;
        }
        count++;
    }
    file.close();
}

void SearchTask(){
    banner();
    ifstream file("todo.txt");
    string line;
    int count = 0;
    string search;
    cout << "Enter task to search: ";
    cin.ignore();
    getline(cin, search);
    bool found = false;
    while (getline(file, line)) {
        if (count % 2 == 1 && line.find(search) != string::npos) {
            found = true;
            cout << "Task found: " << line << endl;
        }
        count++;
    }
    if (!found) {
        cout << "Task not found." << endl;
    }
    file.close();
}

void DeleteTask(){
    banner();
    ifstream file("todo.txt");
    ofstream temp("temp.txt");
    string line;
    int count = 0;
    int id;
    cout << "Enter ID of task to delete: ";
    cin >> id;
    bool found = false;
    while (getline(file, line)) {
        if (count % 2 == 0 && stoi(line) != id) {
            temp << line << endl;
        } else if (count % 2 == 1) {
            temp << line << endl;
        }
        count++;
    }
    if (!found) {
        cout << "Task not found." << endl;
    } else {
        cout << "Task deleted successfully." << endl;
    }
    file.close();
    temp.close();
    remove("todo.txt");
    rename("temp.txt", "todo.txt");
}

void UpdateTask(){
    banner();
    ifstream file("todo.txt");
    ofstream temp("temp.txt");
    string line;
    int count = 0;
    int id;
    cout << "Enter ID of task to update: ";
    cin >> id;
    bool found = false;
    string newTask;
    while (getline(file, line)) {
        if (count % 2 == 0 && stoi(line) != id) {
            temp << line << endl;
        } else if (count % 2 == 0 && stoi(line) == id) {
            found = true;
            cout << "Enter new task: ";
            cin.ignore();
            getline(cin, newTask);
            temp << line << endl;
            temp << newTask << endl;
        } else {
            temp << line << endl;
        }
        count++;
    }
    if (!found) {
        cout << "Task not found." << endl;
    } else {
        cout << "Task updated successfully." << endl;
    }
    file.close();
    temp.close();
    remove("todo.txt");
    rename("temp.txt", "todo.txt");
}