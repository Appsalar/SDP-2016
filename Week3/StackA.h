#pragma once

template <class T>
class StackA
{
private:
	T* pArr;
	size_t size;
	size_t capacity;

public:
	StackA();
	~StackA();

	void push(const T&);
	void pop();
	T& top();
	bool empty() const;

private:
	void setSize(size_t);
};

template<class T>
StackA<T>::StackA()
{
	pArr = nullptr;
	size = 0;
	capacity = 0;
}


template<class T>
StackA<T>::~StackA()
{
	delete[] pArr;
}

template<class T>
void StackA<T>::push(const T& elem)
{
	if (capacity == 0)
		setSize(2);
	else if (size == capacity)
		setSize(2 * capacity);

	pArr[size] = elem;
	++size;
}

template<class T>
void StackA<T>::pop()
{
	if (size > 0)
		--size;
	else
		throw "420 blaze it";

	if (size == 0)
	{
		delete[] pArr;
		pArr = NULL;
		capacity = 0;
	}
	else if (size <= capacity / 4)
		setSize(capacity / 2);
}

template<class T>
T& StackA<T>::top()
{
	return pArr[size - 1];
}

template<class T>
bool StackA<T>::empty() const
{
	return size == 0;
}

template<class T>
void StackA<T>::setSize(size_t newSize)
{
	int* foo = new T[newSize];

	for (int i = 0;i < size;++i)
		foo[i] = pArr[i];

	delete[] pArr;
	pArr = foo;
	capacity = newSize;
}




