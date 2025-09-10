class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();

        // Step 1: Build language -> users map
        unordered_map<int, unordered_set<int>> mpp;
        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                mpp[lang].insert(i+1); // user index is 1-based
            }
        }

        // Step 2: Find users who need teaching
        unordered_set<int> needTeach;
        for (auto &fr : friendships) {
            int u = fr[0], v = fr[1];
            bool canCommunicate = false;

            for (auto &[lang, users] : mpp) {
                if (users.count(u) && users.count(v)) {
                    canCommunicate = true;
                    break;
                }
            }

            if (!canCommunicate) {
                needTeach.insert(u);
                needTeach.insert(v);
            }
        }

        if (needTeach.empty()) return 0;

        // Step 3: Check best language
        vector<int> count(n+1, 0);
        for (int lang = 1; lang <= n; lang++) {
            if (mpp.count(lang)) {
                for (int u : needTeach) {
                    if (mpp[lang].count(u)) {
                        count[lang]++;
                    }
                }
            }
        }

        int best = *max_element(count.begin(), count.end());

        // Step 4: Answer
        return (int)needTeach.size() - best;
    }
};
