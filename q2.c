#include<stdio.h>
#include<string.h>
int compcount=0;
int strmatch(char *t,char *p,int n,int m){
    int i,j;
    for(i=0;i<n-m+1;i++){
        j=0;
        while(j<m){
            compcount++;
            if(p[j]==t[i+j])
                j++;
            else
                break;
        }
        if(j==m)
            return i;
    }
    return -1;
}
int main(){
    char t[100],p[100];
    printf("Enter text\n");
    scanf("%s",t);
    printf("Enter pattern to be searched\n");
    scanf("%s",p);
    int x=strmatch(t,p,strlen(t),strlen(p));
    if(x!=-1)
        printf("%s is found at %d in %s",p,x,t);
    else
        printf("%s is not found in %s",p,t);
    printf("\nComparisons: %d",compcount);
    return 0;
}