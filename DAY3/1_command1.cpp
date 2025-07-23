#include "monitor.h"

class BrightnessCommand 
{
	Monitor& m;
	int value;
public:
	BrightnessCommand(Monitor& m, int v) : m(m), value(v) {}

	void execute() { m.set_brightness(value); }
};

int main()
{
	Monitor m;

	// 모니터의 밝기를 변경하고 싶다.
	// 방법 #1. 밝기를 변경하는 멤버함수 호출
	m.set_brightness(90);

	// 방법 #2. command 패턴 사용
}