/*Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

Implement the Twitter class:

Twitter() Initializes your twitter object.
void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.
 

Example 1:

Input
["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
[[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
Output
[null, null, [5], null, null, [6, 5], null, [5]]

Explanation
Twitter twitter = new Twitter();
twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
twitter.follow(1, 2);    // User 1 follows user 2.
twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.unfollow(1, 2);  // User 1 unfollows user 2.
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.
*/

class Twitter {
private:
    // A map to store tweets for each user, where key = userId and value = list of tweetIds (ordered from most recent to least recent)
    unordered_map<int, list<int>> tweets;

    // A map to store followers for each user, where key = userId and value = set of followerIds
    unordered_map<int, unordered_set<int>> followers;

    // A list to store tweets, where each tweet is represented by a pair (userId, tweetId)
    list<pair<int, int>> allTweets;

public:
    // Constructor
    Twitter() {}

    // Method to post a tweet
    void postTweet(int userId, int tweetId) {
        // Add the tweet to the user's tweet list (ordered by latest)
        tweets[userId].push_front(tweetId);  // Most recent tweet at the front
        // Also, store the tweet globally (so we can retrieve the most recent ones)
        allTweets.push_front({userId, tweetId});
    }

    // Method to get the news feed of a user
    vector<int> getNewsFeed(int userId) {
        vector<int> newsFeed;
        // Set of all users whose tweets should be in the feed (user themselves + the people they follow)
        unordered_set<int> followedUsers = followers[userId];
        followedUsers.insert(userId);  // Include the user themselves

        // Iterate through allTweets and collect the tweets for followed users
        for (auto &tweet : allTweets) {
            int currentUserId = tweet.first;
            int tweetId = tweet.second;
            // If the user is in the followed set, add their tweet to the news feed
            if (followedUsers.find(currentUserId) != followedUsers.end()) {
                newsFeed.push_back(tweetId);
                if (newsFeed.size() == 10) break;  // We only need the 10 most recent tweets
            }
        }

        return newsFeed;
    }

    // Method to follow a user
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }

    // Method to unfollow a user
    void unfollow(int followerId, int followeeId) {
        // Ensure that a user cannot unfollow themselves
        if (followerId != followeeId) {
            followers[followerId].erase(followeeId);
        }
    }
};