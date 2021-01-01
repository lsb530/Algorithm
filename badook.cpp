//����ڿ��� �Է� ���� �ٵ����� ũ�⿡ �ٵϵ��� �����ϰ� �ְ� �� ���� ��
//������ �� �� �״��� �˷��ִ� ���α׷��� ����ÿ�(�� �ٵ����� ũ���
//	�ּ� 7 �̻� �̿��� �ϰ�, �𼭸��� ���� �̿����� �ʰ� �� �鵹���� �ѷ�
//	�׿� ���� ��츸 ����Ѵ�)

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int result = 0; // ����� ����������

void Fill(int **arr, int **isOk, int **checked, int r, int x, int y);  // �÷����ʾ˰����� ����ϰ� �̿�(����Լ�ȣ��) - DFS����
void check(int **arr, int **isOk, int **checked, int r, int x, int y); // Ȯ��

int main()
{
	int num;		   // ������ ������ ����
	srand(time(NULL)); // ���� seed��
	int r;			   // �����迭 ũ��� �ݺ��� ����
	std::cout << "�ٵ����� ũ�⸦ �Է��ϼ��� : ";
	std::cin >> r;
	std::cout << std::endl;

	//���� �迭 �Ҵ�
	int **arr;					  // 2���� �����͹迭
	int **checked = new int *[r]; // üũ�Ǳ����� 2���� �����͹迭
	int **isOk = new int *[r];	  // Ȯ���ϱ����� 2���� ������ �迭
	arr = new int *[r];
	checked = new int *[r];
	isOk = new int *[r];

	for (int i = 0; i < r; i++)
	{
		arr[i] = new int[r];
		checked[i] = new int[r];
		isOk[i] = new int[r];
	}

	//2�����迭 rand�̿��ؼ� �� ���� , checked���� 0�� isOk���� 1�� ����
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < r; j++)
		{
			num = rand() % 2;
			arr[i][j] = num;
			checked[i][j] = 0;
			isOk[i][j] = 1;
		}
	}

	//2�����迭 0���� 1���� ������ �浹,�鵹 ���
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < r; j++)
		{
			if (arr[i][j] == 0)
			{
				std::cout << "��";
			}
			else if (arr[i][j] == 1)
			{
				std::cout << "��";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	//�鵹�� �浹 ��� �� : �÷����� �˰���, DFS, ���ȣ�� ���� �ִ��� �̿���.
	for (int i = 0; i < r; i++)
	{
		Fill(arr, isOk, checked, r, i, 0);
		Fill(arr, isOk, checked, r, 0, i);
		Fill(arr, isOk, checked, r, r - 1, i);
		Fill(arr, isOk, checked, r, i, r - 1);
	}

	for (int i = 1; i < r - 1; i++)
	{
		for (int j = 1; j < r - 1; j++)
		{
			check(arr, isOk, checked, r, i, j);
		}
	}

	std::cout << "�� ���� " << result << " �� �׾����ϴ�" << std::endl;
	for (int i = 0; i < r; i++)
	{
		delete[] arr[i];
		delete[] checked[i];
		delete[] isOk[i];
	}
	delete[] arr;
	delete[] checked;
	delete[] isOk;
}

void Fill(int **arr, int **isOk, int **checked, int r, int x, int y)
{

	if (x >= r || x < 0 || y >= r || y < 0)
		return;

	isOk[x][y] = 0;

	if (checked[x][y])
		return;
	else
	{
		checked[x][y] = 1;
	}
	if (arr[x][y] == 1)
		return;

	Fill(arr, isOk, checked, r, x - 1, y);
	Fill(arr, isOk, checked, r, x + 1, y);
	Fill(arr, isOk, checked, r, x, y - 1);
	Fill(arr, isOk, checked, r, x, y + 1);
}

void check(int **arr, int **isOk, int **checked, int r, int x, int y)
{

	if (x >= r || x < 0 || y >= r || y < 0)
		return;

	if (checked[x][y])
		return;
	else
	{
		checked[x][y] = 1;
	}
	if (arr[x][y] == 1)
		return;
	if (isOk[x][y] == 0)
		return;

	result++;

	check(arr, isOk, checked, r, x - 1, y);
	check(arr, isOk, checked, r, x + 1, y);
	check(arr, isOk, checked, r, x, y - 1);
	check(arr, isOk, checked, r, x, y + 1);
}