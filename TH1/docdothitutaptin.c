#include<stdio.h>
#define m 100

typedef struct{
	int n;
	int a[m][m];
} Graph;

void init_g(Graph *g, int n) {
	int i,j;
	g->n=n;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			g->a[i][j]=0;
		}
	}
}

void add_e(Graph *g, int x, int y){
	g->a[x][y] = 1;
	g->a[y][x] = 1;
}

int main(){
	int e, u, v, n, b, i, j;
	Graph g;
	freopen("dt1.txt", "r", stdin);
	scanf("%d%d", &n, &b);
	
	init_g(&g, n);
	for(e=1; e<=n;e++)	{
		scanf("%d%d", &u, &v);
		add_e(&g, u, v);
	}
	
	for(i=1;i<=g.n; i++){
		for(j=1;j<=g.n;j++){
			printf("%d ", g.a[i][j]);
		}
		printf("\n");
	}
}


























