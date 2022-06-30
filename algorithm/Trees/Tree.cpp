#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
    Node(){};
    Node(int data);
};
Node::Node(int data){
    lchild=nullptr;
    this->data=data;
    rchild=nullptr;
}

class Tree
{
private:
    Node *root;

public:
    Tree();
    ~Tree();
    void CreateTree();
    void Preorder(Node *p);
    void Preorder() { Preorder(root); } // Passing Private Parameter in Constructor
    void Inorder(Node *p);
    void Inorder() { Inorder(root); }
    void Postorder(Node *p);
    void Postorder() { Postorder(root); }
    void Levelorder(Node *p);
    void Levelorder() { Levelorder(root); }
    int height(Node *p);
    int height() { return height(root); }
    int countNode(Node *p);
    int countNode() { return countNode(root); }
    int leafNode(Node *p);
    int leafNode() { return leafNode(root); }
    int deg2Node(Node *p);
    int deg2Node() { return deg2Node(root); }
    int deg1Node(Node *p);
    int deg1Node() { return deg1or2Node(root); }
    int deg1or2Node(Node *p);
    int deg1or2Node() { return deg1or2Node(root); }
    void iterativePreorder(Node *p);
    void iterativePreorder() { iterativePreorder(root); }
    void iterativeInorder(Node *p);
    void iterativeInorder() { iterativeInorder(root); }
    void iterativePostorder(Node *p);
    void iterativePostorder() { iterativePostorder(root); }
    //Node *generateFromTraversal(int inorder[], int preorder[], int inStart, int inEnd);
};

Tree::Tree()
{
    root = NULL;
}
Tree::~Tree() {delete root;}

void Tree::CreateTree()
{
    Node *p;
    Node *t;
    int x;
    queue<Node *> q;

    root = new Node;
    cout << "Enter root data: ";
    cin >> x;
    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;

    q.emplace(root);

    while (!q.empty())
    {
        p = q.front();
        q.pop();

        cout << "Enter the left child data of " << p->data << " :";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->rchild = nullptr;
            t->lchild = nullptr;
            p->lchild = t;
            q.emplace(t);
        }

        cout << "Enter the right child data of " << p->data << " :";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->rchild = nullptr;
            t->lchild = nullptr;
            p->rchild = t;
            q.emplace(t);
        }
    }
}
//Recursive iteration
void Tree::Preorder(Node *p)
{
    if (p)
    {
        cout << p->data << ", ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Tree::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << ",";
        Inorder(p->rchild);
    }
}
void Tree::Postorder(Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << ", ";
    }
}
void Tree::Levelorder(Node *p)
{
    queue<Node *> q;
    cout << root->data << ", ";
    q.emplace(root);

    while (!q.empty())
    {
        p = q.front();
        q.pop();
        if (p->lchild)
        {
            cout << p->lchild->data << ", ";
            q.emplace(p->lchild);
        }
        if (p->rchild)
        {
            cout << p->rchild->data << ", ";
            q.emplace(p->rchild);
        }
    }
}

//Iterative traversal
// vector<int> Solution::solve(TreeNode* A) {
//     stack<TreeNode*> stk;
//     if(root){
//         stk.push(root)
//     }
//     vector<int> ans;
//     TreeNode* ptr;
//     while(!st.empty()){
//         ptr=stk.top();
//         stk.pop();
//         ans.push(ptr->val);
//         if(ptr->right){
//             stk.push(ptr->right);
//         }
//         if(ptr->left){
//             stk.push(ptr->left);
//         }
        
//     }
// }
void Tree::iterativePreorder(Node *p)
{
    stack<Node *> stk;
    //stk.emplace(p);
    while (!stk.empty() || p != nullptr)
    {

        if (p != nullptr)
        {
            cout << (p->data) << " ";
            stk.push(p);
            p = p->lchild;
        }
        else
        {
            p = stk.top();
            stk.pop();
            p = p->rchild;
        }
    }
    //cout << endl;
}

void Tree::iterativeInorder(Node *p)
{
    stack<Node *> stk;
    //stk.emplace(p);
    while (!stk.empty() || p != nullptr)
    {

        if (p != nullptr)
        {
            stk.push(p);
            p = p->lchild;
        }
        else
        {
            p = stk.top();
            stk.pop();
            cout << (p->data) << " ";
            p = p->rchild;
        }
    }

    //---> Think when below code will fail 
    // do
    // {
    //     if (p != nullptr)
    //     {
    //         stk.push(p);
    //         p = p->lchild;
    //     }
    //     else
    //     {
    //         p = stk.top();
    //         stk.pop();
    //         cout << (p->data) << " ";
    //         p = p->rchild;
    //     }
    // } while (!stk.empty() || p != nullptr);
    //cout << endl;
}

