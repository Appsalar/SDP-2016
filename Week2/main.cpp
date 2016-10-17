#include <iostream>

void swap(int v[], int i, int j) {
	int	t;

	t = v[i];
	v[i] = v[j];
	v[j] = t;
}

void print(int v[], int n)
{
	for (int i = 0; i < n; i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

void perm(int v[], int n, int k) {

	if (k == n) {
		print(v, n);
	}
	else
		for (int i = k; i<n; i++) {
			swap(v, k, i);
			perm(v, n, k + 1);
			swap(v, k, i);
		}
}

void heap_perm(int v[], int n, int maxN)
{
	if (n == 1)
	{
		print(v, maxN);
		return;
	}
	int i = 0;
	while (true)
	{
		heap_perm(v, n - 1, maxN);
		if (i == n - 1)
			break; //може и return
		if (n % 2 == 0)
			swap(v, i, n - 1);
		else
			swap(v, 0, n - 1);
		++i;
	}
}


void comb(int v[], int n, int maxK, int start = 1, int k = 0)
{
	if (k >= maxK)
	{
		print(v, maxK);
		return;
	}

	for (int i = start; i <= n; i++)
	{
		v[k] = i;
		comb(v, n, maxK, i + 1, k + 1); // i вместо i + 1 за повторения 
	}
}

void varMulti(int v[], int n, int maxK, int k = 0)
{
	if (k >= maxK)
	{
		print(v, maxK);
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		v[k] = i;
		varMulti(v, n, maxK, k + 1);
	}
}


int main()
{
	const int n = 5;
	int k = 2;
	int v[n];

	for (int i = 0; i < n; i++)
		v[i] = i + 1;
	//perm(v, n, 0);
	//heap_perm(v, n);
	//comb(v, n, k);
	varMulti(v, n, k);

	return 0;
}