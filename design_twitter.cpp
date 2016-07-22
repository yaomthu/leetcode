/**
 * Design twitter
 * Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:

postTweet(userId, tweetId): Compose a new tweet.
getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
follow(followerId, followeeId): Follower follows a followee.
unfollow(followerId, followeeId): Follower unfollows a followee.

solution: 重点使用stl提供的make_heap, pop_heap, push_heap函数来进vector<pair<int,int>>进行堆排序。
make_heap(vec.begin(), vec.end(), cmp): 对vec按照cmp进行堆排序
pop_heap(vec.begin(), vec.end(), cmp)：将vec的堆顶元素与最后一个元素互换，然后找到最后一个元素合适的位置。
push_heap(vec.begin(), vec.end(), cmp): 将vec的最后一个元素排到合适的位置。
由于cmp需要使用到hashmap users信息，所以要把users传入cmp里。
timecomplexity:
postTweet, follow, unfollow: O(1)
getNewsFeed: O(10logn), n 是 平均每个人的followee个数。
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

namespace design_twitter {
class Twitter {
public:
    class Tweet {
        public:
            int tweetId;
            int timestamp;
            Tweet(int tweetId_, int timestamp_): tweetId(tweetId_), timestamp(timestamp_) {}
    };
    class User {
        public:
            int userId;
            unordered_set<int> following;
            vector<Tweet> tweets;
            User(int userId_) : userId(userId) {}
    };

    /** Initialize your data structure here. */
    Twitter() {
        time = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if (users.find(userId) == users.end())
            users[userId] = new User(userId);
        users[userId]->tweets.push_back(Tweet(tweetId, time++));
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        if (users.find(userId) == users.end())
            return ans;
        vector<pair<int,int> > heap;
        if (users[userId]->tweets.size() > 0)
            heap.push_back(make_pair(userId, users[userId]->tweets.size()-1));
        for (auto followeeId : users[userId]->following) {
            if (users[followeeId]->tweets.size())
                heap.push_back(make_pair(followeeId, users[followeeId]->tweets.size()-1));
        }
        Cmp cmp(users);
        make_heap(heap.begin(), heap.end(), cmp);
        for (int i=0; i < 10 && heap.size(); i++) {
            auto top = heap.front();
            pop_heap(heap.begin(), heap.end(), cmp);
            heap.pop_back();
            ans.push_back(users[top.first]->tweets[top.second].tweetId);
            if (--top.second >= 0) {
                heap.push_back(top);
                push_heap(heap.begin(), heap.end(), cmp);
            }
        }
        return ans;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            if (users.find(followerId) == users.end())
                users[followerId] = new User(followerId);
            if (users.find(followeeId) == users.end())
                users[followeeId] = new User(followeeId);
            users[followerId]->following.insert(followeeId);
        }
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId && users.find(followerId) != users.end()) {
            users[followerId]->following.erase(followeeId);
        }
    }
private:
    int time;
    unordered_map<int, User*> users;
    struct Cmp {
        unordered_map<int, User*>& users;
        Cmp(unordered_map<int, User*>& users_) : users(users_) {}
        bool operator() (const pair<int,int>& a, const pair<int,int>& b) {
            return users[a.first]->tweets[a.second].timestamp < users[b.first]->tweets[b.second].timestamp;
        }
    };
};
}

int main_design_twitter() {
  design_twitter::Twitter* twitter = new design_twitter::Twitter();
  twitter->postTweet(1,5);
  twitter->follow(1,2);
  twitter->postTweet(2,6);
  twitter->unfollow(1,2);
  vector<int> ans = twitter->getNewsFeed(1);
  for (auto tweet : ans) {
    cout << tweet << " ";
  }
}
