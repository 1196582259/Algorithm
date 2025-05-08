#pragma once
#include<iostream>
#include <utility>
#include <iostream>
#include <vector>
#include <stack>
#include <functional>
using namespace std;
// 冒泡排序
void sort_bubble(int* arr, int len) {
	std::cout << "冒泡排序开始：" << std::endl;
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (arr[i] > arr[j]) {
				std::swap(arr[i], arr[j]);
			}
		}
	}
}
// 选择排序
void sort_select(int* arr, int len) {
	std::cout << "选择排序开始：" << std::endl;
	for (int i = 0; i < len; i++) {
		int index = i;
		for (int j = i + 1; j < len; j++) {
			if (arr[index] > arr[j]) {
				index = j;
			}
		};
		std::swap(arr[i], arr[index]);
	};
}

// 插入排序
void sort_insert(int* arr, int len) {
	std::cout << "插入排序开始：" << std::endl;
	for (int i = 0; i < len; i++) {
		int j = i;
		int tmp = arr[i];
		while (j && tmp < arr[j - 1]) {
			arr[j] = arr[j - 1];
			j--;
		};
		arr[j] = tmp;
	}
}
// 计算 Hibbard 增量
int getHibbardGap(int k) {
	return (1 << k) - 1; // 2^k - 1
}
// 希尔排序（使用 Hibbard 增量）
void shellSort(std::vector<int>& arr) {
	int n = arr.size();
	int k = 1;

	// 计算最大增量
	while (getHibbardGap(k) < n) {
		k++;
	}

	// 逐步缩小增量
	for (int gap = getHibbardGap(k - 1); gap > 0; gap = getHibbardGap(--k)) {
		for (int i = gap; i < n; ++i) {
			int temp = arr[i];
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
}
// 希尔排序
void sort_shell(int* arr, int len, int step) {
	int gap = len / step;
	while (gap) {
		cout << "gap =" << gap << endl;
		for (int i = gap; i < len; i++) {
			int tmp = arr[i];
			int j = i;
			while (j >= gap && tmp < arr[j - gap]) {
				arr[j] = arr[j - gap];
				j -= gap;
			};
			arr[j] = tmp;
		}
		gap = gap == 1 ? 0 : (gap / step | 1);
	}
}


void merge(int* arr, int left, int mid, int right) {
	if (left == right) return;
	int tmp;
	int* left_arr = new int[mid - left + 1];
	int* right_arr = new int[right - mid];
	for (int i = 0; i < mid - left + 1; i++) {
		left_arr[i] = arr[left + i];
	};
	for (int i = 0; i < right - mid; i++) {
		right_arr[i] = arr[mid + 1 + i];
	};
	int i = 0;
	int j = 0;
	int k = left;
	while (i < mid - left + 1 && j < right - mid) {
		if (left_arr[i] <= right_arr[j]) {
			arr[k] = left_arr[i++];
		}
		else {
			arr[k] = right_arr[j++];
		};
		k++;
	}
	while (i < mid - left + 1) {
		arr[k++] = left_arr[i++];
	}
	while (j < right - mid) {
		arr[k++] = right_arr[j++];
	}
};
void split_mid(int* arr, int left, int right) {
	if (left == right) return;
	int mid = (left + right) / 2;
	split_mid(arr, left, mid);
	split_mid(arr, mid + 1, right);
	merge(arr, left, mid, right);
}
// 归并排序
void sort_merge(int* arr, int len) {
	int mid = len / 2;
	split_mid(arr, 0, len - 1);
};


int partition(int* arr, int left, int right) {
	int randomIndex = left + rand() % (right - left + 1); // 随机选择基准元素
	int pivot = arr[randomIndex];
	std::swap(arr[randomIndex], arr[right]); // 将基准元素交换到数组末尾
	int i = left - 1;
	for (int j = left; j < right; j++) {
		if (arr[j] < pivot) {
			std::swap(arr[++i], arr[j]);
		};
	}
	std::swap(arr[i + 1], arr[right]); // 将基准元素交换到正确位置
	return i + 1;
}

void sort_quick_floo(int* arr, int left, int right) {
	if (left < right) {
		int pi = partition(arr, left, right);
		sort_quick_floo(arr, left, pi - 1);
		sort_quick_floo(arr, pi + 1, right);
	}
};

// 快速排序
void sort_quick(int* arr, int len) {
	sort_quick_floo(arr, 0, len - 1);
};


void heapify(int* arr, int n, int i) {
	int largest_index = i;
	int left_child = 2 * i + 1;
	int right_child = 2 * i + 2;
	if (left_child < n && arr[left_child] > arr[largest_index]) {
		largest_index = left_child;
	}
	if (right_child < n && arr[right_child] > arr[largest_index]) {
		largest_index = right_child;
	}
	if (largest_index != i) {
		std::swap(arr[i], arr[largest_index]);
		heapify(arr, n, largest_index);
	}
};




// 堆排序
void sort_heap(int* arr, int len) {
	int n = len - 1;
	for (int i = n / 2 + 1; i >= 0; i--) {
		heapify(arr, n, i);
	};
	for (int i = n; i >= 0; i--) {
		std::swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

// 计数排序
void sort_count(int* arr, int len) {

	int max = arr[0];
	for (int i = 1; i < len; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	int* count = new int[max + 1];
	for (int i = 0; i < max + 1; i++) {
		count[i] = 0;
	}
	for (int i = 0; i < len; i++) {
		count[arr[i]]++;
	}
	int index = 0;
	for (int i = 0; i < max + 1; i++) {
		while (count[i] > 0) {
			arr[index++] = i;
			count[i]--;
		}
	}
	delete[] count;
}


// 桶排序
void sort_bucket(int* arr, int len) {
	int max = arr[0];
	int min = arr[0];
	for (int i = 1; i < len; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	int bucket_num = max - min + 1;
	vector<vector<int>> bucket(bucket_num);

	for (int i = 0; i < len; i++) {
		bucket[arr[i] - min].push_back(arr[i]);
	}
	int index = 0;
	for (int i = 0; i < bucket_num; i++) {
		for (int j = 0; j < bucket[i].size(); j++) {
			arr[index++] = bucket[i][j];
		}
	}
}

// 基数排序
void sort_radix(int* arr, int len) {
	int max = arr[0];
	for (int i = 1; i < len; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	int exp = 1;
	int* output = new int[len];
	while (max / exp > 0) {
		int count[10] = { 0 };
		for (int i = 0; i < len; i++) {
			count[arr[i] / exp % 10]++;
		}
		for (int i = 1; i < 10; i++) {
			count[i] += count[i - 1];
		}
		for (int i = len - 1; i >= 0; i--) {
			output[count[arr[i] / exp % 10] - 1] = arr[i];
			count[arr[i] / exp % 10]--;
		}
		for (int i = 0; i < len; i++) {
			arr[i] = output[i];
		}
		exp *= 10;
	}
	delete[] output;
}




// vector 版本
// 快速排序
void sort_quick(vector<int>& v, int l, int r) {
	if (l >= r) return;
	int len = v.size();
	int i = l, j = r;
	while (i < j) {
		while (v[j] >= v[l] && j > i) j--;
		while (v[i] <= v[l] && j > i) i++;
		std::swap(v[i], v[j]);
	};
	swap(v[i], v[l]);
	sort_quick(v, l, i - 1);
	sort_quick(v, i + 1, r);
}


void find(void* arr, int arr_len, int el_size, void (*temp)(int&, int&)) {
	temp(arr_len, el_size);
};

// 二分查找法
template<typename T>
T find_bisection(vector<T>& v, int (*sortFunc)(T&)) {
	int size = v.size();
	int l = 0, r = size - 1;
	cout << "二分查找法开始执行" << endl;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		int result = sortFunc(v[mid]);
		if (result == 0) {
			return v[mid];
		}
		else if (result == -1) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	};
	return T();
};


// 中缀转前缀
//template<typename T>
//T toPrefix(const T& infix, int size) {
//	stack<char> st;
//	ostringstream prefix;
//	for (int i = size - 1; i >= 0; --i) {
//
//	};
//
//};
// 中缀转后缀




// 闭包
void handleIndex(int index, function<void()> vistor)
{
	if (index == 1)
	{
		vistor();
	}
}
void OnHandleIndex(int index)
{
	int k = 123;
	handleIndex(index, [&]()
		{
			cout << k << endl;
			cout << "deal" << endl;
			return;
		});
}