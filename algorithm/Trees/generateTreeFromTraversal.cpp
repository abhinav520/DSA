#include <iostream>
#include "Tree.cpp"  //included my own tree file
using namespace std;
int searchIndex(int inorder[],int key,int inStart,int inEnd){
    for(int i=inStart;i<=inEnd;i++){
        if(key==inorder[i]){
            return i;
        }
    }
    return -1;
}


Node* generateFromTraversal(int inorder[],int preorder[],int inStart,int inEnd){
    static int preIndex=0;
    if(inStart>inEnd){
        return nullptr;
    }
    Node* node=new Node(preorder[preIndex++]);
    if(inStart==inEnd){
        return node;
    }
    int splitIndex=searchIndex(inorder,node->data,inStart,inEnd);
    node->lchild=generateFromTraversal(inorder,preorder,inStart,splitIndex-1);
    node->rchild=generateFromTraversal(inorder,preorder,splitIndex+1,inEnd);
    return node;
} 


int main()
{
    int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};
    Node* t= generateFromTraversal(inorder,preorder,0,(sizeof(inorder)/sizeof(inorder[0])-1));
    Tree bt;
    bt.iterativePreorder(t);

    return 0;
}