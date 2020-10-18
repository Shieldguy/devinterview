
public class Solution {

	public int longestStrChain(String[] words) {

    Map<String, Integer> map = new HashMap<>();
    Arrays.sort(words, (a,b)->(a.length()-b.length()));

    int ans = 0;
    for(String w : words) {
      int max = 0;
      for(int i=0;i<w.length();i++) {
        String tmp = w.substring(0, i) + w.substring(i + 1);
        max = Math.max(max, map.getOrDefault(tmp, 0) + 1);
      }
      map.put(w, max);
      ans = Math.max(ans, max);
    }
    return ans;
  }
}
