#include<stdio.h>
int main()
{
int r,c,i,j;
printf("Enter rows and colunm");
scanf("%d %d", &r,&c);
int sensor1[r][c], sensor2[r][c], combination[r][c];
printf("Enter elements of sensor1:\n");
for(i = 0; i<r; i++)
for(j=0; j<c; j++) {
scanf("%d", &sensor1[i][j]);
}
printf("\nEnter elements of sensor2:\n");
for(i = 0; i<r; i++) {
for(j=0; j<c; j++) {
scanf("%d", &sensor2[i][j]);
}
}
for(i=0; i<r; i++)
{
for(j=0; j<c; j++) 
{
combination[i][j]= sensor1[i][j]+sensor2[i][j];
}
}
printf("\nThe resultant is:\n");
for(i=0; i<r; i++) {
for(j=0; j<r; j++) {
printf("%d\t", combination[i][j]);
}
printf("\n");
}
return 0;
}
