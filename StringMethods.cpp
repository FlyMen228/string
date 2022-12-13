#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

std::string getSubstringInBrackets(const std::string& sourceString)
{
    if (!sourceString.find('(')) {
        std::cout << "Opening bracket was not found!\n";
        return NULL;
    }

    if (!sourceString.find(')')) {
        std::cout << "Closing bracket was not found!\n";
        return NULL;
    }

    //Это вариант подстроки, когда первое вхождение подстроки в скобках = строка между первой слева открывающей и закрывающей скобок
    //return sourceString.substr(sourceString.find('(') + 1, sourceString.find(')') - 2);

    //Это наиболее правильный, на мой взгляд вариант, где закрывающая скобка ищется справа, т.е. выводится строка из правильной скобочной пос-ти
    return sourceString.substr(sourceString.find('(') + 1, sourceString.rfind(')') - 2);
}

void addExclamationAfterSpaceInFile() {
    std::ifstream reader("../F1.txt");

    if (!reader.is_open()) {
        reader.close();

        std::cout << "File opening error!";

        std::exit(1);
    }

    std::string text;

    std::stringstream buffer;

    buffer << reader.rdbuf();

    text = buffer.str();

    reader.close();

    for (std::size_t i = 0; i < text.size(); ++i) {
        if (text[i] == ' ') {
            text.insert(i + 1, "!");
        }
    }

    std::ofstream writer("../F2.txt");

    if (!writer.is_open()) {
        writer.close();

        std::cout << "Writer opening error!";

        std::exit(1);
    }

    writer << text;

    writer.close();
}