class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int ans=0;

        int leftmax=0;
        int rightmax=0;

        while(left<right){
            int c=min(height[left], height[right])*(right-left);
            ans=max(ans, c);
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return ans;
    }
};