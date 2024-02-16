#include "prelab4.h"
#include <stdio.h>
#include <stdlib.h>

Employee * readEmployeeArray(FILE *fp) {
    int length = 0;
    fscanf(fp, "%d", &length);

    Employee * empArr = (Employee*) malloc(sizeof(Employee) * (length) + sizeof(int));

    if (!empArr) {
        return NULL;
    }

    *((int*) empArr) = length;

    empArr = (Employee*)((int*)empArr + 1);

    int empID = 0;
    int jobType = 0;
    float salary = 0;
    for (int i = 0; i < length; i++) {
        fscanf(fp, "%d %d %f", &empID, &jobType, &salary);
        empArr[i].empID = empID;
        empArr[i].jobType = jobType;
        empArr[i].salary = salary;
    }

    return empArr;    
}

int getSize(Employee * arr) {
    return *((int*)arr-1);
}

int getEmpFromID(Employee * arr, int empID) {
    int size = getSize(arr);

    for (int i = 0; i < size; i++) {
        if ((arr + i)->empID == empID) {
            return i;
        }
    }

    return -1;
}

void setEmpSalary(Employee * arr, int empID, float salary, int *ec) {
    int index = getEmpFromID(arr, empID);
    if (index == -1) {
        *ec = 1;
        return;
    }

    arr[index].salary = salary;
    *ec = 0;
    return;
}

float getEmpSalary(Employee * arr, int empID, int *ec) {
    int index = getEmpFromID(arr, empID);
    if (index == -1) {
        *ec = 1;
        return -1.0;
    }

    *ec = 0;
    return arr[index].salary;
}

void setEmpJobType(Employee * arr, int empID, int job, int *ec) {
    int index = getEmpFromID(arr, empID);
    if (index == -1) {
        *ec = 1;
        return;
    }

    arr[index].jobType = job;
    *ec = 0;
    return;
}

int getEmpJobType(Employee * arr, int empID, int *ec) {
    int index = getEmpFromID(arr, empID);
    if (index == -1) {
        *ec = 1;
        return -1;
    }

    *ec = 0;
    return arr[index].jobType;
}

void freeArray(Employee * arr) {
    arr = (Employee*)((int*)arr -1);
    free(arr);
    arr = NULL;
}
