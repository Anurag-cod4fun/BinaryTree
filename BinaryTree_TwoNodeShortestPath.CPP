// findind shortest path between two nodes in the binary tree using LCA
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* temp = new Node();
    temp -> left = temp -> right = NULL;
    temp -> data = data;
    return temp;
}

Node* findLCA(Node* root , int n1 , int n2) {
    if (root == NULL) {
        return NULL;
    }
    if (root -> data == n1 || root -> data == n2) {
        return root;
    }
    Node* left = findLCA(root -> left , n1 , n2);
    Node* right = findLCA(root -> right , n1 , n2);

    if (left != NULL || right != NULL) {
        return root;
    }
    if (left == NULL || right == NULL) {
        return NULL;
    }
    if (left == NULL) {
        return findLCA(root -> left , n1 , n2);
    }
        return findLCA(root -> left , n1 , n2);
}

int getdist (Node* root , int k , int d) {
    if (root == NULL) {
        return -1;
    }
    if (root -> data == k) {
        return d;
    }
    int left = getdist(root->left , k , d+1);
    if (left != -1) {
        return left;
    }
    return getdist(root->right , k , d+1);
}

int Tdist(Node* root , int n1 , int n2) {
    Node* lca = findLCA(root ,  n1,  n2);
    int d1 = getdist(lca , n1 , 0);
    int d2 = getdist(lca , n2 , 0);

    return d1 + d2;
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt" , "w" , stdout);
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    int n1 , n2;
    cin >> n1 >> n2;
    int ans = Tdist(root , n1 , n2);
    cout << ans;
}