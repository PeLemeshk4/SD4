#include <iostream>
#include <string>
#include "../Header files/Dictionary.h"
#include "../Header files/IODictionary.h"
#include "../Header files/Services.h"

string WritePair(KeyValuePair* pair)
{
    if (pair)
    {
        return '[' + pair->GetKey() + "]: " + to_string(pair->GetValue());
    }
    return "[...] : Empty";
}

string WriteStatus(Dictionary* dictionary)
{
    HashTable* table = dictionary->GetHashTable();
    string result = "\n=== Dictionary Main Menu ===\n";
    result += "Total entries: " + to_string(table->GetSize()) + '\n';
    for (int i = 0; i < table->GetCapacity(); i++)
    {
        KeyValuePair* pair = table->GetBuckets()[i];
        if (pair)
        {
            result += WritePair(pair) + '\n';
        }
    }
    result += "\n=== Hash Table State ===\n";
    result += "Capacity: " + to_string(table->GetCapacity()) + '\n';
    result += "Size: " + to_string(table->GetSize()) + '\n';
    result += "Load Factor: " + to_string(
        (double)table->GetSize() / (double)table->GetCapacity()) + '\n';
    result += "\nKey-value pairs:\n";
    for (int i = 0; i < table->GetCapacity(); i++)
    {
        KeyValuePair* pair = table->GetBuckets()[i];
        result += '[' + to_string(i) + "] " + WritePair(pair) + '\n';
    }
    return result;
}

void IODictionary::RunMenu()
{
    string dictionaryMenu[] = {
        "=== Dictionary Main Menu ===",
        "Add key-value pair",
        "Remove by key",
        "Find value by key",
        "Display current state",
        "Clear dictionary",
        "Resize",
        "Exit"
    };
    int size = sizeof(dictionaryMenu) / sizeof(dictionaryMenu[0]);

    Dictionary* dictionary = new Dictionary();
    while (true)
    {
        int choice = InputWithMessage(WriteManual(dictionaryMenu, size));

        switch (choice)
        {
            case 1:
            {
                string key = InputStringWithMessage("Enter the key: ");
                int value = InputWithMessage("Enter the value: ");
                dictionary->SetValue(key, value);
                cout << "Element was insert.\n";
                break;
            }
            case 2:
            {
                string key = InputStringWithMessage("Enter the key: ");
                if (dictionary->RemoveKeyValue(key))
                {
                    cout << "Element was excluded.\n";
                }
                else
                {
                    cout << "No element with this key was found.\n";
                }

                break;
            }
            case 3:
            {
                string key = InputStringWithMessage("Enter the key: ");
                try
                {
                    int result = dictionary->GetValue(key);
                    cout << "Value with of this key is " << result << ".\n";
                }
                catch (const exception& e)
                {
                    cerr << "Error: " << e.what() << '\n';
                }
                break;
            }
            case 4:
            {
                cout << WriteStatus(dictionary);
                
                break;
            }
            case 5:
            {
                dictionary->GetHashTable()->Clear();

                break;
            }
            case 6:
            {
                HashTable* table = dictionary->GetHashTable();
                table->Resize(table->GetCapacity() * 2);

                break;
            }
            case 7:
            {
                exit(0);
            }
            default:
            {
                cout << "Incorrect choice.\n";
                break;
            }
        }
    }
}