class Solution {
    public String minWindow(String s, String t) {
        int m = s.length();
        int n = t.length();

        if (m < n) {
            return "";
        }

        int[] freq = new int[128];

        for (char c : t.toCharArray()) {
            freq[c]++;
        }

        int left = 0;
        int start = 0;
        int minLen = Integer.MAX_VALUE;
        int required = n;

        for (int right = 0; right < m; right++) {
            char c = s.charAt(right);

            if (freq[c] > 0) {
                required--;
            }
            freq[c]--;

            while (required == 0) {
                int windowLen = right - left + 1;

                if (windowLen < minLen) {
                    minLen = windowLen;
                    start = left;
                }

                char leftChar = s.charAt(left);
                freq[leftChar]++;

                if (freq[leftChar] > 0) {
                    required++;
                }

                left++;
            }
        }

        return minLen == Integer.MAX_VALUE
                ? ""
                : s.substring(start, start + minLen);
    }
}