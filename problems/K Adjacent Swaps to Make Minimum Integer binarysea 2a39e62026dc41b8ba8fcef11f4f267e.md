# K Adjacent Swaps to Make Minimum Integer | binarysearch

Created Time: Mar 03, 2021 9:01 AM
Last edited time: May 23, 2021 8:53 AM
Pattern: https://www.notion.so/String-31fee88325084b2db1f8d82cce81360c, https://www.notion.so/String-Sort-8b1d83e8165540abbba208eb208ec5a0
Points: 2000
Pomos (25 mins): 1
Source: https://binarysearch.com/problems/K-Adjacent-Swaps-to-Make-Minimum-Integer
Status: waiting

You are given a string `num` representing a decimal number and an integer `k`. Given that you can make at most `k` number of adjacent swaps between the digits in `num`, return the smallest decimal number (in string) you can make.

**Constraints**

- `1 ≤ n ≤ 100,000` where `n` is the length of `num`
- `0 ≤ k ≤ 100,000`

****Input****

`num = "4325"`

`k = 3`

****Output****

`"2345"`

We can make the following swaps:

- Swap `"32"` to get `"4235"`
- Swap `"42"` to get `"2435"`
- Swap `"43"` to get `"2345"`

---