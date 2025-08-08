#include <math.h>

int main() {
    float a = 5.5;
    float b = 2.2;
    float result;
    result = a + b;
    result = a - b;
    result = a * b;
    result = a / b;
    int comparison_result;
    if (a > b) {
        comparison_result = 1; 
    } else if (a < b) {
        comparison_result = -1;
    } else {
        comparison_result = 0;
    }

    float infinity = INFINITY;
    float nan_value = NAN;

    float special_result;

    special_result = a / 0.0;
    special_result = a * infinity;

    special_result = a / infinity;
    special_result = a * nan_value;

    return 0;
}
