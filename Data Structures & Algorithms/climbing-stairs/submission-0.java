class Solution {
    public int climbStairs(int n) {
        int[] nums = new int[n+1];
        if(n==1 || n==2){
            return n;
        }
        nums[1]=1;
        nums[2]=2;
        for(int i=3;i<n+1;i++){
            nums[i] = nums[i-2]+nums[i-1];
        }
        return nums[n];
    
        
    }
}
