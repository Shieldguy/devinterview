class Solution {
    public boolean isSubsequence(String source, String target) {
        int offset = 0, i = 0;
        while(i < source.length() && offset < target.length()) {
            if(source.charAt(i) == target.charAt(offset)) {
                ++offset;
            }
            ++i;
        }
        return target.length() == offset;
    }
    
    public int helper(String source, String target) {
        int min = Integer.MAX_VALUE;
        if(isSubsequence(source, target))
            return 1;
        for(int i = 1; i < target.length(); i++) {
            if(isSubsequence(source, target.substring(0, i))) {
                min = Math.min(min, helper(source, target.substring(i)));
            }
        }
        return min == Integer.MAX_VALUE? min: min+1;
    }
    
    public int helper(String source, String target, int[] dp, int pos) {
        int min = Integer.MAX_VALUE;
        if(dp[pos] > 0) {
            return dp[pos];
        }
        
        if(source.length() >= target.length() && isSubsequence(source, target)) {
            dp[pos] = 1;
            return dp[pos];
        }
        int spos = 0;
        for(int i = 1; i < target.length(); i++) {
            if(source.length() < i) {
                break;
            } else {
                boolean isSubseq = false;
                while(spos < source.length()) {
                    if(source.charAt(spos++) == target.charAt(i-1)) {
                        isSubseq = true;
                        break;
                    }
                }
                if(isSubseq) {
                    if(dp[pos+i] > 0) {
                        min = Math.min(min, dp[pos+i]);
                    } else {
                        min = Math.min(min, helper(source, target.substring(i), dp, pos+i));
                    }
                }
            }
        }
        dp[pos] = min == Integer.MAX_VALUE? min: min+1;
        return dp[pos];
    }
    
    public int simple(String source, String target) {
        int tpos = 0;
        int count = 0;
        while(tpos < target.length()) {
            int tmp = tpos;
            for(int i = 0; i < source.length(); i++) {
                if(tpos < target.length() && source.charAt(i) == target.charAt(tpos))
                    ++tpos;
            }
            if(tpos == tmp)
                return -1;
            ++count;
        }
        return count;
    }
    
    public int shortestWay(String source, String target) {
        //int res = helper(source, target, new int[target.length()], 0); // 5% 
        //int res = helper(source, target); // timeout
        int res = simple(source, target);       // 66.85%
        return res == Integer.MAX_VALUE? -1: res;
    }
}
