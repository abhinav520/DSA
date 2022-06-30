#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
    Node() {}
    Node(int data);
};
Node::Node(int data)
{
    lchild = nullptr;
    this->data = data;
    rchild = nullptr;
}

class BST
{
private:
    Node *root;

public:
    BST() { root = nullptr; }
    ~BST() { delete root; }
    Node *getRoot() { return root; }
    void iInsert(int key);
    Node *rInsert(Node *p, int key);
    void Inorder(Node *p);
    Node *iSearch(int key);
    Node *rSearch(Node *p, int key);
    Node *Delete(Node *p, int key);
    int Height(Node *p);
    Node *InorderPre(Node *p);
    Node *InorderSucc(Node *p);
    void createFromPreorder(int pre[], int n);
    void createFromPostorder(int post[], int n);
};

void BST::iInsert(int key)
{
    Node *p = root;
    Node *r = nullptr;
    if (root == nullptr)
    {
        root = new Node(key);
        return;
    }
    while (p != nullptr) //condtn so that it gets inserted at leaf node
    {
        r = p;
        if (p->data > key)
        {
            p = p->lchild;
        }
        else if (p->data < key)
        {
            p = p->rchild;
        }
        else
        {
            return;
        }
    }
    Node *node = new Node(key);
    if (r->data > key)
    {
        r->lchild = node;
    }
    else
    {
        r->rchild = node;
    }
}

Node *BST::rInsert(Node *p, int key)
{
    if (p == nullptr)
    {
        Node *node = new Node(key);
        return node;
    }
    if (p->data > key)
    {
        p->lchild = rInsert(p->lchild, key);
    }
    else
    {
        p->rchild = rInsert(p->rchild, key);
    }
    return p; //key==p->data
}

void BST::Inorder(Node *p) //sorted order
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

Node *BST::iSearch(int key)
{
    Node *p = root;
    while (p != NULL)
    {
        if (p->data == key)
        {
            return p;
        }
        else if (p->data > key)
        {
            p = p->lchild;
        }
        else
        {
            p = p->rchild;
        }
    }
    return NULL;
}

Node *BST::rSearch(Node *p, int key)
{
    if (p->data == key || p == nullptr)
    {
        return p;
    }
    else if (p->data > key)
    {
        return rSearch(p->lchild, key);
    }
    else
    {
        return rSearch(p->rchild, key);
    }
}

Node *BST::Delete(Node *p, int key)
{
    Node *q;
    if (p == nullptr)
    {
        return nullptr;
    }
    if (p->lchild == nullptr && p->rchild == nullptr)
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
        if (Height(p->lchild) > Height(p->rchild))
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
    return p;
}

int BST::Height(Node *p)
{
    if (p == nullptr)
    {
        return 0;
    }
    int l = Height(p->lchild);
    int r = Height(p->rchild);
    return l > r ? l + 1 : r + 1;
}

Node *BST::InorderPre(Node *p) //note i have passed root's leftchild and not root
{ 
    while (p && p->rchild != nullptr)
    {
        p = p->rchild;
    }
    return p;
}

Node *BST::InorderSucc(Node *p)  //note i have passed root's rightchild and not root
{
    while (p && p->lchild != nullptr)
    {
        p = p->lchild;
    }
    return p;
}

void BST::createFromPreorder(int *pre, int n)
{
    stack<Node *> stk;
    Node *t, *p;
    int i = 0;
    root = new Node(pre[i++]);
    p = root;
    // Node* inf=new Node(1e9);
    // stk.push(inf);
    while (i < n)
    {
        //left child case
        if (pre[i] < p->data)
        {
            t = new Node(pre[i++]);
            p->lchild = t;
            stk.push(p);
            p = t;
        }
        else
        {
            //right child case
            if (pre[i] > p->data && pre[i] < (stk.empty() ? 1e9 : stk.top()->data))
            {
                t = new Node(pre[i++]);
                p->rchild = t;
                p = t;
            }
            else
            {
                p = stk.top();
                stk.pop();
            }
        }
    }
}
void BST::createFromPostorder(int *pos, int n)
{
    stack<Node *> stk;
    Node *t, *p;
    int i = 0;
    Node *root = new Node(pos[i++]);
    p = root;
    Node *inf = new Node(-1e9);
    stk.push(inf);
    while (i < n)
    {
        //right child case
        if (pos[i] > p->data)
        {
            t = new Node(pos[i++]);
            p->rchild = t;
            stk.push(p);
            p = t;
        }
        else
        {
            //left child case
            if (pos[i] < p->data && pos[i] > stk.top()->data)
            {
                t = new Node(pos[i++]);
                p->lchild = t;
                p = t;
            }
            else
            {
                p = stk.top();
                stk.pop();
            }
        }
    }
}

int main()
{
    BST bst;
    // Iterative insert
    bst.iInsert(10);
    bst.iInsert(5);
    bst.iInsert(20);
    bst.iInsert(8);
    bst.iInsert(30);

    // Inorder traversal
    bst.Inorder(bst.getRoot());
    cout << endl;

    // Iterative search
    Node *temp = bst.iSearch(2);
    if (temp != nullptr)
    {
        cout << temp->data << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    // Recursive search
    temp = bst.rSearch(bst.getRoot(), 20);
    if (temp != nullptr)
    {
        cout << temp->data << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    // Recursive insert
    bst.rInsert(bst.getRoot(), 50);
    bst.rInsert(bst.getRoot(), 70);
    bst.rInsert(bst.getRoot(), 1);
    bst.Inorder(bst.getRoot());
    cout << "\n"
         << endl;

    // Inorder predecessor and inorder successor
    BST bs;
    bs.iInsert(5);
    bs.iInsert(2);
    bs.iInsert(8);
    bs.iInsert(7);
    bs.iInsert(9);
    bs.iInsert(1);

    temp = bs.InorderPre(bs.getRoot());
    cout << "InPre: " << temp->data << endl;

    temp = bs.InorderSucc(bs.getRoot());
    cout << "InSucc: " << temp->data << endl;

    bs.Inorder(bs.getRoot());
    cout << endl;

    // Delete
    bs.Delete(bs.getRoot(), 5);
    bs.Inorder(bs.getRoot());
    cout << endl;

    // BST from Preorder traversal
    cout << "BST from Preorder: " << flush;
    int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
    int n = sizeof(pre) / sizeof(pre[0]);

    BST b;
    b.createFromPreorder(pre, n);
    b.Inorder(b.getRoot());
    cout << endl;

    // BST from Preorder traversal
    cout << "BST from Postorder: " << flush;
    int post[] = {15, 10, 25, 20, 45, 50, 40, 30};
    int n2 = sizeof(post) / sizeof(post[0]);
    BST b2;
    b2.createFromPostorder(post, n2);
    b2.Inorder(b.getRoot());
    cout << endl;

    return 0;
}