class Solution {
public:
   bool judgeCircle(string moves) {
    int x = 0, y = 0;

    for (char c : moves) {
        if (c == 'U') y++;
        if (c == 'D') y--;
        if (c == 'R') x++;
        if (c == 'L') x--;
    }

    return x == 0 && y == 0;
}
};