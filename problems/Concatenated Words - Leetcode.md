---
Created Time: Dec 19, 2020 2:28 PM
Do Date: Dec 19, 2020
Last edited time: May 11, 2021 9:06 AM
Points: 2000
Pomos (25 mins): 1
Problem Statement: Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.
A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array
Source: https://leetcode.com/problems/concatenated-words/
Status: ok
---

# Concatenated Words - Leetcode

Given a list of words (**without duplicates**), please write a program that returns all concatenated words in the given list of words.
A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.
**Example:**
```
Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
 "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
```
**Note:**
1. The number of elements of the given array will not exceed `10,000` 
2. The length sum of elements in the given array will not exceed `600,000`.
3. All the input string will only include lower case letters.
4. The returned elements order does not matter.
---
I think it can be solved using trie datastructure. I will try to implement this. (below is working)
```cpp
#define alpha 26
struct trie {
    /** Initialize your data structure here. */
    struct node {
        char ch;
        int is_word = false;
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
        n->is_word = word.length();
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
    
    bool check_concatenation(string &word, int idx)
    {
        node *n = root; 
        bool ans = false; 
        for (int i = idx; i < word.length(); i++)
        {
            if (n->children[word[i] - 'a']) 
                n = n->children[word[i] - 'a'];
            else return false; 
            if (n->is_word)
            {
                ans = check_concatenation(word, i + 1); 
            }
            if (ans) return true; 
        }
        if (n->is_word) return (n->is_word != word.length());
        else return false;
    }
    
};
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        trie t; 
        for (auto &w: words)
        {
            t.insert(w); 
        }
        vector<string> ans;
        for (int i = 0; i < words.size(); i++)
        {
            if (t.check_concatenation(words[i], 0)) ans.push_back(words[i]); 
        }
        return ans; 
    }
};
```
Patterns: [Trie](Trie.md)