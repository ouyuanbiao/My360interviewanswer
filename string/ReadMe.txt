string ����

��ʵ��std::string�����Ҫ���ܡ����������Լ�д��ͷ�ļ��С�����ʵ��Ҳ���ˣ������ܲ���ȫ��ȷ��

��������ʵ������࣬�����価�����꾡�ĵ�Ԫ����������Խ��Խ�ã������߼�·������ԽȫԽ�á�

������Դ�����ϸ����ÿһ��ϸ�����⡣

1.�㷨���Ӷ���O(n)���У�
	string::string( const char* s )
	string::string( const char* s, size_t len )
	string::string( const string& rhs )
	string& string::operator=( const string& rhs )
	const char* string::data() const
2.�㷨���Ӷ���O(1)���У�
	string::string()
	string::~string()
	size_t string::size() const
	const char* string::c_str() const
	char* string::operator[]( size_t index )
3.û����Դй¶