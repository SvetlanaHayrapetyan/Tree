#include <queue>
#include <vector>

// Define a class to find kth largest element in a stream of numbers.
class KthLargest {
public:
    // Declare a min heap to keep track of the k largest elements.
    std::priority_queue<int, std::vector<int>, std::greater<>> minHeap;
    // Store the value of 'k' to know which largest element to keep track of.
    int kthSize;

    // Constructor for initializing the KthLargest class.
    // k - The kth position to track.
    // nums - Initial list of numbers from which we find the kth largest element.
    KthLargest(int k, std::vector<int>& nums) {
        kthSize = k;
        // Add initial numbers to the heap
        for (int num : nums) {
            add(num);
        }
    }

    // Function to add a number to the stream and return the kth largest element.
    int add(int val) {
        // Add the new number to the min heap.
        minHeap.push(val);
        // If the heap size is greater than k, remove the smallest element.
        if (minHeap.size() > kthSize) {
            minHeap.pop();
        }
        // Return the kth largest element (top of the min heap).
        return minHeap.top();
    }
};

/**
 * The provided code snippet illustrates the use of the KthLargest class.
 * It demonstrates the instantiation of a KthLargest object and subsequent calls to its add method.
 */
