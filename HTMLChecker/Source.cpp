#include <iostream>
#include <fstream>

using namespace std;

int Count(string a) {
    int count1 = 0;
    int count2 = 0;

    int index1 = 0;
    int index2 = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a.find('>',index1) != 18446744073709551615) {
            count1++;
        }
        if (a.find('<',index2) != 18446744073709551615) {
            count2++;
        }
        index1 = a.find('>', index1)+1;
        index2 = a.find('<', index2)+1;

    }
    if (count1 == count2) {
        return 1;
    }
    else {
        return 0;
    }
    
}
int main()
{
    ifstream is("index.html", ios::in);
    if (!is.is_open())
    {
        cout << "Open file error\n";
    }

    char str[200];
    bool error = 1;

    do
    {
        is.getline(str, 200);
        string a = str;
        if (!Count(a)) {
            cout << "Error";
            error = 0;
        }

    } while (!is.eof());

    if (error) {
        is.seekg(0, ios::beg);
        while (!is.eof()) {
            is.getline(str, 200);
            cout << str << endl;
        }
    }

    is.close();
}