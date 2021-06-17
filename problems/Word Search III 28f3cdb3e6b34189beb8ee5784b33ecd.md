# Word Search III

Created Time: Jan 12, 2021 8:53 PM
Do Date: Jan 13, 2021
Last edited time: May 11, 2021 9:05 AM
Pattern: https://www.notion.so/Matrix-4e063cbec5124ef1af380e9e5daf8ffb, https://www.notion.so/Backtracking-90d58a7ffa85438e86ce346981bf35b5
Points: 1600
Problem Statement: Given a word and a matrix? Return the list of all indices where the word occurs in the matrix. You cannot reuse a cell for a single word. 
Related To: Word%20Search%20cf164f2e5a734d9a8134eae2d127b04c.md
Status: done

```cpp
void traverse(int i, int j, ans, word)
{
		if (ans.size() == word.length()) return;
		int idx = ans.size();
		if (mat[i][j] == word[idx])
		{
				ans.push_back({i, j})
				traverse(i + 1, j, ans, word)
				traverse(i, j + 1, ans, word); 
		}
}
```

```cpp
class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, vector<pair<int, int>>& ans, string& word, vector<vector<bool>>& vis)
    {
        vis[i][j] = true; 
        int idx = ans.size();
        if (board[i][j] != word[idx])
        {
            vis[i][j] = false; 
            return false; 
        }
        ans.push_back({i, j}); 
        
        if (ans.size() == word.length()) return true; 
        
        auto check = [&](int i, int j){
            return (i >= 0 and i < board.size() and j >= 0 and j < board[0].size() and vis[i][j] == false);
        };
        
        vector<pair<int, int>> nbs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
        
        bool flag = false; 
        for (auto nb : nbs)
        {
            int i1 = i + nb.first, j1 = j + nb.second; 
            if (check(i1, j1))
            {
                flag = flag | dfs(board, i1, j1, ans, word, vis); 
            }
            if (flag) return flag;
        }
        
        vis[i][j] = false; 
        ans.pop_back();
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) return false;
        int n = board.size(), m = board[0].size(); 
        vector<vector<bool>> vis(n, vector<bool> (m));
        vector<pair<int, int>> ans; 
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                bool flag = dfs(board, i, j, ans, word, vis); 
                if (flag)
                {
                    for (int k = 0; k < ans.size(); k++)
                    {
                        cout << ans[k].first << " " << ans[k].second << endl;
                    }
                    return true; 
                }
            }
        }
        return false; 
    }
};
```