#include<iostream>
using namespace std;
class test{
	public:
		test(){
			num  = 0;
		}
		int get(){
			return num;
		}
		void add(){
			num++;
		}
	private:
		int num;
};
int main(){
	test x = test();
	cout << x.get() << endl;
	x.add();
	cout << x.get() << endl;
}