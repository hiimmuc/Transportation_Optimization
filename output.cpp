#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <math.h>
#include <string>

typedef struct{
    char *cusName;
    char *drvName;
    char *pltNum;
    int fee, time1,time2; 
}bill_for_cus;
bill_for_cus *construct_bill(int num, bill_for_cus *bill){
    // for test, incompleted, fields must be assigned with correct linked couple
    int i;
    for(i=0;i<num;i++){
        bill[i].cusName="dang";
        bill[i].drvName="paul";
        bill[i].pltNum="29A12345";
        bill[i].fee=i+1;
        bill[i].time1=2*i+2;
        bill[i].time2=2*i+3;
    }
    return bill;
}
void print_bill(int numOfBill,bill_for_cus* bill){
    FILE* fp;
    char* buf;
    char* filename;
    int i;
    for(i=0;i<numOfBill;i++){
        filename= (char*)malloc((strlen(bill[i].cusName)+5)*sizeof(char));
        buf=(char*)malloc(200*sizeof(char));
        sprintf(filename,"%s%d.txt",bill[i].cusName,i);
        fp=fopen(filename,"w+");
        sprintf(buf,"Your driver: %s\t plate number:%s\n Your fee: %d\n estimate departure time: %d\n estimate arrival time: %d\n",bill[i].drvName,bill[i].pltNum,bill[i].fee,bill[i].time1,bill[i].time2);
        fputs(buf,fp);
        free(buf);
        free(filename);
        fclose(fp);
    }
}       
int main(){
    int numOfCus=2;
    bill_for_cus* bill=(bill_for_cus*)malloc(numOfCus*sizeof(bill_for_cus));
    construct_bill(numOfCus,bill);
    print_bill(numOfCus,bill);
    printf("%s\n",bill[0].cusName);
    return 0;

 }