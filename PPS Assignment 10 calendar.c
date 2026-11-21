#include<stdio.h>
#include<time.h>

int isLeapYear( int year )
{
return (year % 400 == 0) || ( year % 100 != 0 && year % 4 == 0);
}

void printMonth( int month, int year, int startDay)
{
char *months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
{
if( month == 2 && isLeapYear(year))
daysInMonth[1] = 29;
printf("\n  %s %d\n", months[month - 1], year);
printf(" Sun Mon Tue Wed Thur Fri Sat\n");
}
for (int i = 0; i < startDay; i++)
printf("        ");

for (int date = 1; date <= daysInMonth[month - 1]; date++)
{
printf("%3d ", date);
if ((startDay + date) % 7 == 0)
printf("\n");
}
}

int main()
{
int year, startDay;
printf("Enter the year: ");
scanf("%d", &year);

struct tm t = {0, 0, 0, 1, 0, year -1900 };
mktime(&t);
startDay = t.tm_wday;

for (int month = 1; month <= 12; month++)
{
printMonth (month, year, startDay);
int days = (month == 2 && isLeapYear(year)) ? 29 :
(int[]){31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}[month - 1];
startDay = (startDay + days) % 7;
}
return 0;
}
