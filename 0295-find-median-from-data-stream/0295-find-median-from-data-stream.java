import java.util.Collections;
import java.util.PriorityQueue;

class MedianFinder {
    private PriorityQueue<Integer> smallHalf; // Max-heap
    private PriorityQueue<Integer> largeHalf; // Min-heap

    public MedianFinder() {
        // Max-heap to store the smaller half of numbers
        smallHalf = new PriorityQueue<>(Collections.reverseOrder());
        // Min-heap to store the larger half of numbers
        largeHalf = new PriorityQueue<>();
    }
    
    public void addNum(int num) {
        // Step 1: Add to small half (max-heap)
        smallHalf.offer(num);
        
        // Step 2: Balancing - Move the largest of small half to large half
        largeHalf.offer(smallHalf.poll());
        
        // Step 3: Maintain size property (smallHalf can have at most 1 more element than largeHalf)
        if (smallHalf.size() < largeHalf.size()) {
            smallHalf.offer(largeHalf.poll());
        }
    }
    
    public double findMedian() {
        if (smallHalf.size() > largeHalf.size()) {
            return smallHalf.peek();
        }
        return (smallHalf.peek() + largeHalf.peek()) / 2.0;
    }
}
