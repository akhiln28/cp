/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
 
void traverse(Tree* root, int x, int y, map<int, pair<int, int>> &mp)
{
    if (root == nullptr) return;
    // there is no node at x
    if (mp.find(x) == mp.end()) mp[x] = {root->val, y}; 
    // there is node at x but it is below the current node (root)
    else if (y < mp[x].second) mp[x] = {root->val, y}; 
    traverse(root->left, x - 1, y + 1, mp); 
    traverse(root->right, x + 1, y + 1, mp); 
}
vector<int> solve(Tree* root) {
    // map<x_coordinate, pair<val, y_coordinate>>
    map<int, pair<int, int>> mp; 
    traverse(root, 0, 0, mp); 
    vector<int> ans; 
    for (auto [k, v] : mp)
        ans.push_back(v.first); 
    return ans; 
}
