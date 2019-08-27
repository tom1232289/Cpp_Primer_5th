#include <iostream>
#include <memory>

using namespace std;

// 函数对象类，对给定指针执行delete
class DebugDelete
{
public:
	DebugDelete(ostream &s=std::cerr):os(s){}
	// 与任何函数模板相同，T的类型由编译器推断
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