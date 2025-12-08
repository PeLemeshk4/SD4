#pragma once

#include <iostream>

using namespace std;

//! \brief Структура пары "ключ-значение".
struct KeyValuePair
{
private:

	//! \brief Ключ.
	string _key;

	//! \brief Значение.
	int _value;

public:

	//! \brief Создает пару "ключ-значение".
	//! \param key Ключ.
	//! \param value Значение.
	KeyValuePair(string key, int value);

	//! \brief Возвращает ключ.
	//! \return Ключ.
	string GetKey();

	//! \brief Возвращает значение.
	//! \return Значение.
	int GetValue();

	//! \brief Устанавливает значение.
	//! \param value Значение.
	void SetValue(int value);
};
