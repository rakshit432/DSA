class Robot {
public:
    int w = 0, h = 0;
    pair<int,int> dir;
    int x_bound, y_bound;

    Robot(int width, int height) {
        x_bound = width;
        y_bound = height;
        dir = {1, 0}; // East
    }
    
    void step(int num) {
        int perimeter = 2 * (x_bound + y_bound - 2);
        if (perimeter == 0) return;

        num %= perimeter;
        if (num == 0) num = perimeter;

        while (num--) {
            while (true) {
                int nw = w + dir.first;
                int nh = h + dir.second;

                // valid move
                if (nw >= 0 && nw < x_bound && nh >= 0 && nh < y_bound) {
                    w = nw;
                    h = nh;
                    break;
                }

                // rotate CCW (your logic)
                int x1 = dir.first;
                int y1 = dir.second;
                dir.first = -y1;
                dir.second = x1;
            }
        }
    }
    
    vector<int> getPos() {
        return {w, h};
    }
    
    string getDir() {
        if (dir == make_pair(1,0)) return "East";
        if (dir == make_pair(0,1)) return "North";
        if (dir == make_pair(-1,0)) return "West";
        return "South";
    }
};