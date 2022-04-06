//
//  Q1991.cpp
//  init
//
//  Created by Kong Nayeon  on 2022/04/01.
//
//
//  BinarySearchTree.c
//  Tree
//
//  Created by Kong Nayeon  on 2021/10/01.
//
#include <iostream>
#include <string.h>
using namespace std;


typedef struct TreeNode{
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

//새로운 트리를 생성해서 반환한다
TreeNode* newNode(char data){
    TreeNode *newTree = (TreeNode*)malloc(sizeof(TreeNode));
    newTree->data = data;
    newTree->left = newTree->right = NULL;
    return newTree;
}

//재귀를 이용한 탐색
TreeNode* searchNode(TreeNode *tree,char data){
    if (tree != NULL){
        if(tree->data == data) return tree;
        else {
            TreeNode *temp = searchNode(tree->left, data);
            if(temp!=NULL) return temp;
        }
        return searchNode(tree->right, data);
    }
    
    return NULL;
}

//노드 추가
void insertNode(TreeNode* tree, char a ,char b, char c){
    
    tree -> data = a;
    
    //'.'이 들어오면 값을 넣지 않는다
    if(b!='.') tree->left = newNode(b);
    else tree->left =NULL;
    if(c!='.') tree->right = newNode(c);
    else tree->right = NULL;
}

//중위 순회
void in_order(TreeNode*root){
    if(root!=NULL){
        in_order(root->left);
        cout << root->data;
        in_order(root->right);
    }
}

//전위 순회
void pre_oder(TreeNode*root){
    
    cout << root->data;
    if(root->left!=NULL) pre_oder(root->left);
    if(root->right!=NULL)pre_oder(root->right);

}

//후위 순회
void post_order(TreeNode*root){
    if(root!=NULL){
        post_order(root->left);
        post_order(root->right);
       cout << root->data;
    }
}


int main(void){
    
    
    TreeNode *tree = newNode(NULL);
    TreeNode *temp;
    int num;
    char a,b,c;
    
    cin >> num;
    
    for(int i = 0; i<num; i++){
        cin >> a >> b >> c;
        temp = searchNode(tree, a);
        if(temp !=NULL) insertNode(temp,a,b,c);
        else insertNode(tree, a, b, c);
    }
    
    pre_oder(tree);
    cout<<endl;
    in_order(tree);
    cout<<endl;
    post_order(tree);

    return 0;
}
