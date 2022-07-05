#include <iostream>

// 클래스를 만들지 말고, 클래스를 찍어낼때 사용할 "틀(템플릿)"을 제공하자.
// 함수 뿐 아니라 "클래스도 템플릿"으로 할수 있습니다.
namespace util
{
	template<typename T>
	class vector
	{
		T* ptr;
		int  sz;
	public:
		vector(int n, T value = 0)
		{
			sz = n;
			ptr = new T[sz];

			for (int i = 0; i < sz; i++)
			{
				ptr[i] = value;
			}
		}
		~vector() { delete[] ptr; }

		T& at(int idx) { return ptr[idx]; }


		void resize(int newsize)
		{
			if (newsize > sz)
			{
				T* tmp = new T[newsize];

				memcpy(tmp, ptr, sizeof(T) * sz);

				delete[] ptr;

				ptr = tmp;

				sz = newsize;
			}
			else
			{
			}
		}

		int size() { return sz; }
		bool empty() { return sz == 0; }
	};
}



int main()
{
//	vector v1(5, 3); // error. 클래스 템플릿은 타입인자를 반드시 
					//         전달해야 합니다.
	util::vector<int>    v1(5, 3);
	util::vector<double> v2(5, 3.1);

	v1.at(0) = 10;
	v1.resize(10);
	std::cout << v1.at(0) << std::endl;
	std::cout << v1.size() << std::endl;

}