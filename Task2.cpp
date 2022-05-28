/*   Task 2
Sarmad Salman
Muhammad Hassaan
*/

#include<iostream>
#include<conio.h>
using namespace std;
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
class linkedlist{
    node* top = NULL;
    node* head = NULL;
    int size = 0;
public:
    void add(int a){
        if(top == NULL){
            node* temp = new node;
            temp -> data = a;
            temp -> next = temp->prev = temp;
            top = temp;
            head = top;
            ++size;
            return;
        }
        node *last = top->prev;
        node *temp = new node;
        temp->data = a;
        temp->next = top;
        top->prev = temp;
        temp->prev = last;
        last->next = temp;
        ++size;
    }
    int length(){
        return size;
    }
    void next(){
        top = top->next;
    }
    void start(){
        top = head;
    }
    void get(){
        if (length() == 1){
            cout<<top->next->data;
        }
        else{
            cout<<top->data;
        }
    }
    void removed(){
        node *temp = top;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete(top);
        --size;
    }
    void display() {
        node *temp = top;
        if(top != NULL){
            do{
                cout<< temp->data <<"\t";
                temp = temp->next;
            }
            while(temp != top);
       }
        cout<<endl;
    }
};
int main(){
    int num, k; linkedlist list;
    cout<<"Number of Participants: ";
    cin>>num;
    cout<<"Number of Participants to be skipped: ";
    cin>>k;
    for(int i = 1; i <= num; ++i){
        list.add(i);
    }
    list.start();
    cout<<"Components of L1: \n";
    list.display();
    while(list.length()>1){
        for(int i = 1; i <= k+1; ++i){
            list.next();
        }
        cout<<"Removed: "; list.get(); cout<<endl;
        list.removed();
    }
    cout<<"Leader is: "; list.get(); cout<<endl;
    _getch();
    return 0;
}