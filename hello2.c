#include"stdio.h"
#include <math.h>
#include <stdlib.h>

#define MAX_N 20

int calcSum(int nums[], int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum = sum + nums[i];
    }

    return sum;
}

double calcAve(int nums[], int n) {

    if (n == 0) {
        printf("nが0なので平均が計算できません\n");
        return 0;
    }

    int sum = calcSum(nums, n);
    double ave = (double)sum / (double)n;

    return ave;
}

double calcVar(int nums[], int n) {

    if (n == 0) {
        printf("nが0なので分散が計算できません\n");
        return 0;
    }

    double ave = calcAve(nums, n);
    double sum;

    sum = 0;
    for (int i = 0; i < n; i++) {
        double y = (nums[i] - ave) * (nums[i] - ave);
        sum = sum + y;
    }

    double var = sum / n;

    return var;
}

double calcSd(int nums[], int n) {

    double var = calcVar(nums, n);
    double sd = sqrt(var);

    return sd;
}

int cmpnum(const void* n1, const void* n2)
{
    if (*(long*)n1 > *(long*)n2)
    {
        return -1;
    }
    else if (*(long*)n1 < *(long*)n2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main() {
    int nums_s[MAX_N] = { 65 ,80 ,67 ,35 ,58 ,60 ,72 ,75 ,68 ,92 ,36 ,50 ,25 ,85 ,46 ,42 ,78 ,62 ,84 ,70 };
    int nums_e[MAX_N] = { 44 ,87 ,100 ,63 ,52 ,60 ,58 ,73 ,55 ,86 ,29 ,56 ,89 ,23 ,65 ,84 ,64 ,27 ,86 ,84 };
    int n = MAX_N;
    double z;
    printf("理科\n");
    printf("合計：%d\n", calcSum(nums_s, n));
    printf("平均：%f\n", calcAve(nums_s, n));
    printf("標準偏差%f\n", calcSd(nums_s, n));
    for (int i = 0; i < MAX_N; i++) {
        z = 10 * (nums_s[i] - calcAve(nums_s, n)) / calcSd(nums_s, n) + 50;
        printf("%d人目の偏差値:%f\n", i+1, z);
    }
    printf("降順\n");
    qsort(nums_s, sizeof(nums_s) / sizeof(nums_s[0]), sizeof(long), cmpnum);
    for (int i = 0; i < sizeof(nums_s) / sizeof(nums_s[0]); i++)
    {
        printf("%d\n", nums_s[i]);
    }
    printf("\n");
    printf("英語\n");
    printf("合計：%d\n", calcSum(nums_e, n));
    printf("平均：%f\n", calcAve(nums_e, n));
    printf("標準偏差%f\n", calcSd(nums_e, n));
    for (int i = 0; i < MAX_N; i++) {
        z = 10 * (nums_e[i] - calcAve(nums_e, n)) / calcSd(nums_e, n) + 50;
        printf("%d人目の偏差値:%f\n", i+1, z);
    }
    printf("降順\n");
    qsort(nums_e, sizeof(nums_e) / sizeof(nums_e[0]), sizeof(long), cmpnum);
    for (int i = 0; i < sizeof(nums_e) / sizeof(nums_e[0]); i++)
    {
        printf("%d\n", nums_e[i]);
    }

    return 0;
}
