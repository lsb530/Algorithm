//����ڿ� ��ǻ�Ϳ��� ���������� ���� ����� �����Ѵ�.
//�������̽��� ���� �����̸�, �̱� ��� ���� HP �� 10�� �����´�.
//���α׷��� ������� �̸��� HP ��ǻ���� �̸��� HP�� �ʼ�������
//�ϸ��� ������� �ϸ�, ��ǻ�ʹ� ������������ �����ϰ� �����ϵ��� �Ѵ�.
//�ʱ� HP�� ���� 50�� ������, �������� HP�� 0�� �� ��� ������
//�̱� ���� ǥ���� �־�� �Ѵ�.
//Player �� class �� �����ϰ�, HP �� private ������ ������ �־�� �Ѵ�.
//ĸ��ȭ�� ������ �ݵ�� ���� �� �ֵ��� �Ѵ�.

#include <iostream>				// C++�⺻��������
#include <ctime>				// random�޼ҵ徲�����ؼ�
#include <cstring>				// string ���� ���ؼ�
#include <string.h>				// Ȥ�� ����...
#pragma warning(disable : 4996) // ���� ��������� �ذ� �ڵ�

using namespace std; // std:: ����

class Player // PlayerŬ����
{
private:		// ĸ��ȭ�� ���ؼ� private
	int hp;		// hp�� ����
	char *name; // �̸���
public:
	Player(const char *myname) : hp(50) // Player�⺻ ������ hp�� �̴ϼȶ�������
	{
		srand(time(NULL)); // �����ڷ� �����ɶ� seed���� �������־���� �׷����� ��� ������ ������
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
	}
	char *getName() { return name; } // �̸���ȯ�޼ҵ�
	int getHP() { return hp; }		 // hp��ȯ �޼ҵ�(�Լ����� �����ؾߵ� private)�̶�
	void win() { hp += 10; }		 // �̰�����
	void lost() { hp -= 10; }		 // ������
	int RockPaperScissors()			 // �ָ԰����� �����Լ�
	{
		int num;
		num = rand() % 3;
		return num;
	}
	void Status() // ������� �޼ҵ�
	{
		cout << this->getName() << "�� hp�� " << this->getHP() << "�Դϴ�." << endl;
	}
	void Play(Player &x) // Play�ϴ� �Լ�
	{
		int total = 1; // Ƚ�� ī���� ���� �߳�..
		cout << "Computer�� User�� ��������������!" << endl;
		cout << "User�� Computer�� �ʱ� HP�� 50�Դϴ�. (�̱�� HP+10, ���� HP-10)" << endl;
		while (1) // ���ѷ���
		{
			if (this->getHP() == 0 || x.getHP() == 0) // �ݺ�Ż������
			{
				if (this->getHP() == 0)
				{
					cout << endl
						 << x.getName() << " �� �¸��Ͽ����ϴ�!!" << endl;
				}
				else if (x.getHP() == 0)
				{
					cout << endl
						 << this->getName() << " �� �¸��Ͽ����ϴ�!!" << endl;
				}
				exit(1);
			}
			int num; // user
			cout << endl
				 << total << " ��° ����,����,�� ������...." << endl;
			cout << "����(0), ����(1), ��(2) �� ������ ���ðڽ��ϱ�? : ";
			cin >> num;
			int com_num = this->RockPaperScissors(); // computer�� �ָ�,����,���� com_num������ ������( �Լ��ν� ��� ȣ���ϸ� if���ȿ��� ���Ҷ����� ���� �ٲ� )
			if (num == 0 && com_num == 0)			 // �������
			{
				cout << "�����ϴ�" << endl;
				x.Status();
				this->Status();
			}
			if (num == 0 && com_num == 1) // ��ǻ�Ͱ� �̰�����
			{
				cout << "��ǻ�Ͱ� �̰���ϴ�" << endl;
				x.lost();
				this->win();
				x.Status();
				this->Status();
			}
			if (num == 0 && com_num == 2) // User�� �̰�����
			{
				cout << "����� �̰���ϴ�" << endl;
				x.win();
				this->lost();
				x.Status();
				this->Status();
			}
			if (num == 1 && com_num == 1)
			{
				cout << "�����ϴ�" << endl;
				x.Status();
				this->Status();
			}
			if (num == 1 && com_num == 0)
			{
				cout << "����� �̰���ϴ�" << endl;
				x.win();
				this->lost();
				x.Status();
				this->Status();
			}
			if (num == 1 && com_num == 2)
			{
				cout << "��ǻ�Ͱ� �̰���ϴ�" << endl;
				x.lost();
				this->win();
				x.Status();
				this->Status();
			}
			if (num == 2 && com_num == 2)
			{
				cout << "�����ϴ�" << endl;
				x.Status();
				this->Status();
			}
			if (num == 2 && com_num == 0)
			{
				cout << "��ǻ�Ͱ� �̰���ϴ�" << endl;
				x.lost();
				this->win();
				x.Status();
				this->Status();
			}
			if (num == 2 && com_num == 1)
			{
				cout << "����� �̰���ϴ�" << endl;
				x.win();
				this->lost();
				x.Status();
				this->Status();
			}
			total += 1; //�ݺ����� ���������� Ƚ������
		}
	}
};

int main()
{
	Player c("Computer"); // Computer��� �̸��� Player c����
	Player u("User");	  // User��� �̸��� Player c����
	c.Play(u);			  // ��ǻ�Ͱ� User�� Play�ϴ� �Լ���Ȳ ����
	return 0;
}
