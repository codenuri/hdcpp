#include <iostream>
#include <algorithm>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>

int main()
{
	std::set<std::string> s = {"BB", "AA", "CC"}; // 문자열들을 보관

	// set : key(한개의 데이타)를 여러개 보관
	// map : key-value 를 여러개 보관

	std::map<std::string, std::string> m = { {"mon", "월요일"}, 
											 {"tue", "화요일"} };

	// 아래 처럼 넣어도 됩니다.
	m["wed"] = "수요일"; // {"wed", "수요일"}

	std::cout << m["mon"] << std::endl; // "월요일"

	// 위 코드는 마치 영한 사전 같아 보입니다.
	// 그래서 다른 언어는 map 을 "dictionary"라고도 합니다.
}





