#include<stdlib.h>
#include<vector>
#include <iostream>
#include <stdexcept>
#include <utility> // for std::move

#include "../tools/exception.cpp"


namespace my_lib {
	template <typename T>
	class Vector {
	private:
		T* data;
        size_t size;
		size_t capacity;
	public:
		Vector() : data(nullptr), size(0), capacity(0) {};
		~Vector() {
			delete[] data;
		};
		size_t get_size() const {
			return size;
		};
		size_t get_capacity() const {
			return capacity;
		};
		void resize(size_t new_capacity) {
			T* new_data = new T[new_capacity];
			for (int i = 0; i < size; i++) {
				new_data[i] = std::move(data[i]);
			};
            delete[] data;
			data = new_data;
			capacity = new_capacity;
		};
		void push_back(T value) {
			if (size == capacity) {
				resize(capacity == 0? 1 : capacity * 2);
			}
			data[size++] = value;
		};
		void pop_back() {
			if (size == 0) {
				throw EmptyContainerException("Vector is empty");
			}
            size--;
		};
		void clear() {
			size = 0;
		};
		// ����������ͷ��ڴ棩
		void clear_and_free() {
			delete[] data;    // �ͷ��ڴ�
			data = nullptr;   // ��ָ���ÿ�
			size = 0;         // ����С��Ϊ 0
			capacity = 0;     // ��������Ϊ 0
		};
		T* begin() {
			return data;
		};
		T& operator [](size_t index) {
			if (index >= size || index < 0) {
				//throw error("Index out of range");
				throw std::out_of_range("Index out of range");
			}
			return data[index];
		}
	};
}