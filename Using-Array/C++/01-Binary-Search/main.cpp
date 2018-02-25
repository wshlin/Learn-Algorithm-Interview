#include <iostream>
#include <cmath>
#include <cassert>
#include <ctime>
#include "util.h"

using namespace std;

template<typename T>
int binarySearch(T arr[], int n, T target) {

    int l = 0, r = n - 1;  // find the target in the range of [l...r]
    while (l <= r) {       // when l == r, the interval [l...r] is still valid
        int mid = l + (r - l) / 2;
        if (arr[mid] == target)
            return mid;
        if (target > arr[mid])
            l = mid + 1;   // target in [mid+1...r], [l...mid] must have no target
        else 
            r = mid - 1;   // target in [l...mid-1], [mid...r] must have no target
    }
    return -1;
}

template<typename T>
int binarySearchII(T arr[], int n, T target) {

    int l = 0, r = n;     // find the target in the range of [l...r)
    while (l < r) {       // when l == r, the interval [l...r) is an invalid interval
        int mid = l + (r - l) / 2;
        if (arr[mid] == target)
            return mid;
        if (target > arr[mid])
            l = mid + 1;  // target in [mid+1...r), [l...mid] must have no target
        else 
            r = mid;      // target in [l...mid), [mid...r) must have no target
    }
    return -1;
}

int main() 
{
    int n = pow(10, 7);
    int* data = MyUtil::generateOrderedArray(n);

    clock_t startTime = clock();
    for(int i = 0 ; i < n ; i ++)
        assert(i == binarySearch(data, n, i));
    clock_t endTime = clock();

    cout << "Binary Search test complete." << endl;
    cout << "Time cost: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

    return 0;  
}
