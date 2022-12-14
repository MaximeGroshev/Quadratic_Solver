#include "quad_equ_solver.h"

void welcome_message()
{
    printf("Hello. This function solves quadratic equations.\n");
	printf("Enter coefficients a, b, c into an equation of form ax^2 + bx + c = 0\n");
}

//--------------------------------------------------------------------

 void read_coefficients(double* a, double* b, double* c)
{
    while(scanf("%lf %lf %lf", a, b, c) != 3)
    {
        printf("Input error, repeat the input.");
        skip_input_line();
    }
}

//--------------------------------------------------------------------

 void skip_input_line()
{
    while (getchar() != '\n');
}

//--------------------------------------------------------------------

int ask_user_about_continuing_work()
{
    printf("Thank you for taking part in the demonstration.\n");
    printf("Do you want to continue? Choose the option:\n");
    printf("Press (Enter),to continue. Press any other button to quit.\n");
    skip_input_line();

    int ch = getchar();
    if(ch == '\n')
    {
        printf("Enter coefficients of the equation\n");
        return 1;
    }
    return 0;
}

//--------------------------------------------------------------------

void output_equation_decisins(double x1, double x2, int nRoot)
{
    switch (nRoot)
    {
        case INF_ROOTS:
            printf("Infinite number of roots\n");
            break;

        case NO_ROOTS:
            printf("No roots\n");
            break;

        case ONE_ROOT:
            printf("X=%.2lg\n", x1);
            printf("Result was rounded to the first significant number\n");
            break;

        case TWO_ROOTS:
            printf("X1 = %.2lg; X2 = %.2lg\n", x1, x2);
            printf("Result was rounded to the first significant number\n");
            break;

        default:
            ASSERT("Error in the working of the program");
    }
}
