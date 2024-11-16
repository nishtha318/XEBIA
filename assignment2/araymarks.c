#include <stdio.h>
int main() {
int marks[] = {77, 64, 82, 55, 93};
int n = 5;
for (int i = 0; i < n; i++) {
marks[i] += 5;
}
for (int i = 0; i < n; i++) {
printf("%d ", marks[i]);
}
return 0;
}