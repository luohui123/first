#include <stdio.h>
#include <time.h>


void Towers(int n,char x,char y,char z);
void move_hanoi(char x, int n, char z);

int count_move = 0;  // 移动次数

// 汉诺塔
void Towers(int n,char x,char y,char z){
	if(n==1){
		move_hanoi(x, 1, z);
	}
	else{
		Towers(n-1,x,z,y);  // x向y处移动，借助z
	    move_hanoi(x, n, z);  // 移动输出 
		Towers(n-1,y,x,z);  // y向z处移动，借助x
	}
}

// 移动
void move_hanoi(char x, int n, char z){
	count_move++;
    printf("%d：Move disk %d from %c to %c\n",count_move,n,x,z);
}

int main(int argc, char *argv[]) {
	int n;
	n=3;
    clock_t s, e;
    s = clock();
	Towers(n,'A','B','C');
    e = clock();
    double spent = (double)(e-s)/CLOCKS_PER_SEC;
    printf("deepth:%d, spent %.3fs", n, spent);
	return 0;
}