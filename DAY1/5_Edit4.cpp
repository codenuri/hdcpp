// Edit 예제 정리 - 34page ~

// Edit2.cpp
// => 변하는 것을 가상함수로 - template method
// => 파생 클래스를 만들어서 가상 함수 재정의

// 특징 #1. NumEdit 가 Validation 정책을 소유 한다.
// => Edit 기능 + Validation 기능
// => 다름 입력 도구에서 NumEdit 의 Validation 정책 사용못함

//특징 #2. 실행시간에 정책을 변경할수 없다.




// Edit3.cpp
// => 변하는 것을 다른 클래스로 - strategy 패턴

// 특징 #1. LimitDigitValidator 는 validation 정책만 있다.
// => edit 기능은 없음.
// => 다양한 입력 도구에서 validation 정책 사용가능

// 특징 #2. 실행시간에 validation 정책 교체 가능


//-----------------
// 하지만 "도형편집기예제에서" Rect 의 draw_imp 는

// => 사각형을 어떻게 그릴지는 "사각형만" 사용하면된다.
// => 사각형을 그리는 법은 "변하지 않는다."
// 이 경우는 template method가 좋다
// => template method 는 멤버 함수로 변하는 것 구현
// => 그림을 그리려면 "private멤버 데이타"접근필요!!
//    멤버 함수가 좋습니다.
