// ��ϰ7.30��ͨ��thisָ��ʹ�ó�Ա��������Ȼ�Ϸ��������е���ࡣ������ʽ��ʹ��ָ����ʳ�Ա����ȱ�㡣
#include<iostream>
#include<string>
using namespace std;
class Sales_data {
private:
	string bookNo;
	unsigned units_sold = 0;
	double sellingprice = 0.0;//ԭʼ�۸�
	double saleprice = 0.0;//ʵ�ۼ۸�
	double discount = 0.0;//�ۿ�
public:
	string isbn() const { return this->bookNo; }
	Sales_data& combine(const Sales_data& rhs) {
		units_sold += rhs.units_sold;
		saleprice = (saleprice*units_sold + rhs.saleprice*rhs.units_sold) / (units_sold + rhs.units_sold);
		if (sellingprice != 0)
			discount = saleprice / sellingprice;
		return *this;
	}
};

// ������˼·���Ա�ʹ��thisָ����ʳ�Ա�����ס�

// �����ͨ��thisָ����ʳ�Ա���ŵ��ǣ����Էǳ���ȷ��ָ�����ʵ��Ƕ���ĳ�Ա�����ҿ����ڳ�Ա������ʹ�������ݳ�Աͬ�����βΣ�
//		   ȱ�����Եö��࣬���벻����ࡣ