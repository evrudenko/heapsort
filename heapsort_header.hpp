#ifndef _HEAPSORT_HEADER_HPP_
#define _HEAPSORT_HEADER_HPP_

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

/*
 * Приводит строку row в удобную для дальнейшей обработки форму.
 * Удаляет лишние пробелы, символы ([],).
*/
string format_string(string &str);

/*
 * Функция возвращает вектор, содержащий числа, находящиеся в
 * файле filename.
*/
template<typename T>
vector<T> read_array(string filename);

/*
 * Функция выводит массив(вектор) v в консоль.
*/
template<typename T>
void list_array(const T &v);

/*
 * Шаблонный модуль пирамидальной сортировки.
 * Для использования необходимо обратиться к статическому методу sort(), передав
 * в качестве аргумента вектор с данными, которые неободимо отсортировать.
 * НЕОБХОДИМО, чтобы тип переданных данных реализовывал операторы > и <!
*/
template<typename T>
class HeapSortingModule {
public:
	/*
	 * Функция сортировки элементов вектора v методом кучи (пирамидальная
	 * сортировка).
	*/
	static void sort(vector<T> &v);
private:
	/*
	 * Вспомогательная функция, используется функцией heapsort().
	 * Переставляет элементы вектора v таким образом, чтобы выполнялись свойства
	 * кучи, heapsize - количество несортированных элементов в векторе.
	*/
	static void _buildHeap(vector<T> &v, int heapsize);

	/*
	 * Вспомогательная функция, используется функциями _buildHeap() и heapsort().
	 * Выполняет восстановление свойства кучи для поддерева с корнем по индексу
	 * index, heapsize - количество несортированных элементов в векторе v.
	*/
	static void _heapify(vector<T> &v, int index, int heapsize);
};

#endif