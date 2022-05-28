// Program to check if the entered equation is balanced or not

#include <iostream>
#include<conio.h>
#include<string>
using namespace std;
struct node{
    int data;
    struct node* next;
};
class stack{
    node *top = NULL;
    int size = 0;
public:    
    bool isEmpty() 
    { 
        if (top == NULL){
            return 1;
        }
        else{
            return 0;
        }
    } 
    void push(char a){
        struct node* temp = new node();
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
            --size;
        }
    }
    void Clear(){
        if(isEmpty() == 0){
            while(size !=0){
                pop();
            }
        }
        else{
            return;
        }
    }
    void Check(string a){
        for(int i = 0; i<=a.length(); ++i){
            if(a[i] == '('){
                push(a[i]);
            }
            else if(a[i] == ')'){
                if(isEmpty() == 1){
                    cout<<"Equation ain't Balanced\n";
                    return;
                }
                else{
                    pop();
                }
            }
        }
        if(isEmpty() == 1){
            cout<<"Equation Balanced\n";
        }
        else if(isEmpty() != 1){
            cout<<"Equation ain't Balanced\n";
        }
    }
};
int main(){
    string a; stack start;
    while(true){
        cout<<"Enter an equation or press 0 to exit: ";
        getline(cin, a, '\n');
        if(a == "0"){
            break;
        }
        start.Check(a);
        start.Clear();
    }
    _getch();
    return 0;
}
