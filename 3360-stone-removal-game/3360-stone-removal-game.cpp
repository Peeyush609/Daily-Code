class Solution {
public:
    
    bool alice(int n, int last){
        if(n < last - 1){
            return false;
        }

        return bob(n - (last - 1), last - 1);
    }
    bool bob(int n, int last){
        if(n < last - 1){
            return true;
        }

        return alice(n - (last - 1), last - 1);
    }

    bool canAliceWin(int n) {
        if(n < 10)  return false;

        return bob(n - 10, 10);
    }
};