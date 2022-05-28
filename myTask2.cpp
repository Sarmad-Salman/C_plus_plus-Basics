#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
struct node{
    char data;
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
        char y;
        struct node* temp;
        if(isEmpty() == 1){
            cout<<"\nNothing to Pop.";
        }
        else{
            temp = top;
            y = temp ->data;
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
    int prec(char a){
        if(a == '^'){
            return 5;
        }
        else if(a == '/'){
            return 4;
        }
        else if(a == '*'){
            return 3;
        }
        else if(a == '+'){
            return 2;
        }
        else if(a == '-'){
            return 1;
        }
        else{
            return -1;
        }
    }
    char Top(){
        if(isEmpty() == 0){
            return top->data;
        }
        else{
            return -1;
        }
    }
    void IntoPost(string a){
        string New;
        for(int i = 0; i<a.length(); ++i){
            if(a[i] >= 'a' && a[i] <= 'z' || a[i] >='A' && a[i]<='Z'){
                New += a[i];
            }
            else if(a[i] == '('){
                push(a[i]);
            }
            else if(a[i] == ')'){
                while(Top()!='('){
                    char c = Top();
                    New += c;
                    pop();
                }
                if(Top() == '('){
                    pop();
                }
            }
            else if (a[i] == '/' || a[i] == '*' || a[i] == '-' || a[i] == '+' || a[i] == '^'){
                while(prec(a[i])<=prec(Top())){
                char c = Top();
                New += c;
                pop();
                }
                push(a[i]);
            }
        }
        if(isEmpty() == 0){
            while(size !=0){
                char c = Top();
                New += c;
                pop();
            }
        }
        cout<<"Postfix Expression is: "<<New<<endl<<endl;
    }
};
int main(){
    string a; stack start;
    while(true){
        cout<<"Enter an Infix expression or press 0 to exit: ";
        getline(cin, a, '\n');
        if(a =="0"){
            break;
        }
        start.IntoPost(a);
        start.Clear();
    }
    _getch();
    return 0;
}