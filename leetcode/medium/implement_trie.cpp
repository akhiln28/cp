#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <cmath>
#include <stdio.h>
#define alpha 26

using namespace std;

struct trie {
    /** Initialize your data structure here. */
    struct node {
        char ch;
        bool is_word = false;
        vector<node *> children;
        node (char ch)
        {
            this->ch = ch;
            is_word = false;
            children.resize(alpha);
        }
    };
    node *root; 
    trie() {
        root = new node('a' - 1);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        node *n = root;
        int i = 0;
        for (i = 0; i < word.length(); i++)
        {
            if (n->children[word[i] - 'a'])
                n = n->children[word[i] - 'a'];
            else break;
        }
        for (int j = i; j < word.length(); j++)
        {
            n->children[word[j] - 'a'] = new node(word[j]);
            n = n->children[word[j] - 'a'];
        }
        n->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node *n = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (n->children[word[i] - 'a']) 
                n = n->children[word[i] - 'a'];
            else return false;
        }
        return n->is_word == true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node *n = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (n->children[prefix[i] - 'a']) 
                n = n->children[prefix[i] - 'a'];
            else return false;
        }
        return true;
    }
};

int main()
{
    trie t;
    t.insert("akhil");
    cout << t.search("akhil") << endl;
    cout << t.startsWith("akh") << endl;
    cout << t.search("akhi") << endl;
    cout << t.search("akl") << endl;
}