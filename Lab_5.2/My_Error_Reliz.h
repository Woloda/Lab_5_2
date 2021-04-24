#pragma once

class My_Error_Reliz {	//власний винятковий незалежний клас з полями
	std::string message;	//поле 'message' відповідає за відображення типа помилки
public:
	My_Error_Reliz(std::string message) : message(message) {}	//конструктор ініціалізації
	std::string What() { return message; }	//отримання(гетер) значення поля 'message'
};