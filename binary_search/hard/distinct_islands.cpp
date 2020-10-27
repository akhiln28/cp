void dfs(vector<vector<int>> &matrix, int i, int j, vector<pair<int, int>> &island)
{
    // update matrix so that this will not be visited next time
    matrix[i][j] = 0;
    island.push_back({i, j}); 
    if (i and matrix[i - 1][j]) dfs(matrix, i - 1, j, island); 
    if (j and matrix[i][j - 1]) dfs(matrix, i, j - 1, island); 
    if (i < matrix.size() - 1 and matrix[i + 1][j]) dfs(matrix, i + 1, j, island); 
    if (j < matrix[0].size() - 1 and matrix[i][j + 1]) dfs(matrix, i, j + 1, island); 
}

// transfrom the list of coordinates relative to the first coordinate
void convert(vector<pair<int, int>> &list)
{
    sort(list.begin(), list.end()); 
    for (int i = 1; i < list.size(); i++) {
        list[i] = {list[i].first - list[0].first, list[i].second - list[0].second};
    }
    list[0].first = 0, list[0].second = 0; 
}

int solve(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size(); 
    // islands is the list of island (list of connected coordinates)
    vector<vector<pair<int, int>>> islands; 

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j])
            {
                vector<pair<int, int>> island;
                dfs(matrix, i, j, island);
                islands.push_back(island); 
            }
        }
    }
    set<vector<pair<int, int>>> distinct_islands; 
    for (int i = 0; i < islands.size(); i++)
    {
        convert(islands[i]); 
        distinct_islands.insert(islands[i]); 
    }
    return distinct_islands.size(); 
}
