#include<stdio.h>
#include<time.h>

   int age_calc(int day, int month, int year) {
    time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);

    int currentDay = localTime->tm_mday;
    int currentMonth = localTime->tm_mon + 1;
    int currentYear = localTime->tm_year + 1900;

    int age = currentYear - year;

    age = (currentMonth < month || (currentMonth == month && currentDay < day)) ? age - 1 : age;

        return age;
   }

int main() {
    int day, month, year;

    printf("Enter your birth day: ");
    scanf("%d", &day);
    printf("Enter your birth month: ");
    scanf("%d", &month);
    printf("Enter your birth year: ");
    scanf("%d", &year);

    int age =  age_calc(day, month, year);

    printf("Your age: %d", age);
    return 0;
}