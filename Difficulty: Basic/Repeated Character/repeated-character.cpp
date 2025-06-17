#include <unordered_map>

class Solution {
  public:
    char firstRep(string s) {
        unordered_map<char, int> freq;

       
        for (char ch : s) {
            freq[ch]++;
        }

        for (char ch : s) {
            if (freq[ch] > 1)
                return ch;
        }

        return '#';
    }
};
