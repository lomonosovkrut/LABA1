
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h> 
#include <cstdio>
#include <stdlib.h>
#include <time.h>

int main() {
    setlocale(LC_ALL, "RUS");
    int rows, cols, i, j, count = 0;

    // Получение размера массива от пользователя
    printf("Введите количество строк: ");
    scanf("%d", &rows);
    printf("Введите количество столбцов: ");
    scanf("%d", &cols);

    // Создание двумерного динамического массива
    int** arr = (int**)malloc(rows * sizeof(int*));
    for (i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }

    // Ввод элементов массива от пользователя
    srand(time(NULL));
    printf("Введите элементы массива:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            arr[i][j] = rand() % 100;
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
  

    // Подсчет количества элементов кратных 4
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (arr[i][j] % 4 == 0) {
                count++;
            }
        }
    }

    // Вывод результата
    printf("Количество элементов кратных 4: %d\n", count);

    // Освобождение памяти
    for (i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
