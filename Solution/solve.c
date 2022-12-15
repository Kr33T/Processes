#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <math.h>
#define WRITEPATH "..\\res.txt"

void decision(float a, float b, float c);

int main(int argc, char* argv[])
{
	float* array = calloc(3, sizeof(float*));

	for (int i = 0; i < 3; i++)
	{
		array[i] = atof(argv[i]);
	}

	float a = array[0], b = array[1], c = array[2];
	if (a == 0)
	{
		printf("��������� a �� ����� ��������� �������� 0 (����)!");
		return 0;
	}
	if (a == -107374176. || b == -107374176. || c == -107374176. || isinf(a) != 0 || isinf(b) != 0 || isinf(c) != 0)
	{
		printf("������� ������ �����������!");
		return 0;
	}
	decision(a, b, c);
	return 0;
}

void decision(float a, float b, float c)
{
	FILE* writeFile = fopen(WRITEPATH, "w");
	if (a == 0 && b == 0 && c == 0)
	{
		printf("������ � ��������� ���");
		fprintf(writeFile, "������ � ��������� ���");
	}
	else if (a != 0 && b != 0 && c != 0)
	{
		float D;
		D = pow(b, 2) - (4 * a * c);

		fprintf(writeFile, "������������: %f\n", D);

		if (D < 0)
		{
			fprintf(writeFile, "������ � ��������� ���");
		}
		else if (D == 0)
		{
			float x;
			x = -b / (2 * a);
			fprintf(writeFile, "� ��������� ���� ���� ������:\n%g", x);
		}
		else if (D > 0)
		{
			float x1, x2;
			x1 = (-b + sqrt(D)) / (2 * a);
			x2 = (-b - sqrt(D)) / (2 * a);
			fprintf(writeFile, "��������� ����� ��� �����:\n%g %g", x1, x2);
		}
	}
	else if (a == 0 && c == 0)
	{
		fprintf(writeFile, "� ��������� ������� ���� ������:\n0");
	}
	else if (b == 0 && c == 0)
	{
		fprintf(writeFile, "��������� ����� ���� ������:\n0");
	}
	else if (b == 0)
	{
		c *= -1;
		c /= a;
		if (c < 0)
		{
			fprintf(writeFile, "������ � ��������� ���");
		}
		else
		{
			c = sqrt(c);
			fprintf(writeFile, "� ��������� ������� 2 �����:\n%g %g", c, -c);
		}
	}
	else if (c == 0)
	{
		fprintf(writeFile, "��������� ����� ��� �����:\n0 %g", -b / a);
	}
	else if (a == 0)
	{
		c *= -1;
		c /= b;
		fprintf(writeFile, "��������� ����� ���� ������:\n%g", c);
	}
	fclose(writeFile);
}