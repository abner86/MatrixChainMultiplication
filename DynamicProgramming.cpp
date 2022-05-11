#include <iostream>
#include <vector>
using namespace std;

void OptimalParentheses(const vector<vector<int>>& S, int i, int j) {
	if (i == j) {
		std::cout << (char)(i + 65);
	}
	else {
		std::cout << "(";
		OptimalParentheses(S, i, S[i][j]);
		OptimalParentheses(S, S[i][j] + 1, j);
		std::cout << ")";
	}
}

void MatrixChainMultiplication(const vector<int>& dims)
{
	int n = dims.size();

	vector<vector<int>> Opt;
	for (int i = 0; i < n + 1; i++) {
		vector<int> tempV;
		for (int j = 0; j < n + 1; j++) {
			tempV.push_back(0);
		}
		Opt.push_back(tempV);
	}

	vector<vector<int>> S;
	for (int i = 0; i < n + 1; i++) {
		vector<int> tempV;
		for (int j = 0; j < n + 1; j++) {
			tempV.push_back(0);
		}
		S.push_back(tempV);
	}

	for (int i = 1; i <= n; i++)
	{
		Opt[i][i] = 0;
		S[i][i] = 0;
	}

	for (int len = 2; len <= n; len++)
	{
		for (int i = 1; i <= n - len; i++)
		{
			int j = i + len - 1;
			Opt[i][j] = INT_MAX;
			for (int k = i; j < n && k <= j - 1; k++)
			{
				int cost = Opt[i][k] + Opt[k + 1][j] + (dims[i - 1] * dims[k] * dims[j]);
				if (cost < Opt[i][j]) {
					Opt[i][j] = cost;
					S[i][j] = k;
				}
			}
		}
	}

	std::cout << "m = ";
	cout << "\n";

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			std::cout << Opt[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "\n";

	std::cout << "s = ";
	cout << "\n";

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			std::cout << S[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "Order: ";
	OptimalParentheses(S, 0, n - 2);
	cout << endl;

	std::cout << "Cost: " << Opt[1][n - 1] << "\t";
	cout << endl;
}

int main()
{
	vector<int> matrix = { 3, 7, 4, 20, 5 };
	MatrixChainMultiplication(matrix);
}