// class heap {

// public:
// 	int arr[50000];
// 	int size = 0;

// 	heap(){
// 		arr[0] = -1;
// 		size = 0;
// 	}

// 	// T.C - O(logN) for insertion in Heap 
// 	void insert(int val){

// 		size = size + 1;
// 		int index = size;
// 		arr[index] = val;

// 		while(index > 1){
// 			int parent = index/2;

// 			if(arr[parent] < arr[index]){
// 				swap(arr[parent],arr[index]);
// 				index = parent;
// 			}else{
// 				return;
// 			}
// 		}

// 	}

// 	void print(){
// 		for(int i = 1; i <= size; i++){
// 			cout << arr[i] << " ";
// 		}
        
// 	}

//     double solve(){
//        // vector<int> ans;

//      // int size =  arr.size();
     

    

//       if(size%2 == 1){
//         //return arr[size/2];

//         double first = arr[(size/2) + 1];
//         double second = arr[size/2];

//         cout << "first:" << first  << " " << second << endl;

//       return (double)(first + second)/2.0;
//       }

//       return arr[size/2];

      
//     }

// 	// Deletion of root node in heap
// 	// T.C-> O(logn)
// 	void deletefromHeap(){
// 		if(size == 0){
// 			cout << "Nothing to delete" << endl;
// 			return;
// 		}

// 		// Step 1: Put last element into first index
// 		arr[1] = arr[size];
// 		// Step 2: remove the last element
// 		size--;

// 		// Step 3: take root node to it's correct position
// 		int i = 1;
// 		while(i <= size){
// 			int leftIndex = 2 * i;
// 			int rightIndex = 2 * i + 1;
// 			int maxi = i;

// 			if(leftIndex <= size && arr[leftIndex] > arr[maxi]){
// 				maxi = leftIndex;
// 			}

// 			if(rightIndex <= size && arr[rightIndex] > arr[maxi]){
// 				maxi = rightIndex;
// 			}

// 			if(maxi != i){
// 				swap(arr[i], arr[maxi]);
// 				i = maxi;
// 			}else return;

// 		}
// 	}

// 	void heapify(vector<int> &arr, int n, int i){

// 		int largest = i;
// 		int left = 2 * i;
// 		int right = 2 * i + 1;

// 		if(left <= n && arr[largest] < arr[left]){
// 			largest = left;
// 		}

// 		if(right <= n && arr[largest] < arr[right]){
// 			largest = right;
// 		}

// 		if(largest != i){
// 			swap(arr[largest], arr[i]);
// 			heapify(arr, n, largest);
// 		}		
// 	}

// 	void heapSort(vector<int> &arr, int n){
// 		int size = n;

// 		while(size > 1){
// 		// step1: swap
// 			swap(arr[size], arr[1]);
// 			size--;

// 			heapify(arr,size,1);
// 		}
// 	}

// };
class MedianFinder {
    // max heap:
    priority_queue<int> first; 

    // min heap:
    priority_queue<int, vector<int>, greater<int>> later; 

public:
    MedianFinder() {
    }

    void addNum(int num) {


        if (first.empty() || num <= first.top()) {
            first.push(num);
        }
        else {
            later.push(num);
        }

        // if first size > later means ther is max that must be on right part
        if (first.size() > later.size() + 1) {
            later.push(first.top());
            first.pop();
        } // if later size > first mean there is minimum that should be left side
        else if (later.size() > first.size()) {
            first.push(later.top());
            later.pop();
        }
    }

    double findMedian() {

        if (first.size() > later.size()) {
            return first.top();
        }

        return (first.top() + later.top()) / 2.0;
    }
};
