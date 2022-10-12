
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main()
{

    ifstream write_f;
    write_f.open("file.txt");

    char str;
    int c_num = 0;
    int c_words = 0;
    int c_lines = 0;
    int c_char = 0;
    while (!write_f.eof())
    {
        write_f.get(str);
        if (str == ' ')
        {
            c_words++;
        }
        else if ((str >= 65 && str <= 90) || (str >= 97 && str <= 122))
        {
            c_char++;
        }
        else if (str >= '0' && str <= '9')
        {
            c_num++;
        }else if(str = '\n'){
            c_lines++;
        }
    }
    cout << "Total characters : " << c_char << endl;
    cout << "Total digits : " << c_num << endl;
    cout << "Total words : " << c_words + 1 << endl;
    cout << "Total lines : " << c_lines << endl;
    write_f.close();
    return 0;
}
