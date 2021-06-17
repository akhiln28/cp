# Minimum Adjacent Swaps to Reach the Kth Smallest Number - LeetCode

Created Time: May 02, 2021 9:45 AM
Day Completed: https://www.notion.so/5-May-21-Wednesday-09a2f79e5c0b4ae1b828890e885d3cf9
Last edited time: May 04, 2021 9:07 AM
Pattern: https://www.notion.so/String-Sort-8b1d83e8165540abbba208eb208ec5a0
Points: 1500
Source: https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/
Status: done

![LeetCode_Sharing.png](problems/Minimum%20Adjacent%20Swaps%20to%20Reach%20the%20Kth%20Smallest%20N%2044658f739d8d4d65ba9f398cbe76e69a/LeetCode_Sharing.png)

You are given a string `num`, representing a large integer, and an integer `k`.

We call some integer **wonderful** if it is a **permutation** of the digits in `num` and is **greater in value** than `num`. There can be many wonderful integers. However, we only care about the **smallest-valued** ones.

- For example, when `num = "5489355142"`:
    - The 1 smallest wonderful integer is `"5489355214"`.

        st

    - The 2 smallest wonderful integer is `"5489355241"`.

        nd

    - The 3 smallest wonderful integer is `"5489355412"`.

        rd

    - The 4 smallest wonderful integer is `"5489355421"`.

        th

Return *the **minimum number of adjacent digit swaps** that needs to be applied to* `num` *to reach the* `kth` ***smallest wonderful** integer*.

The tests are generated in such a way that `kth` smallest wonderful integer exists.

**Example 1:**

```
Input: num = "5489355142", k = 4
Output: 2
Explanation: The 4th smallest wonderful number is "5489355421". To get this number:
- Swap index 7 with index 8: "5489355142" -> "5489355412"
- Swap index 8 with index 9: "5489355412" -> "5489355421"
```

**Example 2:**

```
Input: num = "11112", k = 4
Output: 4
Explanation: The 4th smallest wonderful number is "21111". To get this number:
- Swap index 3 with index 4: "11112" -> "11121"
- Swap index 2 with index 3: "11121" -> "11211"
- Swap index 1 with index 2: "11211" -> "12111"
- Swap index 0 with index 1: "12111" -> "21111"
```

**Example 3:**

```
Input: num = "00123", k = 1
Output: 1
Explanation: The 1st smallest wonderful number is "00132". To get this number:
- Swap index 3 with index 4: "00123" -> "00132"
```

**Constraints:**

- `2 <= num.length <= 1000`
- `1 <= k <= 1000`
- `num` only consists of digits.