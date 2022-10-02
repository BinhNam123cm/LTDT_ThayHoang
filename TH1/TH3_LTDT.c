
//Phuong phap danh sach cung
//#include<stdio.h>
//#define MAX_M 500
//
//typedef struct {
//	itn u, v;
//}Edge;
//
//typedef struct {
//	int n, m;
//	Edge edges[MAX_M];
//} Graph;
//
//void init_graph(Graph *pG, int n){
//	pG->n = n;
//	pG->m = 0;
//}
//
//void add_edge(Graph *pG, int u, int v){
//	pG->edges[pG->m].u = u;
//	pG->edges[pG->m].v = v;
//	
//	pG->m++;
//}
//
//int degree(Graph *pG, int u){
//	int e, deg_u = 0;
//	for(e=0;e<pG->m; e++){
//		if(pG->edges[e].u == u)
//			deg_u++;
//		if(pG->edges[e].v==u)
//			deg_u++;
//	}
//	return deg_u;
//}

//Phuong phap ma tran dinh - dinh (ma tran ke)
//#include<stdio.h>
//#define MAX_N 100
//
//typedef struct {
//	int n;
//	int A[MAX_N][MAX_N];
//} Graph;
//
//void init_graph(Graph *pG, int n){
//	pG->n = n;
//	//so cung = 0
//	//pG->m = 0;
//	int u;
//	int v;
//	for( u = 1; u <= n; u++){
//		for( v = 1; v<=n; v++){
//			pG->A[u][v] = 0;
//		}
//	}
//}
//
//void add_edge(Graph *pG, int u, int v){
//	//co chua da cung
//	pG->A[u][v] += 1;
//	pG->A[v][u] += 1;
//	
//	//khong co chua da cung
////	pG->A[u][v] += 1;
////	pG->A[v][u] += 1;
////	
//	//DEM SO CUNG
//	//pG->m++;
//}
//
////kiem tra c co ke v hay khong
//int adjaccent(Graph *pG, int u, int v){
//	//return pG->A[u][v] > 0;
//	return pG->A[u][v] != 0;
//}
//
//////dinh khong co khuyen
////int degree(Graph *pG, int u){
////	int deg_u = 0,v;
////	for(v = 1; v<=pG->n; v++){
////		deg_u += pG->A[u][v];
////	}
////	return deg_u;
////}
//
//////dinh co khuyen
////int degree(Graph *pG, int u){
////	int deg_u = 0;
////	for(int v = 1; v<=pG->n; v++){
////		deg_u += pG->A[u][v];
////	}
////	return deg_u + pG->A[u][u];
////}
////khong da cung
////int degree(Graph* G, int x) {
////int y, deg = 0;
////for (y = 1; y <= G->n; y++)
////if (G->A[x][y] > 0)
////deg++;
////return deg;
////}
////co da cung
//int degree(Graph* G, int x) {
//int y, deg = 0;
//for (y = 1; y <= G->n; y++)
//deg += G->A[x][y];
//return deg;
//}
//int main(){
//	Graph g;
////	int n, m, u, v,e;
////	scanf("%d%d", &n, &m);
////	init_graph(&g, n);
////	
////	for(e = 0; e<m; e++){
////		scanf("%d%d", &u, &v);
////		add_edge(&g, u, v);
////	}
////	printf("\n");
////	for( u = 1; u<=g.n; u++){
////		for(v = 1; v<=g.n;v++){
////			printf("%d\n", g.A[u][v]);
////		}
////		printf("\n");
////	}
//int n =4,v;
//
//	init_graph(&g, n);
//	add_edge(&g,1,2);
//	add_edge(&g,1,3);
//	add_edge(&g,1,3);
//	add_edge(&g,3,4);
//	add_edge(&g,1,4);
//	printf("\n");
//		for (v=1;v<=n;v++){
//		printf("deg(%d) = %d\n", v, degree(&g, v));	
//	}
//	return 0;
//
//
//}


//Phuong phap ma tran dinh - cung (ma tran dinh lien thuoc)
#include<stdio.h>
#define MAX_N 100
#define MAX_M 500

typedef struct {
	int n, m;
	int A[MAX_N][MAX_M];
} Graph;

void init_graph(Graph *pG, int n, int m){
	pG->n = n;
	pG->m = m;
	int u,e;
	for( u = 1; u <= n; u++){
		for( e = 1; e<=m; e++){
			pG->A[u][e] = 0;
		}
	}
}

void add_edge(Graph *pG, int e, int u, int v){

	pG->A[u][e] = 1;
	pG->A[v][e] = 1;
}

