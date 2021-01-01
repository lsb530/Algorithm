//사용자에게 입력 받은 바둑판의 크기에 바둑돌을 랜덤하게 넣고 흑 돌이 백
//돌에게 몇 개 죽는지 알려주는 프로그램을 만드시오(단 바둑판의 크기는
//	최소 7 이상 이여만 하고, 모서리나 변은 이용하지 않고 꼭 백돌에게 둘러
//	쌓여 죽은 경우만 계산한다)

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int result = 0; // 결과값 전역변수로

void Fill(int **arr, int **isOk, int **checked, int r, int x, int y);  // 플러드필알고리즘을 비슷하게 이용(재귀함수호출) - DFS일종
void check(int **arr, int **isOk, int **checked, int r, int x, int y); // 확인

int main()
{
	int num;		   // 랜덤값 저장할 변수
	srand(time(NULL)); // 랜덤 seed값
	int r;			   // 동적배열 크기와 반복문 끝값
	std::cout << "바둑판의 크기를 입력하세요 : ";
	std::cin >> r;
	std::cout << std::endl;

	//동적 배열 할당
	int **arr;					  // 2차원 포인터배열
	int **checked = new int *[r]; // 체크되기위한 2차원 포인터배열
	int **isOk = new int *[r];	  // 확인하기위한 2차원 포인터 배열
	arr = new int *[r];
	checked = new int *[r];
	isOk = new int *[r];

	for (int i = 0; i < r; i++)
	{
		arr[i] = new int[r];
		checked[i] = new int[r];
		isOk[i] = new int[r];
	}

	//2차원배열 rand이용해서 값 저장 , checked에는 0을 isOk에는 1을 저장
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

	//2차원배열 0인지 1인지 따져서 흑돌,백돌 출력
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < r; j++)
		{
			if (arr[i][j] == 0)
			{
				std::cout << "○";
			}
			else if (arr[i][j] == 1)
			{
				std::cout << "●";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	//백돌이 흑돌 잡는 논리 : 플러드필 알고리즘, DFS, 재귀호출 등을 최대한 이용함.
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

	std::cout << "흑 돌이 " << result << " 개 죽었습니다" << std::endl;
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