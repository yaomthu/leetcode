/**
 * Binary watch
 * A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.
For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".
 */

#include <iostream>
#include <vector>
using namespace std;

namespace binary_watch {
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        if (num == 0) {
            ans.push_back("0:00");
            return ans;
        }
        int hourLights = 0;
        while (hourLights <= num && hourLights <= 3) {
            int minLights = num - hourLights;
            if (minLights < 0 || minLights > 5) {
                hourLights++;
                continue;
            }
            vector<int> hours;
            permutation(4, hourLights, 1, hours, 0, 11);
            vector<int> minutes;
            permutation(6, minLights, 1, minutes, 0, 59);
            for (int i = 0; i < hours.size(); i++) {
                for (int j = 0; j < minutes.size(); j++) {
                    string temp = to_string(hours[i]) + ":";
                    if (minutes[j] < 10) {
                        temp += '0';
                    }
                    temp += to_string(minutes[j]);
                    ans.push_back(temp);
                }
            }
            hourLights++;
        }
        return ans;
    }
    void permutation(int total, int lights, int index, vector<int>& res, int record, int maximum) {
        if (index > total) {
            if (record <= maximum) {
                res.push_back(record);
            }
            return;
        }
        if (lights > 0) {
            permutation(total, lights-1, index+1, res, (record << 1) | 1, maximum);
        }
        if (total - index >= lights) {
            permutation(total, lights, index+1, res, record << 1, maximum);
        }
    }
};
}

int main_binary_watch() {
  (new binary_watch::Solution())->readBinaryWatch(6);
}