int adjaccent(Graph *pG, int u, int v){
	int e = 0;
	for(e = 1; e<=pG->m; e++){
		if (pG->A[u][v] == 1 && pG->A[v][e] ==1)
			return 1;
	}
	return 0;
}


int degree(Graph *pG, int u){
	int e, deg_u=0;
	for (e=1; e<=pG->m;e++){
		if(pG->A[u][e] ==1){
			deg_u++;
		}
	}
	return deg_u;
}
//MA TRAN LIEN THUOC
//int main(){
//	Graph g;
//	int n = 4, m=5, v;
//	init_graph(&g, n, m);
//	add_edge(&g, 1,1,2);
//	add_edge(&g, 2,1,3);
//	add_edge(&g, 3,1,3);
//	add_edge(&g, 4,3,4);
//	add_edge(&g, 5,1,4);
//	
//	for (v=1;v<=n;v++){
//		printf("deg(%d) = %d\n", v, degree(&g, v));	
//	}
//	return 0;
//}

//data.txt
int main(){
	Graph g;
	int n, m, v, u,e;
	
	FILE *f= fopen("data.txt", "r");
	fscanf(f, "%d%d", &n, &m);
	init_graph(&g, n, m);

	for(e=1; e<=m; e++){
		fscanf(f, "%d%d", &u, &v);
		add_edge(&g, e, u, v);
	}
	for (v=1;v<=n;v++){
		printf("deg(%d) = %d\n", v, degree(&g, v));	
	}
	return 0;
}
//
//
////PHUONG PHAP DANH SACH DINH KE
///* KHAI BAO VA DINH NGHIA CTDL DANH SACH */
//#define MAX_ELEMENTS 100
//typedef int ElementType;
//typedef struct {
//ElementType data[MAX_ELEMENTS];
//int size;
//} List;
///* Tao danh sach rong */
//void make_null(List* L) {
//L->size = 0;
//}
///* Them mot phan tu vao cuoi danh sach */
//void push_back(List* L, ElementType x) {
//L->data[L->size] = x;
//L->size++;
//}
///* Lay phan tu tai vi tri i, phan tu bat dau o vi tri 1
//*/
//ElementType element_at(List* L, int i) {
//return L->data[i-1];
//}
///* Tra ve so phan tu cua danh sach */
//int count_list(List* L) {
//return L->size;
//}
//
//#include<stdio.h>
//#define MAX_N 100
//
//typedef struct {
//	int n;
//	List adj[MAX_N];
//} Graph;
//
//void init_graph(Graph *pG, int n){
//	int u;
//	pG->n = n;
//	
//	for( u = 1; u<=n; u++){
//		make_null(&pG->adj[u]);
//	}
//}
//
//void add_edge(Graph *pG, int u, int v){
//	push_back(&pG->adj[u], v);
//	push_back(&pG->adj[v], u);
//}
//int adjaccent(Graph *pG, int u, int v){
//	int j;
//	for(j=1; j<= pG->adj[u].size; j++)
//		if(element_at(&pG->adj[u],j)==v)
//			return 1;
//	return 0;
//}
//int degree(Graph *pG, int u){
//	return pG->adj[u].size;
//}
//List neighbors(Graph* G, int x) {
//    List L;
//    make_null(&L);
//    int e, y;
//    for (y = 1; y <= G->n; y++) {
//    	if (x == y) continue;
//        for (e = 1; e <= G->m; e++)
//            if (G->A[x][e] > 0 && G->A[y][e] > 0) {
//                push_back(&L, y);
//                break;
//            }
//    }
//    return L;
//}
//int main(){
//	Graph g;
//	int n = 4, v;
//	init_graph(&g, n);
//	add_edge(&g, 1,2);
//	add_edge(&g, 1,3);
//	add_edge(&g, 1,3);
//	add_edge(&g, 3,4);
//	add_edge(&g, 1,4);
//	
//	for (v=1;v<=n;v++){
//		printf("deg(%d) = %d\n", v, degree(&g, v));	
//	}
//	return 0;
//}

//data.txt
//int main(){
//	Graph g;
//	int n , v, u,e;
//	
//	FILE *f= fopen("data.txt", "r");
//	fscanf(f, "%d", &n);
//	init_graph(&g, n);
//
//	for(e=1; e<=n; e++){
//		fscanf(f, "%d%d", &u, &v);
//		add_edge(&g, u, v);
//	}
//	for (v=1;v<=n;v++){
//		printf("deg(%d) = %d\n", v, degree(&g, v));	
//	}
//	return 0;
//}




























