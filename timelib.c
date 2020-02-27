#include <stdio.h>
#include <stdlib.h>

//Funktion um zu �berpr�fen ob das Jahr ein Schaltjahr ist
int is_leap(int year)
{
    if (year < 1582)
    {
        return -1;
    }
    if(year%4==0)
    {
        if(year%100==0)
        {
            if(year%400==0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

int day_of_the_year(int day, int month, int year)
{
    if(exist_date(day,month,year))
    {
        int number=0;
        int i;
        for(i=1;i<month;i++)
            {
                number+=get_days_for_month(i,year);
            }
        number+=day;
        return number;
    }
    return -1;

}

void input_date(int *pointerday, int *pointermonth, int *pointeryear)
{
	do {

		printf("Geben sie den Tag ein :\n");
		scanf("%i", &*pointerday);
		fflush(stdin);
		printf("Geben sie den Monat ein :\n");
		scanf("%i", &*pointermonth);
		fflush(stdin);
		printf("Geben sie das Jahr ein :\n");
		scanf("%i", &*pointeryear);
		fflush(stdin);











	} while (!(exist_date(*pointerday, *pointermonth, *pointeryear)));
}

int get_days_for_month(int month, int year)
{
    int daysForMonth[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    if(is_leap(year))
    {
        daysForMonth[1]=29;
    }
    return daysForMonth[month-1];
}

int exist_date(int day, int month, int year)
{
    if (year <1582 || year> 2400)
    {
        return 0;
    }

    if(day>get_days_for_month(month,year) || day<1)
    {
        return 0;
    }
    if(month>12 || month< 1)
    {
        return 0;
    }

    return 1;
}
int wday(int year, int month, int day)
{
	int adjustment, mm, yy;

	adjustment = (14 - month) / 12;
	mm = month + 12 * adjustment - 2;
	yy = year - adjustment;
	return (day + (13 * mm - 1) / 5 +
		yy + yy / 4 - yy / 100 + yy / 400) % 7;
}
void ausgabeWochentag(int year, int month,int day){
    if (wday(year,month,day)==0){

        printf("Es ist ein Sonntag\n");
    }
    else if (wday(year,month,day)==1){

        printf("Es ist ein Montag\n");
    }
    else if (wday(year,month,day)==2){

        printf("Es ist ein Dienstag\n");
    }
    else if (wday(year,month,day)==1){

        printf("Es ist ein Mittwoch\n");
    }
    else if (wday(year,month,day)==3){

        printf("Es ist ein Donnerstag\n");
    }
    else if (wday(year,month,day)==4){

        printf("Es ist ein Freitag\n");
    }
    else if (wday(year,month,day)==5){

        printf("Es ist ein Samstag\n");
    }

}
