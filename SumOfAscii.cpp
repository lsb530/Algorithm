//사용자에게 입력 받은 문자열의 아스키코드 값을 모두 더하여 출력하는
//프로그램을 만들어라.단 각 문자의 아스키코드 값을 모두 아래와 같이
//표시해야 하며, 입력되는 문자에 공백은 없는 것으로 가정하고, 최소 5
//이상 모든 길이의 문자열을 받을 수 있어야 한다.

#include <iostream>	 // C++ 기본 입출력헤더
#include <string>	 // string 이용하기위해서
using namespace std; // std:: 생략
int main()
{
	string a;
	int sum = 0;
	cout << "문자열을 입력하세요 : ";
	cin >> a;
	if (a.length() <= 4) // string길이가 4이하이면 종료
	{
		cout << "5자리수 이상의 글자를 입력해주세요" << endl;
		exit(1);
	}
	for (int i = 0; i < a.length(); i++) // string을 배열로 짜름 .. 0부터 길이까지 하나씩..
	{
		sum += (int)(a.at(i)); // 하나씩 int로 쪼개서 sum에 저장
		cout << int(a.at(i));  // 하나씩 출력
		{
			if (i < a.length() - 1)
			{
				cout << " + ";
			} // 길이가 끝에 닿기전까진 +로 출력
			else
			{
				cout << " = " << sum << endl;
			} // 끝이면 =로 출력
		}
	}
	return 0;
}