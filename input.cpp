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

int* getpos(int line){
    int pos[2]={NULL,NULL};
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
int main(){
    // getpos(3);
    printf("%d\n",getpos(1)[0]);
    printf("%d\n",getpos(3)[1]);
    printf("%d\n",getpos(4)[0]);
    printf("%d\n",getpos(4)[1]);


    return 0;
}