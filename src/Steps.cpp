/*

	You have N steps to climb .
	You can either take one step or two steps at a time .
	You need to find the total number of ways you can reach N steps .

	Example : For N=4 , You can either reach 4 steps in following ways
	->1111
	->112
	->121
	->211
	->22
	So total number of ways is 5

	Input : A Integer denoting N (number of steps )
	Output : Return an Integer denoting the number of ways to reach N steps

	Example Input : get_steps(5)
	Example Output : Returns 8

	Note : Test Cases would be small <25.

*/
#include "stdafx.h"


int count_steps(int s, int i, int *count)
{
	if (i <s)
	{
		count_steps(s, i + 1, count);
		count_steps(s, i + 2, count);
	}
	else if (i == s&&s != 0)
	{
		(*count)++;
	}
	return *count;
}
int get_steps(int s)
{
	int i = 0, count = 0;
	return count_steps(s, i, &count);

}