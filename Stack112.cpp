#include "Stack112.h"
#include<iostream>

Stack112::Stack112(size_t maxSize) {
	this->maxSize = maxSize;
	this->arr = new char[maxSize];
}
Stack112::Stack112(const Stack112& stack) {
	if (stack.arr != nullptr) {
		this->maxSize = stack.maxSize;
		this->currentSize = stack.currentSize;
		this->arr = new char[this->maxSize];
		for (size_t i = 0; i < this->currentSize; i++) {
			this->arr[i] = stack.arr[i];
		}
	}
}
Stack112::Stack112(Stack112&& stack) {
	std::swap(this->maxSize, stack.maxSize);
	std::swap(this->currentSize, stack.currentSize);
	std::swap(this->arr, stack.arr);
}
Stack112& Stack112::operator=(const Stack112& stack) {
	if (this == &stack)
		return *this;
	if (stack.arr == nullptr) {
		this->~Stack112();
		return *this;
	}
	if (stack.maxSize != this->maxSize) {
		this->~Stack112();
		this->maxSize = stack.maxSize;
		this->arr = new char[this->maxSize];
	}
	this->currentSize = stack.currentSize;
	for (size_t i = 0; i < this->currentSize; i++)
		this->arr[i] = stack.arr[i];
	return *this;
}
Stack112& Stack112::operator=(Stack112&& stack) {
	if (this == &stack)
		return *this;
	if (this->arr != nullptr)
		this->~Stack112();
	std::swap(this->maxSize, stack.maxSize);
	std::swap(this->currentSize, stack.currentSize);
	std::swap(this->arr, stack.arr);
	return *this;
}
Stack112::~Stack112() {
	if (this->arr == nullptr) {
		delete[] this->arr;
		this->currentSize = 0;
		this->maxSize = 0;
	}
}

inline void Stack112::push(char ch) {
	if (!this->full())
		this->arr[this->currentSize++] = ch;
	else
		std::cout << "Stack overflow!" << std::endl;
}
inline void Stack112::pop() {
	if (!this->empty())
		this->currentSize--;
	else
		std::cout << "Stack is empty!" << std::endl;
}
