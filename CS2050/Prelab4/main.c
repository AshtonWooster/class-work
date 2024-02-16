#include "prelab4.h"
#include <stdio.h>

void outputArray(Employee* arr) {
    int length = getSize(arr);
    for (int i = 0; i < length; i++) {
        printf("ID: %d JOB: %d SALARY: %f\n", arr[i].empID, arr[i].jobType, arr[i].salary);
    }
    printf("\n");
}

int main() {
    FILE* empFile;
    empFile = fopen("employees.txt", "r");

    if (!empFile) {
        printf("ERROR OPENING FILE\n");
        return 1;
    }

    Employee * myArray;
    myArray = readEmployeeArray(empFile);

    outputArray(myArray);

    freeArray(myArray);

    fclose(empFile);
}
