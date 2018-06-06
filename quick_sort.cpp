#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <conio.h>

struct Info
{
	char S[30];
};

void Sort1(Info *a, int L, int R) {

	int i, j, x, t;
	char b[30];

	i = L;
	j = R;
	x = (i + j) / 2;

	while (i <= j) {
		while (strcmp(a[i].S, a[x].S) < 0) i++;
		while (strcmp(a[j].S, a[x].S) > 0) j--;
		if (i <= j) {
			strcpy(b, a[i].S);
			strcpy(a[i].S, a[j].S);
			strcpy(a[j].S, b);
			i++;
			j--;
		}
	}

	if (i < R) Sort1(a, i, R);
	if (j > L) Sort1(a, L, j);

}


void Sort2(Info *a, int L, int R) {

	int i, j, x, t;
	char b[30];

	i = L;
	j = R;
	x = (i + j) / 2;

	while (i <= j) {
		while (strcmp(a[i].S, a[x].S) > 0)
			i++;
		while (strcmp(a[j].S, a[x].S) < 0)
			j--;
		if (i <= j) {
			strcpy(b, a[i].S);
			strcpy(a[i].S, a[j].S);
			strcpy(a[j].S, b);
			i++;
			j--;
		}
	}

	if (i < R) Sort2(a, i, R);
	if (j > L) Sort2(a, L, j);

}

void Sort3(int *a, int L, int R) {

	int i, j, x, t,b;

	i = L;
	j = R;
	x = (i + j) / 2;

	while (i <= j) {
		while (a[i]<a[x]) i++;
		while (a[j]>a[x]) j--;
		if (i <= j) {
			b = a[i]; a[i] = a[j]; a[j] = b;
			i++;
			j--;
		}
	}

	if (i < R) Sort3(a, i, R);
	if (j > L) Sort3(a, L, j);

}


void Sort4(int *a, int L, int R) {

	int i, j, x, t,b;


	i = L;
	j = R;
	x = (i + j) / 2;

	while (i <= j) {
		while (a[i]>a[x]) i++;
		while (a[j]<a[x]) j--;
		if (i <= j) {
			b = a[i]; a[i] = a[j]; a[j] = b;
			i++;
			j--;
		}
	}

	if (i < R) Sort4(a, i, R);
	if (j > L) Sort4(a, L, j);

}



int main()
{
	FILE *f;
	Info *a = NULL; int *b=NULL; int n,j,z;
	char ch,sh, file[30];
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);


	do {
		printf("\nN - Считать из файла строки; \K - Считать из консоли;\ V - Вывод;\ S - Отсортировать строки;\H - Отсортировать числа; \ F - Освободить; \E - конец.\nВаш выбор?");
		ch = getchar();   fflush(stdin);
		ch = toupper(ch);
		switch (ch) {
			//----------
		case 'N': if (a) {
			printf("Error: сначала надо освободить память!"); break;
		}
				  printf("Введите название файла \n");
				  scanf("%s",file);
				  f = fopen(file, "rt+");
				  if (f == NULL) {
					  printf("Неудалось открыть файл \n");
					  break;
				  }
				  fscanf(f,"%d",&n);
				  a = new Info[n];
				  b = new int[n];
				  j = 0;
				  for (int i = 0; i < n; i++) {
					  fscanf(f, "%s", a[i].S);
					  z = atoi(a[i].S);
					  if (z)
					  {
						  b[j] = z;
						  j++;
					  };
				  };
				  if (j==0) { delete[] b;b = NULL;
				  };
				  fclose(f);
				  break;
		case 'K': if (a) {
			printf("Error: сначала надо освободить память!"); break;
		}
				  printf("Количество элементов:\n");
				  scanf( "%d", &n);
				  printf("Элементы:\n");
				  a = new Info[n];
				  b = new int[n];
				  j = 0;
				  for (int i = 0; i < n; i++) {
					  scanf("%s", a[i].S);
					  z = atoi(a[i].S);
					  if (z)
					  {
						  b[j] = z;
						  j++;
					  };
					  if (j == 0) {
						  delete[] b; b = NULL;
					  };
				  }
				  break;
		case 'S': if (a)
		{
			printf("\n1 - По возрастанию; 2 - По убыванию.\nВаш выбор?");
			sh = getchar();
			sh = getchar();
			fflush(stdin);
			sh = toupper(sh);
			switch (sh) {
			case '1':
				Sort1(a,0,n-1);
				break;
			case '2':
				Sort2(a,0,n-1);
			}
  	}
		  else { printf("Массив пустой\n"); }
				  break;


		case 'H': if (b)
		{
			printf("\n1 - По возрастанию; 2 - По убыванию.\nВаш выбор?");
			sh = getchar();
				sh = getchar();
			fflush(stdin);
			sh = toupper(sh);
			switch (sh) {
			case '1':
				Sort3(b, 0, j - 1);
				break;
			case '2':
				Sort4(b, 0, j - 1);
			}
		}
				  else { printf("Массив пустой\n"); }
				  break;

		case 'V':
			printf("\n1 - В файл строки; 2 - В консоль строки.3 - В файл числа; 4 - В консоль числа.\nВаш выбор?");
			sh = getchar();
			sh = getchar();
			fflush(stdin);
			sh = toupper(sh);
			switch (sh) {
			case '1': if (!a) { printf("Массив пустой\n"); break;
			}
					  printf("Введите название файла \n");
					  scanf("%s", file);
					  f = fopen(file, "wt+");
					  for (int i = 0; i < n; i++)
						  fprintf(f, "%s ", a[i].S);
					  fclose(f);
					  break;

			case '2':if (!a) { printf("Массив пустой\n"); break;
			}
					 for (int i = 0; i < n; i++)
						 printf("%s ", a[i].S);
					 break;

			case '3':if (!b) { printf("Массив пустой\n"); break;
			}
					 printf("Введите название файла \n");
					 scanf("%s", file);
					 f = fopen(file, "wt+");
					 for (int i = 0; i < j; i++)
						 fprintf(f, "%d ", b[i]);
					 fclose(f);
					 break;
			case '4':if (!b) { printf("Массив пустой\n"); break;
			}
					 for (int i = 0; i < j; i++)
						 printf("%d ", b[i]);
					 break;
			}; break;
		case 'F':
			delete[] a;
			delete[] b;
			a = NULL;
			b = NULL;
			printf("Вся память под массив особождена\n");
			break;
			//-----------------------выход------------------------
		case 'E': return 0;
		default:
			printf("Нет такой команды\nPress any key");
			getch();
			}
			ch = getchar();
	} while (ch != 'E');
return 0;
}

