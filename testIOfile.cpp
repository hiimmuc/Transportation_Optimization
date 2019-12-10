#include <stdio.h>
#include <stdlib.h>
#include "InOutFiles.h"
#include <conio.h>
#include <malloc.h>
#include <math.h>
#include <string>

int main(){

    int numOfCus=count("customer.txt");//count customers
    int numOfDrv=count("driver.txt");//count drivers
    
    customer *c=(customer*)malloc(numOfCus*sizeof(customer));
    // allocate memory for number of customers counted above
    driver *d=(driver*)malloc(numOfDrv*sizeof(driver));
    //same as above
    constructC(numOfCus,c);
    constructD(numOfDrv,d);
    int **cusCipMat=allocate(numOfCus,2);//allocate memory for cip mattrix
    getCusCip(cusCipMat,c,numOfCus);//get values for cip mattrix

    int **CusCfpMat=allocate(numOfCus,2);//same
    getCusCfp(CusCfpMat,c,numOfCus);//same

    int **DrvDpMat=allocate(numOfDrv,2);//same
    getDrvDp(DrvDpMat,d,numOfDrv);//same
    printf_s("so khach:%d\n",numOfCus);
    for(int i=0;i<numOfCus;i++){
        printf_s("ten:%s\n", c[i].name);
        printf_s("sdt:%s\n",c[i].phone);
        printf_s("don tai:%d\t%d\n",c[i].cip[0],c[i].cip[1]);
        printf_s("tra tai:%d\t%d\n",c[i].cfp[0],c[i].cfp[1]);
    }
    printf_s("so tai xe: %d\n",numOfDrv);
    for(int i=0;i<numOfDrv;i++){
        printf_s("ten:%s\n", d[i].name);
        printf_s("sdt:%s\n",d[i].phone);
        printf_s("bien so:%s\n", d[i].numberPlt);
        printf_s("vi tri hien tai:%d\t%d\n",d[i].dp[0],d[i].dp[1]);
    }
    printMat(cusCipMat,numOfCus,2);
    printMat(CusCfpMat,numOfCus,2);
    printMat(DrvDpMat,numOfDrv,2);
    return 0;
}
