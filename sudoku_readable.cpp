#include<iostream>

struct Pg{int n;
	bool f;
}g[9][9];

bool cr(int r,int c){
	for(int i=0; i<9; i++){
		if(i!=c){
			if(g[r][i].n==g[r][c].n){
				return 0;
			}
		}
	}
	return 1;
}
bool cc(int r,int c){
	for(int i=0;i<9;i++){
		if(i!=r){
			if(g[i][c].n==g[r][c].n){
				return 0;
			}
		}
	}
	return 1;
}

bool cs(int r,int c){
	int i,j,v=r/3,h=c/3;
	for(i=v*3; i<(v*3+3); i++){
		for(j=h*3; j<(h*3+3); j++){
			if(i!=r||j!= c){
				if(g[r][c].n==g[i][j].n)return 0;
			}
		}
	}
	return 1;
}

bool s(int r,int c){
	while(g[r][c].f==1){
		c++;
		if(c>8){
			c=0;
			r++;
		}
		if(r>8){
			return 1;
		}
	}for(int n=1;n<10;n++){
		int tr,tc;
		g[r][c].n=n;
		if(cc(r,c)&&cr(r,c)&&cs(r,c)){
			tc=c+1;
			tr=r;
			if(tc>8){
				tc=0;
				tr++;
			}if(tr>8){
				return 1;
			}if(s(tr,tc)){
				return 1;
			}
		}
	}g[r][c].n=0;
	return 0;
}

using namespace std;
void ss(int in_g[9][9]){
	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(in_g[i][j]==0){
				g[i][j].f=0;
				g[i][j].n=0;
			}
			else{
				g[i][j].f=1;
				g[i][j].n=in_g[i][j];
			}
		}
	}
	s(0,0);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			cout<<g[i][j].n<<" ";
		}
		cout<<endl;
	}
}
int main(){
	int n,b[9][9];
	cin>>n;
	int i,j,k;
	for(i=0;
		i<n;
		i++){for(j=0;
			j<9;
			j++){for(k=0;k<9;k++){
			b[j][k]=0;
			cin>>b[j][k];
		}
	}
	ss(b);
}return 0;
}