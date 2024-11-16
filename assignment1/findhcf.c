#include <stdio.h>
int main() {
int i,x, y,hcf,largest;
printf("enter the two numbers(x,y):\n");
scanf("%d%d",&x,&y);
largest=(x>y)?x:y;


for(i=largest;i>=2;i--){
    if(x%i==0 && y%i==0){
        hcf=i;
        break;
    }
}
printf("hcf is: %d",hcf);

return 0;
}