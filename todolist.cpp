#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct todolist{
    string task;
    int id;
};

int ID ;
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
        cin>>choice<<endl;

        switch (choice)
        {
            case 1:
              AddTask();
              break;

            case 2:
              //ShowTask();
              break;
            
            case 3:
             // SearchTask();
              break;

            case 4:
              //DeleteTask();
              break;
            
            case 5:
              //UpdateTask();
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
        cin>>more<<endl;
        if(more=='y'){
            AddTask();
          }
        else(){
        cout<<"Added suceedfully"<<endl;
        }
    }
}


