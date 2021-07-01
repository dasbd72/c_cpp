#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
struct Line{
	vector<int> index;
	Line *next;
};
int main(){
	int N, M, K, L, amount;
	scanf("%d %d",&N, &M);
	L = 330;
	amount = N;
	Line *head = new Line();
	head->next = NULL;
	Line *block = head;
	for(int i = 0, x;i < N;i++){
		scanf("%d",&x);
		if(block->index.size() == L){
			block->next = new Line();
			block = block->next;
		}
		block->index.push_back(x);
	}
	while(M--){
		char command[6];int coor, x;
		Line *use = head;
		scanf("%s %d",command, &coor);
		if(command[0]=='A'){
			scanf("%d",&x);
			while(coor > 1 + use->index.size()){
				coor -= use->index.size();
				use = use->next;
			}
			int tmp1, tmp2;
			tmp1 = x;
			for(int i = coor - 1;i < use->index.size();i++){
				tmp2 = use->index[i];
				use->index[i] = tmp1;
				tmp1 = tmp2;
			}
			use->index.push_back(tmp1);
			
			if(use->index.size() > L*2){
				Line *cut = new Line();
				cut->next = use->next;
				use->next = cut;
				int count = 0;
				for(int i = use->index.size()/2;i<=use->index.size();i++){
					count++;
					cut->index.push_back(use->index[i-1]);
				}
				while(count--){
					use->index.pop_back();
				}
			}
		}
		else if(command[0]=='L'){
			while(coor > use->index.size()){
				coor -= use->index.size();
				use = use->next;
			}
			for(int i = coor;i < use->index.size();i++){
				use->index[i-1] = use->index[i];
			}
			use->index.pop_back();
		}
		else {
			while(coor > use->index.size()){
				coor -= use->index.size();
				use = use->next;
			}
			printf("%d\n",use->index[coor-1]);
		}
		/*
		Line *pp=head;
		while(pp!=NULL){
			for(int i = 0;i<pp->index.size();i++){
				cout << pp->index[i] << ' ';
			}cout<<"__";
			pp = pp->next;
		}cout << endl;
		*/
	}
}

