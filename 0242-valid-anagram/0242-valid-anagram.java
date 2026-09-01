class Solution {
    public boolean isAnagram(String s, String t) {
        // Anagrams must have the same length
        if (s.length() != t.length()) {
            return false;
        }

        // Frequency array for 26 lowercase letters
        int[] count = new int[26];

        // Count characters in s
        for (int i = 0; i < s.length(); i++) {
            count[s.charAt(i) - 'a']++;
        }

        // Subtract characters found in t
        for (int i = 0; i < t.length(); i++) {
            count[t.charAt(i) - 'a']--;
        }

        // All frequencies must be zero
        for (int frequency : count) {
            if (frequency != 0) {
                return false;
            }
        }

        return true;
    }
}