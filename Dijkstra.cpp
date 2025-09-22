#include <iostream>

using namespace std;

int main(){
	int Size;
	cout<<"Enter Size : ";
	cin>>Size;
	
	const int INF = 9999;
	int Graph[Size][Size];
	
	for(int i = 0 ; i < Size ; i++){
		for(int j = 0 ; j < Size ; j++){
			Graph[i][j] = INF;
		}
	}
	
	for(int x = 0; x < Size; x++){
		for(int y = 0;y < Size;y++){
			if(x == y){
				Graph[x][y] = 0;
			}
			else if(Graph[y][x] == INF){
				int Ch;
				cout<<x + 1<<" -> "<<y + 1<<" (1 for true ,0 for false):";
				cin>>Ch;
				if(Ch == 1){
					cout<<"Peice  "<< x + 1 <<" -> "<< y + 1<<" : ";
					cin>>Graph[x][y];
				}
			}
		}
	}
	
	int Dist[Size];
	bool Vis[Size];
	
	for(int i = 0;i < Size;i++){
		Dist[i] = INF;
		Vis[i] = false;
	}
	Dist[0] = 0;
	
	for(int cou = 0; cou < Size;cou++){
		int minDist = INF;
		int u = -1;
		for(int i = 0;i < Size;i++){
			if(!Vis[i] && Dist[i]< minDist){
				minDist = Dist[i];
				u = i;
			}
		}
		if(u == -1){
			break;
		}
		Vis[u] = true;
		
		for(int v = 0; v < Size;v++){
			if(!Vis[v] && Graph[u][v] != INF){
				if(Dist[u] + Graph[u][v] < Dist[v]){
					Dist[v] = Dist[u] + Graph[u][v];
				}
			}
		}
	}
	
	cout<<"limit distance of 1 to "<<endl;
	for(int x = 0;x < Size;x++){
		cout<<x + 1<<" : "<<Dist[x]<<endl;
	}
	
	return 0;
}