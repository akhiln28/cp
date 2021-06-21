---
Created Time: Jan 19, 2021 5:20 PM
Last edited time: May 20, 2021 9:56 AM
Source: https://leetcode.com/discuss/interview-question/248131/microsoft-interview-round-1-alien-dictionary
Status: waiting
---

# Microsoft Interview (round 1) - Alien Dictionary - LeetCode Discuss

There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.
For example,
 Given the following words in dictionary,
[
 "wrt",
 "wrf",
 "er",
 "ett",
 "rftt"
 ]
 The correct order is: "wertf".
[https://leetcode.com/problems/alien-dictionary](https://leetcode.com/problems/alien-dictionary) (premium)
The idea is to create a graph of characters and then find topological sorting of the created graph.
1. 
    Create a graph g with number of vertices equal to the size of alphabet in the given alien language. For example, if the alphabet size is 5, then there can be 5 characters in words. Initially there are no edges in graph.
2. 
    Do following for every pair of adjacent words in given sorted array. …..a) Let the current pair of words be word1 and word2. One by one compare characters of both words and find the first mismatching characters. …..b) Create an edge in g from mismatching character of word1 to that of word2.
3. 
    Print topological sorting of the above created graph.
Read More
class Solution
 {
 vector adj[30];
```
// Topological  sorting
void dfs(int x, vector<bool> &visited ,stack<int> &s )
{
    if(visited[x])
    return;
    
        visited[x] = true;
       
        
        vector<int> a = adj[x];
        
        for(auto y: a)
        {
            dfs(y,visited,s);
          
        }
          s.push(x);
}
public:
string findOrder(string dict[], int N, int K) 
{
   for(int x=0; x<K; x++)
   {
       adj[x].clear();
   }
   
   for(int x=0; x<N-1; x++)
   {
       int i =0;
       int n1 = dict[x].size(), n2 = dict[x+1].size();
       while(i<n1 and i<n2 and (dict[x][i] == dict[x+1][i]))
       {
           i++;
       }
       
       if(i<n1 and i<n2)
       {
       int a = dict[x][i] - 'a';
       int b = dict[x+1][i] - 'a';
    //   cout<<a<<"  "<<b<<endl;
       if(a!=b)
       adj[a].push_back(b);                // make the adjacency list 
       }
   }   
   
       vector<bool> visited(K);
    for(int x=0; x<K; x++)
    {
        visited[x] = false;
       
    }
    
   
    stack<int> s;
    for(int x=0; x<K; x++)
    {
     dfs(x,visited,s);
         
    }
    string ans;
    while(!s.empty())
    {
        int i = s.top();
        s.pop();
        char t1 = i+'a';
        ans.push_back(t1);
    }
   
       return ans;
    
       
   
}
```
Read More
The simple solution is use `HashMap` with key: character, value: known previous character set. For the given example, the map will be: {f:[t],e:[w],t:[r],r:[e]}.
 Then for each character, do a DFS.
If there is character we couldn't know the order, it will be put in randomly position. Since it says it's ordered it means there shouldn't be cycle. So in the code cycle is not checked.
```
String order(List<String> dictionary) {
  var set = new HashSet<Character>();
  var orders= new HashMap<Character, Set<Character>>();
  processDictionary(dictionary, set, orders);
  var sb = new StringBuilder();
  for(var ch : set) {
    dfs(ch, orders,  sb,  new HashSet<>());
  }
  return sb.toString();
}
void processDictionary(List<String> dictionary, Set<Character> set, Map<Character, Set<Character>> orders) {
  for(int i=1;i<dictionary.size();i++) {
    setOrder(orders, dictionary.get(i-1), dictionary.get(i));
    addChars(set, dictionary.get(i));
  }
}
void setOrder(Map<Character, Set<Character>> orders, String a, String b) {
  var len = Math.min(a.length(), b.length());
  for(int i=0; i<len; i++) {
    var ca=a.charAt(i) ;
    var cb=b.charAt(i);
    if (ca != cb) {
      var set = orders.getOrDefault(cb, new HashSet<>());
      set.add(ca);
      orders.add(cb, set);
      break;
    }
  }
}
void addChars(Set<Character> set, String str) {
  for (var ch : str.toCharArray()) {
    set.add(ch);
  }
}
void dfs(char ch, Map<Character, Set<Character>> orders, StringBuilder sb, Set<Character> visited) {
  if(!visited.contains(ch)) {
    for(var c : orders.getOrDefault(ch, Collections.emptyList())) {
        dfs(c, orders, sb, visited);
    }
    sb.append(ch);
    visited.add(ch);
  }
}
```
Read More
Decided to throw my hat in the ring as well and I agree that this is *really* tricky for a 45min interview.
 I assume that there must be at least 2 words
```
    Dictionary<char,List<char>> charGraph = new Dictionary<char,List<char>>(); //Stores the adj list
    HashSet<char> seen = new HashSet<char>(); //Tracking the visited nodes
    char[] order = null; //Output
    int index = 0;
    string AlienOrder (string[] words)
    {
        if(words.Length>1) //Must have atleast 2 words
        {
            ConstructGraph(words);
            var alphas = charGraph.Keys; //All distinct chars
            order = new char[alphas.Count];
            
            foreach(var alpha in alphas)
            {
                if(!seen.Contains(alpha))
                {
                    if(IsGraphCyclic(alpha,new HashSet<char>{}))
                        return string.Empty;
                }
            }
            return new string(order);
        }
        return string.Empty;
    }
    
    bool IsGraphCyclic(char ch, HashSet<char> parents) //With a cycle no order can be determined.
    {
        order[index++] = ch;
        seen.Add(ch);
        parents.Add(ch);
        foreach(var child in charGraph[ch])
        {
            if(parents.Contains(child))
                return true;
            if(!seen.Contains(child))
            {
                if(IsGraphCyclic(child,parents))
                    return true;
            }
        }
        parents.Remove(ch);
        return false;
    }
    
    void ConstructGraph(string[] words)
    {
        for(int i=0;i<words.Length -1; i++)
        {
            var word1 = words[i];
            var word2 = words[i+1];
            AddGraphNodes(word1,word2);
        }
    }
    
    void AddGraphNodes(string word1, string word2)
    {
        var length = Math.Min(word1.Length, word2.Length);
        var index = 0;
        while(index<length)
        {
            if(word1[index] == word2[index])
            {
                CreateNode(word1[index]);
                index++;
            }
            else
            {
                CreateNode(word1[index]);
                CreateNode(word2[index]);
                charGraph[word1[index]].Add(word2[index]); //Add edge.
                break;
            }
        }
    }
    
    void CreateNode(char ch)
    {
        if(!charGraph.ContainsKey(ch))
            charGraph[ch] = new List<char>{};
    }
```
Read More
Pretty tricky for a 45min-1hour interview slot.
```
def build_graph(words):
    g = {c: [] for w in words for c in w}
    for i in range(1, len(words)):
        for c1, c2 in zip(words[i-1], words[i]):
            if c1 != c2:
                g[c1].append(c2)
                break
    return g
def find_first_letter(g):
    s = set()
    for l in g.values():
        for c in l:
            s.add(c)
    first_letter = [c for c in g if c not in s]
    if len(first_letter) != 1:
        raise Exception("no first letter %s" % first_letter)
    return first_letter[0]
def explore(g, c, visited, result):
    if visited[c] == 1:
        raise Exception("cycle")
    if visited[c] == 2:
        return
    visited[c] = 1
    for c2 in g[c]:
        explore(g, c2, visited, result)
    result.append(c)
    visited[c] = 2
def topo_sort(g):
    visited = collections.defaultdict(lambda: 0)
    result = []
    first_letter = find_first_letter(g)
    explore(g, first_letter, visited, result)
    result.reverse()
    return "".join(result)
def sort_alphabet(words):
    return topo_sort(build_graph(words))
```
Read More
Lexicographically Topological sorting ...
 public class Solution {
 /**
 * @param words: a list of words
 * @return: a string which is correct order
 */
```
public static class Graph {
    private List<Graph> adj;
    private char vertax;
    
    public Graph(char a){
        this.vertax = a;
        this.adj = new ArrayList<Graph>();            
    }
    
    public void addEdge(Graph b){
        System.out.printf("edge added from %s to %s\n", this.vertax, b.vertax);
        this.adj.add(b);
    }
}
public String topoSort(Map<Character, Graph> nodeMap){
    
    Map<Character, Integer> inDegree = new HashMap<Character,Integer>();
    
    for(Character key : nodeMap.keySet()){
        inDegree.put(key, 0);
    }
    
    for(Map.Entry<Character, Graph> entry : nodeMap.entrySet()){
        Character c = (Character) entry.getKey();
        Graph g = (Graph) entry.getValue();
        for(Graph adj : g.adj){
            Character key = adj.vertax;
            inDegree.put(key, inDegree.get(key) + 1); 
        }
    }
    
    PriorityQueue<Character> q = new PriorityQueue<Character>();
    
    for(Map.Entry<Character, Integer> entry : inDegree.entrySet()){
        Character c = (Character) entry.getKey();
        Integer degree = (Integer) entry.getValue();
        if(degree == 0){
            q.add(c);
        }
    }
    
    StringBuilder sb = new StringBuilder();
    while(!q.isEmpty()){
        Character c = q.poll();
        sb.append(c);
        Graph peek = nodeMap.get(c);
        for(Graph g : peek.adj){
            int degree = inDegree.get(g.vertax);
            inDegree.put(g.vertax, degree - 1);
            if(degree - 1 == 0){
                q.add(g.vertax);
            }
        }
    }
    
    if (sb.length() != inDegree.size()) {
        return "";
    }
    
    return sb.toString();
}
public String alienOrder(String[] words) {
    // Write your code 
    
    Map<Character, Graph> nodeMap = new HashMap<Character, Graph>();
    for(int j =0 ; j< words.length ; j++){
        
        char arr [] = words[j].toCharArray();
        for(char c : arr){
            if(nodeMap.get(c) == null){
                Graph g = new Graph(c);
                nodeMap.put(c,g);     
            }
            
        }
    }
    
    for(int j =0 ; j< words.length -1 ; j++){
        
        char [] a = words[j].toCharArray();
        char [] b = words[j+1].toCharArray();
        
        int i = 0;
        
        while(a[i] == b[i] && i < Math.min(a.length, b.length)){
            i++;
        }
        
        
        Graph aGraph = null, bGraph = null;
        aGraph = nodeMap.get(a[i]);
        bGraph = nodeMap.get(b[i]);
        aGraph.addEdge(bGraph);
    }
    
    
    return topoSort(nodeMap);
}
```
Patterns: 