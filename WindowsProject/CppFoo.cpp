#include "HedFoo.h"
typedef std::basic_string<TCHAR, std::char_traits<TCHAR>,std::allocator<TCHAR> > String;

LRESULT __stdcall WorkWindowsProcedure(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	
	HDC hDC = { NULL };
	PAINTSTRUCT pS = { NULL };
	static HPEN hPenStd = { NULL };
	static HBRUSH hBrush = { NULL };
	static RECT aria = { NULL };
	static INT64 sx = NULL, sy = NULL;
	//
	switch (Message)
	{
	case WM_CREATE:
		MessageBox(hWnd, _T("Я Вас приветствую !"), _T(""), MB_OK);
		MainAddMenu(hWnd);
		MainAddAcshen(hWnd);
		break;
	case WM_COMMAND:
		switch (wParam)
		{
		case IB_CM_OPEN:
			MessageBox(hWnd, _T("Я Вас приветствую !\nIB_CM_OPEN"), _T(""), MB_OK);
			break;
		case IB_CM_OPEN_INFO:
			MessageBox(hWnd, _T("Я Вас приветствую !\nIB_CM_OPEN_INFO"), _T(""), MB_OK);
			break;
		case IB_CM_DONETION:
			MessageBox(hWnd, _T("Я Вас приветствую !\nIB_CM_DONETION"), _T(""), MB_OK);
			break;
		case IB_CM_BUTTOM_ONE_CLIC:
			MessageBox(hWnd, _T("Я Вас приветствую !\nIB_CM_BUTTOM_ONE_CLIC"), _T(""), MB_OK);
			break;
		default:
			return DefWindowProc(hWnd, Message, wParam, lParam);
			break;
		}
		break;
	case WM_SIZE:
		sx = LOWORD(lParam);
		sy = HIWORD(lParam);
		break;
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &pS);
		//if (!Rectangle(hDC, )) 
		EndPaint(hWnd, &pS);
		break;
	case WM_DESTROY:
		PostQuitMessage(NULL);
		break;
	default:
		return DefWindowProc(hWnd, Message, wParam, lParam);
		break;
	}
	
	return 0;


}

void __stdcall MainAddMenu(HWND hWnd)
{
	HMENU rMenu = CreateMenu();
	HMENU lMenu = CreateMenu();
	AppendMenu(rMenu, MF_POPUP, reinterpret_cast<UINT_PTR>(lMenu), _T("Menu"));
	AppendMenu(lMenu, MF_STRING, IB_CM_OPEN_INFO, _T("Info"));
	AppendMenu(lMenu, MF_SEPARATOR, NULL, NULL);
	AppendMenu(lMenu, MF_STRING, IB_CM_DONETION, _T("Donation"));
	SetMenu(hWnd, rMenu);
}

void __stdcall MainAddAcshen(HWND hWnd)
{
	static HWND hButtom = CreateWindow(
		_T("button"), 
		_T("Я красная кнопка"), 
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		10, 10,
		100, 25, 
		hWnd, reinterpret_cast<HMENU>(IB_CM_BUTTOM_ONE_CLIC), 
		0, 0);
}
//HBRUSH hbrush, h_brush[6];
//LPCTSTR str = _T("сплошное заполнение");
//LPCTSTR hstr[] = { _T("HS_BDIAGONAL – слева направо и снизу вверх"),
//_T("HS_CROSS - горизонтальная и вертикальная штриховка"),
//_T("HS_DIAGCROSS - под углом в 45 градусов"),
//_T("HS_FDIAGONAL - слева направо и сверху вниз"),
//_T("HS_HORIZONTAL - горизонтальная штриховка"),
//_T("HS_VERTICAL - вертикальная штриховка") };
//LRESULT CALLBACK WorkWindowsProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	PAINTSTRUCT ps;
//	HDC hdc;
//	int i;
//	int nIndex[] = { HS_BDIAGONAL, HS_CROSS, HS_DIAGCROSS, HS_FDIAGONAL,
//	HS_HORIZONTAL, HS_VERTICAL };
//	switch (message)
//	{
//	case WM_CREATE:
//		hbrush = CreateSolidBrush(RGB(255, 255, 0));
//		for (i = 0; i < 6; i++)
//			h_brush[i] = CreateHatchBrush(nIndex[i], RGB(0, 128, 0));
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hWnd, &ps);
//		SelectObject(hdc, hbrush);
//		Ellipse(hdc, 1, 1, 40, 40);
//		TextOut(hdc, 50, 11, str, _tcsclen(str));
//		for (i = 0; i < 6; i++)
//		{
//			SelectObject(hdc, h_brush[i]);
//			Rectangle(hdc, 1, 41 + i * 40, 40, 80 + i * 40);
//			TextOut(hdc, 50, 51 + i * 40, hstr[i], _tcsclen(hstr[i]));
//		}
//		EndPaint(hWnd, &ps);
//		break;
//	case WM_DESTROY:
//		DeleteObject(hbrush);
//		for (i = 0; i < 6; i++) DeleteObject(h_brush[i]);
//		PostQuitMessage(0);
//		break;
//	default: return DefWindowProc(hWnd, message, wParam, lParam);
//	}
//	return 0;
//}
//RECT pRect = { -100, -100, 100, 100 };
//RECT pEllips = { -120, -80, 120, 80 };
//RECT pSm = { -60, -40, 60, 40 };
//const int WIDTH = 400;
//LRESULT CALLBACK WorkWindowsProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	PAINTSTRUCT ps;
//	HDC hdc;
//	static int sx, sy;
//	HRGN hRgnEllipse;
//	HRGN hRgn;
//	static HBRUSH hBrush;
//	switch (message)
//	{
//	case WM_SIZE:
//		sx = LOWORD(lParam);
//		sy = HIWORD(lParam);
//		break;
//	case WM_CREATE:
//		hBrush = CreateSolidBrush(RGB(0, 0, 255));
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hWnd, &ps);
//		SetMapMode(hdc, MM_ANISOTROPIC);
//		SetWindowExtEx(hdc, WIDTH, -WIDTH, NULL);
//		SetViewportExtEx(hdc, sx, sy, NULL);
//		SetViewportOrgEx(hdc, sx / 2, sy / 2, NULL);
//		hRgn = CreateRectRgnIndirect(&pRect);
//		hRgnEllipse = CreateEllipticRgnIndirect(&pEllips);
//		CombineRgn(hRgn, hRgn, hRgnEllipse, RGN_DIFF);
//		DeleteObject(hRgnEllipse);
//		hRgnEllipse = CreateEllipticRgnIndirect(&pSm);
//		CombineRgn(hRgn, hRgn, hRgnEllipse, RGN_OR);
//		DeleteObject(hRgnEllipse);
//		FillRgn(hdc, hRgn, hBrush);
//		DeleteObject(hRgn);
//		EndPaint(hWnd, &ps);
//		break;
//	case WM_DESTROY: PostQuitMessage(0); break;
//	default: return DefWindowProc(hWnd, message, wParam, lParam);
//	}
//	return 0;
//}

