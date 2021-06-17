# Last Value Map | binarysearch

Created Time: Mar 01, 2021 8:34 AM
Do Date: Mar 01, 2021
Last edited time: Mar 06, 2021 3:58 PM
Pattern: https://www.notion.so/Hashing-dc1f706a2c0b4b5eb6ee200a3ab1ae98
Points: 1500
Source: https://binarysearch.com/problems/Last-Value-Map
Status: done

Implement a data structure `LastValueMap` which has the following methods:

- `void set(int key, int value)` which associates `key` with `value`.
- `void remove(int key)` which removes `key` and its associated `value`.
- `int getLast()` which returns the value of the last added key. If a `key` is updated with a value, it should become last. You can assume that there is always a last value.

**Constraints**

- `0 ≤ n ≤ 200,000` where `n` is the number of method calls

****Input****

`methods = ["constructor", "set", "set", "getLast", "set", "getLast", "remove", "getLast"]`

`arguments = [[], [1, 2], [2, 3], [], [1, 9], [], [1], []]``

****Output****

`[null, null, null, 3, null, 9, null, 3]`

### **Explanation**

`x = LastValueMap()
x.set(1, 2)
x.set(2, 3)
x.getLast() == 3
x.set(1, 9)
x.getLast() == 9
x.remove(1)
x.getLast() == 3`

---

```cpp
class LastValueMap {
    public:
    LastValueMap() {
        mp.clear(); 
        lastkeys.clear(); 
    }

    void set(int key, int value) {
        mp[key] = value;
        lastkeys.push_back(key);
    }

    void remove(int key) {
        mp.erase(key); 
    }

    int getLast() {
        while (mp.find(lastkeys.back()) == mp.end())
        {
            lastkeys.pop_back();
        }
        if (lastkeys.size()) return mp[lastkeys.back()];
        return 0; 
    }
    private:
    vector<int> lastkeys;
    unordered_map<int, int> mp;
};
```