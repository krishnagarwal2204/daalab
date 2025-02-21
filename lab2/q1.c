#include<stdio.h>
int count=0;
int con_int_check(int m,int n){
    int t=m>=n?n:m;
    while(t!=1){
        count++;
        if(m%t==0 && n%t==0)
            return t;
        t=t-1;
    }
    return t;
}
int main(){
    int a,b;
    printf("Enter 2 numbers to find their gcd\n");
    scanf("%d %d",&a,&b);
    printf("The gcd of %d and %d is %d\n",a,b,con_int_check(a,b));
    printf("Opcount: %d",count);
    return 0;
}