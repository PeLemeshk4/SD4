#pragma once

#include "HashTable.h"

//! \brief Структура данных словарь.
struct Dictionary
{
private:

	//! \brief Массив пары "ключ-значения".
	HashTable* _hashTable;

public:

	//! \brief Создает структуру данных словарь.
	Dictionary();

	//! \brief Освобождает память.
	~Dictionary();

	//! \brief Устанавливает значение по указанному ключу.
	//! \param key Ключ.
	//! \param value Значение.
	void SetValue(std::string key, int value);

	//! \brief Возвращает значение по ключу.
	//! \param key Ключ.
	//! \return Значение.
	int GetValue(std::string key);

	//! \brief Удаляет пару "ключ-значение".
	//! \param key Ключ.
	bool RemoveKeyValue(std::string key);

	//! \brief Проверяет есть ли ключ в словаре.
	//! \param key Ключ.
	//! \return True если существует такой ключ в словаре. Иначе False.
	bool HasKey(std::string key);

	//! \brief Возвращает хэш-таблицу.
	//! \return Хэш-тфблица.
	HashTable* GetHashTable();
};