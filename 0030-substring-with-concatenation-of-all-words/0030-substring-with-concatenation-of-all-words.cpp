class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (totalLen > s.size())
            return ans;

        unordered_map<string, int> need;

        for (string word : words)
            need[word]++;

        // Try each possible offset
        for (int offset = 0; offset < wordLen; offset++) {

            int left = offset;
            int count = 0;

            unordered_map<string, int> have;

            for (int right = offset;
                 right + wordLen <= s.size();
                 right += wordLen) {

                string word = s.substr(right, wordLen);

                // Word not present in words
                if (!need.count(word)) {
                    have.clear();
                    count = 0;
                    left = right + wordLen;
                    continue;
                }

                have[word]++;
                count++;

                // Too many occurrences of this word
                while (have[word] > need[word]) {
                    string leftWord = s.substr(left, wordLen);

                    have[leftWord]--;
                    left += wordLen;
                    count--;
                }

                // Exactly all words found
                if (count == wordCount) {
                    ans.push_back(left);

                    // Move window forward
                    string leftWord = s.substr(left, wordLen);
                    have[leftWord]--;
                    left += wordLen;
                    count--;
                }
            }
        }

        return ans;
    }
};