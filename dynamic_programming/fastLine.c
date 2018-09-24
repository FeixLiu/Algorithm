/*two working lines and each line has n machines presented as i, j
  operating time of each machine is presented as a[i][j]
  time to switch between lines is presented as t[i][j] (from machien i, j to machine (i + 1) % 2, j + 1)
  no extra time if not change line*/

voit fastLine(int n, int** a, int** t)
{
	int M[0][n + 1];
	int i, j;
	for(i = 0; i < 2; i ++)
		for(j = 0; j < n + 1; j ++)
			M[i][j] = INT_MAX;
	M[0][0] = t[0][0] + a[0][0];
	M[0][1] = t[0][1] + a[0][1];
	for(j = 1; j < n; j ++)
		for(i = 0; i < 2; i ++)
			M[i][j] = min(M[i][j - 1] + a[i][j], M[(i + 1) % 2][j - 1] + a[i][j] + t[(i + 1) % 2][j - 1]);
	M[0][n + 1] = M[0][n] + t[0][n];
	M[1][n + 1] = M[1][n] + t[1][n];
	i = M[0][n + 1] > M[1][n + 1] ? 1 : 0;
	j = n + 1;
	printf("%d\t", M[i][j]);
	j = n;
	printf("%d %d\n",i, j);
	while(j > 0)
	{
		if(M[i][j - 1] + a[i][j] == M[i][j])
			j --;
		else
			i = (i + 1) % 2, j --;
		printf("%d\t%d %d", M[i][j], i, j);
	}
}