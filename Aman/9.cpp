#include<bits/stdc++.h>
using namespace std;

struct Node{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
}*root=NULL;

int NodeHeight(struct Node *p){
    int hl,hr;
    hl=p && p->lchild ?p->lchild->height:0;
    hr=p && p->rchild ? p->rchild->height:0;
    return hl>hr?hl+1:hr+1; // change kr baddmein to hl and hr
}

int BalanceFactor(struct Node *p) {
    int hl,hr;
    hl=p && p->lchild ?p->lchild->height:0;
    hr=p && p->rchild ? p->rchild->height:0;
    return hl-hr;
}

void Inorder(struct Node *p) {
    if(p!=NULL) 
    {
        cout<<p->data<<" "<<p->height<<"   ";
        Inorder(p->lchild);
        
        Inorder(p->rchild);
    }
}

struct Node *LLRotation(struct Node *p) {
    struct Node *pl=p->lchild;
    struct Node *plr=pl->rchild;
    pl->rchild=p;
    p->lchild=plr;

    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);

    if(root == p) {
        root=pl;
    }
    return pl;

}

struct Node *LRRotation(struct Node *p){
    struct Node *pl=p->lchild;
    struct Node *plr=pl->rchild;
    
    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;

    plr->lchild=pl;
    plr->rchild=p;

    pl->height=NodeHeight(pl);
    p->height=NodeHeight(p);
    plr->height=NodeHeight(plr);
    if(p==root) {

        root=plr; 
    }

    return plr;
}

struct Node *RRRotation(struct Node *p) {
    struct Node *pr=p->rchild;
    struct Node *prl=pr->lchild;
    pr->lchild=p;
    p->rchild=prl;

    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);

    if(root == p) {
        root=pr;
    }
    return pr;
}

struct Node *RLRotation(struct Node *p) {
    return NULL;
}

struct Node *RInsert(struct Node *p,int key) {
    struct Node *t;
    if(p==NULL) {
        t=new Node;
        t->data=key;
        t->height=1; //change kr baadmein to 0
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key<p->data) {
        p->lchild=RInsert(p->lchild,key);
    }
    else if(key > p->data) {
        p->rchild=RInsert(p->rchild,key);
    }
    //UPDATE THE HEIGHT OF EVERY NODE
    p->height=NodeHeight(p);
    // Check BF and rotations decide
    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1) {
       return LLRotation(p);
    }
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1) {
        return LRRotation(p);
    }
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1) {
        return RRRotation(p);
    }
    // else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild==1)) {
    //     return RLRotation(p);
    // }
    return p;
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
struct Node *Delete(struct Node *p,int key)
{
     if (p == nullptr){
        return nullptr;
    }
 
    if (p->lchild == nullptr && p->rchild == nullptr){
        if (p == root){
            root = nullptr;
        }
        delete p;
        return nullptr;
    }
 
    if (key < p->data){
        p->lchild = Delete(p->lchild, key);
    } else if (key > p->data){
        p->rchild = Delete(p->rchild, key);
    } else {
        Node* q;
        if (NodeHeight(p->lchild) > NodeHeight(p->rchild)){
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        } else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
 
    // Update height
    p->height = NodeHeight(p);
 
    // Balance Factor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) {  // L1 Rotation
        return LLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1){  // L-1 Rotation
        return LRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1){  // R-1 Rotation
        return RRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1){  // R1 Rotation
        return RLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 0){  // L0 Rotation
        return LLRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 0){  // R0 Rotation
        return RRRotation(p);
    }
 
    return p;
}

int main() {
    root=RInsert(root,30);
    RInsert(root,20);
    RInsert(root,40);
    RInsert(root,10);
    Inorder(root);
    cout<<endl;
    Delete(root,40);
    Inorder(root);
    return 0;
} 