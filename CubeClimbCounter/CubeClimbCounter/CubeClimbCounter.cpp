#include <iostream>
#include "windows.h"
#include "CubeClimbFunction.h"
#include "WorkWithIFDInTxtFile.h"

/**
 * @brief Главная функция программы.
 *
 * Эта функция является точкой входа в программу CubeClimbCounter.
 * Она считывает параметры командной строки, обрабатывает их и
 * выполняет необходимые действия для рассчета и записи результата в файл.
 *
 * @param [in] argc - количество аргументов командной строки
 * @param [in] argv - массив аргументов командной строки
 * @return Код завершения программы.
 */
int main(const int argc, char** argv)
{
	// Установка локали для поддержки русского языка
	setlocale(LC_ALL, "Russian");
	// Установка кодировки консоли для поддержки юникода (UTF-8)
	SetConsoleOutputCP(65001);

	try
	{
		// Проверка количества аргументов командной строки
		if (argc != 3)
		{
			throw runtime_error("\nОшибка!\nПрограмма запущена некорректно!\nПример правильного запуска программы : CubeClimbCounter.exe ./input.txt ./output.txt");
		}
		// Проверка наличия значений в аргументах командной строки
		if (argv[1] == nullptr || argv[2] == nullptr)
		{
			throw runtime_error("\nОшибка!\nПрограмма запущена некорректно!\nПример правильного запуска программы : CubeClimbCounter.exe ./input.txt ./output.txt");
		}

		// Имя входного и выходного файлов
		string inputFileName = argv[1];
		string outputFileName = argv[2];

		// Проверка формата входного файла
		if (inputFileName.size() < 4 || inputFileName.substr(inputFileName.size() - 4) != ".txt")
		{
			throw runtime_error("\nОшибка!\nНеверный формат входного файла.\nПожалуйста, используйте файлы с расширением .txt");
		}

		// Проверка формата выходного файла
		if (outputFileName.size() < 4 || outputFileName.substr(outputFileName.size() - 4) != ".txt")
		{
			throw runtime_error("\nОшибка!\nНеверный формат выходного файла.\nПожалуйста, используйте файлы с расширением .txt");
		}

		// Попытка открыть входной файл
		ifstream inputFile(inputFileName);
		if (!inputFile.is_open()) {
			throw runtime_error("\nОшибка!\nФайл с входными данными не существует или не доступен для чтения.\nПожалуйста, укажите существующий входной файл или предоставьте доступ к чтению уже существующего.");
		}

		// Проверка наличия данных во входном файле
		if (inputFile.peek() == ifstream::traits_type::eof()) {
			throw runtime_error("\nОшибка!\nФайл с входными данными является пустым.\nПожалуйста, внесите данные в входной файл.");
		}

		// Попытка открыть выходной файл
		ofstream outputFile(outputFileName);
		if (!outputFile.is_open()) {
			outputFileName = "new_output.txt";
			outputFile.open(outputFileName);
		}

		int cubeNumber = NULL;

		try {
			string line;
			getline(inputFile, line);

			// Проверка валидности данных во входном файле
			if (line.length() > 3)
			{
				throw runtime_error("Введены некорректные данные!\nВ строку не допускается ввод более трех символов.");
			}

			// Извлечение числа из входного файла
			auto result = extractIFDFromTxt(inputFileName);

			if (holds_alternative<int>(result)) {
				cubeNumber = get<int>(result);
			}
			else
			{
				throw runtime_error("Введены некорректные данные!\nВ строку не допускается ввод любых символов, кроме цифр.");
			}
		}
		catch (const exception& error)
		{
			// Запись ошибки в выходной файл и его закрытие
			outputFile << error.what();
			outputFile.close();
		}

		// Рассчет количества лестниц и запись результата в выходной файл
		int stepsResult = cubeStepsCounter(cubeNumber, cubeNumber + 1);
		printIFDToTxt(outputFileName, stepsResult);
	}
	catch (const exception& error) {
		// Вывод ошибки в консоль
		cout << error.what() << endl;
	}

	return 0;
}
