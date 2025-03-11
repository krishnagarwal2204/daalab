#include<stdio.h>
#include<string.h>
int count=0;
void shiftablecreate(int table[],int size,char p[],int m){
	for(int i=0;i<size;i++){
		table[i]=m;
	}
	for(int j=0;j<m-1;j++){
		table[p[j]]=m-j-1;
	}
}
int horspoolmatch(char t[],int n,char p[],int m){
	int table[256];
	shiftablecreate(table,256,p,m);
	int i=m-1;
	int k;
	while(i<=n-1){
		k=0;
	while(k<=m-1){
		count++;
		if(p[m-1-k]==t[i-k])
			k=k+1;
		else
			break;
	}
		if(k==m)
			return i-m+1;
		else
			i=i+table[t[i]];
	}
	return -1;
}
int main(){
	char t[100],p[100];
	printf("Enter text\n");
	scanf("%s",t);
	printf("Enter pattern to be matched\n");
	scanf("%s",p);
	int x=horspoolmatch(t,strlen(t),p,strlen(p));
	if(x!=-1)
		printf("%s is found at %d in %s",p,x,t);
	else
		printf("%s is not found in %s\n",p,t);
	printf("\nComparison count %d\n",count);
	return 0;
}
