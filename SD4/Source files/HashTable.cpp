#include "../Header files/HashTable.h"
#include <random>
#include <string>

HashTable::HashTable()
{
	Initialize(DefaultCapacity);
}

HashTable::HashTable(int initialCapacity)
{
    if (initialCapacity <= 0)
    {
        initialCapacity = DefaultCapacity;
    }
    Initialize(initialCapacity);
}

HashTable::~HashTable()
{
    Destroy();
}

int HashTable::GetSize() const
{
    return _size;
}

int HashTable::GetCapacity() const
{
    return _capacity;
}

KeyValuePair** HashTable::GetBuckets()
{
    return _buckets;
}

bool HashTable::Insert(const char* key, int value)
{
    if (!key || _size >= _capacity)
    {
        return false;
    }

    int hash = HashFunction(key);
    for (int i = 0; i < _capacity; i++)
    {
        int index = (hash + i) % _capacity;
        if (!_buckets[index])
        {
            char* keyCopy = new char[strlen(key) + 1];
            strcpy_s(keyCopy, strlen(key) + 1, key);
            _buckets[index] = new KeyValuePair(keyCopy, value);
            _size++;
            return true;
        }
        else if (_buckets[index] && _buckets[index]->GetKey() == key)
        {
            _buckets[index]->SetValue(value);
            return true;
        }
    }
    return false;
}

bool HashTable::Find(const char* key, int* value)
{
    if (!key || !value)
    {
        return false;
    }

    int hash = HashFunction(key);
    for (int i = 0; i < _capacity; i++)
    {
        int index = (hash + i) % _capacity;
        if (!_buckets[index])
        {
            return false;
        }
        if (_buckets[index] && _buckets[index]->GetKey() == key)
        {
            *value = _buckets[index]->GetValue();
            return true;
        }
    }
    return false;
}

bool HashTable::Remove(const char* key)
{
    if (!key)
    {
        return false;
    }

    int hash = HashFunction(key);
    for (int i = 0; i < _capacity; i++)
    {
        int index = (hash + i) % _capacity;
        if (!_buckets[index])
        {
            return false;
        }
        if (_buckets[index] && _buckets[index]->GetKey() == key)
        {
            delete _buckets[index];
            _buckets[index] = nullptr;
            _size--;
            return true;
        }
    }
    return false;
}

bool HashTable::Resize(int capacity)
{
    if (capacity <= _size)
    {
        return false;
    }

    KeyValuePair** newBuckets = new KeyValuePair*[capacity];
    if (!newBuckets)
    {
        return false;
    }

    for (int i = 0; i < capacity; ++i)
    {
        newBuckets[i] = nullptr;
    }

    int oldCapacity = _capacity;
    KeyValuePair** oldBuckets = _buckets;

    _buckets = newBuckets;
    _capacity = capacity;
    _size = 0;

    for (int i = 0; i < oldCapacity; ++i)
    {
        if (oldBuckets[i])
        {
            Insert(oldBuckets[i]->GetKey().c_str(), oldBuckets[i]->GetValue());
            delete oldBuckets[i];
        }
    }

    delete[] oldBuckets;
    return true;
}

void HashTable::Clear()
{
    for (int i = 0; i < _capacity; i++)
    {
        KeyValuePair* pair = _buckets[i];
        if (pair)
        {
            Remove(pair->GetKey().c_str());
        }     
    }
}

int HashTable::HashFunction(const char* key)
{
    static unsigned char pearsonTable[256];
    static bool initialized = false;

    if (!initialized)
    {
        unsigned char* temp = new unsigned char[256];

        for (int i = 0; i < 256; ++i)
        {
            temp[i] = static_cast<unsigned char>(i);
        }

        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(temp, temp + 256, g);

        std::copy(temp, temp + 256, pearsonTable);

        delete[] temp;
        initialized = true;
    }


    unsigned char hash = 0;
    for (const char* c = key; *c; c++)
    {
        unsigned char byte = static_cast<unsigned char>(*c);
        hash = pearsonTable[(hash + byte) % 256]; 
    }
    return static_cast<int>(hash) % _capacity;
}


bool HashTable::Initialize(int capacity)
{
    _buckets = new KeyValuePair*[capacity];
    if (!_buckets)
    {
        return false;
    }
    _capacity = capacity;
    _size = 0;
    for (int i = 0; i < _capacity; ++i)
    {
        _buckets[i] = nullptr;
    }
    return true;
}

void HashTable::Destroy()
{
    if (_buckets)
    {
        for (int i = 0; i < _capacity; ++i)
        {
            if (_buckets[i])
            {
                delete _buckets[i];
            }
        }
        delete[] _buckets;
        _buckets = nullptr;
        _size = 0;
        _capacity = 0;
    }
}