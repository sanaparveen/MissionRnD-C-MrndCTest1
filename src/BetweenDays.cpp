/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};


int fourDigit(struct node *date);
int twoDigit(struct node *date);

const int noOfMonthDays[12] = { 31, 28, 31, 30, 31, 30,
31, 31, 30, 31, 30, 31 };
int countLeapYear(int mon, int years)
{
	if (mon <= 2)
		years--;
	return (years / 4) - (years / 100) + (years / 400);
}

int dateDifference(int day1, int mon1, int year1, int day2, int mon2, int year2)
{

	int index;
	long int d1, d2;
	d1 = year1 * 365 + day1;
	for (index = 0; index < mon1 - 1; index++)
		d1 += noOfMonthDays[index];
	d1 += countLeapYear(mon2, year2);

	d2 = year2 * 365 + day2;
	for (index = 0; index<mon2 - 1; index++)
		d2 += noOfMonthDays[index];
	d2 += countLeapYear(mon2, year2);

	return (d2 - d1) - 1;
}

int between_days(struct node *date1head, struct node *date2head){

	int day1 = 0, day2 = 0, mon1 = 0, mon2 = 0, year1 = 0, year2 = 0, index, diff = 0;
	if (date1head == NULL || date2head == NULL)
		return -1;

	day1 = twoDigit(date1head);
	date1head = date1head->next->next;
	mon1 = twoDigit(date1head);
	date1head = date1head->next->next;
	year1 = fourDigit(date1head);
	day2 = twoDigit(date2head);
	date2head = date2head->next->next;
	mon2 = twoDigit(date2head);
	date2head = date2head->next->next;
	year2 = fourDigit(date2head);

	if (day1 < 1 || day2 < 1 || mon1 < 1 || mon2 < 1 || year1 < 0 || year2 < 0)
		return -1;
	if (day1 > 31 || day2 >  31 || mon1 > 12 || mon2 > 12 || year1 > 9999 || year2 > 9999)
		return -1;

	diff = dateDifference(day1, mon1, year1, day2, mon2, year2);
	if (diff < 1)
		return 0;

	return diff;
}
int twoDigit(struct node *date)
{
	int val;
	val = date->data;
	date = date->next;
	val = val * 10 + date->data;
	return val;

}
int fourDigit(struct node *date)
{
	int y = 0;
	while (date != NULL)
	{
		y = y * 10 + date->data;
		date = date->next;
	}
	return y;

}
