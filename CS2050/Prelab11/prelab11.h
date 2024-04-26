#ifndef _PRELAB11
#define _PRELAB11
#include <stdio.h>
#include <stdlib.h>

typedef struct Employee {
    int ID;
    int SSN;
} Employee;

typedef struct EmpDatabase {
    int length;
    int errorCode;
    Employee ** listByID;
    Employee ** listBySSN;
} EmpDatabase;

EmpDatabase* createSearchableEmployeeDB(Employee **, int);

Employee * findEmpBySSN(int, EmpDatabase*);

Employee * findEmpByID(int, EmpDatabase*);

void freeEmpDatabase(EmpDatabase*);

int getErrorCode(EmpDatabase*);

#endif
