/*  Queue Implementation via LinkedList*/

#include<iostream>
using namespace std;
struct node{
    string data;
    struct node* next;
};
class list{
    node* tail;
    node* head;
    int size = 0;
    int max_size;
public:
    list(int a){
    tail = NULL;
    head = NULL;
    max_size = a;
    }
    bool isEmpty(){
		if (tail == NULL && head == NULL)
			return true;
		else
			return false;
	}
    bool isFull(){
        if(size == max_size)
            return true;
        else
            return false;
    }
    string Top(){
		return head->data;
	}
    void Enqueue(string msg){
        if (size < max_size)
		{
			node* temp = new node;
			temp->next = NULL;
			temp->data = msg;
			if (isEmpty()){
				temp->next = NULL;
				head = temp;
				tail = temp;
			}
			else{
				tail->next = temp;
				tail = tail->next;
			}
			size++;
        }
    }
    void deQueue(){
        if (!isEmpty()){
			if (head != tail){
                node* temp = head;
				head = temp->next;
                delete(temp);
            }
			else{
				head = NULL;
				tail = NULL;
			}
			size--;
        }
        else
            cout<<"\nQueue is Empty.\n";
    }
    void disp(){
        if(!isEmpty()){
		    node* temp = head;
		    for (int i = 0; i < size; i++){
		    	cout << i + 1 << ": " << temp->data << "\n";
		    	temp = temp->next;
		    }
        }
        else
            cout<<"\nQueue is Empty\n";
	}
};
int main(){
    int nonblocking_flag, size; int wait_size = 20;
    cout<<"Enter the size of message queue: ";
    cin>>size; list queue(size); list wait(wait_size);
    start:
        cout<<"\nEnter 1 for non-blocking and 0 for blocking access: ";
        cin>>nonblocking_flag;
        if(nonblocking_flag == 1){
            int input; string msg; int current_size = 0 ;
            do{
                cout<<"\nEnter 1 to send, 2 to receive, 0 to exit: ";
                cin>>input;
                if(input == 1){
                    cout<<"\nEnter Message to Send: ";
                    getline(cin>>ws, msg);
                    current_size++;
                    if(current_size <= size){
                        queue.Enqueue(msg);
                        cout<<"\nMain Queue:\n";
                        queue.disp();
                    }
                    else{
                        cout<<"\nQueue is Full, message discarded.\n";
                        cout<<"\nMain Queue:\n"; current_size--;
                        queue.disp();
                    }
                }
                else if (input == 2){
                    if(!queue.isEmpty()){
                        cout<<"\nThe message is: "<<queue.Top(); queue.deQueue();
                        current_size--;
                        cout<<"\nMain Queue:\n";
                        queue.disp();
                    }
                    else
                        cout<<"Queue is Empty\n";
                }
            }while(input != 0);
        }
        else if(nonblocking_flag == 0){
            int input; string msg; int current_size = 0; int space = 0; int rec = 0;
            cout<<"\nSize of waiting queue is 20 at the moment\n";
            do{
                cout<<"\nEnter 1 to send, 2 to receive, 0 to exit: ";
                cin>>input;
                if(input == 1){
                    cout<<"\nEnter Message to Send: ";
                    getline(cin>>ws, msg);
                    current_size++;
                    if(current_size <= size){
                        queue.Enqueue(msg);
                        space++;
                        if(rec>0){
                            cout<<"\nThe message is: "<<queue.Top(); queue.deQueue();
                            rec--; current_size--;
                        }
                        cout<<"\nMain Queue:\n";
                        queue.disp();
                    }
                    else{
                        cout<<"\nQueue is Full, message sent to waiting queue.\n";
                        wait.Enqueue(msg);
                        cout<<"\nWaiting Queue:\n";
                        wait.disp();
                    }
                }
                else if (input == 2){
                    if(!queue.isEmpty()){
                        cout<<"The message is: "<<queue.Top(); queue.deQueue();
                        current_size--; space--;
                        if(space<size){
                            if(!wait.isEmpty() && !queue.isFull()){
                                queue.Enqueue(wait.Top());
                                wait.deQueue();
                            }
                        }
                        cout<<"\nMain Queue:\n";
                        queue.disp();
                    }
                    else{
                        cout<<"Queue is Empty, receival put into waiting\n";
                        rec++;
                    }
                }
            }while(input != 0);
        }
        else{
            cout<<"Not a valid option";
            goto start;
        }
    return 0;
}
