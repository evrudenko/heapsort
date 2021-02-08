#include "heapsort_header.hpp"

// Функция сортировки элементов вектора v методом кучи.
template<typename T>
void HeapSortingModule<T>::sort(vector<T> &v) {
	int heapsize = v.size();

	_buildHeap(v, heapsize);

	while(heapsize > 1) {
		swap(v[0], v[heapsize - 1]);
		--heapsize;
		_heapify(v, 0, heapsize);
	}
}

// Вспомогательная функция, используется функцией heapsort().
// Переставляет элементы вектора v таким образом, чтобы выполнялись свойства
// кучи, heapsize - количество несортированных элементов в векторе.
template<typename T>
void HeapSortingModule<T>::_buildHeap(vector<T> &v, int heapsize) {
	for(int i = heapsize / 2 - 1; i >= 0; --i)
		_heapify(v, i, heapsize);
}

// Вспомогательная функция, используется функциями _buildHeap() и heapsort().
// Выполняет восстановление свойства кучи для поддерева с корнем по индексу
// index, heapsize - количество несортированных элементов в векторе v.
template<typename T>
void HeapSortingModule<T>::_heapify(vector<T> &v, int index, int heapsize) {
	int leftChild_i = index * 2 + 1,
		rightChild_i = leftChild_i + 1,
		max_val_i = index;
	
	if(rightChild_i < heapsize) {
		max_val_i = v[rightChild_i] > v[leftChild_i] ? rightChild_i : leftChild_i;
		max_val_i = v[max_val_i] > v[index] ? max_val_i : index;
	}
	if(rightChild_i == heapsize)
		max_val_i = v[leftChild_i] > v[index] ? leftChild_i : index;

	if(max_val_i != index) {
		swap(v[max_val_i], v[index]); // v.swap(max_val_i, index);
		_heapify(v, max_val_i, heapsize);
	}
}