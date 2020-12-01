#include <stdio.h>
#include <math.h>

struct point_float {
    float x1;
    float x2;
};

struct point_double {
    double x1;
    double x2;
};

struct point_float solve_in_floats(float delta_float) {
    struct point_float answer_float;

    answer_float.x2 = (2.0001f + delta_float - 2.0f) / 0.0001f;
    answer_float.x1 = 2.0f - answer_float.x2;

    return answer_float;
}


struct point_double solve_in_doubles(double delta_double) {
    struct point_double answer_double;

    answer_double.x2 = (2.0001f + delta_double - 2.0f) / 0.0001f;
    answer_double.x1 = 2.0f - answer_double.x2;

    return answer_double;
}

float float_distance(struct point_float p1, struct point_float p2) {
    return sqrtf((p1.x1 - p2.x1) * (p1.x1 - p2.x1) + (p1.x2 - p2.x2) * (p1.x2 - p2.x2));
}

float double_distance(struct point_double p1, struct point_double p2) {
    return sqrtf((p1.x1 - p2.x1) * (p1.x1 - p2.x1) + (p1.x2 - p2.x2) * (p1.x2 - p2.x2));
}

int main() {
    struct point_float real_float_answer = solve_in_floats(0.0f);
    struct point_double real_double_answer = solve_in_doubles(0.0);

    float delta_float = 0.0001f;
    double delta_double = 0.0001;

    float epsilon_float = 0.000001f;
    double epsilon_double = 0.000001;

    struct point_float float_answer = solve_in_floats(delta_float);
    float result_deviaton_in_float = float_distance(real_float_answer, float_answer);

    struct point_double double_answer = solve_in_doubles(delta_double);
    double result_deviaton_in_double = double_distance(real_double_answer, double_answer);

    while (result_deviaton_in_float >= epsilon_float)
    {
        printf("Delta: %.8f, deviation: %.8f\n", delta_float, result_deviaton_in_float);
        delta_float /= 2.0f;
        float_answer = solve_in_floats(delta_float);
        result_deviaton_in_float = float_distance(real_float_answer, float_answer);
    }

    while (result_deviaton_in_double >= epsilon_float)
    {
        printf("Delta: %.8f, deviation: %.8f\n", delta_double, result_deviaton_in_double);
        delta_double /= 2.0f;
        double_answer = solve_in_doubles(delta_double);
        result_deviaton_in_double = double_distance(real_double_answer, double_answer);
    }
}