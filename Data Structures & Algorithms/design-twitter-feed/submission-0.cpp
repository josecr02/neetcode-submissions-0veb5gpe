class Twitter {
    // keep a map of user-users following, and another user-users that follow them.
    // each user has min heap, and posts get added to it when adding. 
    unordered_map<int,set<int>> followMap;
    int time;
    unordered_map<int, vector<pair<int,int>>> tweetMap; // vector of 2 elememnts: {time, tweetId};

public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;

        auto compare = [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> minHeap(compare);

        followMap[userId].insert(userId); // just in case not already
        for (int followeeId : followMap[userId]){
            if (tweetMap.count(followeeId)){
                // followe has posts
                const vector<pair<int,int>>& tweets = tweetMap[followeeId];
                int index = tweets.size() - 1;
                minHeap.push({tweets[index].first, tweets[index].second, followeeId, index});
            }
        }

        while (!minHeap.empty() && res.size() < 10){
            // keep filling
            vector<int> curr = minHeap.top();
            minHeap.pop();
            res.push_back(curr[1]); // push the tweetId
            int index = curr[3]; // tweet index of the user
            if (index > 0) {
                const auto& tweet = tweetMap[curr[2]][index - 1];
                minHeap.push({tweet.first, tweet.second, curr[2], index - 1});
            }
        }

        return res;

    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
