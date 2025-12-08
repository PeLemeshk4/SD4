#include "../Header files/Dictionary.h"
#include <string>

Dictionary::Dictionary()
{
    _hashTable = new HashTable();
}

Dictionary::~Dictionary()
{
    delete _hashTable;
}

void Dictionary::SetValue(string key, int value)
{
    _hashTable->Insert(key.c_str(), value);
}

int Dictionary::GetValue(string key)
{
    int* value = new int();
    _hashTable->Find(key.c_str(), value);
    if (!value)
    {
        throw  out_of_range("Key not found in dictionary.");
    }
    return *value;
}

void Dictionary::RemoveKeyValue(string key)
{
    _hashTable->Remove(key.c_str()); 
}

bool Dictionary::HasKey(string key)
{
    int* value = new int();
    return _hashTable->Find(key.c_str(), value);
}

HashTable* Dictionary::GetHashTable()
{
    return _hashTable;
}