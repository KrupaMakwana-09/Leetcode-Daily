import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] words = s.split(" ");
        
        // Base check: lengths must be identical
        if (pattern.length() != words.length) {
            return false;
        }
        
        // Two maps to ensure bidirectional mapping (bijection)
        Map<Character, String> charToWord = new HashMap<>();
        Map<String, Character> wordToChar = new HashMap<>();
        
        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern.charAt(i);
            String w = words[i];
            
            // Check character to word mapping
            if (charToWord.containsKey(c) && !charToWord.get(c).equals(w)) {
                return false;
            }
            
            // Check word to character mapping
            if (wordToChar.containsKey(w) && wordToChar.get(w) != c) {
                return false;
            }
            
            // Establish the bidirectional link
            charToWord.put(c, w);
            wordToChar.put(w, c);
        }
        
        return true;
    }
}
