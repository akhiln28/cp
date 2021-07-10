def solve(ribbons: list[int], k: int) -> int:
    def isPossible(ribbons, k, mid):
        ans = 0
        for i in ribbons:
            ans += i//mid
        return ans >= k
    if k > sum(ribbons):
        return -1
    left = 1
    right = max(ribbons)
    ret = 1
    while left <= right:
        mid = (left + right)//2
        if isPossible(ribbons, k, mid):
            left = mid + 1
            ret = max(ret, mid)
        else:
            right = mid - 1
    return ret

ribbons = [1, 2, 3, 4, 9]
k = 5
print(solve(ribbons, k))
