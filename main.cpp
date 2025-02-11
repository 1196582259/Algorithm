#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

#include "line/line.cpp"
#include "algorithm.cpp"

using namespace std;

// ²âÊÔº¯Êý
void testPerformance(int n) {
    std::vector<int> arr(n);
    for (int& num : arr) {
        num = rand() % n;
    }

    auto start = std::chrono::high_resolution_clock::now();
    shellSort(arr);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    std::cout << "n = " << n << ", Time: " << elapsed.count() << " seconds\n";
}
int main() {
	
    for (int n = 1000; n <= 100000; n *= 2) {
        testPerformance(n);
    }
    int arr[] = { 1, 3, 2, 5, 4, 12312,222,444,33,21,5342,543,23,567,369,123,456,789,987,654,321,123,456,789,987,654,3 };
    int len = sizeof(arr) / sizeof(arr[0]);
    //sort_merge(arr, len);
    //sort_heap(arr, len);
	//sort_count(arr, len);
	sort_bucket(arr, len);
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    vector<int> v = { 1, 3, 2, 5, 4, 12312,222,444,33,21,5342,543,23,567,369,123,456,789,987,654,321,123,456,789,987,654,3 };
    sort_quick(v, 0, v.size() - 1);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    vector<int>test = { 1,2,3,4,5,6,7,8 };
    int i = find_bisection<int>(test, [](int& n)->int {
        int k = 8;
        if (n == k) return 0;
        if (n < k) return 1;
        if (n > k) return -1;
    });
    cout << i << endl;
}

