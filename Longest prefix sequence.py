from typing import Any


def solve(words: list[str]):
    n: int = len(words)
    class Node:
        def __init__(self, char: str) -> None:
            self.char = char
            self.children: list[Node] = 26 * [None]
            self.idx: int = -1
    def add(root: Node, word: str, idx: int):
        node = root
        ptr = 0
        for ptr in range(len(word)):
            child = node.children[ord(word[ptr]) - ord('a')]
            if child:
                node = child
            else:
                break
        while ptr < len(word):
            node.children[ord(word[ptr]) - ord('a')] = Node(word[ptr])
            node = node.children[ord(word[ptr]) - ord('a')]
            ptr += 1
        node.idx = idx

    # construct the graph by finding all the prefixes of each word
    def constructGraph(root: Node, words: list[str]):
        n = len(words)
        graph: list[list[int]] = [[] for _ in range(n)]
        for i in range(n):
            word = words[i]
            ptr = 0
            node = root
            for ptr in range(len(word)):
                child = node.children[ord(word[ptr]) - ord('a')]
                if child.idx not in [-1, id]:
                    graph[i].append(child.idx)
                node = child
        return graph

    # root represents the root of the trie
    root = Node('a')
    # add words to the trie
    for idx in range(n):
        add(root, words[idx], idx)

    graph = constructGraph(root, words)

    def dfs(idx: int, graph, dist):
        if dist[idx] != -1:
            return dist[idx]
        ans = 1
        for nb in graph[idx]:
            if dist[nb] == -1:
                dfs(nb, graph, dist)
            ans = max(ans, 1 + dist[nb])
        dist[idx] = ans
        return ans

    # now find the longest length in the graph, using dfs
    dist: list[int] = [-1] * n
    ans = 1
    for i in range(n):
        if dist[i] == -1:
            dfs(i, graph, dist)
        ans = max(ans, dist[i])
    return ans

words = ["abc", "ab", "x", "xy", "abcd"]
print(solve(words))