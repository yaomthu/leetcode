/**
 * Read N Characters Given Read4 II - Call multiple times  QuestionEditorial Solution  My Submissions
Total Accepted: 11388
Total Submissions: 47789
Difficulty: Hard
The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

Note:
The read function may be called multiple times.
 */
#include <iostream>
using namespace std;

namespace read_n_characters_given_read4_ii {
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        if (n == 0)
            return 0;
        int total = 0;
        if (index >= 0) {
            while (cache[index] != '\0' && total < n) {
                buf[total++] = cache[index++];
            }
            if (cache[index] == '\0')
                index = -1;
            if (total == n) {
                buf[total] = '\0';
                return total;
            }
        }
        while (total + 4 <= n) {
            int count = read4(buf + total);
            total += count;
            if (count < 4) {
                buf[total] = '\0';
                return total;
            }
        }
        int count = read4(cache);
        cache[count] = '\0';
        index = 0;
        while (index < count && total < n) {
            buf[total++] = cache[index++];
        }
        buf[total] = '\0';
        return total;
    }
private:
    char cache[5];
    int index = -1;
};
}
