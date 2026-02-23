#pragma once

template <typename T>
class DynamicArray {
private:
	int _capacity;
	int _size;
	T* _data;

	void resize() {
		_capacity *= 2;
		int* newArr = new int[_capacity];
		for (int i = 0; i < _size; i++) {
			newArr[i] = _data[i];
		}

		delete[] _data;
		_data = newArr;
	}

public:
	DynamicArray(int capacity) : _capacity{ capacity }, _size{ 0 } {
		if (_capacity == 0) { _capacity = 1; }

		_data = new int[_capacity];
	}
	~DynamicArray() {
		delete[] _data;
	}

	int Capacity() const {
		return _capacity;
	}
	int Size() const {
		return _size;
	}

	T GetValue(int index) const {
		return _data[index];
	}

	void push_back(T value) {
		if (_size == _capacity) {
			resize();
		}

		_data[_size] = value;
		_size++;
	}
	/*void push_back(T values[]) {
		for (int i = 0; i < values.; i++) {

		}
	}*/
};