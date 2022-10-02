#include<stdio.h>
/*khai bao Graph*/
#define max 100
typedef struct {
	int n;
	int a[max][max];
}Graph;
/*Khoi tao Graph*/
void init_graph(Graph *g, int n){
	int i, j;
	g->n=n;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			g->a[i][j]=0;
		}
	}
}
/*Them cung*/
void add_edge(Graph *g, int x, int y){
	g->a[x][y]=1;
	g->a[y][x]=1;
}
/* KHAI BAO VA DINH NGHIA CTDL DANH SACH */
#define MAX_ELEMENTS 100
typedef int ElementType;
typedef struct {
	ElementType data[MAX_ELEMENTS];
	int size;
} List;
/* Tao danh sach rong */
void make_null(List* L) {
	L->size = 0;
}
/* Them mot phan tu vao cuoi danh sach */
void push_back(List* L, ElementType x) {
	L->data[L->size] = x;
	L->size++;
}
/* Kiem tra y co ke voi x khong */
int adjacent(Graph* G, int x, int y) {
	return G->a[x][y] != 0;
}
/* Lay phan tu tai vi tri i, phan tu bat dau o vi tri 1 
*/
ElementType element_at(List* L, int i) {
return L->data[i-1];
}
/* Tim cac dinh ke cua dinh x */
List neighbors(Graph* G, int x) {
	int y;
	List list;
	make_null(&list);
	for (y = 1; y <= G->n; y++)
		if (adjacent(G, x, y))
		push_back(&list, y);
	return list;
}

/* Khai bao Queue */
#define MAX_ELEMENTS 100
#define MAX_VERTEXES 100
typedef struct {
	int data[MAX_ELEMENTS];
	int front, rear;
} Queue;
/*Khoi tao Queue*/
void make_null_queue(Queue* Q) {
	Q->front = 0;
	Q->rear = -1;
}
/*Them phan tu vao Queue*/
void push(Queue* Q, int x) {
	Q->rear++;
	Q->data[Q->rear] = x;
}

int top(Queue* Q) {
	return Q->data[Q->front];
}
void pop(Queue* Q) { 
	Q->front++;
}
int empty(Queue* Q) {
	return Q->front > Q->rear;
}

/*Tim kiem phan tu dau tien theo chieu rong*/
/*
void breath_first_search(Graph* G) {
	Queue frontier;
	int	mark[MAX_VERTEXES];
	make_null_queue(&frontier);

	int j;
	for (j = 1; j <= G->n; j++)
		mark[j] = 0;

	push(&frontier, 1);
	mark[1] = 1;

	while (!empty(&frontier)) {

		int x = top(&frontier); pop(&frontier);
		printf("%d\n", x);

		List list = neighbors(G, x);

		for (j = 1; j <= list.size; j++) {
			int y = element_at(&list, j);
			if (mark[y] == 0) {
				mark[y] = 1;
				push(&frontier, y);
			}
		} 
	} 
}
*/

//Duyet Theo chieu Rong
void breath_first_search(Graph* G){
	Queue H;
	int mark[MAX_VERTEXES];
	make_null_queue(&H);
	// khoi tao mark ( chua xet )
	int i,j;
	for (j=1;j <= G->n; j++) // duyet tu dinh 1 -> n
		mark[j] = 0;
	// dua 1 vao HD
	//printf("1 \n");
	for(i=1;i<=G->n;i++){
		if(mark[i]==1) // ki?m tra tính liên thông
		continue;
		push(&H,i);
		mark[i]=1;
		while (!empty(&H)){
		int x = top(&H); pop(&H);
		printf("%d \n",x);
	// kiem tra cac dinh ke
	List L = neighbors(G,x);
	for (j=1;j <= L.size; j++){
		int y = element_at(&L,j);
		if (mark[y] == 0) {
			mark[y] = 1;
			push(&H,y);
		}
	}
}}}


int main(){
	freopen("dt.txt", "r", stdin); 
	Graph G;
	int n, m, u, v, w, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	
	breath_first_search(&G);
	return 0;
}























