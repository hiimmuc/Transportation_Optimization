#include <stdio.h>
#include <stdlib.h>
#include <string>

int actualLength(const char *string) {

    while(isspace((unsigned char)string[0]))
        string++;
    char *final = strdup(string);
    int length = strlen(final);
    while(length > 0 && isspace((unsigned char)final[length-1]))
        length--;
    final[length-1] = '\0';
    return (strlen(final)+1);
}
char* readline(int lineNumber,const char *txtFile){
    char *buf=(char*)malloc(50*sizeof(char));
    int count =1;
    FILE *fileName;
    fileName = fopen(txtFile,"r");
    while (fgets(buf,200,fileName) != NULL) 
    {
        if (count == lineNumber){
            break;
        }
        else{
            count++;
        }
    }
    
    char *line = (char*)malloc(actualLength(buf)*sizeof(char)); 
    strcpy(line,buf);
    delete buf;
    fclose(fileName);
    
    return line;
    delete line;
}

int *getpos(int line, const char* filename){
    static int pos[2]={NULL,NULL};
    // int *pos=NULL;
    char*buf=(char*)malloc(strlen(readline(line, filename))*sizeof(char));
    
    strcpy(buf,readline(line,filename));
    for (int i=strlen(buf); i>0; i--){
        if (buf[i]==';'){
            pos[0]= buf[i-1]-'0';
            pos[1]= buf[i+1]-'0';
            break;       
        }        
    }  
    delete buf;
    return pos;
}
int count(const char *obj){
    FILE *fp; 
    int count=0;  
    char c;  
        fp = fopen(obj, "r"); 
    
    if (fp == NULL) { 
         return 0; 
    } 
    
    for (c = getc(fp); c != EOF; c = getc(fp)) 
        if (c == '=') // Increment count if this character is newline 
            count =count + 1;   
    fclose(fp); 
    
    
    return count;
}
typedef struct{
    char* name;
    char* phone;
    int cip[2];
    int cfp[2];
}customer;
typedef struct{
    char* name;
    char* phone;
    char* number_plt;
    int dp[2];
}driver;
customer* construct_c(int num,customer *c){
    int i;
    for (i=0;i<num;i++){
        c[i].name=readline((1+5*i),"customer.txt");
        c[i].phone=readline((2+5*i),"customer.txt");
        c[i].cip[0]=*getpos((3+5*i),"customer.txt");
        c[i].cip[1]=*(getpos((3+5*i),"customer.txt")+1);
        c[i].cfp[0]=*getpos((4+5*i),"customer.txt");
        c[i].cfp[1]=*(getpos((4+5*i),"customer.txt")+1);
     }
    return c;
}
driver* construct_d(int num,driver *d){
    int i;
    for (i=0;i<num;i++){
        d[i].name=readline((1+5*i),"driver.txt");
        d[i].phone=readline((2+5*i),"driver.txt");
        d[i].number_plt=readline((3+5*i),"driver.txt");
        d[i].dp[0]=*getpos((4+5*i),"driver.txt");
        d[i].dp[1]=*(getpos((4+5*i),"driver.txt")+1);
        // c[i].cfp[0]=*getpos((4+5*i),"customer.txt");
        // c[i].cfp[1]=*(getpos((4+5*i),"customer.txt")+1);
     }
    return d;
}

int main(){
    int i;
    int numOfCus=count("customer.txt");
    int numOfDrv=count("driver.txt");
    
    customer *c=(customer*)malloc(numOfCus*sizeof(customer));
    driver *d=(driver*)malloc(numOfDrv*sizeof(driver));
    construct_c(numOfCus,c);
    construct_d(numOfDrv,d);


    printf_s("so khach:%d\n",numOfCus);
    for(i=0;i<numOfCus;i++){
        printf_s("ten:%s\n", c[i].name);
        printf_s("sdt:%s\n",c[i].phone);
        printf_s("don tai:%d\t%d\n",c[i].cip[0],c[i].cip[1]);
        printf_s("tra tai:%d\t%d\n",c[i].cfp[0],c[i].cfp[1]);
    }
    printf_s("so tai xe: %d\n",numOfDrv);
    for(i=0;i<numOfDrv;i++){
        printf_s("ten:%s\n", d[i].name);
        printf_s("sdt:%s\n",d[i].phone);
        printf_s("bien so:%s\n", d[i].number_plt);
        printf_s("vi tri:%d\t%d\n",d[i].dp[0],d[i].dp[1]);
    }
    
   
    
    return 0;
}