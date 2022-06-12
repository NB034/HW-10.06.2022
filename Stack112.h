#pragma once

class Stack112 {
	char* arr = nullptr;
	int currentSize = 0;
	int maxSize = 0;
public:
	Stack112(size_t maxSize);
	Stack112(const Stack112& stack);
	Stack112(Stack112&& stack);
	Stack112& operator=(const Stack112& stack);
	Stack112& operator=(Stack112&& stack);
	~Stack112();

	inline bool full() const { return this->currentSize == this->maxSize; }
	inline bool empty() const { return this->currentSize == 0; }

	inline char top() const { return this->arr[this->currentSize - 1]; }
	inline char& top() { return this->arr[this->currentSize - 1]; }

	inline int size() const { return this->currentSize; }
	inline int getMaxSize() const { return this->maxSize; }

	void push(char ch);
	void pop();
};