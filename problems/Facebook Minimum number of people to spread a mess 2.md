---
Created Time: Mar 25, 2021 8:46 AM
Last edited time: May 20, 2021 9:55 AM
Source: https://leetcode.com/discuss/interview-question/algorithms/124827/find-minimum-number-of-people-to-reach-to-spread-a-message-across-all-people-in-twitter%20%F0%9F%91%8C%202%20+
Status: waiting
---

# Facebook | Minimum number of people to spread a message - LeetCode Discuss

![LeetCode_Sharing.png](Facebook%20Minimum%20number%20of%20people%20to%20spread%20a%20mess%206d7a0e426b134a95bfb050e364eddb44/LeetCode_Sharing.png)
This is a very interesting graph problem, here is what I would do:
**step 1**. Build a directed graph based on the input people (nodes) and their relationship (edges).
**step 2**. Find [strongly connected components](https://en.wikipedia.org/wiki/Strongly_connected_component) (SCCs) in the graph. Let's use the wikipedia's graph example, in that case, there are `3` SCCs: `(a, b, e)`, `(c, d, h)` and `(f, g)`. There are two famous algorithms for getting the SCCs: [Kosaraju's algorithm](https://en.wikipedia.org/wiki/Kosaraju%27s_algorithm) and [Tarjan's algorithm](https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm).
**step 3**. Pick one of the nodes from the SCCs we get: `a, c, f`, now these `3` nodes form a [DAG](https://en.wikipedia.org/wiki/Directed_acyclic_graph), we just need to do topological sort for them, eventually `a` is the root node in the path (or stack), and we can let `a` spread the message and guarantee all other people will get it.
Sometimes, there could be several topological paths, and the root nodes of those paths will be the minimum people to reach out to spread the message.
Patterns: 