#pragma once
#ifndef __INOUTFILES_H_
#define __INOUTFILES_H_

#ifdef __cplusplus
extern "C" {
#endif
    struct customerr {
        char* name;
        char* phone;
        int cip[2];//customer's initial position
        int cfp[2];//customer's final position
    };
    typedef struct customerr customer;

    struct driverr {
        char* name;
        char* phone;
        char* numberPlt;
        int dp[2];//driver's present position
    };
    typedef struct driverr driver;

    int actualLength(const char* string);
    char* readline(int lineNumber, const char* txtFile);
    int* getpos(int line, const char* filename);
    int count(const char* obj);
    customer* constructC(int num, customer* c);
    driver* constructD(int num, driver* d);
    //int** allocate(int number_of_row, int number_of_cols);
    //void printMat(int** arr, int num_of_rows, int num_of_cols);
    void getCusCip(int** CusCipMat, customer* c, int numOfCus);
    void getCusCfp(int** CusCfpMat, customer* c, int numOfCus);
    void getDrvDp(int** DrvDpMat, driver* d, int numOfDrv);
#ifdef __cplusplus
}
#endif 

#endif