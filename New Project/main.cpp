#include <stdio.h>

bool isSubsetSum( int set[], int n,int sum)
{
	int i,j,k;
	bool subset[sum+1][n+1];
	for(i=0;i<=n;i++)
	{
		subset[0][i] = true;
	}
	for(i=1;i<=sum;i++)
	{
		subset[i][0] = false; 
	}
	for(i=1;i<=sum;i++)
	{
		for(j=1;j<=n;j++)
		{
			subset[i][j] = subset[i][j-1];
			if(i>=set[j-1])
			{
				subset[i][j] = subset[i][j] || subset[i-set[j-1]][j-1];
			}
		}
	}
	return subset[sum][n];
}

bool isSubsetSjum(int set[], int n, int sum)
{
	// The value of subset[i][j] will be true if there is a subset of set[0..j-1]
	// with sum equal to i
	bool subset[sum+1][n+1];

	// If sum is 0, then answer is true
	for (int i = 0; i <= n; i++)
	subset[0][i] = true;

	// If sum is not 0 and set is empty, then answer is false
	for (int i = 1; i <= sum; i++)
	subset[i][0] = false;

	// Fill the subset table in botton up manner
	for (int i = 1; i <= sum; i++)
	{
	for (int j = 1; j <= n; j++)
	{
		subset[i][j] = subset[i][j-1];
		if (i >= set[j-1])
		subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
	}
	}
	return subset[sum][n];
}

int main()
{
    int n,set[1000000];
    int x,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	scanf("%d",&set[i]);
    }
    scanf("%d",&x);
    if (isSubsetSum(set, n, x) == true)
	printf("True\n");
else
	printf("False\n");

    return 0;
}
