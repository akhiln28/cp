import java.util.ArrayList;
import java.util.List;

/**
 * m_1871_jump_game_7
 */
class Solution {
    private int minReach(List<Integer> indiceList, int start, int minJump, int maxJump) {
        int left = start, right = indiceList.size();
        int ans = Integer.MAX_VALUE;
        while (left <= right) {
            int mid = left + (right - left)/2;
            int diff =indiceList.get(mid) - indiceList.get(start);
            if (diff >= minJump && diff <= maxJump) {
                ans = Math.min(ans, mid);
                right = mid - 1;
            }
            else if (diff > maxJump) {
                right = mid - 1;
            }
            else if (diff < minJump) {
                left = mid + 1;
            }
        }
        return ans;
    }

    private

    private int maxReach(List<Integer> indiceList, int start, int minJump, int maxJump) {
        return 0;
    }
    public boolean canReach(String s, int minJump, int maxJump) {
        List<Integer> indices = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '0') indices.add(i);
        }
        int left = 0, right = 0;
        for (int i = 0; i < indices.size(); i++) {
            int updatedLeft = minReach(indices, left, minJump, maxJump);
            int updatedRight = maxReach(indices, right, minJump, maxJump);
            if (updatedLeft != Integer.MAX_VALUE) left = updatedLeft;
            if (updatedRight != Integer.MIN_VALUE) right = updatedRight;
        }
        indices.forEach(i -> { System.out.println(i); });
        return false;
    }
}

class Main {
    public static void main(String[] args) {
        Solution obj = new Solution();
        System.out.println(obj.canReach("11010", 1, 2));
    }
}