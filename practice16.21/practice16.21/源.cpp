#include <iostream>
#include <memory>

using namespace std;

// ���������࣬�Ը���ָ��ִ��delete
class DebugDelete
{
public:
	DebugDelete(ostream &s=std::cerr):os(s){}
	// ���κκ���ģ����ͬ��T�������ɱ������ƶ�
	template <typename T> 
	void operator()(T *p) const{
		os << "deleting unique_ptr" << endl;
		delete p;
	}
private:
	ostream &os;
};

int main()
{
	unique_ptr<int, DebugDelete> p(new int, DebugDelete());
	unique_ptr<string, DebugDelete> sp(new string, DebugDelete());

	return 0;
}