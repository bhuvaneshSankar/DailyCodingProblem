void printSpiral(int arr[10][10], int sr, int sc, int er, int ec){
    if(sr<=er && sc<=ec){
    int i, j;
    for(i=sr, j=sc; j<=ec ; j++){   //left to right
        printf("%d ", arr[i][j]);
    }
    for(i=sr+1, j=ec; i<=er; i++){  //up to down
        printf("%d ", arr[i][j]);
    }
    for(i=er, j=ec-1; sc!=er && j>=sc; j--){  //right to left
        printf("%d ", arr[i][j]);
    }
    for(i=er-1, j=sc; sr!=ec && i>sc; i--){   //down to up
        printf("%d ", arr[i][j]);
    }
    printSpiral(arr, sr+1, sc+1, er-1, ec-1);
    }
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--){
	    int i, j, m, n, arr[10][10];
	    scanf("%d %d", &m, &n);
	    for(i=0; i<m; i++)
	        for(j=0; j<n; j++)
	            scanf("%d", &arr[i][j]);
	   int sr = 0, sc = 0, er = m-1, ec = n-1;
       printSpiral(arr, sr, sc, er, ec);
       printf("\n");
	   
	}
	return 0;
}