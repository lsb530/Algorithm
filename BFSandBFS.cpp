#include <iostream>
#include <queue>
using namespace std;

vector <int> optimalSolution;
struct node
{
	int level;
	int profit;
	int weight;
	float bound;
	vector <int> k;
	bool operator<(const node &rhs) const {
		return (bound < rhs.bound);
	}
};

float bound(node u, int n, int W, vector<int> pVec, vector<int> wVec)
{
	int j = 0, k = 0;
	int totweight = 0;
	int result = 0;

	if (u.weight < W)
	{
		result = u.profit;
		j = u.level + 1;
		totweight = u.weight;

		while ((j < n) && (totweight + wVec[j] <= W))
		{
			totweight = totweight + wVec[j];
			result = result + pVec[j];
			j++;
		}
		k = j;
		if (k < n)
		{
			result = result + (W - totweight) * pVec[k] / wVec[k];
		}
		return result;
	}
	else
		return 0;
}

void print_a(queue<node> q)
{
	cout << "Queue[ ";
	while (!q.empty()) {
		cout << q.front().profit << ' ';
		//cout << q.front().bound << ' ';
		q.pop();
	}
	cout << "]" << endl;
}

void print_b(priority_queue<node> q)
{
	cout << "Priority Queue[ ";
	while (!q.empty()) {
		//cout << q.front().profit << ' ';
		printf("%.1f ", q.top().bound);
		//cout << q.top().bound << ' ';
		q.pop();
	}
	cout << "]" << endl;
}

void Best_First_Search_knapsack(int n, int p[], int w[], int W)
{
	priority_queue<node> Q;
	int number_of_node = 1;
	int optSize = 0;
	node u, v;
	vector<int> pV;
	vector<int> wV;
	v.level = -1;
	for (int i = 0; i < n; i++)
	{
		pV.push_back(p[i]);
		wV.push_back(w[i]);
	}
	v.profit = 0;
	v.weight = 0;
	v.bound = 115.0f;
	v.k.resize(n + 1, 0);
	u.k.resize(n + 1, 0);
	int maxProfit = 0;
	Q.push(v);
	while (!Q.empty())
	{
		v = Q.top();
		print_b(Q);
		Q.pop();
		if(v.bound > maxProfit)
			number_of_node += 2;
		if (v.level == -1)
			u.level = 0;
		else if (v.level != (n - 1))
			u.level = v.level + 1;
		
		u.weight = v.weight + w[u.level];
		u.profit = v.profit + p[u.level];
		u.k = v.k;
		u.k.at(u.level) = 1;
		if (u.weight <= W && u.profit > maxProfit) {
			maxProfit = u.profit;
			optimalSolution = u.k;
		}

		u.bound = bound(u, n, W, pV, wV);
		if (u.bound > maxProfit && u.weight < W) {
			Q.push(u);
		}
		u.weight = v.weight;
		u.profit = v.profit;
		u.k.at(u.level) = 0;
		u.bound = bound(u, n, W, pV, wV);
		if (u.bound > maxProfit && u.weight < W) {
			Q.push(u);
		}
		
	}

	for (int i = 0; i < optimalSolution.size(); i++)
	{
		if (optimalSolution.at(i) == 1)
			optSize++;
	}
	cout << "maxprofit = " << maxProfit << endl;
	cout << "expanded nodes = " << number_of_node << endl;
}



void Breadth_First_Search_knapsack(int n, int p[], int w[], int W)
{
	queue<node> Q;
	int number_of_node = 1;
	node u, v;
	vector<int> pV;
	vector<int> wV;
	for (int i = 0; i < n; i++)
	{
		pV.push_back(p[i]);
		wV.push_back(w[i]);
	}
	v.level = -1;
	v.profit = 0;
	v.weight = 0;
	v.bound = 115.0f;

	int maxProfit = 0;
	Q.push(v);
	while (!Q.empty())
	{
		v = Q.front();
		print_a(Q);
		Q.pop();

		if (v.level == -1)
			u.level = 0;
		else if (v.level != (n - 1))
			u.level = v.level + 1;
		// Left Child
		u.weight = v.weight + w[u.level];
		u.profit = v.profit + p[u.level];
		u.bound = bound(u, n, W, pV, wV);

		if (u.weight <= W && u.profit > maxProfit)
			maxProfit = u.profit;
		if (u.bound > maxProfit)
			Q.push(u);

		//Right Child
		u.weight = v.weight;
		u.profit = v.profit;
		u.bound = bound(u, n, W, pV, wV);

		if (u.bound > maxProfit)
			Q.push(u);

		number_of_node += 2;
	}
	cout << "maxprofit = " << maxProfit << endl;
	cout << "expanded nodes = " << number_of_node << endl;
}

int main()
{
	int n = 4, W = 16;
	int w[4] = { 2, 5, 10, 5 };
	int p[4] = { 40, 30, 50, 10 };

	cout << "컴퓨터소프트웨어학과  4학년  2015726100  이 승 복" << endl << endl;
	cout << "Breadth First" << endl;
	Breadth_First_Search_knapsack(n, p, w, W);
	cout << endl;
	cout << "Best First" << endl;
	Best_First_Search_knapsack(n, p, w, W);
	cout << endl;
}