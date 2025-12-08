#pragma once

#include <string>

//! \brief Выводит инструкции в консоль и возвращает выбор.
//! \param manuals Список со всеми инструкциями.
//! \param size Длина массива manuals.
//! \return Возвращает полную строку меню.
std::string WriteManual(std::string* manuals, int size);

//! \brief Ввод с сообщением.
//! \param message Сообщение, выводимое перед вводом.
//! \return Возвращает введённое целое значение.
int InputWithMessage(std::string message);

std::string InputStringWithMessage(std::string message);