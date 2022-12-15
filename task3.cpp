#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    setlocale(LC_ALL, "rus");
    string glas = "ауоиэыяюеё";
    string buff;
    string buffres;
    ifstream fin("input.txt");
    ofstream res("output.txt");
    while (!fin.eof()) 
    {
        fin >> buff;
        int counter = 0;
        string used;
        for (int i = 0; i < buff.size(); i++) 
        {
            for (int j = 0; j < 10; j++) 
            {
                if (buff[i] == glas[j]) 
                {
                    bool flag = true;
                    for (int k = 0; k < used.size(); k++)
                    {
                        if (used[k] == buff[i]) 
                        {
                            flag = false;
                        }
                    }
                    if (flag) 
                    {
                        counter++;
                    }
                    used = used + buff[i];

                }
            }
        }
        if (counter >= 4)
        {
            for (int i = 0; i < buff.size(); i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (buff[i] == glas[j])
                    {
                        buff[i] = toupper(buff[i]);
                    }
                }
            }
            buff = buff + "(" + used + ")";

        }
        res << buff + " ";
        
    }
    fin.close();
    res.close();
    return 0;
}
