#include<stdio.h>
#define max 100
#define no_e -1
typedef struct {
	int n;
	int m;
	int w[max][max];
} Graph;

void init_graph(Graph *g, int n, int m){
	g->n=n;
	g->m= m;
	int u, v;
	for(u=1;u<=n;u++){
		for(v=1;v<=m;v++){
			g->w[u][v]=no_e;
		}
	}
}

void add_edge(Graph *g,int u, int v, int w){
	g->w[u][v] = w;
	g->w[v][u] = w;
//	g->m++;
}

#define o 99999
int mark[max];
int pi[max];
int p[max];

void MooreDijkstra(Graph *g, int s){
	int u, v, it;
	for(u=1;u<=g->n;u++){
		pi[u]=o;
		mark[u]=0;
	}
	
	pi[s]=0;
	p[s]=-1;
	
	for(it=1;it<g->n;it++){
		int  min_pi = o;
		for(v=1;v<=g->n;v++){
			if(mark[v]==0&&pi[v]<min_pi){
				min_pi=pi[v];
				u=v;
			}
		}
		
		mark[u] = 1;
		
		for(v=1;v<=g->n;v++){
			if(g->w[u][v] != no_e && mark[v]==0){
				if(pi[u] + g->w[u][v] < pi[v]){
					pi[v] = pi[u] + g->w[u][v];
					p[v]=u;
				}
			}
		}
		
	}


}

int main(){
//	freopen("dt.txt", "r", stdin); //Khi n?p bài nh? b? dòng này.
	Graph G;
	int n, m, u, v, w, e, kq = -1;
	scanf("%d%d", &n, &m);
	init_graph(&G, n,m);
	
	for (e = 1; e <= m; e++) {
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	MooreDijkstra(&G,1);
	if(pi[n]<=0)
	    pi[n]=kq;
    printf("%d", pi[n]);
	
}















































