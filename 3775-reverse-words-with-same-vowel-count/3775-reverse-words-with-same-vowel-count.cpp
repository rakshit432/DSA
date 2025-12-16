class Solution {
public:
    string reverseWords(string s) {

        string parivontel = s;

        vector<string> parts;
        string word = "";

        for (char ch : s) {
            if (ch != ' ') word += ch;
            else {
                parts.push_back(word);
                word = "";
            }
        }









        
        parts.push_back(word);

        int baseVowels = 0;
        for (char ch : parts[0]) {
            if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
                baseVowels++;
        }

        for (int i = 1; i < parts.size(); i++) {
            int vowelCount = 0;
            for (char ch : parts[i]) {
                if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
                    vowelCount++;
            }
            if (vowelCount == baseVowels) {
                reverse(parts[i].begin(), parts[i].end());
            }
        }

        string result = "";
        for (int i = 0; i < parts.size(); i++) {
            result += parts[i];
            if (i + 1 < parts.size()) result += ' ';
        }

        return result;
    }
};