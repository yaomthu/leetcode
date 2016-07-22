/**
 * logger rate limitter
 * Design a logger system that receive stream of messages along with its timestamps, each message should be printed if and only if it is not printed in the last 10 seconds.

Given a message and a timestamp (in seconds granularity), return true if the message should be printed in the given timestamp, otherwise returns false.

It is possible that several messages arrive roughly at the same time.

Example:

Logger logger = new Logger();

// logging string "foo" at timestamp 1
logger.shouldPrintMessage(1, "foo"); returns true;

// logging string "bar" at timestamp 2
logger.shouldPrintMessage(2,"bar"); returns true;

// logging string "foo" at timestamp 3
logger.shouldPrintMessage(3,"foo"); returns false;

// logging string "bar" at timestamp 8
logger.shouldPrintMessage(8,"bar"); returns false;

// logging string "foo" at timestamp 10
logger.shouldPrintMessage(10,"foo"); returns false;

// logging string "foo" at timestamp 11
logger.shouldPrintMessage(11,"foo"); returns true;
 */

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

namespace logger_rate_limitter {
class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {

    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        while (Q.size() && Q.front().first <= timestamp - 10) {
            record.erase(Q.front().second);
            Q.pop();
        }
        bool ans = record.find(message) != record.end()? false : true;
        if (ans) {
            Q.push(make_pair(timestamp, message));
            record.insert(message);
        }
        return ans;
    }
private:
    queue<pair<int,string> > Q;
    unordered_set<string> record;
};

class Logger2 {
 public:
     /** Initialize your data structure here. */
     Logger2() {
     }

     /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
         If this method returns false, the message will not be printed.
         The timestamp is in seconds granularity. */
     bool shouldPrintMessage(int timestamp, string message) {
         if (record.find(message) != record.end() && record[message] > timestamp - 10)
             return false;
         record[message] = timestamp;
         return true;
     }
 private:
     unordered_map<string,int> record;
};
}
