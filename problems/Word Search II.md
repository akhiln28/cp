---
Created Time: Dec 01, 2020 11:55 PM
Do Date: Dec 01, 2020
Last edited time: May 11, 2021 9:06 AM
Points: 2000
Related To: Word%20Search%20cf164f2e5a734d9a8134eae2d127b04c.md
Source: https://leetcode.com/problems/word-search-ii/
Status: done
---

# Word Search II

Given an `m x n` `board` of characters and a list of strings `words`, return *all words on the board*.
Each word must be constructed from letters of sequentially adjacent cells, where **adjacent cells** are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
**Example 1:**
![https://assets.leetcode.com/uploads/2020/11/07/search1.jpg](https://assets.leetcode.com/uploads/2020/11/07/search1.jpg)
```
Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
```
**Example 2:**
![https://assets.leetcode.com/uploads/2020/11/07/search2.jpg](https://assets.leetcode.com/uploads/2020/11/07/search2.jpg)
```
Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []
```
**Constraints:**
- `m == board.length`
- `n == board[i].length`
- `1 <= m, n <= 12`
- `board[i][j]` is a lowercase English letter.
- `1 <= words.length <= 3 * 104`
- `1 <= words[i].length <= 10`
- `words[i]` consists of lowercase English letters.
- All the strings of `words` are unique.
---
```cpp
class Solution {
public:
    struct trie {
        struct node 
        {
            char ch;
            bool is_word;
            vector<node *> next;
            node (char ch)
            {
                this->ch = ch;
                next.resize(26);
                is_word = false;
            }
        };
        node *root;
        trie()
        {
            root = new node('0');
        }
        void insert(string word)
        {
            node *n = root;
            int i = 0; 
            for (i = 0; i < word.length(); i++)
            {
                if (n->next[word[i] - 'a']) n = n->next[word[i] - 'a'];
                else break;
            }
            for (int j = i; j < word.length(); j++)
            {
                n->next[word[j] - 'a'] = new node(word[j]);
                n = n->next[word[j] - 'a'];
            }
            n->is_word = true;
        }
        bool check(vector<vector<char>> &board, int i, int j)
        {
            int n = board.size(), m = board[0].size();
            return (i >= 0 and i < n and j >= 0 and j < m);
        }
        
        void search_point(vector<vector<char>> &board, int i, int j, string str, node *n, vector<string> &ans, vector<vector<bool>> &vis)
        {
            vector<pair<int, int>> t{{i, j + 1}, {i, j - 1}, {i + 1, j}, {i - 1, j}};
            str += n->ch;
            vis[i][j] = true;
            if (n->is_word) ans.push_back(str);
            for (auto p : t)
            {
                if (check(board, p.first, p.second) and n->next[board[p.first][p.second] - 'a'] and !vis[p.first][p.second])
                {
                    search_point(board, p.first, p.second, str, n->next[board[p.first][p.second] - 'a'], ans, vis);
                }
            }
            vis[i][j] = false;
        }
				// searches for all the words in the board
        void search_board(vector<vector<char>> &board, vector<string> &ans)
        {
            int n = board.size(), m = board[0].size();
            vector<vector<bool>> vis(n, vector<bool> (m, false));
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (root->next[board[i][j] - 'a'])
                        search_point(board, i, j, "", root->next[board[i][j] - 'a'], ans, vis);
                }
            }
        }
    };
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (!board.size()) return {};
        trie t;
        for (int i = 0; i < words.size(); i++)
        {
            t.insert(words[i]);
        }
        vector<string> ans;
        t.search_board(board, ans);
        set<string> s(ans.begin(), ans.end());
        ans = vector<string> (s.begin(), s.end());
        return ans;
    }
};
```
Patterns: [Trie](Trie.md)