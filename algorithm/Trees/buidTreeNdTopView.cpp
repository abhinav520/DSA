//Given a pointer to the root of a binary tree, print the top view of the binary tree. Thetree as seen from the top the nodes, is called the top view of the tree
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node *left;
    node *right;
};
typedef struct node node;

struct Queue
{
    node *treeNode;
    int hd;
    struct Queue *next;
} *front = NULL, *last = NULL;
struct utility
{
    node *treeNode;
    int hd;
};
void enqueue(int hd, node *treeNode)
{
    struct Queue *temp = (struct Queue *)malloc(sizeof(struct Queue));
    if (temp == NULL)
    {
        printf("Queue overflow\n");
        exit(1);
    }
    temp->treeNode = treeNode;
    temp->hd = hd;
    temp->next = NULL;
    if (front == NULL)
    {
        front = last = temp;
    }
    else
    {
        last->next = temp;
        last = temp;
    }
}

struct utility dequeue()
{
    if (front == NULL)
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    else
    {
        struct utility x;
        x.treeNode = front->treeNode;
        x.hd = front->hd;
        struct Queue *temp = front;
        front = front->next;
        free(temp);
        return x;
    }
}
int qIsEmpty()
{
    return (front == NULL);
}
node *build()
{
    int x;
    cin >> x;
    if (x == -1)
    {
        return NULL;
    }
    node *root = (node *)malloc(sizeof(node));
    root->val = x;
    cout << "\nEnter left of " << x << " : ";
    root->left = build();
    cout << "\nEnter right of " << x << " : ";
    root->right = build();
    return root;
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

int countNode(node *p)
{
    int l = 0;
    int r = 0;
    if (p == nullptr)
    {
        return 0;
    }
    l = countNode(p->left);
    r = countNode(p->right);
    return l + r + 1;
}

void topView(node *root, int n, int *lArr, int *rArr)
{
    if (root == NULL)
    {
        exit(1);
    }

    enqueue(0, root);
    while (!(qIsEmpty()))
    {
        struct utility it = dequeue();
        int hd = it.hd;
        node *currNode = it.treeNode;
        if (hd >= 0)
        {
            if (rArr[hd] == -1)
            {
                rArr[hd] = currNode->val;
            }
        }
        else
        {
            if (lArr[hd * -1] == -1)
            {
                lArr[hd * -1] = currNode->val;
            }
        }
        if (currNode->left)
        {
            enqueue(hd - 1, currNode->left);
        }
        if (currNode->right)
        {
            enqueue(hd + 1, currNode->right);
        }
    }
}

int main()
{
    printf("If there is no child enter -1\n");
    cout << "\nEnter root value: ";

    node *root = build();
    int n = countNode(root);
    int lArr[n + 1];
    int rArr[n + 1];
    for (int i = 0; i <= n; i++)
    {
        lArr[i] = -1;
        rArr[i] = -1;
    }
    topView(root, n, lArr, rArr);
    cout << "\n";
    for (int i = n; i >= 1; i--)
    {
        if (lArr[i] == -1)
            continue;
        cout << lArr[i] << " ";
    }
    for (int i = 0; i <= n; i++)
    {
        if (rArr[i] == -1)
            break;
        cout << rArr[i] << " ";
    }
    cout << endl;
    cout << "\nPre Order: ";
    preorder(root);
    cout << "\nPost Order: ";
    postorder(root);
    cout << "\nIn Order: ";
    inorder(root);
}

//1 2 4 -1 -1 5 6 -1 -1 -1 3 -1 7 -1 -1
//1 2 -1 4 -1 5 -1 6 -1 -1 3 -1 -1

// { Driver Code Starts
//Initial Template for C++

// #include <bits/stdc++.h>
// using namespace std;

// // Tree Node
// struct Node
// {
//     int data;
//     Node *left;
//     Node *right;
// };

// // Utility function to create a new Tree Node
// Node *newNode(int val)
// {
//     Node *temp = new Node;
//     temp->data = val;
//     temp->left = NULL;
//     temp->right = NULL;

//     return temp;
// }

// // Function to Build Tree
// Node *buildTree(string str)
// {
//     // Corner Case
//     if (str.length() == 0 || str[0] == 'N')
//         return NULL;

//     // Creating vector of strings from input
//     // string after spliting by space
//     vector<string> ip;

//     istringstream iss(str);
//     for (string str; iss >> str;)
//         ip.push_back(str);

//     // Create the root of the tree
//     Node *root = newNode(stoi(ip[0]));

//     // Push the root to the queue
//     queue<Node *> queue;
//     queue.push(root);

//     // Starting from the second element
//     int i = 1;
//     while (!queue.empty() && i < ip.size())
//     {

//         // Get and remove the front of the queue
//         Node *currNode = queue.front();
//         queue.pop();

//         // Get the current node's value from the string
//         string currVal = ip[i];

//         // If the left child is not null
//         if (currVal != "N")
//         {

//             // Create the left child for the current node
//             currNode->left = newNode(stoi(currVal));

//             // Push it to the queue
//             queue.push(currNode->left);
//         }

//         // For the right child
//         i++;
//         if (i >= ip.size())
//             break;
//         currVal = ip[i];

//         // If the right child is not null
//         if (currVal != "N")
//         {

//             // Create the right child for the current node
//             currNode->right = newNode(stoi(currVal));

//             // Push it to the queue
//             queue.push(currNode->right);
//         }
//         i++;
//     }

//     return root;
// }

// // } Driver Code Ends

// /*
// struct Node
// {
//     int data;
//     Node* left;
//     Node* right;
// };
// */
// class Solution
// {
// public:
//     //Function to return a list of nodes visible from the top view
//     //from left to right in Binary Tree.
//     vector<int> topView(Node *root)
//     {
//         map<int, int> mp;
//         queue<pair<int, Node *>> q;
//         q.push({0, root});
//         while (!q.empty())
//         {
//             pair<int, Node *> tmp = q.front();
//             q.pop();
//             if (mp.find(tmp.first) == mp.end())
//             {
//                 mp[tmp.first] = (tmp.second)->data;
//             }
//             if (tmp.second->left)
//             {
//                 q.push({tmp.first - 1, tmp.second->left});
//             }
//             if (tmp.second->right)
//             {
//                 q.push({tmp.first + 1, tmp.second->right});
//             }
//         }
//         vector<int> ans;
//         cout<<endl;
//         for (auto x : mp)
//         {
//             ans.push_back(x.second);
//         }
//         return ans;
//     }
// };

// // { Driver Code Starts.

// int main()
// {
//     int tc;
//     cin >> tc;
//     cin.ignore(256, '\n');
//     while (tc--)
//     {
//         string treeString;
//         getline(cin, treeString);
//         Solution ob;
//         Node *root = buildTree(treeString);
//         vector<int> vec = ob.topView(root);
//         for (int x : vec)
//             cout << x << " ";
//         cout << endl;
//     }
//     return 0;
// } // } Driver Code Ends