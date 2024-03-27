#include <iostream>
#include <cstring>
using namespace std;
bool areStringsEqual(const char str1[], const char str2[])
{
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return false;
        }
        i++;
    }
    return (str1[i] == '\0' && str2[i] == '\0');
}

void reverse(char str[])
{
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void null(char str[])
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        str[i] = '\0';
    }
}

void Add(char in1[], char in2[], char out[]);
void simplify(char out[]);

int main()
{
    char input[1000];
    char in1[1000] = "A", in2[1000] = "A", output[1000] = "A";

    cout << "Input the expression: ";
    do
    {
        cin >> input;

        if (!areStringsEqual("+", input) && !areStringsEqual("=", input))
        {
            strcpy_s(in1, input);
            strcpy_s(in2, output);

            reverse(in1);
            reverse(in2);

            null(output);

            Add(in1, in2, output);

            null(in1);
            null(in2);

            reverse(output);
        }

    } while (!areStringsEqual("=", input));

    simplify(output);

    cout << "The answer is: " << output << endl;

    return 0;
}

void Add(char in1[], char in2[], char out[])
{
    int carry = 0;
    int length, len1, len2;

    len1 = strlen(in1);
    len2 = strlen(in2);

    if (strlen(in1) >= strlen(in2))
        length = len1;
    else
        length = len2;

    int i = 0;

    while (i < length || carry > 0)
    {
        int i1, i2;

        if (in1[i] >= 'A' && in1[i] <= 'Z')
            i1 = in1[i] - 65;
        else
            i1 = 0;

        if (in2[i] >= 'A' && in2[i] <= 'Z')
            i2 = in2[i] - 65;
        else
            i2 = 0;

        int result = i1 + i2 + carry;
        carry = 0;

        while (result > 25)
        {
            result -= 26;
            carry++;
        }

        out[i] = result + 65;
        i++;
    }
}

void simplify(char out[])
{
    int i = 0;
    int len = strlen(out);

    while (out[i] == 'A')
    {
        if (strlen(out) == 1)
            return;
        out[i] = '\0';
        for (int j = 1; j < len; j++)
        {
            int temp = out[j];
            out[j] = out[j - 1];
            out[j - 1] = temp;
        }
    }
}

