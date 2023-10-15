/*
 * @Description: 
 * @Author: Alex Li
 * @Date: 2022-03-20 22:40:50
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * Copyright (c) 2023 by ${Alex Lil}, All Rights Reserved. 
 */
/*
 * @Description: 
 * @Author: Alex Li
 * @Date: 2022-03-20 22:40:50
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * Copyright (c) 2023 by ${Alex Lil}, All Rights Reserved. 
 */

#include <iostream>
using namespace std;
const int ALPHABET_SIZE=26;

//trie node structure
typedef struct TrieNode{
    struct TrieNode * children[ALPHABET_SIZE];
    bool isEndOfWord;
}TrieNode;

 TrieNode * create_node(void){
     TrieNode * pNode=new TrieNode;
     pNode->isEndOfWord=false;
     for (int i = 0; i < ALPHABET_SIZE; i++)
     pNode->children[i]=NULL;
     return pNode;     
}

void insert_node(TrieNode * root,string word){
    TrieNode * current=root;
    int len=word.length();
     for (int i = 0; i < len; i++){
        int index=word[i]-'a';
        if(current->children[index]==NULL){
            current->children[index]=create_node();
        }
        current=current->children[index];
     }
     current->isEndOfWord=1;
}

bool search_node(TrieNode * root, string word){
    TrieNode * current=root;
    int len=word.length();
    for (int i = 0; i <len; i++){
        int index=word[i]-'a';
        if (current->children[index]==NULL)return 0;
        current=current->children[index];
    }
    return current->isEndOfWord;    
}

bool isEmpty(TrieNode * root){
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
       if (root->children[i])return false;
        }
    return true;
}

TrieNode* remove_node(TrieNode * root,string word,int depth=0){
    if(!root)return NULL;
    if(depth==word.size()){
        if(root->isEndOfWord)root->isEndOfWord=false;
    if(isEmpty(root)){
        delete(root);
        root=NULL;
    }
    return root;
    }
    int index=word[depth]-'a';
    root->children[index]=remove_node(root->children[index],word,depth+1);
    if(isEmpty(root)&&root->isEndOfWord==false){
        delete(root);
        root=NULL;
    }
    return root;
}

int main(){
     TrieNode * root=create_node();
    
     insert_node(root, "hello");

     if(search_node(root,"hello")) cout<<" in";
     else cout<< "no in";
     cout<<endl;
     remove_node(root,"hello");
     if(search_node(root,"hello")) cout<<" in";
     else cout<< "no in";
}