template<typename T>
class vector
{
public:
	void resize(int n)
	{
		// 버퍼 크기가 부족해서 다시 할당하려고 합니다.
		// 어떻게 할당할까요 ?
		// C++에서는 메모리를 할당하는 방법이 아주 많이 있습니다.
		// new / malloc / system call / windows api/ 풀링 

		// 변하지 않는 것 : resize 알고 리즘
		// 변하는 것      : 메모리를 할당/해지 하는 방법
		// => 해결책 :  메모리를 할당/해지 를 분리
	}
};

int main()
{
	
}