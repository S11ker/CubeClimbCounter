#pragma once
#include <fstream>
#include <string>
#include <regex>
#include <variant>
#include <stdexcept>
using namespace std;

/**
 * @brief Извлекает число из текстового файла и возвращает его в виде варианта (int, float или double).
 *
 * Функция открывает и читает текстовый файл с заданным именем и извлекает первую строку.
 * Затем она пытается определить тип числа в строке и возвращает его в виде варианта (variant).
 *
 * @param [in] fileName - имя текстового файла, из которого нужно извлечь число
 * @return Вариант (variant), содержащий извлеченное число (int, float или double)
 * @throws runtime_error в случае ошибки, такой как неверный формат файла, невозможность определить тип числа или ошибка при открытии файла.
 */
variant<int, float, double> extractIFDFromTxt(const string& fileName) {
    // Проверяем, имеет ли файл расширение .txt
    if (fileName.length() < 4 || fileName.find(".txt") == string::npos) {
        throw runtime_error("Invalid file format");
    }

    // Устанавливаем глобальную локаль для корректной обработки десятичных разделителей
    locale::global(locale("en_US.UTF-8"));

    // Открываем файл для чтения
    ifstream file(fileName);

    // Проверяем, успешно ли открыт файл
    if (!file.is_open()) {
        throw runtime_error("Could not open the file");
    }

    // Считываем первую строку из файла
    string line;
    if (getline(file, line)) {
        // Заменяем запятые на точки, если они используются как разделители десятичных знаков
        for (char& c : line) {
            if (c == ',') {
                c = '.';
            }
        }

        // Проверяем строку на соответствие регулярным выражениям для int, float и double
        regex intRegex("\\d+");
        regex floatRegex("\\d+\\.\\d");
        regex doubleRegex("\\d+\\.\\d+");

        if (regex_match(line, intRegex)) {
            return stoi(line);  // Преобразуем строку в int
        }
        else if (regex_match(line, floatRegex)) {
            return stof(line);  // Преобразуем строку в float
        }
        else if (regex_match(line, doubleRegex)) {
            return stod(line);  // Преобразуем строку в double
        }
        else {
            throw runtime_error("It is impossible to determine the type of number in a string");
        }
    }
    else {
        throw runtime_error("File is empty");
    }
}


void printIFDToTxt(const string& fileName, double number) {

}