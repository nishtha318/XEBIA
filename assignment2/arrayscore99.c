#include <stdio.h>
int main() {
int marks[] = {78, 99, 55, 99, 39};
int n = 5, count = 0;
for (int i = 0; i < n; i++) {
    if (marks[i] == 99) {
        printf("99 found at index %d\n", i);
        count++;
    }
}
printf("total number of students who scored 99 is %d\n",count);
}