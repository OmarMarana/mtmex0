#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INVALID_INPUT false
#define FAILURE 0

int getSizeOfInput();
bool getInput(int length_of_input, int input_array[]);
int* allocateTheMemory(int length_of_input );
void processTheInput(int length_of_input, int input_array[]);

int main()
{
	int length_of_input = 0;
    length_of_input = getInputSizeFromUser();
    if(length_of_input <= 0)
    {
        return 0;
    }

    int *input_array = allocateMemory(length_of_input);
    if(input_array == NULL)
    {
        printf("memory allocation failed!");
        return FAILURE;
    } 

    int status = getInputFromUser(length_of_input,input_array);
    if(status == INVALID_INPUT)
    {
        printf("Invalid number\n");
        free(input_array);
        return 0;
    }
    
    processInput(length_of_input,input_array);
    free(input_array);
	return 0;
}

int* allocateMemory(int length_of_input)
{
    int *input_array_ptr = malloc(length_of_input * sizeof(int));
    return input_array_ptr;
}


bool getInputFromUser(int length_of_input, int input_array[]) 
{
    printf("Enter numbers:\n");
    int number_index = 0;
    for( number_index = 0 ; number_index < length_of_input; number_index++)
    {
        int current_number = 0;
        if(scanf("%d", &current_number) < 1)
        {
            return false;
        }
        input_array[number_index] = current_number;
    }
    return true;
}

int getInputSizeFromUser()
{
    printf("Enter size of input:\n");
    int length_of_input = 0;
    scanf("%d",&length_of_input);
    if(length_of_input <= 0)
    {
        printf("Invalid size\n");
    }
    return length_of_input;
}

void processInput(int length_of_input, int input_array[])
{
    int i;
    int total_exponent_sum =0;
    for( i = 0 ; i < length_of_input ; i++)
    {
        int current_num = input_array[i];
        int counter_of_2s = 0;
        bool is_reduced_to_one = false;
        while(current_num > 0)
        {
            if(current_num % 2)
            {
                if(current_num == 1)
                {
                    is_reduced_to_one =true;
                }
                break;
            }
            counter_of_2s++; 
            current_num /=2;
        }
        if(is_reduced_to_one)
        {
            total_exponent_sum += counter_of_2s;
        }
        if( is_reduced_to_one)
        {
            printf("The number %d is a power of 2: %d = 2^%d\n",input_array[i],input_array[i],counter_of_2s);
        }
    }
    printf("Total exponent sum is %d\n",total_exponent_sum);
}


