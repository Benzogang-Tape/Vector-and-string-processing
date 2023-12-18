/*#include "Vector.h"

template<typename T>
inline Vector::Vector<T>::Vector() {
	vec = new T[1];
	capasity = 1;
	size = 0;
}

template <typename T>
inline Vector::Vector<T>::~Vector() {
	delete[] vec;
}

template<typename T>
void Vector::Vector<T>::puhsBack(T data) {
	if (size == capasity) {
		T* temp = new T[capasity * growthFactor];

		for (size_t i{}; i < size; i++) {
			temp[i] = vec[i];
		}

		delete[] vec;
		capasity *= growthFactor;
		vec = temp;
	}
	vec[size] = data;
	size++;
}

template<typename T>
T Vector::Vector<T>::getDataByIndex(size_t index) {
	if (index < size)
		return vec[index];
	return -1;
}

template<typename T>
size_t Vector::Vector<T>::getSize() {
	return size;
}

template<typename T>
size_t Vector::Vector<T>::getCapasity() {
	return capasity;
}

template<typename T>
void Vector::Vector<T>::print() {
	for (size_t i{}; i < size; i++) {
		std::cout << vec[i] << ' ';
	}
	std::cout << std::endl;
}
*/

//template<typename T>
//Vector::Vector<T>::Vector(T* vec, const size_t& size, const size_t& capasity, const size_t& growthFactor)
//	: vec(vec), size(size), capasity(capasity), growthFactor(growthFactor)
//{
//}




/*

#pragma once
#include<iostream>
namespace Vector {

	template <typename T>
	class Vector
	{
		T* vec;
		size_t size;
		size_t capasity;
		size_t growthFactor = 2;


	public:
		Vector(T* vec, const size_t& size, const size_t& capasity, const size_t& growthFactor)
			: vec(vec), size(size), capasity(capasity), growthFactor(growthFactor);

		Vector();
		~Vector();

		void puhsBack(T data);
		void getDataByIndex(size_t index);
		size_t getSize();
		size_t getCapasity();
		void print();
	};
}

*/