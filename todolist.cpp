#include <iostream>
using namespace std;

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
        cin>>choice;

        switch (choice)
        {
            case 1:
              AddTask();
              break;

            case 2;
              ShowTask();
              break;
            
            case 3;
              SearchTask();
              break;

            case 4;
              DeleteTask();
              break;
            
            case 5;
              UpdateTask();
              break;
            
            default:
              cout<<"Invalid choice"<<endl;
               break;
                    }
    }
    return 0;
}