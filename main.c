#include <stdio.h>
#include <stdlib.h>
#include "InOutFiles.h"

int main(){
    int numOfCus=count("customer.txt");//count customers
    int numOfDrv=count("driver.txt");//count drivers
    
    customer *c=(customer*)calloc(numOfCus,sizeof(customer));
    // allocate memory for number of customers counted above
    driver *d=(driver*)calloc(numOfDrv,sizeof(driver));
    //same as above
    construct_c(numOfCus,c);
    construct_d(numOfDrv,d);
    int **cus_cip_mat=allocate(numOfCus,2);//allocate memory for cip mattrix
    get_cus_cip(cus_cip_mat,c,numOfCus);//get values for cip mattrix

    int **cus_cfp_mat=allocate(numOfCus,2);//same
    get_cus_cfp(cus_cfp_mat,c,numOfCus);//same

    int **drv_dp_mat=allocate(numOfDrv,2);//same
    get_drv_dp(drv_dp_mat,d,numOfDrv);//same
    return 0;
}