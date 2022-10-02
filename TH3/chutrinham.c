#include<stdio.h>
#define max 100
#define o 999999
typedef struct {
	int u, v;
	int w;
} Egde;

typedef struct {
	int n,m;
	Egde e[max];
} Graph;

void init_graph(Graph *g, int n){
	g->n=n;
	g->m=0;
}

void add_edge(Graph *g,int u, int v, int w){
	g->e[g->m].u = u;
	g->e[g->m].v = v;
	g->e[g->m].w = w;
	g->m++;
}

int pi[max];
int p[max];

int BellmanFord(Graph *g, int s){
	int u, v, w, it, k;
	for(u=1; u<=g->n;u++){
		pi[u]= o;
	}
	
	pi[s] = 0;
	p[s] = -1;
	
	for(it=1;it<g->n;it++){
		for(k=0;k<g->m;k++){
			u = g->e[k].u;
			v = g->e[k].v;
			w = g->e[k].w;
			if(pi[u] = o){
				continue;
			}
			
			if(pi[u] + w < pi[v]){
				pi[v] = pi[u] + w;
				p[v] = u;
			}
		}
	}
	
	int negative = 0;
	for(k=0;k<g->m;k++){
		u = g->e[k].u;
		v = g->e[k].v;
		w = g->e[k].w;
		if(pi[u] + w <pi[v]){
			negative = 1;
			break;
		}
	return negative;
}
}
int main(){
	Graph G;
	int m,n,u,v,i,j;
	int k,i_ke,j_ke;
	freopen("dt.txt", "r", stdin); //Khi n?p bài nh? b? dòng này.
	scanf("%d%d", &m, &n);
	init_graph(&G, n);
	
	int c = BellmanFord(&G,1);
	if(c==1){
		printf("negative cycle");
	}
	else 
		printf("ok");
	return 0;
}




























