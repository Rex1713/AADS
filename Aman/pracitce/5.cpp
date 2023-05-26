#include<bits/stdc++.h>
using namespace std;

struct Node {
    struct Node *lchild;
    string data;
    string meaning;
    struct Node *rchild;
}*root=NULL;

void Insert(string key) 
{
    struct Node *t=root;
    struct Node *p,*r;
    if(root==NULL) {
        p=new Node;
        p->data=key;
        cout<<"Enter the meaning of "<<p->data<<endl;
        cin>>p->meaning;
        p->lchild=p->rchild=NULL;
        return;
    }
    while(t!=NULL) {
        r=t;
        if(key==t->data) {
            return;
        }
        else if(key<t->data)
        {
            t=t->lchild;
        }
        else {
            t=t->rchild;
        }
    }
    p=new Node;
    p->data=key;
    cout<<"Enter the meaning of "<<p->data<<endl;
    cin>>p->meaning;
    p->lchild=p->rchild=NULL;
    if(key < r->data) {
        r->lchild = p;
    }
    else {
        r->rchild=p;
    }
}

void Inorder(struct Node *p) {
    if(p) 
    {
        Inorder(p->lchild);
        cout<<p->data;
        Inorder(p->rchild);
    }
}





