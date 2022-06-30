#include <iostream>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
    int height; //for maintaining balance factor
    Node() {}
    Node(int data, int height);
};
Node::Node(int data, int height)
{
    lchild = nullptr;
    this->data = data;
    rchild = nullptr;
    this->height = height;
}

class AVL
{
public:
    Node *root;
    AVL() { root = nullptr; }
    ~AVL() { delete root; }

    //Helper methods for inserting/deleting
    int NodeHeight(Node *p);
    int BalanceFactor(Node *p);
    Node *LLRotation(Node *p);
    Node *RRRotation(Node *p);
    Node *LRRotation(Node *p);
    Node *RLRotation(Node *p);
    Node *InorderPre(Node *p);
    Node *InorderSucc(Node *p);

    // Insert
    Node *rInsert(Node *p, int key);

    // Traversal
    void Inorder(Node *p);
    void Inorder() { Inorder(root); }
    Node *getRoot() { return root; }

    // Delete
    Node *Delete(Node *p, int key);
};

int AVL::NodeHeight(Node *p)
{
    int hl,hr;
    if(p==nullptr){
        return 0;
    }
    hl=(p && p->lchild)? p->lchild->height:0;
    hr=(p && p->rchild) ? p->rchild->height:0;
    return (hl>hr)? hl+1:hr+1;
}

int AVL::BalanceFactor(Node *p)
{
    int hl,hr;
    hl=(p && p->lchild)? p->lchild->height:0;
    hr=(p && p->rchild) ? p->rchild->height:0;
    return (hl-hr);
}

Node *AVL::LLRotation(Node *p)
{
    //initialising helping pointers
    Node* pl=p->lchild;
    Node* plr=pl->rchild;

    //changing linkage (balancing)
    pl->rchild=p;
    p->lchild=plr;

    //update height
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);

    //update root
    if(root==p){
        root=pl;
    }
    return pl;
}

Node *AVL::RRRotation(Node *p)
{
    //initialising helping pointers
    Node* pr=p->rchild;
    Node* prl=pr->lchild;

    //changing linkage (balancing)
    pr->lchild=p;
    p->rchild=prl;

    //update height
    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);

    //update root
    if(root==p){
        root=pr;
    }
    return pr;

}

Node *AVL::LRRotation(Node *p)
{
    //initialising helping pointers
    Node* pl=p->lchild;
    Node* plr=pl->rchild;

    //changing linkage (balancing)
    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;
    plr->rchild=p;
    plr->lchild=pl;

    
    //update height
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
    plr->height=NodeHeight(plr);

    //update root
    if(p==root){
        root=plr;
    }
    return plr;
}

Node *AVL::RLRotation(Node *p)
{  
    //initialising helping pointers 
    Node* pr=p->rchild;
    Node* prl=pr->lchild;

    //changing linkage (balancing)
    p->rchild=prl->lchild;
    pr->lchild=prl->rchild;
    prl->lchild=p;
    prl->rchild=pr;

    
    //update height
    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
    prl->height=NodeHeight(prl);

    //update root
    if(p==root){
        root=prl;
    }
    return prl;
}

Node *AVL::InorderPre(Node *p)
{
    while(p && p->rchild!=nullptr){
        p=p->rchild;
    }
    return p;
}

Node *AVL::InorderSucc(Node *p)
{
    while(p && p->lchild!=nullptr){
        p=p->lchild;
    }
    return p;
}

Node *AVL::rInsert(Node *p, int key)
{
    if (p == nullptr)
    {
        Node *node = new Node(key, 1);
        return node;
    }
    if (p->data > key)
    {
        p->lchild = rInsert(p->lchild, key);
    }
    else/* if(p->data < key)*/
    {
        p->rchild = rInsert(p->rchild, key);
    }

    //Update Height
    p->height=NodeHeight(p);

    //Blance Factor and Rotation
    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1){   //+ve=L, -ve=R
        return LLRotation(p);        
    }
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1){   
        return LRRotation(p);
    }
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1){
        return RRRotation(p);
    }
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1){
        return RLRotation(p);
    }
    return p;
}

void AVL::Inorder(Node *p) //sorted order
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

Node *AVL::Delete(Node *p, int key)    //here we are assuming that key which i am deleting is definetly present
{
    Node *q;
    if (p == nullptr)
    {
        return nullptr;
    }
    if (p->lchild == nullptr && p->rchild == nullptr)  //if p is a leaf node
    {
        if (p == root)
        {
            root = nullptr; //so that root ka vajood bacha rhe
        }
        delete p;
        return nullptr;
    }
    if (p->data > key)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if (p->data < key)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else
    {
        if (NodeHeight(p->lchild) > NodeHeight(p->rchild))
        {
            q = InorderPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InorderSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }

    //Update Height
    p->height=NodeHeight(p);

    //BalanceFactor and Rotation
    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1){ //L-1 Rotation  
        return LLRotation(p);                               //(L signifies deleted from right side and become heavy on left)
    }
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1){ //L-1 Rotation
        return LRRotation(p);
    }
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==0){ //L-0 Rotation
        return LLRotation(p); //any rotation(LR,LL) both will balanced avl tree
    }
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1){ //R-1 Rotation 
        return RRRotation(p);                                      //(R signifies deleted from left side and become heavy on right)
    }
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1){ //R--1 Rotation
        return RLRotation(p);
    }
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1){ //R-0 Rotation
        return RLRotation(p); //any rotation(RL,RR) both will balanced avl tree
    }

    return p;
}

int main()
{

    AVL tree;

    int A[] = {10, 20, 30, 25, 28, 27, 5};
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        tree.root = tree.rInsert(tree.root, A[i]);
    }

    tree.Inorder();
    cout << endl;

    tree.Delete(tree.root, 28);
    tree.Delete(tree.root, 30);
    tree.Delete(tree.root, 27);

    tree.Inorder();
    cout << endl;
    return 0;
}