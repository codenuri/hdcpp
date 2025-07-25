#include <iostream>

void hoo(int&& arg) {} 


template<typename F>
void chronometry(F f, int& arg)
{
	f(arg); 
}

// main					chronometry					 hoo(int&&)
// hoo(10) ==============================================> ok
// chronometry(10) ======> int&& arg = 10;
//						   hoo(arg) 인데, arg는 lvalue====> error	
//						   hoo(static_cast<int&&>(arg))===> ok
template<typename F>
void chronometry(F f, int&& arg)
{
//	f(arg); 

	// 이함수의 인자는 원래 rvalue 였는데, 받으면서 이름이 생겼다(arg)
	// 즉, lvalue 가 되었다.
	// 원래 함수로 forwarding 할때는 다시 ralue 로 변경해서 전달
	f(static_cast<int&&>(arg)); 
}

int main()
{
	hoo(10);	
	chronometry(hoo, 10);  
}
