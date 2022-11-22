//1)//SLL
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int d){
        data=d;
        next=NULL;
    }
};
class SLL{
    public:
    Node *hptr=NULL;
    void insert_at_end(int d){
        Node *nptr=new Node(d);
        Node *temp=hptr;
        if(temp==NULL){
            hptr=nptr;
            return;
        }
        else{
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=nptr;
            return;
        }
    }
    void deletion(int d){
        Node *temp=hptr;
        if(temp==NULL){
            cout<<"SLL is empty"<<endl;
            return;
        }
        else if(temp->data==d){
            hptr=temp->next;
            return;
        }
        else{
            while(temp!=NULL && temp->next->data!=d){
                temp=temp->next;
            }
            if(temp==NULL){
                cout<<"Element not found"<<endl;
                return;
            }
            else{
                temp->next=temp->next->next;
                return;
            }
        }
    }
    void display(){
        Node *temp=hptr;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    SLL sll;
    int ch,x;
    do{
        cout<<"SLL operations:"<<endl;
        cout<<"1.Insertion at end"<<endl<<"2.Deletion"<<endl<<"3.Display"<<endl<<"4.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch){
            case 1: cout<<"Enter an element to insert: ";
                    cin>>x;
                    sll.insert_at_end(x);
                    break;
            case 2: cout<<"Enter an element to delete: ";
                    cin>>x;
                    sll.deletion(x);
                    break;
            case 3: cout<<"The elements in SLL are:"<<endl;
                    sll.display();
                    break;
            case 4: cout<<"Thank you, we are going to end"<<endl;
                    exit(0);
            default:cout<<"Invalid choice!!!"<<endl;
                    break;
        }
    }while(ch!=4);
    return 0;
}
********************************************************************************************
///2)  //CLL
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int d){
        data=d;
        next=NULL;
    }
};
class CLL{
    public:
    Node *hptr=NULL;
    void insert_at_end(int d){
        Node *nptr=new Node(d);
        Node *temp=hptr;
        if(temp==NULL){
            hptr=nptr;
            hptr->next=hptr;
            return;
        }
        else{
            while(temp->next!=hptr){
                temp=temp->next;
            }
            temp->next=nptr;
            nptr->next=hptr;
            return;
        }
    }
    void deletion(int d){
        Node *temp=hptr;
        if(temp==NULL){
            cout<<"CLL is empty"<<endl;
            return;
        }
        else if(temp->data==d){
            while(temp->next!=hptr){
                temp=temp->next;
            }
            temp->next=temp->next->next;
            hptr=temp->next;
        }
        else{
            while(temp->next!=hptr && temp->next->data!=d){
                temp=temp->next;
            }
            if(temp->next==hptr){
                cout<<"Element not found"<<endl;
            }
            else{
                temp->next=temp->next->next;
            }
        }
    }
    void display(){
        Node *temp=hptr;
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=hptr);
        cout<<endl;
    }
};
int main(){
    CLL cll;
    int ch,x;
    do{
        cout<<"CLL operations:"<<endl;
        cout<<"1.Insertion at end"<<endl<<"2.Deletion"<<endl<<"3.Display"<<endl<<"4.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch){
            case 1: cout<<"Enter an element to insert: ";
                    cin>>x;
                    cll.insert_at_end(x);
                    break;
            case 2: cout<<"Enter an element to delete: ";
                    cin>>x;
                    cll.deletion(x);
                    break;
            case 3: cout<<"The elements in CLL are:"<<endl;
                    cll.display();
                    break;
            case 4: cout<<"Thank you, we are going to end"<<endl;
                    exit(0);
            default:cout<<"Invalid choice!!!"<<endl;
                    break;
        }
    }while(ch!=4);
    return 0;
}
*************************************************************************************************
/////3) //STACK USING LINKED LIST
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int d){
        data=d;
    }
};
class Stack{
    public:
    Node *hptr=NULL;
    void push(int d){
        Node *temp=hptr;
        Node *nptr=new Node(d);
        if(temp==NULL){
            hptr=nptr;
        }
        else{
            nptr->next=hptr;
            hptr=nptr;
        }
    }
    int pop(){
        Node *temp=hptr;
        if(temp==NULL){
            cout<<"Stack is underflow!!"<<endl<<"No element popped"<<endl;
            return -1;
        }
        else{
            int x=hptr->data;
            hptr=hptr->next;
            return x;
        }
    }
    void display(){
        Node *temp=hptr;
        cout<<"The elements of Stack are: "<<endl;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    Stack st;
    int ch,x;
    do{
        cout<<"Stack operations:"<<endl;
        cout<<"1.Push"<<endl<<"2.Pop"<<endl<<"3.Display"<<endl<<"4.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch){
            case 1: cout<<"Enter an element to push: ";
                    cin>>x;
                    st.push(x);
                    break;
            case 2: x=st.pop();
                    if(x!=-1){
                        cout<<"The popped element is: "<<x<<endl;
                    }
                    break;
            case 3: st.display();
                    break;
            case 4: cout<<"Thank you, we are going to end"<<endl;
                    exit(0);
            default:cout<<"Invalid choice!!!"<<endl;
                    break;
        }
    }while(ch!=4);
    return 0;
}
******************************************************************************************************
//4)//INFIX TO POSTFIX CONVERSION
#include<iostream>
#include<stack>
using namespace std;
class ITPConversion{
	public:
	stack<char> st;
	string res;
	int prec(char c){
	    if(c=='^'){
	        return 3;
	    }
	    else if(c=='*' || c=='/'){
    	    return 2;
    	}
    	else if(c=='+' || c=='-'){
    	    return 1;
    	}
    	else{
    	    return -1;
    	}
    }
    bool isoperator(char c){
	    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^'){
		    return true;
		}
		else{
		    return false;
		}
	}
	string InfixToPostfix(string s){
	    for(int i=0;i<s.length();i++){
		    if(isoperator(s[i])){
		        if(st.empty()){
		            st.push(s[i]);
		        }
		        else{
		            while(!st.empty() && prec(st.top())>=prec(s[i])){
		                res+=st.top();
		                st.pop();
		            }
		            st.push(s[i]);
		        }
		    }
		    else{
		        res+=s[i];
		    }
		}
		while(!st.empty()){
		    res+=st.top();
		    st.pop();
		}
		return res;
	}
};
 
