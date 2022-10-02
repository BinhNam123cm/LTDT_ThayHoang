#include<stdio.h>
#define max 100
#define no_e 0
#define o 99999
int w[max];
typedef struct {
	int n,m;
	int a[max][max];
} Graph;

void init_graph(Graph *g, int n){
	g->n=n;
	int i,j;
	for(i=1;i<=g->n;i++){
		for(j=1;j<=g->n;j++){
			g->a[i][j]=0;
		}
	}
}

void add_edge(Graph *g,int u, int v, int w){
	g->a[u][v] = w;
	g->a[v][u] = w;
//	g->m++;
}


int mark[max];
int pi[max];
int p[max];


void MooreDijkstra(Graph *g, int s){
	int u, v, it;
	for(u=1;u<=g->n;u++){
		mark[u]=0;
		pi[u]=o;
	}
	
	pi[s]=w[s];
	p[s]=-1;
	
	for(it=1;it<=g->n;it++){
		int j, min_pi = o;
		for(j=1;j<=g->n;j++){
			if(mark[j]==0&&pi[j]<min_pi){
				min_pi=pi[j];
				u=j;
			}
		}
		
		mark[u] = 1;
		
		for(v=1;v<=g->n;v++){
			if(g->a[u][v] != no_e && mark[v]==0){
				if(pi[u] + g->a[u][v] < pi[v]){
					pi[v] = pi[u] + g->a[u][v];
					p[v]=u;
				}
			}
		}
		
	}
}
int main(){
	Graph G;
	int m,n,u,v,i,j;
	int k,i_ke,j_ke;
	freopen("dt.txt", "r", stdin); //Khi n?p bài nh? b? dòng này.
	scanf("%d%d", &m, &n);
	init_graph(&G, n*m);
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&u);
			w[i*n+j+1] = u;
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			int di[] = {-1,1,0,0};
			int dj[] = {0,0,-1,1};
//			
//			i = (u-1)/n;
//			j = (u-1)%n;
//			
			for(k=0;k<4;k++){
				i_ke=i+di[k];
				j_ke = j + dj[k];
				
				if((i_ke>=0)&&(i_ke<m)&&(j_ke>=0)&&(j_ke<n)){
					v = i_ke*n + j_ke+1;
					u = i*n+j+1;
					G.a[u][v] = w[v];
				}
			}
		}
	}
	MooreDijkstra(&G,1);
	
	printf("%d ",pi[G.n]);
	return 0;
}
