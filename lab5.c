/*
A. Code a function to generate a string s1 (length 40 characters), containing random patterns of upper-
case letters ‘A’ – ‘Z’. 
B. Code a function to allow the user to enter a string s2 (minimum length 2 characters, maximum length 
20 characters; actual length is user’s choice) containing a random pattern of upper-case letters ‘A’ – ‘Z’. 
String length and user input must be validated. 
C. Code a function to allow the user to enter a replacement character ch. 
D.  Code a user define function strfilter(s1, s2, ch) that searches s1 and replaces any occurrences of any of 
the characters contained in s2 with character ch. 
E. Output the generated string, the user entered string, replacement character and filtered string from 
the main program. 
Modify lab 4B by replacing all array notations with pure pointer notations. However, arrays must still be 
defined. No subscripts in functions. 

Score: 100/100

 */

#include <stdio.h>
#include <stdlib.h>

/*Function Prototypes*/
int main();
void s1(char *random, int max);
int s2(char *s2_input, int index);
void strfilter(char *random, char *s2_input, char replacement);

int main() 
{
	for (;;) {
		int s1_index = 41;
		char s1_random[s1_index];
		s1(s1_random, s1_index);


		
		printf("\ns1 = ");
		puts(s1_random);
		printf("s2 = ");

		int s2_index = 21;
		char s2_input[s2_index];
		int len = s2(s2_input, s2_index);

		if (len < 2) {
			printf("Size too small\n");
			exit(0);
		}
		printf("ch = ");
		int replacement = getchar();
		if (replacement == EOF)
			break;

		while (getchar() != '\n');

		printf("\n");
		strfilter(s1_random, s2_input, replacement);

		printf("\ns3 = ");
		puts(s1_random);

		printf("Do you wish to run again? Yes(Y), No(N) ");
		int run = getchar();

		if (run == EOF || run == 'N' || run == 'n')
			break;
		while (getchar() != '\n');
	}
}

void s1(char *random, int max) {

	int limit = 0;


	char characters;

	/* random generator */
	for (; max > 1; --max) {
		characters = 'A' + (rand() % 26);
		*random++ = characters;
	}

	*random = 0;

}



int s2(char *s2_input, int max) {
	int input;
	int count = 0;

	--max;

	while ((input = getchar()) != EOF) {
		if (input == '\n')
			break;

		if (input < 65 || input > 90) {
			printf("invalid input\n");
			exit(0);
		}

		if (max <= 0) {
			printf("Size too big\n");
			exit(1);
		}

		*s2_input++ = input;
		--max;
		++count;
	}

	*s2_input = 0;

	return count;
}


/* replacement function */
void strfilter(char *random, char *s2_input, char replacement) {
	while (*s2_input) {
		char *temp = random;

		while (*temp) {
			if (*temp == *s2_input)
				*temp = replacement;
			temp++;
		}
		s2_input++;
	}
}

/*
   OUTPUT

   s1 = LRFKQYUQFJKXYQVNRTYSFRZRMZLYGFVEULQFPDBH
   s2 = ABCDEFGHIJKLMNOP
   ch = *
   s3 = *R**QYUQ***XYQV*RTYS*RZR*Z*Y**V*U*Q*****
   Do you wish to run again? Yes(Y), No(N) Y



   s1 = LRFKQYUQFJKXYQVNRTYSFRZRMZLYGFVEULQFPDBH
   s2 = YUTLEWJDSKAL
   ch = *
   s3 = *QRRCR**NX**OQQ****I*G*PHC*PI**HB*F*FV**
   Do you wish to run again? Yes(Y), No(N) Y



   s1 = LRFKQYUQFJKXYQVNRTYSFRZRMZLYGFVEULQFPDBH
   s2 = Y
   Size too small  



   s1 = JRFJQYUQFJJXYQVNRTYJFRZRMZJYGFVEUJQFPJBH
   s2 = KLJDSAJKLDSAJKLDSAJKLDJSA
   Size too big



   s1 = DQRRCRWDNXEUOQQEKLAITGDPHCSPIJTHBSFYFVLA
   s2 = hjdksahdjsak
   invalid input

	s1 = LRFKQYUQFJKXYQVNRTYSFRZRMZLYGFVEULQFPDBH
	s2 = JDKASLDJKSAL
	ch = &
	s3 = &RF&QYUQF&&XYQVNRTY&FRZRMZ&YGFVEU&QFP&BH
	Do you wish to run again? Yes(Y), No(N) N

   s1 = LRFKQYUQFJKXYQVNRTYSFRZRMZLYGFVEULQFPDBH
   s2 = JKLDSJKLDSAJKLDSA
   ch = J
   s3 = JRFJQYUQFJJXYQVNRTYJFRZRMZJYGFVEUJQFPJBH
   Do you wish to run again? Yes(Y), No(N) N

 */
