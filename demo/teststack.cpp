#include<stdio.h>
#include"../src/data/stack"
int main(){
	exstd::stack<int> stk;
	printf("exstd::stack testing!\n");
	printf("Usage:\n");
	printf("\t0 - pop\n");
	printf("\t1 x - push\n");
	printf("\t2 - size\n");
	printf("\t3 - empty\n");
	printf("\t4 x - x-th element\n");
	printf("\t5 - top\n");
	printf("\t6 - all datas\n");
	while(1){
		printf("Your query: ");
		int op,x;
		scanf("%d",&op);
		if(op==1||op==4)
			scanf("%d",&x);
		if(op==0)
			printf("Pop.\n"),
			stk.pop();
		else if(op==1)
			printf("Push x=%d\n",x),
			stk.push(x);
		else if(op==2)
			printf("Size=%u\n",stk.size());
		else if(op==3)
			printf("Isempty?\n",stk.size());
	}
}