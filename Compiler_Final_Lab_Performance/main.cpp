#include <iostream>

#include <fstream>

#include <string>

using namespace std;

bool isDelimiter(char ch) {

    string delimiters = " +-*/,;><=()[]{}";

    return (delimiters.find(ch) != string::npos);

}



bool isOperator(char ch) {

    string operators = "+-*/><=";

    return (operators.find(ch) != string::npos);

}

bool validIdentifier(string str) {

    if (str.empty() || isdigit(str[0]) || isDelimiter(str[0]))

        return false;

    return true;

}

bool isKeyword(string str) {

    string keywords[] = {

        "if", "else", "while", "do", "break", "continue",

        "int", "double", "float", "return", "char", "case",

        "sizeof", "long", "short", "typedef", "switch", "unsigned",

        "void", "static", "struct", "goto"

    };

    for (const string &keyword : keywords) {

        if (str == keyword)

            return true;

    }

    return false;

}

bool isInteger(string str) {

    if (str.empty())

        return false;

    for (char ch : str) {

        if (!isdigit(ch) && !(ch == '-' && &ch == &str[0]))

            return false;

    }

    return true;

}

bool isRealNumber(string str) {

    bool hasDecimal = false;

    if (str.empty())

        return false;

    for (char ch : str) {

        if (!isdigit(ch) && !(ch == '-' && &ch == &str[0]) && ch != '.') {

            return false;

        }

        if (ch == '.')

            hasDecimal = true;

    }

    return hasDecimal;

}

string subString(string str, int left, int right) {

    return str.substr(left, right - left + 1);

}

void parse(string str) {

    int left = 0, right = 0;

    int len = str.length();



    while (right <= len && left <= right) {

        if (!isDelimiter(str[right]))

            right++;



        if (isDelimiter(str[right]) && left == right) {

            if (isOperator(str[right]))

                cout << "'" << str[right] << "' IS AN OPERATOR" << endl;



            right++;

            left = right;

        } else if (isDelimiter(str[right]) && left != right || (right == len && left != right)) {

            string subStr = subString(str, left, right - 1);



            if (isKeyword(subStr))

                cout << "'" << subStr << "' IS A KEYWORD" << endl;

            else if (isInteger(subStr))

                cout << "'" << subStr << "' IS AN INTEGER" << endl;

            else if (isRealNumber(subStr))

                cout << "'" << subStr << "' IS A REAL NUMBER" << endl;

            else if (validIdentifier(subStr) && !isDelimiter(str[right - 1]))

                cout << "'" << subStr << "' IS A VALID IDENTIFIER" << endl;

            else if (!validIdentifier(subStr) && !isDelimiter(str[right - 1]))

                cout << "'" << subStr << "' IS NOT A VALID IDENTIFIER" << endl;



            left = right;

        }

    }

}

int main() {

    ifstream file("text.txt");

    string str;

    if (file.is_open()) {

        while (getline(file, str)) {

            parse(str);

        }

        file.close();

    } else {

        cerr << "Unable to open the file." << endl;

    }

    return 0;

}
