#include <iostream>

int main()
{
	// 4. 사용자가 -1을 입력할때 까지 계속 입력 받고 싶습니다.
	//   단, 입력된 모든 값은 보관되어 있어야 합니다.

//	int score[4]; // 최초 버퍼를 이렇게 만들면 필요없을때 지울수 없습니다.
				  // 지역변수의 수명은 "정해진 규칙" 대로만 파괴됩니다.

	int size = 4;
	int* score = new int[size]; // 동적메모리 할당
							 // => 사용자가 원할때 지울수 있다(아주 자유롭다)

	int count = 0; // 입력된 갯수



	int n = 0;

	while (1)
	{
		std::cin >> n;

		if (n == -1)
			break;

		score[count] = n; // 보관
		++count;
	}
}

