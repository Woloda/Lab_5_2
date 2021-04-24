#pragma once

#include <exception>


/*Власний винятковий клас, 
який реалізований як нащадок від стандартної виняткової ситуації з полями*/
class My_Error_Descendant : public std::exception {
	std::string message;	//поле 'message' відповідає за відображення типа помилки
public:
	My_Error_Descendant(std::string message) : message(message) {}	//конструктор ініціалізації
	std::string What() { return message; }	//отримання(гетер) значення поля 'message'
};