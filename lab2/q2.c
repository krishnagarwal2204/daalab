#include<stdio.h>
#define MAX 1024
int count=0;
typedef struct{
    int size;
    int factors[MAX];
    int exponents[MAX];
}FACTORIZATION;
void storeprimefactors(int x,FACTORIZATION * factorization){
    factorization->factors[0]=1;
    factorization->exponents[0]=1;
    int i,c,n=x;
    int k=1;
    for(i=2;i<=n;i++){
        c=0;
        while(n%i==0){
            c++;
            n=n/i;
            count++;
        }
        if(c>0){
        factorization->exponents[k]=c;
        factorization->factors[k]=i;
        k++;
        }
    }
    factorization->size=k-1;
}
int mid_school(int m,int n){
    FACTORIZATION mfactorization,nfactorization;
    storeprimefactors(m,&mfactorization);
    storeprimefactors(n,&nfactorization);
    int i=0,j=0,x=1;
    int min;
    while(i<=mfactorization.size && j<=nfactorization.size){
        if(mfactorization.factors[i]>nfactorization.factors[j]){
            j++;
        }
        else if(mfactorization.factors[i]<nfactorization.factors[j]){
            i++;
        }
        else{
            min=mfactorization.exponents[i]>=nfactorization.exponents[j]?nfactorization.exponents[j]:mfactorization.exponents[i];
            for(int p=1;p<=min;p++){
                x=x*mfactorization.factors[i];
            }
            i++;
            j++;
        }
    }
    return x;
}
int main(){
    int a,b;
    printf("Enter 2 numbers to find their gcd\n");
    scanf("%d %d",&a,&b);
    printf("The gcd of %d and %d is %d\n",a,b,mid_school(a,b));
    printf("Opcount: %d",count);
    return 0;
}
