#include <stdio.h>
#include <math.h>
int main() {
   int num, sum = 0, temp, digits = 0, rem;
   printf("enter the number you want to check for:\n");
   scanf("%d",&num);
   temp = num;
   while (temp > 0) {
    digits++;
    temp /= 10;
    }
temp = num;
while (temp > 0) {
    rem = temp % 10;
    sum += pow(rem, digits);
    temp /= 10;
}
if (sum == num)
printf("Armstrong\n");
else
printf("Not Armstrong\n");
return 0;
}