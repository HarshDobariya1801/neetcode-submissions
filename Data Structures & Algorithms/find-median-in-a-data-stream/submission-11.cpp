class MedianFinder {
    // max heap:
    priority_queue<int> first; 

    // min heap:
    priority_queue<int, vector<int>, greater<int>> later; 

public:
    MedianFinder() {
    }

    void addNum(int num) {

            first.push(num);
            later.push(first.top());
            first.pop();

            if(later.size() > first.size()){
                first.push(later.top());
                later.pop();
            }
        // if (first.empty() || num <= first.top()) {
        //     first.push(num);
        // }
        // else {
        //     later.push(num);
        // }

        // // if first size > later means ther is max that must be on right part
        // if (first.size() > later.size() + 1) {
        //     later.push(first.top());
        //     first.pop();
        // } // if later size > first mean there is minimum that should be left side
        // else if (later.size() > first.size()) {
        //     first.push(later.top());
        //     later.pop();
        // }
    }

    double findMedian() {

        if (first.size() > later.size()) {
            return first.top();
        }

        return (first.top() + later.top()) / 2.0;
    }
};
