/**
 * Read N characters given read4
 * The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

Note:
The read function will only be called once for each test case.
 */

#include <iostream>
using namespace std;

namespace read_n_characters_given_read4 {
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int total = 0;
        while (total < n) {
            int count = read4(buf + total);
            int minimum = count;
            if (minimum > n - total)
                minimum = n - total;
            total += minimum;
            buf[total] = '\0';
            if (count < 4)
                break;
        }
        return total;
    }
};
}
