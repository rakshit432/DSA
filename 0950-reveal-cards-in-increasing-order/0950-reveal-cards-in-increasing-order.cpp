#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());

        vector<int> res(n);
        queue<int> q;
        for (int i = 0; i < n; i++) q.push(i);

        for (int card : deck) {
            res[q.front()] = card;   
            q.pop();
            if (!q.empty()) {        
                q.push(q.front());
                q.pop();
            }
        }
        return res;
    }
};