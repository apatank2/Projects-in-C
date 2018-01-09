#include<stdio.h>
#include <math.h>
#include <assert.h>

//Function to calcualte next multiple of two given values
int findNextMultiple(int number1, int number2){
	//TODO
	float result_multiple;
    number1++;
	while (1)
    {
       result_multiple = number1%number2;
       if (result_multiple == 0 )
       {
           break;
       } else
       {
           number1++;
       }
    }
    return number1;
}

//Function to convert Fahrenheit to Celsuius
float convertFtoC(float fahrenheit){
	//TODO
	int i = 32;
	float j = 1.8;
	return ((fahrenheit - i)) / j;
}

//Function to calculate fibonacci series for first 20 numbers
int fibonacci(){
	//TODO
	int fibo_list = 20;
	int array[fibo_list];
	array[0] = 0;
	array[1] = 1;
	int i = 2;
	int result =0;
	for (i;i < fibo_list;i++)
    {
     array[i] = array[i-1] + array[i-2];
    }
    result = array[fibo_list-1];
    return result;
}

//Function to cast a long to an int
int castToInt(long num){
	//TODO
	int i = num;
	return i;
}

//Function to cast a long to an double
double castToDouble(long num){
	//TODO
	double i = num;
	return i;
}

//Function to cast a long to an char
char castToChar(long num){
	//TODO
	char i = num;
	return i;
}

//The main driver
int main(){

	//TODO Write code to print "Hello World"
	printf("\n\tHello World\n");

	//TODO For given value of x calculate value of expression
	printf("\n\t=============================\n");
	printf("\t=           PART A          =\n");
	printf("\t=============================\n\n");

	printf("\n\t=========Starting Expression Conversion Tests===========\n");
	//Write code to evaluate the following expression: 3x^3 - 5x^2 + 6 for x = 2.5.
	float x = 2.5;
	float result = (3 * (x*x*x)) - (5 * (x*x)) + 6; //TODO write your expression here

	assert(result == 21.625);

	//Write code to evaluate the following expression: (4 × 10^8 + 2 × 10^-7) / (7 × 10^-6 + 2 × 10^8)
	float result_exp = 1;
	float result_exp1;
	float result_exp2;
	int raise_to = 8;
	int raise_to1 = 7;
	int raise_to2 = 6;
	int i = 1;
	for ( i ; i <= raise_to; i++)
	{
         result_exp = result_exp * 10;
         if (i==raise_to1)
         {
          result_exp1 = result_exp;
         }
        if (i==raise_to2)
        {
         result_exp2 = result_exp;
        }
       }
	result = ((4 * result_exp) + (2 * (1 / result_exp1))) / ((7 * (1/result_exp2)) + (2 * result_exp)); //TODO write your expression here

	assert(result == 2.0);

	printf("\n\t\t....Converting Expressions Tests Passed\n");

	printf("\n\t=========Starting Next Multiple Tests===========\n");
	//For given numbers find next multiple
	int number1 = 365, number2 = 7;
	assert(371 == findNextMultiple(number1,number2));

	number1 = 12258; number2 = 28;
	assert(12264 == findNextMultiple(number1,number2));

	number1 = 996; number2 = 4;
	assert(1000 == findNextMultiple(number1,number2));

	printf("\n\t\t....Next Multiple Tests Passed\n");

	printf("\n\t=========Starting Fahrenheit to Celsius Tests===========\n");

	//Convert Fahrenheit value to Celsius value
	float fahrenheit = 95;
	float celsius = convertFtoC(fahrenheit);
	assert(35.0 == celsius);

	fahrenheit = 32;
	celsius = convertFtoC(fahrenheit);
	assert(0.0 == celsius);

	fahrenheit = -40;
	celsius = convertFtoC(fahrenheit);
	assert(-40.0 == celsius);
	printf("\n\t\t....Fahrenheit to Celsius Tests Passed\n");

	printf("\n\t=============================\n");
	printf("\t=           PART B          =\n");
	printf("\t=============================\n\n");

	printf("\n\t=========Starting Casting Tests===========\n");
	//Testing our Casting and how its loses values for wrong casting
	long int large_num = 9223372036854775617;
	int large_num_as_int = castToInt(large_num);
	assert(-191 == large_num_as_int);
	double large_num_as_double = castToDouble(large_num);
	assert(9223372036854775808.0 == large_num_as_double);
	char large_num_as_char = castToChar(large_num);
	assert('A' == large_num_as_char);

	printf("\n\t\t....Casting Tests Passed\n");

	printf("\n\t=============================\n");
	printf("\t=           PART C          =\n");
	printf("\t=============================\n\n");

	printf("\n\t=========Starting Fibonacci Tests===========\n");
	//finding fibonacci series for first 20 numbers
	assert(4181 == fibonacci());

	printf("\n\t\t....Fibonacci Tests Passed\n");

	printf("\n\t=========ALL TESTS PASSED===========\n");

	return 0;
}
