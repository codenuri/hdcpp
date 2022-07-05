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
		
		if (count == size)
		{
			// 4개 더 큰 메모리 할당
			int* tmp = new int[size + 4];

			// 기존 버퍼의 내용을 새로운 버퍼에 옮겨 담기
			// score가 가리키는 곳의 메모리를
			// tmp 가 가리키는 곳의 메모리 로 복사
			memcpy(tmp, score, sizeof(int) * size);

			// 기존 버퍼 제거
			delete[] score; // score를 지우는게 아닙니다.
							// score가 가리키는곳 제거

			// score 포인터 변수가 새로운 메모리를 가리키도록
			score = tmp;

			// 마지막 남은 것은 ?
			size = size + 4;

		} // <= tmp 자체는 여기서 파괴
	}

	std::cout << "입력된 갯수    : " << count << std::endl;
	std::cout << "할당된 버퍼크기 : " << size << std::endl;

	for (int i = 0; i < count; i++)
	{
		std::cout << score[i] << std::endl;
	}

	delete[] score;
}
// 실행해서 9개쯤 입력하고 -1 입력해 보세요

// 위처럼 "필요할때 크기 변경이 가능하게 만드는 배열"을
// => 동적배열 또는 vector 라고 부릅니다. 
// => 자료구조에서 배우는 유명한 기술 입니다.

