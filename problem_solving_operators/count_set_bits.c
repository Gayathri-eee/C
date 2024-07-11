#include<stdio.h>
int main(){
    //convert decimal to binary
    int num;
    printf("enter decimal number:");
    scanf("%d",&num);
        //count 1bit in it
        int count=0;
        while(num){
            count =count+(num & 1);
            num>>=1;
        }
    printf("number of set_bits of given number = %d\n",count);
    return 0;
}
