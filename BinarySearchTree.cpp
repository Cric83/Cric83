#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data= data;
        this->left= NULL;
        this->right= NULL;
   }
};
Node* insertinbst(Node* root, int data)
{
    if(root == NULL)
    {
        Node *root= new Node(data);
        return root;
    }
    if(data < root->data)
    {
        root->left= insertinbst(root->left, data);
    }
    if(data > root->data)
    {
        root->right= insertinbst(root->right, data);
    }
    return root;
}
Node* takeinput(Node *root)
{
    int data;
    cin>>data;
    while(data!=-1)
    {
        root= insertinbst(root, data);
        cin>>data;
    }
    return root;
}

void levelordertraversal(Node *root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node *frontnode= q.front();
        q.pop();
        if(frontnode== NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else{
            cout<<frontnode->data<<" ";
            if(frontnode->left)
            q.push(frontnode->left);
            if(frontnode->right)
            q.push(frontnode->right);
        }
    }
}
int main()
{
  Node *root= NULL;
    root= takeinput(root);

    cout<<"Level order traversal: "<<endl;
    levelordertraversal(root);
}
