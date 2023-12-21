#pragma once
#include<iostream>
namespace Vector {

	template <typename T>
	struct Vector
	{
		private:

			T* vec;
			size_t size;
			size_t capasity;
			const size_t growthFactor = 2;

		public:

			Vector();

			Vector(size_t size);

			~Vector();

			Vector<T>& operator= (const Vector<T>& v);

			T& operator[] (const size_t index);

			const T& operator[] (const size_t index) const;

			void reset();

			void reset(const Vector<T>& v);

			void clear();

			Vector<T>& pushBack(T data);

			Vector<T>& pushBack(const Vector<T>& v);

			Vector<T>& popBack(size_t pop_size = 1);

			Vector<T>& reverse();

			T getDataByIndex(size_t index) const;

			size_t getSize() const;

			size_t getCapasity() const;

			void print() const;

			void copy(Vector<T>& v);

			bool isEqual(const Vector<T>& v) const;

			Vector<T>& slice(Vector<T>& slice, const size_t begin, const size_t end);

			Vector<T>& getLastWord(Vector<T>& v) const;

			static void fill_vectors(Vector<T>& ov, Vector<T>& ova, Vector<T>& in, Vector<T>& ina, Vector<T>& ev, Vector<T>& eva, Vector<T>& idze);
	};
}

template<typename T>
inline Vector::Vector<T>::Vector() {
	vec = new T[1];
	capasity = 1;
	size = 0;
}

template<typename T>
inline Vector::Vector<T>::Vector(size_t size) {
	vec = new T[size];
	capasity = size;
	this->size = size;
}

template<typename T>
inline Vector::Vector<T>::~Vector() {
	delete[] vec;
	vec = nullptr;
}

template<typename T>
inline Vector::Vector<T>& Vector::Vector<T>::operator=(const Vector<T>& v) {
	if (this == &v)
		return *this; // Защита от самоприсваивания
	this->reset(v);
	return *this;
}

template<typename T>
inline T& Vector::Vector<T>::operator[](const size_t index) {
	if (index >= 0 and index < size)
		return vec[index];
	std::cout << "Index Error" << std::endl;
}

template<typename T>
inline const T& Vector::Vector<T>::operator[](const size_t index) const {
	if (index >= 0 and index < size)
		return vec[index];
	std::cout << "Index Error" << std::endl;
}

template<typename T>
inline void Vector::Vector<T>::reset() {
	delete[] vec;
	vec = nullptr;
}

template<typename T>
inline void Vector::Vector<T>::reset(const Vector<T>& v) {
	size = 0;
	this->pushBack(v);
}

template<typename T>
inline void Vector::Vector<T>::clear() {
	size = 0;
}

template<typename T>
inline Vector::Vector<T>& Vector::Vector<T>::pushBack(T data) {
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
	return *this;
}

template<typename T>
inline Vector::Vector<T>& Vector::Vector<T>::pushBack(const Vector<T>& v) {
	if (v.getSize() == 0)
		return *this;
	for (size_t i{}; i < v.getSize(); i++) {
		this->pushBack(v[i]);
	}
	return *this;
}

template<typename T>
inline Vector::Vector<T>& Vector::Vector<T>::popBack(size_t pop_size) {
	size -= pop_size;
	return *this;
}

template<typename T>
inline Vector::Vector<T>& Vector::Vector<T>::reverse() {
	size_t half = static_cast<size_t>(size / 2);
	for (size_t i{}; i < half; i++) {
		std::swap(vec[i], vec[size - 1 - i]);
	}
	return *this;
}

template<typename T>
inline T Vector::Vector<T>::getDataByIndex(size_t index) const {
	if (index >= 0 and index < size)
		return vec[index];
	std::cout << "Index Error" << std::endl;
}

template<typename T>
inline size_t Vector::Vector<T>::getSize() const {
	return size;
}

template<typename T>
inline size_t Vector::Vector<T>::getCapasity() const {
	return capasity;
}

template<typename T>
inline void Vector::Vector<T>::print() const {
	for (size_t i{}; i < size; i++) {
		std::cout << vec[i];
	}
	std::cout << std::endl;
}

template<typename T>
inline void Vector::Vector<T>::copy(Vector<T>& v) {
	if (v.getSize() == 0) {
		for (size_t i{}; i < size; i++) {
			v.pushBack(vec[i]);
		}
	}
	else
		std::cout << "Vector is not empty" << std::endl;
}

template<typename T>
inline bool Vector::Vector<T>::isEqual(const Vector<T>& v) const {
	if (v.getSize() != size)
		return false;
	size_t counter{};
	for (size_t i{}; i < size; i++) {
		if (vec[i] == v[i])
			counter++;
	}
	if (counter == size)
		return true;
	return false;
}

template<typename T>
inline Vector::Vector<T>& Vector::Vector<T>::slice(Vector<T>& slice, const size_t begin, const size_t end) {
	if (slice.getSize() == 0) {
		for (size_t i = begin; i < end; i++) {
			slice.pushBack((*this)[i]);
		}
		return slice;
	}
	std::cout << "Vector is not empty" << std::endl;
	return *this;
}

template<typename T>
inline Vector::Vector<T>& Vector::Vector<T>::getLastWord(Vector<T>& v) const {
	if (v.getSize() == 0 and this->getSize() > 1) {
		for (size_t elem = this->getSize() - 2; (*this)[elem] != ' '; elem--) {
			v.pushBack((*this)[elem]);
			if (elem == 0)
				break;
		}
		v.reverse();
		return v;
	}
	std::cout << "Source Vector is empty or destination Vector is not empty" << std::endl;
	return v;
}

template<typename T>
inline void Vector::Vector<T>::fill_vectors(Vector<T>& ov, Vector<T>& ova, Vector<T>& in, Vector<T>& ina, Vector<T>& ev, Vector<T>& eva, Vector<T>& idze) {

	ov.pushBack('o');
	ov.pushBack('v');

	ova.pushBack('o');
	ova.pushBack('v');
	ova.pushBack('a');

	in.pushBack('i');
	in.pushBack('n');

	ina.pushBack('i');
	ina.pushBack('n');
	ina.pushBack('a');

	ev.pushBack('e');
	ev.pushBack('v');

	eva.pushBack('e');
	eva.pushBack('v');
	eva.pushBack('a');

	idze.pushBack('i');
	idze.pushBack('d');
	idze.pushBack('z');
	idze.pushBack('e');
}
