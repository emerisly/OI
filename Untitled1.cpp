#include<bits/stdc++.h>

using namespace std;

struct node{
	int val;
	node *next;
}e; 


void create(node **head){
	*head=(node*)malloc(sizeof(node));
	(*head)->next=NULL;
}

voide cmp(int a,int b){
	return a<b;
}

void insert(int val,node *head){
	node *cur=(node*)malloc(sizeof(node));
	cur->val=val;
	node *p=head;
	if(p==NULL){
		head->next=cur;
		cur->next=NULL;
		return;
	}
	while(p->next!=NULL&&cmp(val,p->next->val))
		p=p->next;
	cur->next=p->next;
	p->next=cur;
}
