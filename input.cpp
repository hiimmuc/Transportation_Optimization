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
    char buf[200];
    int count =1;
    FILE *fileName;
    fileName = fopen(txtFile,"r");
    while (fgets(buf,200,fileName) != NULL) /* read a line */
    {
        if (count == lineNumber){
            break;
        }
        else{
            count++;
        }
    }
    
    char *line = (char*)malloc(actualLength(buf)*sizeof(char)); /*alloc 10 int*/
    strcpy(line,buf);
    fclose(fileName);
    
    return line;
}

int *getpos(int line){
    static int pos[2]={NULL,NULL};
    // int *pos=NULL;
    char*buf=(char*)malloc(strlen(readline(line, "customer.txt"))*sizeof(char));
    
    strcpy(buf,readline(line,"customer.txt"));
    for (int i=strlen(buf); i>0; i--){
        if (buf[i]==';'){
            pos[0]= buf[i-1]-'0';
            pos[1]= buf[i+1]-'0';
            break;       
        }        
    }  

    return pos;
}
typedef struct{
    char* name;
    char* phone;
    int *cip;
    int *cfp;
}customer;

int main(){

    int numOfCus=5;
    customer *c=(customer*)malloc(numOfCus*sizeof(customer));
    c[0].name=readline(1,"customer.txt");
    c[0].cip=getpos(3);
    printf("%s\n", c[0].name);
    printf("%d",*(c[0].cip+1));
    printf("%d",*(c[0].cip));


    return 0;
}