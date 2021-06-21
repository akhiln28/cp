---
Created Time: Dec 21, 2020 9:28 AM
Do Date: Dec 21, 2020
Last edited time: May 11, 2021 9:00 AM
Points: 1700
Source: educative.io
Status: ok
---

# Words Concatenation

Given a string and a list of words, find all the starting indices of substrings in the given string that are a **concatenation of all the given words** exactly once **without any overlapping** of words. It is given that all words are of the same length.
**Example 1:**
```
Input: String="catfoxcat", Words=["cat", "fox"]
Output: [0, 3]
Explanation: The two substring containing both the words are "catfox" & "foxcat".
```
**Example 2:**
```
Input: String="catcatfoxfox", Words=["cat", "fox"]
Output: [3]
Explanation: The only substring containing both the words is "catfox".
```
---
I kind of hate this problem. This is brute force. 
```cpp
using namespace std;
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
class WordConcatenation {
 public:
  static vector<int> findWordConcatenation(const string &str, const vector<string> &words) {
    unordered_map<string, int> wordFrequencyMap;
    for (auto word : words) {
      wordFrequencyMap[word]++;
    }
    vector<int> resultIndices;
    int wordsCount = words.size(), wordLength = words[0].length();
    for (int i = 0; i <= str.length() - wordsCount * wordLength; i++) {
      unordered_map<string, int> wordsSeen;
      for (int j = 0; j < wordsCount; j++) {
        int nextWordIndex = i + j * wordLength;
        // get the next word from the string
        string word = str.substr(nextWordIndex, wordLength);
        if (wordFrequencyMap.find(word) ==
            wordFrequencyMap.end()) {  // break if we don't need this word
          break;
        }
        wordsSeen[word]++;  // add the word to the 'wordsSeen' map
        // no need to process further if the word has higher frequency than required
        if (wordsSeen[word] > wordFrequencyMap[word]) {
          break;
        }
        if (j + 1 == wordsCount) {  // store index if we have found all the words
          resultIndices.push_back(i);
        }
      }
    }
    return resultIndices;
  }
};
int main(int argc, char *argv[]) {
  vector<int> result =
      WordConcatenation::findWordConcatenation("catfoxacat", vector<string>{"cat", "fox"});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
  result = WordConcatenation::findWordConcatenation("catacatfoxfox", vector<string>{"cat", "fox"});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
```
Patterns: [patterns/Greedy](patterns/Greedy.md)[Sliding%20Window](Sliding%20Window.md)