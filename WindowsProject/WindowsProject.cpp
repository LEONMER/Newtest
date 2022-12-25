#include "framework.h"
#include "WindowsProject.h"
#include "HedFoo.h"

int __stdcall wWinMain(HINSTANCE This, // Дескриптор текущего приложения
	HINSTANCE Prev, // В современных системах всегда 0
	LPTSTR cmd, // Командная строка
	int mode) // Режим отображения окна
{
	UNREFERENCED_PARAMETER(Prev);
	UNREFERENCED_PARAMETER(cmd);
	HWND hWnd = nullptr; // Дескриптор главного окна программы
	MSG msg = { 0 }; // Структура для хранения сообщения
	WNDCLASS wc = { 0 }; // Класс окна

	wc.hInstance = This;// Определение класса окна
	wc.lpszClassName = _T("WinName"); // Имя класса окна
	wc.lpfnWndProc = WorkWindowsProcedure; // Функция окна
	wc.style = CS_HREDRAW | CS_VREDRAW; // Стиль окна
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO); // Стандартная иконка
	wc.hCursor = LoadCursor(NULL, IDC_SIZEWE); // Стандартный курсор
	wc.lpszMenuName = NULL; // Нет меню
	wc.cbClsExtra = 0; // Нет дополнительных данных класса
	wc.cbWndExtra = 0; // Нет дополнительных данных окна
	// Заполнение окна белым цветом
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1/*черный фон*/);
	if (!RegisterClass(&wc)) return 0; // Регистрация класса окна 
	// Создание окна
	hWnd = CreateWindow(_T("WinName"), // Имя класса окна
		_T("Заголовок окна"), // Заголовок окна
		WS_OVERLAPPEDWINDOW, // Стиль окна
		CW_USEDEFAULT,// x
		CW_USEDEFAULT,// y Размеры окна
		CW_USEDEFAULT,// Width
		CW_USEDEFAULT,// Height
		HWND_DESKTOP, // Дескриптор родительского окна
		NULL, // Нет меню
		This, // Дескриптор приложения
		NULL); // Дополнительной информации нет
	ShowWindow(hWnd, mode); //Показать окно
	while (GetMessage(&msg, NULL, 0, 0))// Цикл обработки сообщений
	{
		UpdateWindow(hWnd);
		TranslateMessage(&msg);// Функция трансляции кодов нажатой клавиши
		DispatchMessage(&msg); // Посылает сообщение функции WndProc()
	}
	return 0;
}