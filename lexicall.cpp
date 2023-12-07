#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
bool isDelimiter(char ch) {
 string punctuators = ".,;:()[]{}";
 if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' || 
 ch == '/' || ch == '=' || ch == '>' || ch == '<' || 
 punctuators.find(ch) != string::npos){
 return true;
 }
 return false;
}
bool isOperator(char ch) {
 if (ch == '+' || ch == '-' || ch == '*' || 
 ch == '/' || ch == '>' || ch == '<' || 
 ch == '=')
 return true;
 return false;
}
bool validIdentifier(string str) {
 if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
 str[0] == '3' || str[0] == '4' || str[0] == '5' || 
 str[0] == '6' || str[0] == '7' || str[0] == '8' || 
 str[0] == '9' || isDelimiter(str[0]) == true)
 return false;
 return true;
}
bool isKeyword(string str) {
 if (str == "if" || str == "else" ||
 str == "while" || str == "do" || 
 str == "break" || 
 str == "continue" || str == "int"
 || str == "double" || str == "float"
 || str == "return" || str == "char"
 || str == "case" || str == "char"
 || str == "sizeof" || str == "long"
 || str == "short" || str == "typedef"
 || str == "switch" || str == "unsigned"
 || str == "void" || str == "static"
 || str == "struct" || str == "goto")
 return true;
 return false;
}
bool isInteger(string str) {
 int len = str.length();
 if (len == 0)
 return false;
 for (int i = 0; i < len; i++) {
 if (str[i] != '0' && str[i] != '1' && str[i] != '2'
 && str[i] != '3' && str[i] != '4' && str[i] != '5'
 && str[i] != '6' && str[i] != '7' && str[i] != '8'
 && str[i] != '9' || (str[i] == '-' && i > 0))
 return false;
 }
 return true;
}
bool isRealNumber(string str) {
 int len = str.length();
 bool hasDecimal = false;
 if (len == 0)
 return false;
 for (int i = 0; i < len; i++) {
 if (str[i] != '0' && str[i] != '1' && str[i] != '2'
 && str[i] != '3' && str[i] != '4' && str[i] != '5'
 && str[i] != '6' && str[i] != '7' && str[i] != '8'
 && str[i] != '9' && str[i] != '.' || 
 (str[i] == '-' && i > 0))
 return false;
 if (str[i] == '.')
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
 if (isDelimiter(str[right]) == false) {
 right++;
 }
 if (isDelimiter(str[right]) == true && left == right) {
 if (isOperator(str[right]) == true) {
 cout << "'" << str[right] << "' IS AN OPERATOR" << endl;
 }else{
 cout<<"'"<<str[right]<<"' IS A PUNCTUATOR"<<endl;
 }
 right++;
 left = right;
 } else if (isDelimiter(str[right]) == true && left != right
 || (right == len && left != right)) {
 string subStr = subString(str, left, right - 1);
 if (isKeyword(subStr) == true) {
 cout << "'" << subStr << "' IS A KEYWORD" << endl;
 } else if (isInteger(subStr) == true) {
 cout << "'" << subStr << "' IS AN INTEGER" << endl;
 } else if (isRealNumber(subStr) == true) {
 cout << "'" << subStr << "' IS A REAL NUMBER" << endl;
 } else if (validIdentifier(subStr) == true && isDelimiter(str[right - 1]) == false) {
 cout << "'" << subStr << "' IS A VALID IDENTIFIER" << endl;
 } else if (validIdentifier(subStr) == false && isDelimiter(str[right - 1]) == false) {
 cout << "'" << subStr << "' IS NOT A VALID IDENTIFIER" << endl;
 }
 left = right;
 }
 }
}
int main() {
 int lines;
 cout << "Enter the number of lines: ";
 cin >> lines;
 cin.ignore(); 
 for (int i = 0; i < lines; i++) {
 string str;
 cout << "Enter string " << i + 1 << ": ";
 getline(cin, str);
 parse(str);
 }
 return 0;
}        