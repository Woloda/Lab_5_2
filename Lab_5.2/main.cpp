#include <iostream>
#include <string>

#include "My_Error.h"
#include "My_Error_Reliz.h"
#include "My_Error_Descendant.h"


//функція, яка обчислює суму геометричної прогресії(без специфікації виняткових ситуацій)
double Sum_Geom_Progr1(double b_1, double q, int n) {
	if (q == 1)	//виняткова ситуація: 'q = 1'
		throw 1;	//генерування винятку типу "int"
	double S_n, b_n;
	b_n = b_1 * pow(q, n - 1);	//обчислення b_n елемента
	S_n = (b_1 - b_n * q) / (1.0 - q);	//обчислення суми геометричної прогресії
	return S_n;
}

//функція, яка обчислює суму геометричної прогресії(із специфікацією throw())
double Sum_Geom_Progr2(double b_1, double q, int n) throw() {
	if (q == 1)	//виняткова ситуація: 'q = 1'
		throw 1.0;	//генерування винятку типу "double"
	double S_n, b_n;
	b_n = b_1 * pow(q, n - 1);	//обчислення b_n елемента
	S_n = (b_1 - b_n * q) / (1.0 - q);	//обчислення суми геометричної прогресії
	return S_n;
}

//функція, яка обчислює суму геометричної прогресії(з конкретною специфікацією підходящої стандартної виняткової ситуації)
double Sum_Geom_Progr3(double b_1, double q, int n) throw(char) {
	if (q == 1)	//виняткова ситуація: 'q = 1'
		throw '1';	//генерування винятку типу "char"
	double S_n, b_n;
	b_n = b_1 * pow(q, n - 1);	//обчислення b_n елемента
	S_n = (b_1 - b_n * q) / (1.0 - q);	//обчислення суми геометричної прогресії
	return S_n;
}

/*функція, яка обчислює суму геометричної прогресії
(специфікація з власною винятковою ситуацією, яка реалізована як порожній клас)*/
double Sum_Geom_Progr4(double b_1, double q, int n) throw(My_Error) {
	if (q == 1)	//виняткова ситуація: 'q = 1'
		throw My_Error();	//генерування винятку типу "My_Error"
	double S_n, b_n;
	b_n = b_1 * pow(q, n - 1);	//обчислення b_n елемента
	S_n = (b_1 - b_n * q) / (1.0 - q);	//обчислення суми геометричної прогресії
	return S_n;
}

/*функція, яка обчислює суму геометричної прогресії
(специфікація з власною винятковою ситуацією, яка реалізована як незалежний клас з полями – параметрами функції)*/
double Sum_Geom_Progr5(double b_1, double q, int n) throw(My_Error_Reliz) {
	if (q == 1)	//виняткова ситуація: 'q = 1'
		throw My_Error_Reliz("!!!!Denominator = 1!!!");	//генерування винятку типу "My_Error_Reliz"
	double S_n, b_n;
	b_n = b_1 * pow(q, n - 1);	//обчислення b_n елемента
	S_n = (b_1 - b_n * q) / (1.0 - q);	//обчислення суми геометричної прогресії
	return S_n;
}

/*функція, яка обчислює суму геометричної прогресії
(специфікація з власною винятковою ситуацією, яка реалізована як нащадок відстандартної виняткової ситуації з полями)*/
double Sum_Geom_Progr6(double b_1, double q, int n) throw(My_Error_Descendant) {
	if (q == 1)	//виняткова ситуація: 'q = 1'
		throw My_Error_Descendant("!!!!Denominator = 1!!!");	//генерування винятку типу "My_Error_Descendant"
	double S_n, b_n;
	b_n = b_1 * pow(q, n - 1);	//обчислення b_n елемента
	S_n = (b_1 - b_n * q) / (1.0 - q);	//обчислення суми геометричної прогресії
	return S_n;
}

void FU() {		//підмінена стандартна функція "unexpected()"
	std::cout << "\nunexpected error! - bad_exception";
	throw;	//генерування винятку
}

void FT() {		//підмінена стандартна функція "terminate()"
	std::cout << "\nunknown error! - terminate";
	abort();
}

int main(void) {
	set_unexpected(FU);		//встановлення функції "FU()"
	set_terminate(FT);		//встановлення функції "FT()"

	int n(0);
	double b_1(0.0), q(0.0);
	std::cout << "\nEnter a number of geometric progression elements: ";
	std::cin >> n;
	std::cout << "Enter the first element of the geometric progression: "; 
	std::cin >> b_1;
	std::cout << "Enter the denominator of the geometric progression: ";
	std::cin >> q;

	try{
		std::cout << "\n\nThe sum of the geometric progression: " << Sum_Geom_Progr1(b_1, q, n);
		std::cout << "\nThe sum of the geometric progression: " << Sum_Geom_Progr2(b_1, q, n);
		std::cout << "\nThe sum of the geometric progression: " << Sum_Geom_Progr3(b_1, q, n);
		std::cout << "\nThe sum of the geometric progression: " << Sum_Geom_Progr4(b_1, q, n);
		std::cout << "\nThe sum of the geometric progression: " << Sum_Geom_Progr5(b_1, q, n);
		std::cout << "\nThe sum of the geometric progression: " << Sum_Geom_Progr6(b_1, q, n);
	}
	catch (int){
		std::cout << "\n\nCatch (int) <= Sum_Geom_Progr1()";
	}
	catch (double){
		std::cout << "\n\nCatch (double) <= Sum_Geom_Progr2()";
	}
	catch (char){
		std::cout << "\n\nCatch (char) <= Sum_Geom_Progr3()";
	}
	catch (My_Error){
		std::cout << "\n\nCatch (My_Error) <= Sum_Geom_Progr4()";
	}
	catch (My_Error_Reliz obj){
		std::cout << "\n\nCatch (My_Error_Reliz) <= Sum_Geom_Progr5() :";
		std::cout << obj.What();
	}
	/*catch (My_Error_Descendant obj) {
		std::cout << "\n\nCatch (My_Error_Descendant) <= Sum_Geom_Progr6) :";
		std::cout << obj.What();
	}
	catch (std::exception){
		std::cout << "\n\nCatch (exception::My_Error_Descendant) <= Sum_Geom_Progr6() :";
	}*/
	catch (std::bad_exception) {
		std::cout << "\n\nCatch (bad_exception)";
	}

	std::cout << "\n\n";
	system("pause");
	return 0;
}