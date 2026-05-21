class Twitter {
public:
    unordered_map<int,deque<pair<int,int>>> mp;
    unordered_map<int,unordered_set<int>> st;
    int cnt = 0;
    Twitter() { 
        cnt = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        if(mp[userId].size() == 10) mp[userId].pop_front();
        mp[userId].push_back({cnt++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<> > pq;
        for(auto &t:mp[userId]){
            if(pq.size()<10) pq.push(t);
            else if(pq.top().first < t.first){
                pq.pop();
                pq.push(t);
            }
        }
        for(int id:st[userId]){
            for(auto t:mp[id]){
                if(pq.size()<10) pq.push(t);
                else if(pq.top().first < t.first){
                    pq.pop();
                    pq.push(t);
                }
            }
        } 
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
    void follow(int followerId, int followeeId) {
        st[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {  
        st[followerId].erase(followeeId);
    }
};