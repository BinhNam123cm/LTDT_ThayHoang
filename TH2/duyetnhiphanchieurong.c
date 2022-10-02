#include<stdio.h>
/* Khai bao Queue */
#define MAX_ELEMENTS 100
#define MAX_VERTEXES 100
typedef struct {
	int u, p;
} ElementType;
typedef struct {
	ElementType data[MAX_ELEMENTS];
	int front, rear;
} Queue;
/*Khoi tao Queue*/
void make_null_queue(Queue* Q) {
	Q->front = 0;
	Q->rear = -1;
}
/*Them phan tu vao Queue*/
void push(Queue* Q, ElementType x) {
	Q->rear++;
	Q->data[Q->rear] = x;
}

ElementType top(Queue* Q) {
	return Q->data[Q->front];
}
void pop(Queue* Q) { 
	Q->front++;
}
int empty(Queue* Q) {
	return Q->front > Q->rear;
}

#define max 100
typedef struct {
	int n;
	int a[max][max];
} Graph;

void init_graph(Graph *g, int n){
	g->n=n;
	
	int i, j;
	for(i=1;i<=g->n; i++){
		for(j=1;j<=g->n;j++){
			g->a[i][j] = 0;
		}
	}
}

void add_edge(Graph *g, int x, int y){
	g->a[x][y] = 1;
	g->a[y][x] = 1;
}

int adjacent(Graph *g, int x, int y){
	return g->a[x][y] != 0;
}

int mark[max];
int parent[max];
//typedef struct{
//	int k;
//	int t;
//} sx;
void swap(Queue *x, Queue *y){
	sx t;
	t = *x;
	*x = *y;
	*y = t;
}

void NoiBot(Queue *l, int n){
	int x, y;
	for(x = 0; x<=n-2; x++){
		for(y = n-1; y>=x+1; y--){
			if(l[y].t < l[y - 1].t){
				swap(&l[y], &l[y-1]);
			}
		}
	}
	
}
int lenght;

Queue BFS(Graph *g, int s){
	Queue q, l;
	make_null_queue(&q);
	make_null_queue(&l);
	
	ElementType pair;
	pair.u = s;
	pair.p = 0;
	push(&q, pair);

	
	int i = 0;
	while(!empty(&q)){
		ElementType pair = top(&q);
		pop(&q);
		int u = pair.u, p=pair.p;
		if(mark[u]!=0)
			continue;
		
		mark[u] = 1;
		parent[u] = p;
		
	//	l[i].t = u; l[i].k = parent[u];
	//	printf("%d %d\n", u, parent[u]);
		i++;
		int v;
		for(v=0; v<=g->n; v++){
			if(adjacent(g, u, v)){
				ElementType pair;
				pair.u = v; pair.p = u;
				push(&q, pair);
			}				
		}
	}
    lenght = i;
    	int j;
    		NoiBot(&q, i);
	for(j=0;j<lenght;j++){
		printf("%d %d\n", l[j].t, l[j].k);
	}

	
}

int connected(Graph *g){
	int u;
	for(u=1;u<=g->n; u++) {
		mark[u] = 0;
	}
	sx *l;
	BFS(g, 1, l);
	for(u=1; u<=g->n; u++){
		if(mark[u] == 0){
			return 0;
		}
	}
	return 1;
}

int main(){
	freopen("dt.txt", "r", stdin); 
	Graph G;
	sx *l;
	l = (sx*)malloc(sizeof(sx));
	int n, m, u, v, w, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	for(u=1;u<=G.n; u++) {
		mark[u] = 0;
	}
	int cnt = 0;
	for(u=1;u<=G.n; u++) {
		if(mark[u]==0){
			BFS(&G,u,l);
			cnt++;	
		}
	}
//	NoiBot(l, lenght);
//		int j;
//	for(j=0;j<lenght;j++){
//		printf("%d %d\n", l[j].t, l[j].k);
//	}
	return 0;
}



















