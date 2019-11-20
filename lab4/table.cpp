#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class terminal
{
    public:
        void runfile();
};

void terminal::runfile()
{
    ifstream file("ret.csv");
    file.unsetf(ios::skipws);
    
    int i=0, j=0;
    char s, mas[100][100];
    while (!file.eof())
    {
        file >> s;
        if (s == ',')
        {
            cout << "\t";
        }
        else
        {
            cout << s;
        }
        // if (s == '\n')
        //     cout << "\n";
    }
    
    cout << s << endl;

    file.close();
}

int main()
{
    terminal one;

    one.runfile();   

    return 0;
}