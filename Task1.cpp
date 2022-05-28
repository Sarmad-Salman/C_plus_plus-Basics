/*   Task 1
Sarmad Salman
Muhammad Hassaan
*/

#include<iostream>
using namespace std;
struct node{
    int data;
    struct node* next;
};
struct node* top; const int maxi = 10; int size = 0;
bool isEmpty() 
{ 
    if (top == NULL){
        return 1;
    }
    else{
        return 0;
    }
} 
bool isFull(){
    if(size == maxi){
        return 1;
    }
    else{
        return 0;
    }
}
void Top(){
    if(isEmpty() == 0){
        cout<<"Top Element is: "<< top->data<<endl;
   }
   else{
       cout<<"Stack hasn't been formed yet.\n";
   }
}
void push(int a){
    struct node* temp = new node();
    if (isFull() == 1)
    { 
        cout << "\nMaximum Size Exceeded";
    } 
    temp->data = a;
    temp->next = top;
    top = temp;
    ++size;
}
void pop(){
    struct node* temp;
    if(isEmpty() == 1){
        cout<<"\nNothing to Pop.";
    }
    else{
        temp = top;
        top = top->next;
        temp->next - NULL;
        free(temp);
    }
    --size;
}
void Clear(){
    if(isEmpty() == 0){
        while(size !=0){
            pop();
        }
        cout<<"Stack Cleared.\n";
    }
    else{
        cout<<"Already Clear.\n";
    }
}
int main(){
    int a, pu; node* start = new node();
    do{
        cout<<"\nStack Operations: Main Menu\n1: To Push\n2: To Pop\n";
        cout<<"3: Check if Stack is Empty\n4: Check if Stack is Full\n";
        cout<<"5: Clear Stack\n6: Display Top Most in Stack\n0: Exit\n";
        cout<<"\nYour Choice: ";
        cin>> a;
        if(a == 1){
            cout<<"Enter Number to Push: ";
            cin>> pu;
            push(pu);
        }
      else if(a == 2){
          pop();
          cout<<"The popped Number is: "<<pu<<endl;;
      }
      else if (a == 3){
          if(isEmpty() == 1){
              cout<<"Stack is Empty\n\n";
          }
          else{
              cout<<"Stack ain't Empty\n\n";
          }
      }
      else if(a == 4){
          if(isFull() == 1){
              cout<<"Stack is Full\n\n";
          }
          else{
              cout<<"Stack ain't Full\n\n";
          }
      }
      else if(a == 5){
          Clear();
      }
      else if(a == 6){
          Top();
      }
        else if(a == 0){
            cout<<"Exiting Now...\n\n";
        }
        else{
            cout<<"Not a valid option";
        }
    } while(a != 0);
    return 0;
}