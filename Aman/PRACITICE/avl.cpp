#include<bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *lchild;
    string data;
    string meaning;
    int height;
    struct Node *rchild;
}*root=NULL;

void Display(struct Node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        Display(p->lchild);
        Display(p->rchild);

    }
}

struct Node *Rinsert(struct Node *p,string key)
{
    struct Node *t;
    if(p==NULL)
    {
        t=new Node;
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key<p->data) {
        p->lchild=Rinsert(p->lchild,key);
    }
    else if(key>p->data) {
        p->rchild=Rinsert(p->rchild,key);
    }
    return p;
}

int main()
{
    root=Rinsert(root,"cat");
    Rinsert(root,"elephant");
    Rinsert(root,"apple");
    Rinsert(root,"dog");
    Display(root);

}