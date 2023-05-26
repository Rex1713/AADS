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
    struct Node *r,*p;
    if(root==NULL){
        p=new Node;
        cout<<"Enter its meaning";
        cin>>p->meaning;
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    while(t!=NULL) {
        r=t;
        if(key==t->data) {
            return;

        }
        else if(key<t->data) {
            t=t->lchild;         
        }
        else if(key>t->data) {
            t=t->rchild;
        }
    }
    p=new Node;
    p->data=key;
    cout<<"Enter its meaning"<<endl;
    cin>>p->meaning;
    p->lchild=p->rchild=NULL;
    if(key<r->data) r->lchild=p;
    else r->rchild=p;
}

void Inorder(struct Node *p) {
    if(p!=NULL) {
        Inorder(p->lchild);
        cout<<p->data<<" "<<"Meaning :"<<p->meaning<<" "<<endl;
        Inorder(p->rchild);
    }
}

struct Node *Search(string key) {
    struct Node *t=root;
    
    while(t!=NULL)
    {
        if(key==t->data) {
            return t;
        }
        else if(key>t->data) {
            t=t->rchild;
            
        }
        else {
            t=t->lchild;
            
        }
    }
    return NULL;

}

int MaxSearch(string key) {
    struct Node *t=root;
    int cnt=0;
    while(t!=NULL)
    {
        if(key==t->data) {
            return cnt;
        }
        else if(key>t->data) {
            t=t->rchild;
            cnt++;
        }
        else {
            t=t->lchild;
            cnt++;
        }
    }
    return cnt;

}

struct Node *Rinsert(struct Node *p,string key) {
    struct Node *t;
    if(p==NULL) {
        t=new Node; 
        t->data=key;
        t->lchild=t->rchild=NULL;
    }
    if(key<p->data) {
        p->lchild=Rinsert(p->lchild,key);
    }
    else if(key>p->data) {
        p->rchild=Rinsert(p->rchild,key);
    }
    return p;

}

int Height(struct Node *p) {
    int x,y;
    if(p==NULL) return 0;
    x=Height(p->lchild);
    y=Height(p->lchild);
    return x>y?x+1:y+1;
}

struct Node *InPre(struct Node *p) {
    while(p && p->rchild!=NULL) {
        p=p->rchild;
    }
    return p;
}

struct Node *InSucc(struct Node *p) {
    while(p && p->lchild!=NULL) {
        p=p->lchild;
    }
    return p;
}


struct Node *Delete(struct Node *p,string key) 
{
    struct Node *q;
    if(p==NULL) {
        return NULL;
    }
    if(p->lchild==NULL && p->rchild==NULL) {
        if(p==root) {
            root=NULL;
        }
        delete p;
        return NULL;
    }
    if(key<p->data) {
        p->lchild=Delete(p->lchild,key);
    }
    else if(key>p->data) {
        p->rchild=Delete(p->rchild,key);
    }
    else{
        if(Height(p->lchild)<Height(p->rchild)) {
            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else {
            q=InSucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);

        }
    }
    return p;
}

int main() {
    Insert("APPLE");
    Insert("P");
    Insert("R");
    Insert("Q");
    Inorder(root);
    Delete(root,"S");
    cout<<endl;
    Inorder(root);
    

    struct Node *temp;
    temp=Search("P");
    cout<<MaxSearch("P");
    if(temp!=NULL) {
        cout<<"Element is found"<<temp->data;
    }
    else{
        cout<<"Element is not found";
    }
}