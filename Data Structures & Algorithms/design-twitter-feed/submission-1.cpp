class Twitter {
public:
    Twitter() {
        
    }

    struct Tweet
    {
        int userId;
        int tweetId;
    };
    std::vector<Tweet> m_tweets;
    std::unordered_map<int, std::unordered_set<int>> m_user_following;

    void postTweet(int userId, int tweetId) {
        m_tweets.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        std::vector<int> ret;
        ret.reserve(10);
        auto& following = m_user_following[userId];

        for (auto it = m_tweets.rbegin(); it != m_tweets.rend(); ++it)
        {
            if (following.count(it->userId) > 0 || it->userId == userId)
            {
                ret.push_back(it->tweetId);
            }
            if (ret.size() >= 10)
            {
                break;
            }
        }

        return ret;
    }
    
    void follow(int followerId, int followeeId) {
        m_user_following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        m_user_following[followerId].erase(followeeId);
    }
};
