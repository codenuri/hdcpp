#include "monitor.h"

// command 패턴
// => 명령을 캡슐화해서 명령의 저장, 취소, 지연된 실행등을 가능하게 한다

// 메뉴 선택시 해야할 일을
// 함수로 만들면 : 특정 작업만 할수 있다.
// 객체로 만들면 : 특정 작업 + 취소 동작 + 취소를 위한 이전 상태 저장
//				  => 등을 할수 있다.

struct ICommand
{
	virtual void execute() = 0;
	virtual void undo() {}; // undo 는 선택
	virtual ~ICommand() {}
};


class BrightnessCommand 
{
	Monitor& m;
	int value;
	int old_value = 0;
public:
	BrightnessCommand(Monitor& m, int v) : m(m), value(v) {}

	void execute() 
	{ 
		old_value = m.get_set_brightness();
		m.set_brightness(value); 
	}
	void undo() { m.set_brightness(old_value); }
};

int main()
{
	Monitor m;

	// 동작 : 밝기 변경
	int old_value = m.get_set_brightness();
	m.set_brightness(90);

	// 좀전에 한 동작을 취소(undo) 하는 코드를 작성해 보세요
	m.set_brightness(old_value);



	BrightnessCommand cmd(m, 90);
	cmd.execute();
	cmd.undo();

}