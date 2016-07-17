class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int k1 = (C - A) * (D - B);
        int k2 = (G - E) * (H - F);
        int t1 = min(C, G);
        int t2 = max(A, E);
        int t3 = min(D, H);
        int t4 = max(B, F);
        int overlap = 0;
        if(t1 > t2 && t3 > t4)
            overlap = (t1 - t2) * (t3 - t4);
        return k1 + k2 - overlap;
    }
};