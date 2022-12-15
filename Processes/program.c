#define _CRT_SECURE_NO_WARNINGS
#define PATH "..\\x64\\Debug\\Solution.exe"
#define READPATH "..\\data.txt"
#define WRITEPATH "..\\res.txt"

#include <Windows.h>
#include <stdio.h>


int main()
{

	system("chcp 1251 > nul");

	FILE* readFile;
	readFile = fopen(READPATH, "r");
	char* stroke = calloc(50, sizeof(char));
	fgets(stroke, 50, readFile);
	fclose(readFile);

	char* str;
	float* array = calloc(3, sizeof(float*));
	str = strtok(stroke, " ");

	for (int i = 0; str != NULL; i++)
	{
		array[i] = atof(str);
		str = strtok(NULL, " ");
	}

	float a = array[0], b = array[1], c = array[2];
	sprintf(stroke, "%f %f %f", a, b, c);
	char* command_line = stroke;

	LPSTARTUPINFOA sti = calloc(1, sizeof(STARTUPINFO));
	LPPROCESS_INFORMATION li = calloc(1, sizeof(PROCESS_INFORMATION));
	CreateProcessA(
		PATH,
		command_line,
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		sti,
		li
	);
	WaitForSingleObject(li->hProcess, 1);
	printf("Ожидание завершения дочернего процесса");
	DWORD ecode;
	GetExitCodeProcess(li->hProcess, &ecode);
	CloseHandle(li->hProcess);
	CloseHandle(li->hThread);
	float root[2];
	FILE* writeFile = fopen(WRITEPATH, "r");
	if (writeFile == NULL)
	{
		printf("При открытие файла возникла ошибка!");
		return 0;
	}
	fseek(writeFile, -1, SEEK_END);
	while (1)
	{
		if (fgetc(writeFile) != '\n')
		{
			fseek(writeFile, -2, SEEK_CUR);
		}
		else
		{
			break;
		}
	}

	for (int i = 0; i < 2; i++)
	{
		fscanf(readFile, " %f", &root[i]);
	}
	if (root[0] != -107374176. && root[1] != -107374176.)
	{
		printf("\nУравнение имеет два корня: %g и %g", root[0], root[1]);
	}
	else if (root[0] != -107374176.)
	{
		printf("\nУравнение имеет один корень: %g", root[0]);
	}
	else
	{
		printf("\nУравнение не имеет ни одного корня");
	}
	return 0;
}