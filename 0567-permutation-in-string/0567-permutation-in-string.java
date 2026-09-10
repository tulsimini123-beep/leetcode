class Solution {
    public boolean checkInclusion(String s1, String s2) {

        // If s1 is longer, its permutation cannot fit inside s2
        if (s1.length() > s2.length()) {
            return false;
        }

        // Frequency of each character in s1
        int[] count = new int[26];

        for (char c : s1.toCharArray()) {
            count[c - 'a']++;
        }

        // Create a window of size s1.length()
        // and subtract characters as they enter the window
        for (int i = 0; i < s1.length(); i++) {
            count[s2.charAt(i) - 'a']--;
        }

        // Check the first window
        if (allZero(count)) {
            return true;
        }

        // Slide the window through s2
        for (int i = s1.length(); i < s2.length(); i++) {

            // Add the character that enters the window
            count[s2.charAt(i) - 'a']--;

            // Remove the character that leaves the window
            count[s2.charAt(i - s1.length()) - 'a']++;

            // If all frequencies match, we found a permutation
            if (allZero(count)) {
                return true;
            }
        }

        return false;
    }

    private boolean allZero(int[] count) {
        for (int value : count) {
            if (value != 0) {
                return false;
            }
        }

        return true;
    }
}
