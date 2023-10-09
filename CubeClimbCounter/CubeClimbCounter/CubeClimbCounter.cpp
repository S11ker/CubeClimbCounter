#include <iostream>
#include "windows.h"
#include "CubeClimbFunction.h"
#include "WorkWithIFDInTxtFile.h"

int main(const int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(65001);
	ofstream outputFile;

	try
	{
		if (argc != 3)
		{
			throw runtime_error("\nОшибка!\nПрограмма запущена некорректно!\nПример правильного запуска программы : CubeClimbCounter.exe ./input.txt ./output.txt");
		}
		if (argv[1] == nullptr || argv[2] == nullptr)
		{
			throw runtime_error("\nОшибка!\nПрограмма запущена некорректно!\nПример правильного запуска программы : CubeClimbCounter.exe ./input.txt ./output.txt");
		}

		string inputFileName = argv[1];
		string outputFileName = argv[2];

		if (inputFileName.size() < 4 || inputFileName.substr(inputFileName.size() - 4) != ".txt")
		{
			throw runtime_error("\nОшибка!\nНеверный формат входного файла.\nПожалуйста, используйте файлы с расширением .txt");
		}

		if (outputFileName.size() < 4 || outputFileName.substr(outputFileName.size() - 4) != ".txt")
		{
			throw runtime_error("\nОшибка!\nНеверный формат выходного файла.\nПожалуйста, используйте файлы с расширением .txt");
		}

		ifstream inputFile(inputFileName);
		if (!inputFile.is_open()) {
			throw runtime_error("\nОшибка!\nФайл с входными данными не существует или не доступен для чтения.\nПожалуйста, укажите существующий входной файл или предоставьте доступ к чтению уже существующего.");
		}

		if (inputFile.peek() == ifstream::traits_type::eof()) {
			throw runtime_error("\nОшибка!\nФайл с входными данными является пустым.\nПожалуйста, внесите данные в входной файл.");
		}

		ofstream outputFile(outputFileName);
		if (!outputFile.is_open()) {
			outputFileName = "new_output.txt";
			outputFile.open(outputFileName);
		}

		int cubeNumber = NULL;

		try {
			string line;
			getline(inputFile, line);

			if (line.length() > 3)
			{
				throw runtime_error("Введены некорректные данные!\nВ строку не допускается ввод более трех символов.");
			}

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
			outputFile << error.what();
			outputFile.close();
		}

		int stepsResult = cubeStepsCounter(cubeNumber, cubeNumber + 1);
		printIFDToTxt(outputFileName, stepsResult);
	}
	catch (const exception& error) {
		cout << error.what() << endl;
	}

	return 0;
}