int main() {
    ITPConversion itp;
    string expr;
	cout<<"Enter expression: ";
	cin>>expr;
	cout<<"Postfix form: "<<itp.InfixToPostfix(expr)<<endl;
	return 0;
}
********************************************************************************************

//5)//PALINDROME TEST
#include <iostream>
#include <stack>
using namespace std;
bool isPalindrome(string s){
	int len=s.length();
	stack<char> st;
	int mid=len/2, i;
	char ele;
    for(i=0; i<mid; i++){
		st.push(s[i]);
	}
	if(len%2!=0){
		i++;
	}
	while(s[i]!='\0'){
		ele=st.top();
		st.pop();
	    if (ele!=s[i]){
		    return false;
	    }
		i++;
	}
    return true;
}
int main(){
	string s;
	cout<<"Enter a string: ";
    cin>>s;
	if(isPalindrome(s)){
		cout<<"The enetered string "<<s<<" is a palindrome"<<endl;
	}
	else{
		cout<<"The enetered string "<<s<<" is *not* a palindrome"<<endl;
	}
	return 0;
}
*******************************************************************************************

//6)//QUEUES USING LINKED LIST
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int d){
        data=d;
        next=NULL;
    }
};
class Queue{
    public:
    Node *front=NULL;
    Node *rear=NULL;
    void enqueue(int d){
        Node *nptr=new Node(d);
        if(rear==NULL){
            front=rear=nptr;
        }
        else{
            rear->next=nptr;
            rear=nptr;
        }
    }
    int dequeue(){
        if(front==NULL){
            cout<<"Queue is underflow"<<endl<<"No element is dequeued"<<endl;
            return -1;
        }
        else{
            int d=front->data;
            front=front->next;
            return d;
        }
    }
    void display(){
        cout<<"The elements of Queue are:"<<endl;
        Node *temp=front;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    Queue q;
    int ch,x;
    do{
        cout<<"Queue operations:"<<endl;
        cout<<"1.Enqueue"<<endl<<"2.Dequeue"<<endl<<"3.Display"<<endl<<"4.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch){
            case 1: cout<<"Enter an element to enqueue: ";
                    cin>>x;
                    q.enqueue(x);
                    break;
            case 2: x=q.dequeue();
                    if(x!=-1){
                        cout<<"The dequeued element is: "<<x<<endl;
                    }
                    break;
            case 3: q.display();
                    break;
            case 4: cout<<"Thank you, we are going to end"<<endl;
                    exit(0);
            default:cout<<"Invalid choice!!!"<<endl;
                    break;
        }
    }while(ch!=4);
    return 0;
}


********************************************************************************
