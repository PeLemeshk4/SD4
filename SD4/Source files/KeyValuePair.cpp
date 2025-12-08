#include "../Header files/KeyValuePair.h"

KeyValuePair::KeyValuePair(string key, int value)
{
	_key = key;
	_value = value;
}

string KeyValuePair::GetKey()
{
	return _key;
}

int KeyValuePair::GetValue()
{
	return _value;
}

void KeyValuePair::SetValue(int value)
{
	_value = value;
}