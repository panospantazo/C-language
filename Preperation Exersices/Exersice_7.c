#include <stdio.h>
#include <stdlib.h>

void insert_sorted_array(double **arr, int *n, double num);


int main() {
    double *arr = (double *)malloc(5 * sizeof(double));
    int n = 5,i;
    double num = 11.12;
    
    if (arr == NULL) {
        printf("Memory Problem.\n");
        return 1;
    }
    
    arr[0] = 1.2;
    arr[1] = 3.4;
    arr[2] = 5.6;
    arr[3] = 7.8;
    arr[4] = 9.0;

    printf("Beggining Array:\n");
    for (i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    insert_sorted_array(&arr, &n, num);

    printf("\nAfter array insert of %.2f:\n", num);
    for (i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    
    // ����������� ��� ������ ��� ������
    free(arr);
    
    return 0;
}

void insert_sorted_array(double **arr, int *n, double num) {
    // �������� ������ ��� ���� ��� ������ �� ��� �������� ��������
    double *new_arr = (double *)malloc((*n + 1) * sizeof(double));
    
    // �� � �������� �������, ������������ ��� �� ���������
    if (new_arr == NULL) {
        printf("Memory Problem.\n");
        return;
    }
    
    int i = *n - 1;
    
    // ������������ �� �������� ��� ������ ������ ���� ��� ������
    while (i >= 0 && (*arr)[i] > num) {
        new_arr[i + 1] = (*arr)[i];
        i--;
    }
    
    // ��������� ��� ��� ������ ��� ����� ����
    new_arr[i + 1] = num;
    
    // ������������ �� �������� �������� ��� ������ ������ ���� ��� ������
    while (i >= 0) {
        new_arr[i] = (*arr)[i];
        i--;
    }
    
    // ����������� ��� ������������ ������ ��� ������ ������
    free(*arr);
    
    // ������������� ��� ������ ������ �� ��� ��� ������
    *arr = new_arr;
    
    // ������ ��� �������� ��� ������
    (*n)++;
}
