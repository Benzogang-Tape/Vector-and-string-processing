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
			size_t growthFactor = 2;

		public:

			Vector() {
				vec = new T[1];
				capasity = 1;
				size = 0;
			}

			Vector(size_t size) {
				vec = new T[size];
				capasity = size;
				this->size = size;
			}

			~Vector() {
				delete[] vec;
				vec = nullptr;
			}

			Vector<T>& operator= (const Vector<T>& v) {
				if (this == &v)
					return *this; // Защита от самоприсваивания
				this->reset(v);
				return *this;
			}

			T& operator[] (const size_t index) {
				if (index >= 0 and index < size)
					return vec[index];
				std::cout << "Index Error" << std::endl;
			}

			const T& operator[] (const size_t index) const {
				if (index >= 0 and index < size)
					return vec[index];
				std::cout << "Index Error" << std::endl;
			}

			void reset() {
				delete[] vec;
				vec = nullptr;
			}

			void reset(const Vector<T>& v) {
				size = 0;
				this->pushBack(v);
			}

			void clear() {
				size = 0;
			}

			Vector<T>& pushBack(T data) {
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

			Vector<T>& pushBack(const Vector<T>& v) {
				if (v.getSize() == 0)
					return *this;
				for (size_t i{}; i < v.getSize(); i++) {
					this->pushBack(v[i]);
				}
				return *this;
			}

			Vector<T>& popBack(size_t pop_size = 1) {
				size -= pop_size;
				return *this;
			}

			Vector<T>& reverse() {
				size_t half = static_cast<size_t>(size / 2);
				for (size_t i{}; i < half; i++) {
					std::swap(vec[i], vec[size - 1 - i]);
				}
				return *this;
			}

			T getDataByIndex(size_t index) const {
				if (index >= 0 and index < size)
					return vec[index];
				std::cout << "Index Error" << std::endl;
			}

			size_t getSize() const {
				return size;
			}

			size_t getCapasity() const {
				return capasity;
			}

			void print() const {
				for (size_t i{}; i < size; i++) {
					std::cout << vec[i];
				}
				std::cout << std::endl;
			}

			void copy(Vector<T>& v) {
				if (v.getSize() == 0) {
					for (size_t i{}; i < size; i++) {
						v.pushBack(vec[i]);
					}
				}
				else
					std::cout << "Vector is not empty" << std::endl;
			}

			bool isEqual(const Vector<T>& v) const {
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

			Vector<T>& slice(Vector<T>& slice, const size_t begin, const size_t end) {
				if (slice.getSize() == 0) {
					for (size_t i = begin; i < end; i++) {
						slice.pushBack((*this)[i]);
					}
					return slice;
				}
				std::cout << "Vector is not empty" << std::endl;
				return *this;
			}

			Vector<T>& getLastWord(Vector<T>& v) const {
				if (v.getSize() == 0) {
					for (size_t elem = this->getSize() - 2; (*this)[elem] != ' '; elem--) {
						v.pushBack((*this)[elem]);
						if (elem == 0)
							break;
					}
					v.reverse();
					return v;
				}
				std::cout << "Vector is not empty" << std::endl;
				return v;
			}

			static void fill_vectors(Vector<T>& ov, Vector<T>& ova, Vector<T>& in, Vector<T>& ina, Vector<T>& ev, Vector<T>& eva, Vector<T>& idze) {
				
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
	};
}