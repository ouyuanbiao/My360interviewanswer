string 工程

请实现std::string类的主要功能。函数声明以及写作头文件中。部分实现也做了，但可能不完全正确。

请面试者实现这个类，并补充尽可能详尽的单元测试用例，越多越好，代码逻辑路径覆盖越全越好。

请认真对待，仔细考虑每一个细节问题。

1.算法复杂度是O(n)的有：
	string::string( const char* s )
	string::string( const char* s, size_t len )
	string::string( const string& rhs )
	string& string::operator=( const string& rhs )
	const char* string::data() const
2.算法复杂度是O(1)的有：
	string::string()
	string::~string()
	size_t string::size() const
	const char* string::c_str() const
	char* string::operator[]( size_t index )
3.没有资源泄露