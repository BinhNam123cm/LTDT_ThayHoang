#include <stdio.h>
#define MAX_ELEMENTS 100
// Do Thi G (matran dinh )
typedef struct {
 int A[100][500];
 int n;
}dothi;
void khoitao(dothi *G,int n){
int i,j;
G->n = n;
for(i=1;i<=n; i++)
for(j=1;j<=n;j++)
G->A[i][j]=0;
}
void themcung(dothi *G,int x,int y){
G->A[x][y] =1;
G->A[y][x] =1;
}
int kiemtradinh(dothi *G,int x, int y){
return G->A[x][y] != 0;
}
int tinhbac(dothi* G, int x){
int y, bac = 0;
for (y = 1; y <= G->n; y++ )
if(G->A[x][y] > 0 )
bac++; return bac;
}
// Danh sach List
typedef struct {
int data[MAX_ELEMENTS];
int size; // danh sach toi da 
} List;
/* Tao danh sach rong */
void make_null(List* L) {
L->size = 0;
}
/* Them mot phan tu vao cuoi danh sach */
void push_back(List* L, int x) {
L->data[L->size] = x;
L->size++;
}
/* Lay phan tu tai vi tri i, phan tu bat dau o vi tri 1 */
int element_at(List* L, int i) {
return L->data[i-1];
}
/* Tra ve so phan tu cua danh sach */
int count_list(List* L) {
return L->size;
}
List cacdinhke(dothi* G, int x){
int y;
List L;
make_null(&L);
for (y=1;y<= G->n; y++)
if (kiemtradinh(G,x,y)) push_back(&L,y);
return L;
}
typedef struct {
int data[MAX_ELEMENTS];
int front, rear;
} Queue;
void khoitaoHD(Queue* Q) {
Q->front = 0;
Q->rear = -1;
}
void push(Queue* Q, int x) { // day noi dung vao HD
Q->rear++;
Q->data[Q->rear] = x;
}
int top(Queue* Q) { // Lay ra noi dung HD
return Q->data[Q->front];
}
void pop(Queue* Q) { // Xoa vi tri 
Q->front++;
}
int empty(Queue* Q) { // kiem tra rong
return Q->front > Q->rear;
}
//Duyet Theo chieu Rong
void duyetrong(dothi* G) {
Queue H;
int mark[100];
khoitaoHD(&H);
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
List L = cacdinhke(G,x);
for (j=1;j <= L.size; j++){
int y = element_at(&L,j);
if (mark[y] == 0) {
mark[y] = 1;
push(&H,y);
}
}
}
}
}
int main(){
dothi G;
	freopen("dt.txt", "r", stdin); 

	int n, m, u, v, w, e;
	scanf("%d%d", &n, &m);
khoitao(&G, n);
for (e = 0; e < m; e++) {
scanf("%d%d", &u, &v);
themcung(&G, u, v);
}
duyetrong(&G);
}
