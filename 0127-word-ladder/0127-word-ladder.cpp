class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
   {    
    string startWord = beginWord;
    string targetWord = endWord ;
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(startWord);

        while (!q.empty()) {
            string str = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (str == targetWord) return steps;
            for (int i = 0; i < str.length(); i++) {
                char curr = str[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    str[i] = ch;
                    if (st.find(str) != st.end()) {
                        st.erase(str);
                        q.push({str, steps + 1});
                    }
                }
                str[i] = curr;
            }
        }

        return 0;
    }
};