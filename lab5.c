// Jacob Zimmer
// jlz6w7
// CS1050 Lab 5

#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int menu(void);
double sphereVolume(float);
double rectangleArea(float, float);
double triangleArea(float, float);
double trapezoidArea(float, float, float);

int main(void)
{
    printf("\n*** Jacob's Geometry Calculator ***\n");
    while (1)
    {
        float radius, base, height, width1, width2, length;
        float result;

	int choice = menu();

        switch (choice)
        {
            case 1:
                printf("*** Sphere Volume ***\nPlease enter the radius: ");
                scanf("%f", &radius);
                    while (radius <= 0)
                    {
                        printf("Invalid value. Re-enter a positive value only: ");
                        scanf("%f", &radius);
                    }
                result = sphereVolume(radius);
                printf("The volume is %lf units.\n", result);
                continue;
            
            case 2:
                printf("*** Rectangle Area *** \nPlease enter the length and height, separated by a space: ");
                scanf("%f %f", &length, &height);
                    while (length <= 0 || height <= 0)
                    {
                        printf("One or more invalid values. Re-enter two positive values separated by a space: ");
                        scanf("%f %f", &length, &height);
                    }
                result = rectangleArea(length, height);
                printf("The area is %lf units.\n", result);
                continue;
            
            case 3:
                printf("*** Triangle Area *** \nPlease enter the base and height, separated by a space: ");
                scanf("%f %f", &base, &height);
                    while (base <= 0 || height <= 0)
                    {
                        printf("One or more invalid values. Re-enter two positive values separated by a space: ");
                        scanf("%f %f", &base, &height);
                    }
                result = triangleArea(base, height);
                printf("The area is %lf units.\n", result);
                continue;

            case 4:
                printf("*** Trapezoid Area *** \nPlease enter the height then the two width values, separated by spaces: ");
                scanf("%f %f %f", &height, &width1, &width2);
                    while (height <= 0 || width1 <= 0 || width2 <= 0)
                    {
                        printf("One or more invalid values. Re-enter three positive values separated by spaces: ");
                        scanf("%f %f %f", &height, &width1, &width2);
                    }
                result = trapezoidArea(height, width1, width2);
                printf("The area is %lf units.\n", result);
                continue;

            case 0:
                printf("Exiting geometry calculator...\n\n");
                return 0;

            default:
                printf("That is not a valid selection!\nReturning to main menu...\n");
                continue;
        } // end switch
    } // end while

    return 0;
} // end main

int menu(void)
{
    int choice;

    printf("***********************************\nPlease make a selection from the following options:\n1) Volume of a sphere\n2) Area of a rectangle\n3) Area of a triangle\n4) Area of a trapezoid\n0) Exit\n...: ");
    scanf("%d", &choice);

    return choice;
}

double sphereVolume(float radius)
{
    double volume = 4 * PI * pow(radius, 3) / 3;
    return volume;
}

double rectangleArea(float length, float height)
{
    double area = length * height;
    return area;
}

double triangleArea(float base, float height)
{
    double area = (base * height) / 2;
    return area;
}

double trapezoidArea(float height, float width1, float width2)
{
    double area = ((width1 + width2) * height) / 2;
    return area;
}
