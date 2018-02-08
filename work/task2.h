#define SIZE 51


void clearMatrix(char(*arr)[SIZE + 1]);	//заполнение двумерного массива(матрицы) пробелами
void fillMatrix(char(*arr)[SIZE + 1]);	//заполнение верхнего левого квадранта матрицы звездочками
void setMatrix(char(*arr)[SIZE + 1]);	//копирование элементов в другие области матрицы
void printMatrix(char(*arr)[SIZE + 1]);	//печать матрицы