#include <stdio.h>
#include <string.h>

//define customer details
typedef struct  {
    char name[20];
    int phone_num;
    int cip[7][7];
    int cfp[7][7];
} customer_details;

//define driver details
typedef struct {
    char name[20];
    int plate_num;
    int phone_num;
    int dip[7][7];
    int cdp[7][7];
} driver_details;

//print to bill
typedef struct {
    char name[20];
    int phone_num;
    int plate_num; 
    int fee;
    int t_departure, t_arrival;
} bill_for_cus;

int main(){
    FILE* fp[3];
    customer_details c1,c2,c3;
    driver_details d[3];
    int departure_time[3],arrival_time[3],i,temp;
    char filename[20],driver_phone[10];
    int CD_assign[2][3] = {{1,2,3},{3,1,2}};

    //Driver's details (example)
    strcpy(d[0].name,"dang");
    strcpy(d[1].name,"thiem");
    strcpy(d[2].name,"chinh");
    d[0].phone_num = 123;
    d[1].phone_num = 456;
    d[2].phone_num = 789;
    
    for(i=0;i<3;i++){
        //printf("Customer No %d goes with Driver No: %d\n",CD_assign[0][i],CD_assign[1][i]);
        temp = CD_assign[1][i] - 1;
        sprintf(filename,"Bill For Customer %d",i + 1);
        fp[i] = fopen(filename,"w+");
        fprintf(fp[i],"Driver's name : %s\n",d[temp].name);
        sprintf(driver_phone,"%d",d[temp].phone_num);
        fprintf(fp[i],"Driver's phone: %s",driver_phone);
        fclose(fp[i]);
    }
    return 0;
}
