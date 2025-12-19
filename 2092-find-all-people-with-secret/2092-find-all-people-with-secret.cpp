class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(),
             [](auto &a, auto &b) {
                 return a[2] < b[2];
             });

        unordered_set<int> knows;
        knows.insert(0);
        knows.insert(firstPerson);

        int i = 0;
        while (i < meetings.size()) {
            int time = meetings[i][2];

            unordered_map<int, vector<int>> graph;
            unordered_set<int> people;

            // collect all meetings at same time
            while (i < meetings.size() && meetings[i][2] == time) {
                int x = meetings[i][0];
                int y = meetings[i][1];
                graph[x].push_back(y);
                graph[y].push_back(x);
                people.insert(x);
                people.insert(y);
                i++;
            }

            queue<int> q;
            unordered_set<int> visited;

            // start BFS only from people who already know secret
            for (int p : people) {
                if (knows.count(p)) {
                    q.push(p);
                    visited.insert(p);
                }
            }

            // spread within same time
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                for (int nei : graph[cur]) {
                    if (!visited.count(nei)) {
                        visited.insert(nei);
                        q.push(nei);
                    }
                }
            }

            // update permanent knowledge
            for (int p : visited) {
                knows.insert(p);
            }
        }

        return vector<int>(knows.begin(), knows.end());
    }
};
