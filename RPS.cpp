//사용자와 컴퓨터와의 가위바위보 게임 대결을 구현한다.
//인터페이스는 자유 형식이며, 이길 경우 상대방 HP 중 10을 가져온다.
//프로그램은 사용자의 이름과 HP 컴퓨터의 이름과 HP를 필수적으로
//턴마다 보여줘야 하며, 컴퓨터는 가위바위보를 랜덤하게 선택하도록 한다.
//초기 HP는 각각 50씩 가지며, 누군가의 HP가 0이 될 경우 상대방이
//이긴 것을 표시해 주어야 한다.
//Player 는 class 로 구현하고, HP 를 private 변수로 가지고 있어야 한다.
//캡슐화의 개념을 반드시 넣을 수 있도록 한다.

#include <iostream>				// C++기본입출력헤더
#include <ctime>				// random메소드쓰기위해서
#include <cstring>				// string 쓰기 위해서
#include <string.h>				// 혹시 몰라서...
#pragma warning(disable : 4996) // 보안 취약점문제 해결 코드

using namespace std; // std:: 생략

class Player // Player클래스
{
private:		// 캡슐화를 위해서 private
	int hp;		// hp를 넣음
	char *name; // 이름도
public:
	Player(const char *myname) : hp(50) // Player기본 생성자 hp는 이니셜라이져로
	{
		srand(time(NULL)); // 생성자로 생성될때 seed값을 생성해주어야함 그래야지 계속 랜덤값 생성됨
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
	}
	char *getName() { return name; } // 이름반환메소드
	int getHP() { return hp; }		 // hp반환 메소드(함수에서 접근해야됨 private)이라서
	void win() { hp += 10; }		 // 이겼을때
	void lost() { hp -= 10; }		 // 졌을때
	int RockPaperScissors()			 // 주먹가위보 랜덤함수
	{
		int num;
		num = rand() % 3;
		return num;
	}
	void Status() // 상태출력 메소드
	{
		cout << this->getName() << "의 hp는 " << this->getHP() << "입니다." << endl;
	}
	void Play(Player &x) // Play하는 함수
	{
		int total = 1; // 횟수 카운팅 몇판 했나..
		cout << "Computer와 User의 가위바위보게임!" << endl;
		cout << "User와 Computer의 초기 HP은 50입니다. (이기면 HP+10, 지면 HP-10)" << endl;
		while (1) // 무한루프
		{
			if (this->getHP() == 0 || x.getHP() == 0) // 반복탈출조건
			{
				if (this->getHP() == 0)
				{
					cout << endl
						 << x.getName() << " 가 승리하였습니다!!" << endl;
				}
				else if (x.getHP() == 0)
				{
					cout << endl
						 << this->getName() << " 가 승리하였습니다!!" << endl;
				}
				exit(1);
			}
			int num; // user
			cout << endl
				 << total << " 번째 가위,바위,보 게임중...." << endl;
			cout << "가위(0), 바위(1), 보(2) 중 무엇을 내시겠습니까? : ";
			cin >> num;
			int com_num = this->RockPaperScissors(); // computer의 주먹,가위,보를 com_num변수에 저장함( 함수로써 계속 호출하면 if문안에서 비교할때마다 값이 바뀜 )
			if (num == 0 && com_num == 0)			 // 비겼을때
			{
				cout << "비겼습니다" << endl;
				x.Status();
				this->Status();
			}
			if (num == 0 && com_num == 1) // 컴퓨터가 이겼을때
			{
				cout << "컴퓨터가 이겼습니다" << endl;
				x.lost();
				this->win();
				x.Status();
				this->Status();
			}
			if (num == 0 && com_num == 2) // User가 이겼을때
			{
				cout << "당신이 이겼습니다" << endl;
				x.win();
				this->lost();
				x.Status();
				this->Status();
			}
			if (num == 1 && com_num == 1)
			{
				cout << "비겼습니다" << endl;
				x.Status();
				this->Status();
			}
			if (num == 1 && com_num == 0)
			{
				cout << "당신이 이겼습니다" << endl;
				x.win();
				this->lost();
				x.Status();
				this->Status();
			}
			if (num == 1 && com_num == 2)
			{
				cout << "컴퓨터가 이겼습니다" << endl;
				x.lost();
				this->win();
				x.Status();
				this->Status();
			}
			if (num == 2 && com_num == 2)
			{
				cout << "비겼습니다" << endl;
				x.Status();
				this->Status();
			}
			if (num == 2 && com_num == 0)
			{
				cout << "컴퓨터가 이겼습니다" << endl;
				x.lost();
				this->win();
				x.Status();
				this->Status();
			}
			if (num == 2 && com_num == 1)
			{
				cout << "당신이 이겼습니다" << endl;
				x.win();
				this->lost();
				x.Status();
				this->Status();
			}
			total += 1; //반복문이 끝날때마다 횟수증가
		}
	}
};

int main()
{
	Player c("Computer"); // Computer라는 이름의 Player c생성
	Player u("User");	  // User라는 이름의 Player c생성
	c.Play(u);			  // 컴퓨터가 User랑 Play하는 함수상황 재현
	return 0;
}
