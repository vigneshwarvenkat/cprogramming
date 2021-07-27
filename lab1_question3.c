#include <stdio.h>
#include <math.h>
#include <stdbool.h>
bool is_year_leap(int any_year)
  {
    if((any_year%4==0)){
      return true;
    }
     else
    {
      return false;
    }
  }

int main(){
  int input_days, starting_month, starting_day, starting_year;
  printf("Your input days: ");
  scanf("%d", &input_days);
  printf("Your starting month: ");
  scanf("%d", &starting_month);
  printf("Your starting day: ");
  scanf("%d", &starting_day);
  printf("Your input year: ");
  scanf("%d", &starting_year);
  printf("%d days from %d/%d/%d = ", input_days, starting_day,starting_month, starting_year);

  int days_in_leap_months[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
  int days_in_non_leap_months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  int year_counter =0 , month_counter = 0;



  while((input_days>=366 && is_year_leap(starting_year) == true) || (input_days>=365 && is_year_leap(starting_year)==false)){
      if((is_year_leap(starting_year)==true && starting_month<=2) || (is_year_leap(starting_year+1) && starting_month>2)){
        input_days = input_days - 366;
        year_counter+=1;
        starting_year+=1;
      }
      else{
        input_days = input_days - 365;
        year_counter+=1;
        starting_year+=1;
      }

  }
  while(((input_days >= days_in_leap_months[starting_month-1] && is_year_leap(starting_year)==true)|| ((input_days>=days_in_non_leap_months[starting_month-1]) && !is_year_leap(starting_year)))){
    if(is_year_leap(starting_year)){
      input_days = input_days - days_in_non_leap_months[starting_month-1];
      month_counter+=1;
      starting_month+=1;
    }
    else{
    input_days = input_days-days_in_non_leap_months[starting_month-1];
    month_counter+=1;
    starting_month+=1;
  }
  printf("%d years %d months %d days", year_counter, month_counter, input_days);

  return 0;
  }}
