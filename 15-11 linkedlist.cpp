
#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node *next;
		Node(int d){
			data=d;
			next=NULL;
		}
		void display(){
			cout<<data<<endl;
		}
};
class Linkedlist
{
	public:
		Node *hptr=NULL;
		int length=0;
		void append(int d){
			if(hptr==NULL){
				Node *temp=new Node(d);
				hptr=temp;
			}
			else{
				Node *temp=hptr;
				while(temp->next!=NULL){
					temp=temp->next;
				}
				Node *nptr=new Node(d);
				temp->next=nptr;
			}
			length++;
		}
		void insert(int p,int v){
			if(p==0){
				Node *nptr1=new Node(v);
				nptr1->next=hptr;
				hptr=nptr1;
				length++;
			}
			else if(p>length-1)
			{
				cout<<"insert out of bound"<<endl;	
				return;
			}
			else{
				int count=0;
				Node *t=hptr;
				while(count<p-1){
					t=t->next;
					count++;	
				}
				Node *t1=new Node(v);
				Node *temp=t->next;
				t->next=t1;
				t1->next=temp;
				length++;
			}
		}
		void nodedel(int val){
			Node *temp=hptr;
			if(hptr->data==val){
				hptr=hptr->next;
				length--;
			}
			else{
				while(temp->data!=NULL && temp->next->data!=val){
					temp=temp->next;
				}
				if(temp->next==NULL){
					cout<<"data not found"<<endl;
				}
				else{
					temp->next=temp->next->next;
					length--;
				}
			}
		}
		void display(){
			Node *temp=hptr;
			while(temp!=NULL){
				temp->display();
				temp=temp->next;
			}
		}
		void sum(){
			int sum=0;
			Node *temp=hptr;
			while(temp!=NULL){
				sum=sum+temp->data;	
			}
			cout<<sum<<endl;
		}
};
int main()
{
	Linkedlist l;
	int a;
	l.append(5);
	l.append(10);
	l.append(15);
	l.append(20);
	l.append(25);
	l.display();
	l.insert(4,30);
	l.display();
	l.nodedel(20);
	l.display();
	l.sum();
	return 0;
}

