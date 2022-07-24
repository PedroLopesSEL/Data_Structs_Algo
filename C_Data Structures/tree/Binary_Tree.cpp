#include <iostream>

using namespace std;

// class Node
// {
//     int data;
//     Node *left;
//     Node *right;

// public:
//     Node(int val)
//     {
//         data = val;

//         left = NULL;
//         right = NULL;
//     }
// };

// int main()
// {
//     return 0;
// }

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* Create(int data){
    Node* newNode= new Node();
    newNode->data=data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* Insert(Node* root,int data){
    if (root==NULL){
        root = Create(data);
        return root;
    }
    else if (data <=root->data){
        root->left = Insert(root->left,data);
    }
    else if (data >= root->data)
    {
        root->right = Insert(root->right, data);
    }
    return root;
}
bool Search( Node* root, int data){
    if(root == NULL) return false;
    else if (root->data==data)return true;
    else if(data <=root->data) return Search(root->left,data);
    else return Search(root->right,data);

}

int main (){
    Node *root;
    root = NULL; // setting tree as empty
    root = Insert(root,15);// Insert(&=0,1) return for exemple pointer to adress 2020
    root = Insert(root, 10); // Inser(&=200,10)
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);
    int number;
    cout << "Enter number be searched\n";
    cin >> number;
    if (Search(root,number)== true) cout << "Found\n";
    else cout << "Not Found\n";
    return 0;
}