/*  Sarmad Salman
    Muhammad Hassaan*/

#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
struct Queue{
    int front, rear, capacity;
    string *queue;
    int *queue1;
    int noElements = 0;
    int patient_id = 0;
    Queue(int s){
        front = rear = -1;
        capacity = s;
        queue1 = new int[s];
        queue = new string[s]; 
    }
    ~Queue(){
        delete[] queue;
    }
    void RegisterPatient(string name){
        if(noElements == capacity ){
            cout<<"\nQueue is Full\n";
        }
        else {
            if (noElements ==0 ){
                front = 0;
            }
            ++patient_id;
            rear = (rear+1)%capacity;
            queue[rear] = name;
            queue1[rear] = patient_id;
            ++noElements;
            cout<<"Patient Registered\n";
        }
    }
    string ServePatient(){
        if(noElements == 0){
            cout<<"\nQueue is Empty\n";
            return "0";
        }
        else{
            string name = queue [front];
            int patient_id = queue1[front];
            if (front == rear){
                front = rear = -1;
                --noElements;
            }
            else {
                front = (front+1)%capacity;
                --noElements;
            }
            return name;
        }
    }
    bool CanDoctorGoHome(){
        if(noElements == 0){
            return true;
        }
        else{
            return false;
        }
    }
    void ShowAllPatient(){
        int i;
        if(CanDoctorGoHome()==true){
            cout<<"\nQueue is Empty\n";
            cout<<"The Doctor can go home now.\n";
        }
        else{
            cout<<"\nThe Doctor has to Stay now.\n";
            cout<<"\nPatients in the waiting are: -\n";
            cout<<"Name\t\t\tID\n";
            for(i =front; i != rear; i=(i+1)%capacity){
                cout<<queue[i]<<"\t\t08_04_2021___"<<queue1[i]<<"\n";
            }
            cout<<queue[i]<<"\t\t08_04_2021___"<<queue1[i]<<endl<<endl;
        }
    }
};
int main(){
    int size; bool flag; string name; int opt;
    cout<<"Enter size of queue: ";
    cin>>size; Queue q(size);
    while(1){
        cout<<"\nEnter 1 to serve a Patient\n2 to Register a new Patient\n3 to see Patients and their IDs\n0 to Exit the program: ";
        cout<<"\nYour Choice: ";
        cin>>opt;
        if(opt == 1){
            name = q.ServePatient();
            cout<<"\nPatient: "<<name<<" serviced.\n";
        }
        else if (opt == 0){
            break;
        }
        else if (opt == 2){
            cout<<"\nEnter Name: ";
            cin>>name;
            q.RegisterPatient(name);
        }
        else if (opt ==3){
            q.ShowAllPatient();
        }
        else {
            cout<<"\nNot a valid option\n";
        }
    }
    _getch();
    return 0;
}