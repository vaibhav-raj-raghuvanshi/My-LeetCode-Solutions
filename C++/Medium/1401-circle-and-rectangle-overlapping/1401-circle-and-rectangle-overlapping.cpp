class Solution {
public:
    bool checkOverlap(int r, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x = max(x1, min(xCenter, x2));
        int y = max(y1, min(yCenter, y2));
        return (xCenter - x) * (xCenter - x) + (yCenter - y) * (yCenter - y) <= r * r;
    }
};