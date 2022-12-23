/*
Input 3 positive integers from the keyboard, determine if they are valid sides of a triangle. If the 
sides do form a valid triangle, output the 3 sides, type of triangle - equilateral, isosceles, or 
scalene - and the area of the triangle. If the three integers are not the valid sides of a triangle, 
output the 3 sides and an appropriates error message. Be sure to comment and error check in 
your program. Your program needs to be in a loop asking whether the user wants to continue 
entering another set of numbers with a Y/N type of an answer (one character). 

Grade: 100/100

*/

#include <stdio.h>
#include <math.h>


int main ()

{

	char run = 'Y';
	while(run != 'N')
	{

		printf("Input 3 positive integers to form a tringle\n");
		float side1, side2, side3;

		printf("=========================\n");

		printf("Enter the first side ");
		scanf("%f", &side1);

		printf("Enter the second side ");
		scanf("%f", &side2);

		printf("Enter the third side ");
		scanf("%f", &side3);


		float sum = (side1 + side2 + side3) / 2;
		float area = sqrt(sum * (sum - side1) * (sum - side2) * ( sum - side3) );

		if (side1 < 0 || side2 < 0 || side3 <0)
		{

			printf("Invalid Input, there is a negative integer\n");
			printf("First Side: %f\n", side1);
			printf("Second Side: %f\n", side2);
			printf("Third Side: %f\n", side3);

		}

		else if (side1 == side2 && side1 == side3 && side2 == side3)
		{
			printf("Equalatoral Tringle\n");
			printf("First side: %f\n", side1);
			printf("Second side: %f\n", side2);
			printf("Third side: %f\n", side3);
			printf("Area: %f\n", area );

		}

		else if (side1 == side2 || side2 == side3 || side1 == side3)
		{
			printf("Isoceles\n");
			printf("First Side is %f\n", side1);
			printf("Second Side is %f\n", side2);
			printf("Third Side is %f\n", side3);
			printf("Area is %f\n", sqrt(area) );

		}

		else if (side1 + side2 <= side3 || side2 + side3 <= side1 || side1 + side3 <= side2)
		{
			printf("That is not a triangle\n");
			printf("First Side is %f\n", side1);
			printf("Second Side is %f\n", side2);
			printf("Third Side is %f\n", side3);

		}

		else 
		{
			printf("Scalene\n");
			printf("First Side is %f\n", side1);
			printf("Second Side is %f\n", side2);
			printf("Third Side is %f\n", side3);
			printf("Area is %f\n", sqrt(area) );

		}

		printf("Do you wish to run again? Yes(Y), No(N) ");
		scanf("%c", &run);
	}

}



/*OUTPUT
Input 3 positive integers to form a tringle
=========================
Enter the first side 1
Enter the second side 2
Enter the third side 3
That is not a triangle
First Side is 1.000000
Second Side is 2.000000
Third Side is 3.000000
Do you wish to run again? Yes(Y), No(N) Y

Input 3 positive integers to form a tringle
=========================
Enter the first side 2
Enter the second side 2
Enter the third side 2
Equalatoral Tringle
First side: 2.000000
Second side: 2.000000
Third side: 2.000000
Area: 1.732051
Do you wish to run again? Yes(Y), No(N) Y

Input 3 positive integers to form a tringle
=========================
Enter the first side 2
Enter the second side 1
Enter the third side 2
Isoceles
First Side is 2.000000
Second Side is 1.000000
Third Side is 2.000000
Area is 0.983995
Do you wish to run again? Yes(Y), No(N) Y

Input 3 positive integers to form a tringle
=========================
Enter the first side -9
Enter the second side 9
Enter the third side 9
Invalid Input, there is a negative integer
First Side: -9.000000
Second Side: 9.000000
Third Side: 9.000000
Do you wish to run again? Yes(Y), No(N) N
PROGRAM ENDS
*/

