class MedianFinder {
    priority_queue<int> mnheap;
    priority_queue<int, vector<int>, greater<int>> mxheap;

   public:
    MedianFinder() {}

    void addNum(int num) {
        mnheap.push(num);
        mxheap.push(mnheap.top());
        mnheap.pop();
        if(mxheap.size()>mnheap.size()){
            mnheap.push(mxheap.top());
            mxheap.pop();
        }
        
    }

    double findMedian() {
        if (mxheap.size() == mnheap.size()) {
            return (mxheap.top() + mnheap.top()) / 2.0;
        }
        if (mxheap.size() > mnheap.size()) return mxheap.top();
        return mnheap.top();
    }
};
