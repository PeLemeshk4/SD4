#include "../Header files/Services.h"
#include <iostream>
#include <string>

using namespace std;

string WriteManual(string* manuals, int size)
{
    string result = '\n' + manuals[0] + '\n';
    for (int i = 1; i < size; i++)
    {
        result += to_string(i) + ". " + manuals[i] + '\n';
    }
    return result;
}

int InputWithMessage(string message)
{
    while (true)
    {
        cout << message;
        string entrance;
        cin >> entrance;
        try
        {
            int variable = stoi(entrance);
            return variable;
        }
        catch (const exception& e)
        {
            cerr << "Error: " << e.what() << '\n';
        }
    }   
}

string InputStringWithMessage(string message)
{
    cout << message;
    string entrance;
    cin >> entrance;
    return entrance;
}

