#include <iostream>
using namespace std;
int stringLength(char str[])
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}
void stringCopy(char dest[], char src[])
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}
void stringReverse(char str[])
{
    int len = stringLength(str);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}
void stringConcat(char result[], char str1[], char str2[])
{
    int i = 0;
    while (str1[i] != '\0')
    {
        result[i] = str1[i];
        i++;
    }
    int j = 0;
    while (str2[j] != '\0')
    {
        result[i++] = str2[j++];
    }
    result[i] = '\0';
}
int main()
{
    char str1[100], str2[100], result[200], copy[100];
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;
    cout << "Length of first string: " << stringLength(str1) << endl;
    stringCopy(copy, str1);
    cout << "Copied string: " << copy << endl;
    stringReverse(str1);
    cout << "Reversed string: " << str1 << endl;
    stringConcat(result, str1, str2);
    cout << "Concatenated string: " << result << endl;
    return 0;
}