void Tree::iterativePostorder(Node *p)
{

    /*Using two stack*/
    /*if we traverse in : node data->rchild->lchild and then reverse it will will get the answer ans two stacks are used t reverse*/
    // stack<Node*> stk1;
    // stack<Node*> stk2;
    // while(!stk1.empty() || p!=nullptr)
    // {
    //     // stk1.push(p);
    //     // p=p->rchild;
    //     if(p!=nullptr){
    //         stk2.push(p); //instead of printing we are putting in a helper stack
    //         stk1.push(p);
    //         p=p->rchild;
    //     }
    //     else{
    //         p=stk1.top();
    //         stk1.pop();
    //         p=p->lchild;
    //     }
    // }
    // while(!stk2.empty()){
    //     cout<<stk2.top()->data<<" ";  //popping data yields result in reverse order which i want
    //     stk2.pop();
    // }


    /*Using one stack*/
    Node* current=p , *temp=nullptr;
    stack<Node*> stk;
    while (!stk.empty() || current!=NULL)
    {
        if(current!=NULL){
            stk.push(current);
            current=current->lchild;
        }
        else{
            temp=stk.top()->rchild;
            if(temp==nullptr){
                temp=stk.top();
                cout<<temp->data<<" ";
                stk.pop();
                while(!stk.empty() && stk.top()->rchild==temp){
                    temp=stk.top();
                    cout<<temp->data<<" ";
                    stk.pop();
                }
            }
            else{
                current=temp;
            }
        }
    }


    /* It will only work for +ve numbers */
    // stack<Node *> stk;
    // do
    // {
    //     if (p != nullptr)
    //     {
    //         stk.push(p);
    //         p = p->lchild;
    //     }
    //     else
    //     {
    //         p = stk.top();
    //         stk.pop();
    //         if (p->data > 0)
    //         {
    //             p->data = -1 * (p->data);
    //             stk.push(p);
    //             p = p->rchild;
    //         }
    //         else
    //         {
    //             //p = stk2.top();
    //             //stk2.pop();
    //             p->data = -1 * (p->data);
    //             cout << p->data << " ";
    //             p = nullptr;
    //         }
    //     }
    // } while (!stk.empty() || p != nullptr);


    /* Giving conversion type error*/
    // long int temp;
    // while (p != nullptr || !stk.empty())
    // {
    //     if (p != nullptr)
    //     {
    //         stk.push(p);
    //         p = p->lchild;
    //     }
    //     else
    //     {
    //         temp = (long int)stk.top();
    //         stk.pop();
    //         if (temp > 0)
    //         {
    //             stk.push((Node*)(-temp));
    //             p = ((Node *)temp)->rchild;
    //         }
    //         else
    //         {
    //             cout << ((Node *)(-1 * temp))->data << " ";
    //             p = nullptr;
    //         }
    //     }
    // }
    // cout << endl;
}

int Tree::height(Node *p)
{
    int l = 0;
    int r = 0;
    if (p == nullptr)
    {
        return 0;
    }
    l = height(p->lchild);
    r = height(p->rchild);
    //return l+r+1;  //no of nodes
    return ((l > r) ? l + 1 : r + 1);
}

int Tree::countNode(Node *p)
{
    int l = 0;
    int r = 0;
    if (p == nullptr)
    {
        return 0;
    }
    l = countNode(p->lchild);
    r = countNode(p->rchild);
    return l + r + 1;
}

int Tree::leafNode(Node *p)
{
    if (p == nullptr)
    {
        return 0;
    }
    if (!p->lchild && !p->rchild)
    {
        return leafNode(p->lchild) + leafNode(p->rchild) + 1;
    }
    return leafNode(p->lchild) + leafNode(p->rchild);
}

int Tree::deg2Node(Node *p)
{
    if (p == nullptr)
    {
        return 0;
    }
    if (p->lchild && p->rchild)
    {
        return deg2Node(p->lchild) + deg2Node(p->rchild) + 1;
    }
    return deg2Node(p->lchild) + deg2Node(p->rchild);
}

int Tree::deg1Node(Node *p)
{
    if (p == nullptr)
    {
        return 0;
    }
    if ((p->lchild != NULL) ^ (p->rchild != NULL))
    {
        return deg1Node(p->lchild) + deg1Node(p->rchild) + 1;
    }
    return deg1Node(p->lchild) + deg1Node(p->rchild);
}

int Tree::deg1or2Node(Node *p)
{
    if (p == nullptr)
    {
        return 0;
    }
    if (p->lchild || p->rchild)
    {
        return deg1or2Node(p->lchild) + deg1or2Node(p->rchild) + 1;
    }
    return deg1or2Node(p->lchild) + deg1or2Node(p->rchild);
}

int main()
{
    Tree bt;

    bt.CreateTree();
    cout << endl;

    cout << "RecursivePreorder: " << flush;
    bt.Preorder();
    cout << endl;

    cout << "RecursiveInorder: " << flush;
    bt.Inorder();
    cout << endl;

    cout << "RecursivePostorder: " << flush;
    bt.Postorder();
    cout << endl;

    cout << "IterativePreorder: " << flush;
    bt.iterativePreorder();
    cout << endl;

    cout << "IterativeInorder: " << flush;
    bt.iterativeInorder();
    cout << endl;

    cout << "IterativePostorder: " << flush;
    bt.iterativePostorder();
    cout << endl;

    cout << "Levelorder: " << flush;
    bt.Levelorder();
    cout << endl;

    cout << "Height: " << bt.height() << endl;
    cout << "No of nodes: " << bt.countNode() << endl;
    cout << "No of leaf nodes: " << bt.leafNode() << endl;
    cout << "No of nodes with degree 2: " << bt.deg2Node() << endl;
    cout << "No of nodes with degree 1: " << bt.deg1Node() << endl;
    cout << "No of nodes with degree 1 or 2: " << bt.deg1or2Node() << endl;


    return 0;
}