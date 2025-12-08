#pragma once

#include "KeyValuePair.h"

//! \brief Простая хеш-таблица с открытой адресацией и линейным пробированием.
struct HashTable
{
private:
	//! \brief Начальное значение ёмкости по умолчанию.
	const int DefaultCapacity = 16;

	//! \brief Двумерный массив пар "ключ-значение" для метода цепочек. Или одномерный
	//! массив для метода открытой адресации.
	KeyValuePair** _buckets;

	//! \brief Вместимость хеш-таблицы.
	int _capacity;

	//! \brief Текущее количество пар "ключ-значение", хранящихся в таблице.
	int _size;

public:
	//! \brief Конструктор по умолчанию.
	//! Инициализирует таблицу с вместимостью по умолчанию.
	HashTable();

	//! \brief Конструктор с заданной начальной вместимостью.
	//! \param initialCapacity Начальная вместимость таблицы (должна быть > 0).
	HashTable(int initialCapacity);

	//! \brief Деструктор.
	//! Освобождает память.
	~HashTable();

	//! \brief Возвращает текущее количество элементов в таблице.
	//! \return Количество пар "ключ-значение".
	int GetSize() const;

	//! \brief Возвращает вместимость таблицы.
	//! \return Вместимость хеш-таблицы.
	int GetCapacity() const;

	//! \brief Возвращает массив пар.
	//! \return Массив пар.
	KeyValuePair** GetBuckets();

	//! \brief Вставляет пару "ключ-значение" в хеш-таблицу.
	//! \param key Ключ для вставки (не должен быть nullptr).
	//! \param value Значение для вставки.
	//! \return true, если вставка прошла успешно; false, если таблица переполнена.
	bool Insert(const char* key, int value);

	//! \brief Ищет значение по ключу в хеш-таблице.
	//! \param key Ключ, по которому ищется значение (не должен быть nullptr).
	//! \param value Указатель, по которому будет записано найденное значение.
	//! \return true, если ключ найден; false в противном случае.
	bool Find(const char* key, int* value);

	//! \brief Удаляет пару "ключ-значение" по ключу из хеш-таблицы.
	//! \param key Ключ, который нужно удалить (не должен быть nullptr).
	//! \return true, если ключ был найден и удалён; false в противном случае.
	bool Remove(const char* key);

	//! \brief Увеличивает вместимость таблицы (ресайз).
	//! \param capacity Новая вместимость (должна быть > текущего размера).
	//! \return true, если увеличение размера прошёл успешно; false в случае нехватки памяти.
	bool Resize(int capacity);

	//! \brief Удаляет все пары.
	void Clear();

private:
	//! \brief Вычисляет хеш от ключа.
	//! \param key Строка-ключ, для которой вычисляется хеш (не nullptr).
	//! \return Хеш в виде int.
	int HashFunction(const char* key);

	//! \brief Инициализирует внутренний массив пар "ключ-значение".
	//! \param capacity Желаемая вместимость.
	//! \return true при успехе, false при нехватке памяти.
	bool Initialize(int capacity);

	//! \brief Освобождает память, выделенную под пар "ключ-значение".
	void Destroy();
};
