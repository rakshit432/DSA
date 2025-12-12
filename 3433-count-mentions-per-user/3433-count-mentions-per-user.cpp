#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countMentions(int numberOfUsers,
                              vector<vector<string>>& events) {

        int n = numberOfUsers;
        vector<int> ans(n, 0);

        // offlineUntil[u] = time until user remains offline
        vector<int> offlineUntil(n, -1);

        // sort by timestamp then OFFLINE before MESSAGE
        sort(events.begin(), events.end(), [&](auto &a, auto &b) {
            int ta = stoi(a[1]);
            int tb = stoi(b[1]);

            if (ta != tb) return ta < tb;

            if (a[0] == "OFFLINE" && b[0] == "MESSAGE") return true;
            if (a[0] == "MESSAGE" && b[0] == "OFFLINE") return false;

            return false;
        });

        for (int i = 0; i < events.size(); i++) {

            string type = events[i][0];
            int t = stoi(events[i][1]);

            if (type == "MESSAGE") {

                string msg = events[i][2];

                if (msg == "HERE") {
                    for (int u = 0; u < n; u++) {
                        if (offlineUntil[u] == -1 || offlineUntil[u] <= t)
                            ans[u]++;
                    }
                }

                else if (msg == "ALL") {
                    for (int u = 0; u < n; u++)
                        ans[u]++;
                }

                else {
                    // parse idXX idYY ...
                    stringstream ss(msg);
                    string token;
                    while (ss >> token) {
                        if (token.rfind("id", 0) == 0) {
                            int user = stoi(token.substr(2));
                            if (user >= 0 && user < n)
                                ans[user]++;
                        }
                    }
                }
            }

            else { // OFFLINE
                int user = stoi(events[i][2]);
                offlineUntil[user] = t + 60;
            }
        }

        return ans;
    }
};
