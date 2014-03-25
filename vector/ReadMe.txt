vector 工程

请实现std::vector类的主要功能。函数声明以及写作头文件中。部分实现也做了，但可能不完全正确。

请面试者实现这个类，并补充尽可能详尽的单元测试用例，越多越好，代码逻辑路径覆盖越全越好。

请认真对待，仔细考虑每一个细节问题。

1. 算法复杂度为O(n)的有：
	explicit vector( size_t n, const T& value = T())
	void vector<T>::reserve(size_t n) 
	void vector<T>::resize()
	void vector<T>::push_back(const T& element)
	void vector<T>::pop_back()
2.算法复杂度为O(1)的有：
	bool empty()
	void clear()
	T& operator[](size_t index)
	size_t capacity() const
	size_t size() const
	~vector()
	vector<T>& operator=(const vector<T>& rhs)
3.没有资源泄露