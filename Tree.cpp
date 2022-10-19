//to create bianry tree and traverals of binary and some function to find height and width etc.
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
Node* createbinarytree(Node *root)
{
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;
    if(data==-1)
    {
        return NULL;
    }
    root= new Node(data);
    cout<<"Enter the data to be inserted in left of "<<data<<endl;
    root->left= createbinarytree(root->left);
    cout<<"Enter the data to be inserted in the right of "<<data<<endl;
    root->right= createbinarytree(root->right);
    return root;
    
}
int height(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left= height(root->left);
    int right= height(root->right);
    int h= max(left, right)+1;
    return h;
}

//inorder traversal using the recursion
void inorderTraversal(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

//inorder traversal using the iterative way
void iterativeinorder(Node *root)
{
    vector<int> result;
    stack<Node*> st;
    st.push(root);
    while(true)
    {
    if(root != NULL)
    {
        st.push(root->left);
        root= root->left;
    }
    else{
        if(st.empty())
        {
            break;
        }
        root= st.top();
        st.pop();
        result.push_back(root->data);
        root= root->right;
    }
    }

    for(auto i: result)
    cout<<i<<" ";
}


void preorderTraversal(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}
void levelordertraversal(Node *root)
{
    queue<Node*> q;
    q.push(root);
    // q.push(NULL);
    while(!q.empty())
    {
        Node *temp= q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
        // q.push(NULL);
    }
}
//to find the diameter of binary tree
int diameter(Node *root)
{
    //here we have to find the maximum number of nodes in longest width of nodes
    if(root==NULL)
    {
        return 0;
    }
    int op1= diameter(root->left);
    int op2= diameter(root->right);
    int op3= height(root->left)+ height(root->right)+1;
    int ans= max(op3, max(op1, op2));
    return ans;
}
int main()
{
        Node *root=NULL;
        root= createbinarytree(root);
        levelordertraversal(root);
        cout<<"iterative traversal of tree: "<<endl;
        // iterativeinorder(root);
        int h= height(root);
        cout<<"\nheight of binary tree is: "<<h;
        cout<<"\nInorder traversal of binary tree: "<<endl;
        inorderTraversal(root);
        cout<<"\nPreorder traversal of binary tree: "<<endl;
        preorderTraversal(root);
        cout<<"\nPostorderTraversal of binary tree: "<<endl;
        postorderTraversal(root);
}
