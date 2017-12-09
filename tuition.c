//Claire Hough
//cnhfg6
//CS1050 HW1

#include <stdio.h>

int main (void)
{
	int ID; //student ID
	int CredHrs; //total credit hours
	int OOSR; // out of state resident
	int CoE; //College of Engineering credit hours
	float BaseTuition; //base tuition cost
	float GS; //Grant or Scholarship money
	float GrandTotal; // grand tuition total

//asking for ID
	printf("\nEnter a valid student ID to calculate a tuition statement");
	printf(" or enter \"0\" to exit the program.\n");
	scanf("%d", &ID);

//while loop to repeat program
while (ID != 0)
{

//checking if ID is valid
	while (ID > 19999999 || ID < 10000000)
	{

//allows user to quit
		if (ID > 19999999 || ID < 10000000)
		{
			printf("\nID entered is either not 8 digits long");
			printf(" and/or does not start with a 1.\nRenter a");
			printf(" valid ID, or \"0\" to exit.\n");
			scanf("%d", &ID);
		}
		if (ID == 0)
		{
			return 0;
		}
	}

//asking for number of credit hours
	printf("\nEnter how many credit hours you are enrolled in ");
	printf("this semester.\n");
	scanf("%d", &CredHrs);

//calculating base tuition
	BaseTuition = CredHrs * 282.00;

//asking if user is an out of state resident
	printf("\nAre you an out-of-state resident? Enter 1 for yes, ");
	printf("any other value for no.\n");
	scanf("%d", &OOSR);

//checking if user is from out of state and calculating extra cost if so
	if (OOSR == 1)
	{
		BaseTuition += (557.30 * CredHrs);
	}

//asking how many credit hours are from College of Engineering
	printf("\nHow many of your credit hours are from courses within ");
	printf("the College of Engineering?\n");
	printf("Enter the number of credit hours.\n");
	scanf("%d", &CoE);

//checking if College of Enginnering credit hours are valid
	while( CoE > CredHrs)
	{
		printf("\nCredit Hours from the College of Engineering ");
		printf("cannot exceed the total number of credit hours.");
		printf("\nRenter the number of engineering credit hours.\n");
		scanf("%d", &CoE);
	}

//calculating new total tuition
	BaseTuition += (CoE *90.00);

//asking for awarded money total
	printf("\nEnter the total amount of money you have received from");
	printf(" grants and scholarships.\n");
	scanf("%f", &GS);

//checking if awarded money is less than tuition
	while (GS > BaseTuition)
	{
		printf("\nGrant and Scholarship total cannot exceed ");
		printf("Tuition total.\nPlease renter money value.\n");
		scanf("%f", &GS);
	}

//calculating Grand Total
	GrandTotal = BaseTuition - GS;

//final print out
	printf("\n***** TUITION STATEMENT *****\n");
	printf("\nStudent ID : %d", ID);
	printf("\nCredit Hours: %d", CredHrs);
	printf("\n\n*****\n");
	printf("\nBase tuition: $%.2f", BaseTuition);
	printf("\nScholarships and grants: $%.2f", GS);
	printf("\n\n*****\n");
	printf("\nTUITION GRAND TOTAL: $%.2f\n", GrandTotal);

//prompt to repeat program
	printf("\n\nTo calculate a new tuition statement, enter a new ");
	printf("student ID. To exit the program, enter \"0\".\n");

//asking for new ID/allowing user to quit
	printf("Please enter a valid student ID, or \"0\" to quit\n");
	scanf("%d", &ID);
}

return 0;

}
