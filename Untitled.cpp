#include <iostream>
int main(){
	//::cout<<char(78);
	printf("%c%s%c%c%c%d%c%d",78,"==",78,80,'?',0,':',1);
	printf("%1$1s","what");
	//78 == 78 80 ?  0 : 1
	//      0     1     78      78    80     :      ==     ?
	//printf("%6$2d%8%2d%1$1c%3$1c%4$1c%7$2c%2$2s%5$1s",0,1,78,78,80,':',"==","?");
	getchar();
}
