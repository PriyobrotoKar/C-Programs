#include<stdio.h>
#define PI 3.14

int main(){
    int r;
    double area = 0.0;

    printf("Enter the radius of the circle: ");
    scanf("%d", &r);

    area = PI * r * r;

    printf("Area of the circle is: %0.2f\n", area);

    return 0;
}
