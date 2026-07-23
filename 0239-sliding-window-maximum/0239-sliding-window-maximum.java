class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        
        Deque<Integer> que = new ArrayDeque<>();
        int[] ans = new int[nums.length - k + 1];

        int ind = 0;

       for(int i = 0; i < nums.length; i++) {


        while(!que.isEmpty() && que.peekFirst() <= i - k ){
            que.pollFirst();
        }
      while(!que.isEmpty() && nums[que.peekLast()] <= nums[i]){
            que.pollLast();
        }


        que.offerLast(i);



        if(i >= k - 1){
            ans[ind++] = nums[que.peekFirst()];
        }


       }
       return ans;
    }
}