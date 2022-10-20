#include<bits/stdc++.h>
using namespace std;
class TrieNode
{
    public:
    char data;
    TrieNode *children[26];
    bool isterminal;
    
    TrieNode(char ch)
    {
        this->data= ch;
        for(int i=0;i<26;i++)
        {
            children[i]= NULL;
        }
        isterminal= false;
    }
};
class Trie{
    public:
    TrieNode *root;
    Trie()
    {
        root= new TrieNode('\0');
    }
    //to insert the word the trie data structure one by one
    void insertUtil(TrieNode *root, string word)
    {
        //base case
        if(word.length() == 0)
        {
            root->isterminal= true;
            return;
        } 
        //now find the index to insert the word character
        int index= word[0]-'A';   //assuming that the words are caps 
        TrieNode *child;
        if(root->children[index] != NULL)
        {
            child= root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index]= child;
        }

        //recursive call for other word character
        insertUtil(child, word.substr(1));
    }
    void insertWord(string word){
        insertUtil(root, word);
    }

    bool searchWordUtil(TrieNode *root, string word)
    {
        //base case
        if(word.length() == 0){
            return root->isterminal;
        }
        int index= word[0]-'A';
        TrieNode *child;
        if(root->children[index] != NULL)
        {
            child= root->children[index];
        }
        else{
            return false;
        }
        //recursion to further check
        return searchWordUtil(child, word.substr(1));
    }
    bool searchWord(string word){
        return searchWordUtil(root, word);
    }

    bool Deletetheword(TrieNode *root, string word)
    {
        if(word.length() == 0)
        {
            if(root->isterminal == true)
            {
                bool x= root->isterminal;
                root->isterminal= false;
                return x;
            }
            else{
                return root->isterminal;
            }
        }

        int index= word[0]-'A';

        TrieNode *child;
        if(root->children[index]!=NULL)
        {
            cout<<"\nHi"<<endl;
            child= root->children[index];
        }
        else{
            return false;
        }

        //recursion to check the other character inside the word
        return Deletetheword(child, word.substr(1));
    }
    
    void deleteword(string word)
    {
        bool x= Deletetheword(root, word);
        if(x)
        cout<<"\ndeleted the word from the trie."<<endl;
        else{
            cout<<"\nNot found";
        }
    }
};

int main()
{
    Trie *t= new Trie();
    t->insertWord("ANU");
    t->insertWord("ANOR");
    t->insertWord("APOO");
    t->insertWord("POOJS");
    cout<<t->searchWord("POO");
    cout<<t->searchWord("POOJ");
    cout<<t->searchWord("POOJS");
    t->deleteword("anu");
    cout<<"Searching for ANU after deleting the anu"<<endl;
    cout<<t->searchWord("ANU");
}
