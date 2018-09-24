void maxApple(int m, int n, int** A)
{
	int M[m][n];
	int i, j;
	for(i = 0; i < m; i ++)
		for(j = 0; j < n; j ++)
			M[i][j] = 0;
	for(i = 0; i < m; i ++)
		for(j = 0; j < n; j ++)
		{
			if(i ==0 && j == 0)
				M[i][j] = A[i][j];
			else if(i == 0 && j != 0)
				M[i][j] = M[i][j - 1] + A[i][j];
			else if(i != 0 && j == 0)
				M[i][j] = M[i - 1][j] + A[i][j];
			else if(i != 0 && j != 0)
				M[i][j] = M[i - 1][j] > M[i][j - 1] ? M[i - 1][j] + A[i][j] : M[i][j - 1] + A[i][j];
		}
	i = m, j = n;
	while(i >= 0 || j >= 0)
	{
		printf("%d\t%d %d\n", M[i][j], i, j);
		if(i == 0)
			j -= 1;
		else if(j == 0)
			i -= 1;
		else if(M[i - 1][j] + A[i][j] == M[i][j])
			i -= 1;
		else if(M[i][j - 1] + A[i][j] == M[i][j])
			j -= 1;
	}
}
