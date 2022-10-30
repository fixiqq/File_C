#include "Header.h"

int main() {
	system("chcp 1251>nul");
	FILE* file;
	char bufer[] = "koefs.txt";
	float a, b, c;

	if ((file = fopen(bufer, "w+t")) != NULL)
	{
		printf("Введите коэффициенты a, b, c\n");

		printf("a = ");
		scanf("%f", &a);
		printf("b = ");
		scanf("%f", &b);
		printf("c = ");
		scanf("%f", &c);

				if ( (a > MIN && a < MAX && a != 0) && (c > MIN && c < MAX) && (b > MIN && b < MAX))		
				{
					fprintf(file, "%f\n%f\n%f", a, b, c);
					fclose(file);

					if ((file = fopen(bufer, "r")) == NULL)
					{
						printf("Не удалось открыть файл");
						getchar();
						return 0;
					}
					else
					{
						printf("Считывание из файла koefs.txt\n");
						while ((fscanf(file, "%f\n%f\n%f", &a, &b, &c)) != EOF)
						{

							printf("a = %f\nb = %f\nc = %f", a, b, c);
						}
					}	
					FILE* answer = fopen("answer.txt", "w+t");

					QuadraticEquation(a, b, c, answer);
				}
				else
				{
					printf("\nВведите другие значения");
				}
	}

	else
	{
		printf("Не удалось открыть файл\n");
		getchar();
		return 0;
	}

}
void QuadraticEquation(float a, float b, float c, FILE* file)
{
	float x1, x2, discriminant;
	discriminant = powf(b, 2.0) - 4 * a * c;
	if (discriminant < 0)
	{
		fprintf(file, "Нет решений\n");
		printf("\nНет решений\n");
	}
	if (discriminant == 0)
	{
		x1 = (-b) / (2 * a);
		fprintf(file, "Дискриминант равен %f\n", discriminant);
		printf("\nДискриминант равен %f\n", discriminant);
		fprintf(file, "x1 = %f", x1);
		printf("x1 = %f", x1);
	}
	if (discriminant > 0)
	{
		x1 = ((-b) - sqrt(discriminant)) / (2 * a);
		x2 = ((-b) + sqrt(discriminant)) / (2 * a);
		fprintf(file, "Дискриминант равен %f\n", discriminant);
		printf("\nДискриминант равен %f\n", discriminant);
		fprintf(file, "x1 = %f, x2 = %f", x1, x2);
		printf("x1 = %f, x2 = %f", x1, x2);
	}
}