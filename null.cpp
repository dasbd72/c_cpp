#include<iostream>
using namespace std;
class test{
	public:
		test(){
			num  = 0;
		}
		void set(int num){
			cout << num << endl;
			num = num;
			cout << this->num << endl;
			test::num = num;
			cout << num << endl;
		}
	private:
		int num;
};
int main(){
	test x = test();
	x.set(100);
	// 100
	// 0
	// 100
}