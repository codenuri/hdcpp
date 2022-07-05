#include <iostream>

int main()
{
	int cnt = 0;
	std::cout << "학생수는 >> ";
	std::cin >> cnt;

	// 3. 입력된 학생수 만큼 다시 점수를 입력 받아야 합니다.
//	int score[cnt]; // error. 배열의 크기로 변수를 사용할수 없다.

	// 원하는 시간에, 원하는 크기(변수값) 만큼 자유롭게 할당할수 있는 유일한 메모리공간
	// => 힙(heap), 자유기억공간이라고도 합니다.

//	int* score = (int*)malloc(sizeof(int) * cnt); // C 스타일

	int* score = new int[cnt]; // C++

	for (int i = 0; i < cnt; i++)
	{
		std::cin >> score[i];
	}

	// 사용후에는 꼭 지워야 합니다.
	delete[] score;

}