//POINT pt[5] = { {0,100}, {-59,-81}, {95,31}, {-95,31}, {59,-81} };
//const int WIDTH = 400;
//const int HEIGHT = 300;
//LRESULT CALLBACK WorkWindowsProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	PAINTSTRUCT ps;
//	HDC hdc;
//	static int sx, sy;
//	static HBRUSH hBrush;
//	HRGN hRgn;
//	switch (message)
//	{
//	case WM_CREATE:
//		hBrush = CreateSolidBrush(RGB(255, 0, 0));
//		break;
//	case WM_SIZE:
//		sx = LOWORD(lParam);
//		sy = HIWORD(lParam);
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hWnd, &ps);
//		SetMapMode(hdc, MM_ANISOTROPIC);
//		SetWindowExtEx(hdc, WIDTH, -HEIGHT, NULL);
//		SetViewportExtEx(hdc, sx, sy, NULL);
//		SetViewportOrgEx(hdc, sx / 2, sy / 2, NULL);
//		BeginPath(hdc);
//		Polyline(hdc, pt, 5);
//		CloseFigure(hdc);
//		EndPath(hdc);
//		SelectObject(hdc, hBrush);
//		SetPolyFillMode(hdc, WINDING);
//		FillPath(hdc);
//		EndPaint(hWnd, &ps);
//		break;
//	case WM_DESTROY: PostQuitMessage(0); break;
//	default: return DefWindowProc(hWnd, message, wParam, lParam);
//	}
//	return 0;
//}
//const TCHAR* text = _T("Текст для вывода в окне");
//LRESULT CALLBACK WorkWindowsProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	PAINTSTRUCT ps;
//	HDC hdc;
//	TEXTMETRIC tm;
//	TCHAR str[256];
//	RECT rt;
//	SIZE size;
//
//
//
//
//
//
//
//	switch (message)
//	{
//	case WM_PAINT:
//		hdc = BeginPaint(hWnd, &ps);
//		SetBkColor(hdc, RGB(255, 255, 0)); 
//		SetTextColor(hdc, RGB(0, 0, 128)); 
//
//		TextOut(hdc, 0, 0, text, _tcsclen(text));
//		SetBkMode(hdc, TRANSPARENT); 
//		SelectObject(hdc, GetStockObject(ANSI_VAR_FONT));
//
//		GetTextMetrics(hdc, &tm);
//		_stprintf_s(str, _T("tmHeight = %d\ntmInternalLeading =\%d\ntmExternalLeading = %d\ntmAscent = %d\ntmDescent = % d\n"),
//			tm.tmHeight, tm.tmInternalLeading, tm.tmExternalLeading,
//			tm.tmAscent, tm.tmDescent);
//
//		SetRect(&rt, 0, 20, 150, 100);
//		DrawText(hdc, str, _tcslen(str), &rt, DT_LEFT);
//		GetTextExtentPoint32(hdc, text, _tcsclen(text), &size);
//		_stprintf_s(str, _T("Ширина строки = %d\nВысота строки = %d"),
//			size.cx, size.cy);
//
//		SetRect(&rt, 0, 100, 150, 150);
//		DrawText(hdc, str, _tcslen(str), &rt, DT_LEFT);
//		EndPaint(hWnd, &ps);
//		break;
//	case WM_DESTROY: 
//		PostQuitMessage(0); 
//		break;
//	default: 
//		return DefWindowProc(hWnd, message, wParam, lParam);
//		break;
//	}
//	return 0;
//}
