#include <stdio.h>
#define main2 2

// void test() {
//     int x = 2;

//     printf("%d", x);

//     void test2() 
//         printf("%d", x);
//         x = 1;
//     }

//     test2();
//     printf("%d\n", x);
// }

// void func1(int x[][2]) {
//     --x[0][4];
//     printf("%d\n",x[1][0]);
// }

int main() {
    // int x[][4] = {{1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}};

    // func1(x);
    // printf("%d\n", x[1][0]);

    int x = 2;
    int y = 0;
    int z = 2;
    if (x || x-- && ++y) {
        printf("Made It!\n");
    }
    printf("X: %d\n", x);
    printf("Y: %d\n", y);
    printf("Z: %d\n", z);

    return 0;
}