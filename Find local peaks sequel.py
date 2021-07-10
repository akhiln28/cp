def solve(nums):
    n = len(nums)
    next_different = [-1] * n
    before_different = [-1] * n
    for i in range(n - 2, -1, -1):
        if nums[i] != nums[i + 1]:
            next_different[i] = i + 1
        else:
            next_different[i] = next_different[i + 1]

    for i in range(1, n, 1):
        if nums[i] != nums[i - 1]:
            before_different[i] = i - 1
        else:
            before_different[i] = before_different[i - 1]
    ans: list[int] = []
    for i in range(n):
        val = 0
        if next_different[i] != -1:
            if nums[next_different[i]] > nums[i]:
                continue
            else:
                val += 1
        if before_different[i] != -1:
            if nums[before_different[i]] > nums[i]:
                continue
            else:
                val += 1
        if val:
            ans.append(i)
    return ans

nums = [2, 1, 0]
print(solve(nums))