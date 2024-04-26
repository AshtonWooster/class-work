#include "prelab11.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int length = 5;
    Employee ** myEmpArr = (Employee**)malloc(sizeof(Employee*) * length);

    for (int i = 0; i < length; i++) {
        Employee e = {0, rand() % 1000};
        myEmpArr[i] = &e;
    }

    EmpDatabase * myDB = createSearchableEmployeeDB(myEmpArr, length);

    freeEmpDatabase(myDB);
    free(myEmpArr);

    return 0;
}
