/*Морфинг на 1,2,3 кнопки*/
#define _CRT_SECURE_NO_WARNINGS
#include<gl\glut.h>
#include <GL/freeglut.h>
#include <iostream> 
#include <windows.h> 
#include "math.h"
#include <algorithm>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>
HDC			hDC = NULL;									// Device Context Handle
HGLRC		hRC = NULL;									// Rendering Context Handle
HWND		hWnd = NULL;									// Window Handle
HINSTANCE	hInstance;									// Instance Handle
GLuint	texture[1];
bool		keys[256];									// Key Array
bool		active = TRUE;								// Program's Active
bool		fullscreen = TRUE;							// Default Fullscreen To True
float LightPos[] = { 0.0f, 0.0f, 0.0f, 1.0f };
float LightAmb[] = { 0.2f, 0.2f, 0.2f, 1.0f };
float LightDif[] = { 0.6f, 0.6f, 0.6f, 1.0f };
float LightSpc[] = { 0.6f, 0.6f, 0.6f, 1.0f };
float mat_dif[] = { 0, 1, 0, 5 };
float MatAmb[] = { 0.4f, 0.4f, 0.4f, 1.0f };
float MatDif[] = { 1.0f, 1.0f, 0.9f, 1.0f };
float MatSpc[] = { 0.0f, 0.0f, 0.0f, 0.0f };
float MatShn[] = { 128.0f };
float tMatSpc[] = { 1.0f, 1.0f, 1.0f, 1.0f };
float tMatShn[] = { 5.0f };

GLfloat xRotated = 100.0;
GLfloat xRotatedtea = 270;
GLfloat yRotated = 0.0;
GLfloat zRotated = 0.0;
GLfloat		xrot, yrot, zrot,	// углы вращения по X, Y и Z
xspeed, yspeed, zspeed,			// скорость вращения по X, Y и Z
cx, cy, cz = -15;				// положение на X, Y и Z

int			key = 1;			// Используется для проверки морфинга
int			step = 0, steps = 300;		// Счетчик шага и максимальное число шагов
bool		morph = FALSE;		// По умолчанию morph равен False (морфинг выключен

typedef struct											// Структура для вершины
{
	float	x, y, z;									// X, Y и Z координаты
} VERTEX;												// Назовем ее VERTEX

typedef struct											// Структура для объекта
{
	int		verts;										// Количество вершин в объекте
	VERTEX		*points;								// Одна вершина
} OBJECT;												// Назовем ее OBJECT

int			maxver;										// Хранит максимум числа вершин объектов
OBJECT		morph1, morph2, morph3,				// Наши объекты для морфинга (morph1, 2, 3)
helper, *sour, *dest;							// Helper Object, Source Object, Destination Object

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration

void objallocate(OBJECT *k, int n) // Выделение памяти для каждого объекта
{                                  // И определение точек
	k->points = (VERTEX*)malloc(sizeof(VERTEX)*n); // points = размер(VERTEX)* число вершин
}
void objfree(OBJECT *k)                   // Удаление объекта (Освобождение памяти)
{
	free(k->points);                     // Освобождаем память, занимаемую points
}
void readstr(FILE *f, char *string)  // Считывает строку из файла (f)
{
	do                              // Повторять
	{
		fgets(string, 255, f);     // Считывание 255 символов из файла f в переменную string
	} while ((string[0] == '/') || (string[0] == '\n')); // Пока строка пуста
	return;                         // Возврат
}
void objload(char *name, OBJECT *k)  // Загружает объект из файла (name)
{
	int       ver;                  // Будет хранить количество вершин
	float    rx, ry, rz;            // Будут хранить x, y и z координаты вершины


	FILE  *filein;                  // Файл для работы
	char    oneline[255];           // Хранит одну строку текста (до 255 символов)

	filein = fopen(name, "rt");     // Открываем файл на чтение (CTRL-Z означает конец файла)

	readstr(filein, oneline);       // Считываем одну строку текста из файла
	// Сканируем текст на "Vertices: ".
	// Число вершин сохраняем в ver
	sscanf(oneline, "Vertices: %d\n", &ver);
	k->verts = ver;                   // Устанавливаем переменные verts объектов
	// равными значению ver
	objallocate(k, ver);            // Выделяем память для хранения объектов
	for (int i = 0; i<ver; i++)        // Цикл по всем вершинам
	{
		readstr(filein, oneline);   // Считывание следующей строки
		// Поиск 3 вещественных чисел и сохранение их в rx, ry и rz
		sscanf(oneline, "%f %f %f", &rx, &ry, &rz);
		k->points[i].x = rx;   // Устанавливаем значение points.x объекта (k) равным rx
		k->points[i].y = ry;   // Устанавливаем значение points.y объекта (k) равным ry
		k->points[i].z = rz;   // Устанавливаем значение points.z объекта (k) равным rz
	}
	fclose(filein);             // Закрываем файл

	if (ver > maxver) maxver = ver;// Если ver больше чем maxver, устанавливаем maxver равным ver
}                                // Следим за максимальным числом используемых вершин												// Keeps Track Of Highest Number Of Vertices Used In Any Of The
// Objects
VERTEX calculate(int i)    // Вычисление перемещения точек в процессе морфинга
{
	VERTEX a;             // Временная вершина a
	// a.x равно x Источника - x Назначения делить на Steps
	a.x = (sour->points[i].x - dest->points[i].x) / steps;
	// a.y равно y Источника - y Назначения делить на Steps
	a.y = (sour->points[i].y - dest->points[i].y) / steps;
	// a.z равно z Источника - z Назначения делить на Steps
	a.z = (sour->points[i].z - dest->points[i].z) / steps;
	return a;             // Возвращаем результат
} 														// This Makes Points Move At A Speed So They All Get To Their
// Destination At The Same Time
GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height == 0)										// Prevent A Divide By Zero By
	{
		height = 1;										// Making Height Equal One
	}

	glViewport(0, 0, width, height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(30.0, (GLdouble)width / (GLdouble)height, 0.5, 500.0);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}
GLvoid LoadGLTextures()
{
	// Загрузка картинки
	AUX_RGBImageRec *texture1;
	texture1 = auxDIBImageLoad("wi.bmp");
	// Создание текстуры
	glGenTextures(1, &texture[0]);
	glBindTexture(GL_TEXTURE_2D, texture[0]);// texture[0](первая текстура) будет 2D текстурой
	// тип фильтрации
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	// фактическая текстура
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture1->sizeX, texture1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture1->data);
}

int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);					// Set The Blending Function For Translucency
	LoadGLTextures();			// Загрузка текстур
	glEnable(GL_TEXTURE_2D);	// Разрешение наложение текстуры
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// This Will Clear The Background Color To Black
	glClearDepth(1.0);									// Enables Clearing Of The Depth Buffer
	glDepthFunc(GL_LESS);								// The Type Of Depth Test To Do
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glShadeModel(GL_SMOOTH);							// Enables Smooth Color Shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	maxver = 0;											// Sets Max Vertices To 0 By Default
	objload("data/sphere.txt", &morph1);					// Load The First Object Into morph1 From File sphere.txt
	objload("data/torus.txt", &morph2);					// Load The Second Object Into morph2 From File torus.txt
	objload("data/tube.txt", &morph3);					// Load The Third Object Into morph3 From File tube.txt
	objload("data/sphere.txt", &helper);					// Load sphere.txt Object Into Helper (Used As Starting Point)
	sour = dest = &morph1;									// Source & Destination Are Set To Equal First Object (morph1)
	glLightfv(GL_LIGHT1, GL_POSITION, LightPos);
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmb);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDif);
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpc);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHTING);

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, MatAmb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MatDif);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MatSpc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, MatShn);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glAlphaFunc(GL_GREATER, 0.1);
	glEnable(GL_ALPHA_TEST);

	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	return TRUE;										// Initialization Went OK
}
void DrawGLScene()								// Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear The Screen And The Depth Buffer
	glLoadIdentity();									// Reset The View
	glTranslatef(cx, cy, cz);    // Сдвигаем текущую позицию рисования
	glRotatef(xrot, 1, 0, 0);    // Вращаем по оси X на xrot
	glRotatef(yrot, 0, 1, 0);    // Вращаем по оси Y на yrot
	glRotatef(zrot, 0, 0, 1);    // Вращаем по оси Z на zrot

	// Увеличиваем xrot, yrot и zrot на xspeed, yspeed и zspeed
	xrot += xspeed; yrot += yspeed; zrot += zspeed;

	GLfloat tx, ty, tz;          // Временные переменные X, Y и Z
	VERTEX q;                    // Хранит вычисленные значения для одной вершины
	glTranslatef(2.5,0.0,0.0);
	glEnable(GL_COLOR_MATERIAL);
	glBegin(GL_POINTS);  // Начало рисования точек
	// Цикл по всем вершинам объекта morph1 (все объекты состоят из
	for (int i = 0; i<morph1.verts; i++)
	{    // одинакового количества вершин, также можно использовать maxver)
		// Если morph равно True, вычисляем перемещение, иначе перемещение = 0
		if (morph) q = calculate(i); else q.x = q.y = q.z = 0;
		// Вычитание q.x единиц из helper.points[i].x (перемещение по оси X)
		helper.points[i].x -= q.x;
		// Вычитание q.y единиц из helper.points[i].y (перемещение по оси Y)
		helper.points[i].y -= q.y;
		// Вычитание q.z единиц из helper.points[i].z (перемещение по оси Z)
		helper.points[i].z -= q.z;
		// Делаем временную переменную X равной вспомогательной X
		tx = helper.points[i].x;
		// Делаем временную переменную Y равной вспомогательной Y
		ty = helper.points[i].y;
		// Делаем временную переменную Z равной вспомогательной Z
		tz = helper.points[i].z;
		glColor3f(1, 1, 0);                // Установить цвет в ярко голубой
		glVertex3f(tx, ty, tz);            // Нарисовать точку
		glColor3f(0, 0.5f, 1);             // Темный цвет
		tx -= 2 * q.x; ty -= 2 * q.y; ty -= 2 * q.y;   // Вычислить на две позиции вперед
		glVertex3f(tx, ty, tz);            // Нарисовать вторую точку
		glColor3f(0, 0, 1);                // Очень темный цвет
		tx -= 2 * q.x; ty -= 2 * q.y; ty -= 2 * q.y;   // Вычислить еще на две позиции вперед
		glVertex3f(tx, ty, tz);            // Нарисовать третью точку
	}                              // Это создает призрачный хвост, когда точки двигаются
	glEnd();
	// Закончим рисовать точки
	glColor3f(1,1,1);
	// If We're Morphing And We Haven't Gone Through All 200 Steps Increase Our Step Counter
	// Otherwise Set Morphing To False, Make Source=Destination And Set The Step Counter Back To Zero.
	GLUquadricObj *quadObj;
	quadObj = gluNewQuadric(); if (morph && step <= steps)step++; else { morph = FALSE; sour = dest; step = 0; }
	glTranslatef(-50.0, 40.0, -400.5);
	glRotatef(xRotated, 1.0, 0.0, 0.0);
	glRotatef(yRotated, 0.0, 1.0, 0.0);
	glRotatef(zRotated, 0.0, 0.0, 1.0);
	glScalef(1.0, 1.0, 1.0);
	auxWireSphere(30);
	glRotatef(100, 1.0, 0.0, 0.0);
	glRotatef(180, 0.0, 0.0, 1.0);
	auxWireCylinder(40, 60);
	glLoadIdentity();
	gluQuadricTexture(quadObj, GL_TRUE);
	gluQuadricDrawStyle(quadObj, GLU_FILL);
	glTranslatef(-130.0, 40.0, -400.5);
	glRotatef(100, 1.0, 0.0, 0.0);
	glRotatef(180, 0.0, 0.0, 1.0);
	gluCylinder(quadObj, 30, 30, 60, 20, 20);
	glTranslatef(0.0, 0.0, -15.0);
	glRotatef(xRotatedtea, 1.0, 0.0, 0.0);
	glLightfv(GL_LIGHT0, GL_POSITION, LightPos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpc);
	glEnable(GL_LIGHT0);
	glRotatef(180, 0.0, 1.0, 0.0);
	auxSolidTeapot(20);
	gluDeleteQuadric(quadObj);
}

GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	objfree(&morph1);									// Jump To Code To Release morph1 Allocated Ram
	objfree(&morph2);									// Jump To Code To Release morph2 Allocated Ram
	objfree(&morph3);									// Jump To Code To Release morph3 Allocated Ram
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL, 0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL, NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL, "Release Of DC And RC Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL, "Release Rendering Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}
		hRC = NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd, hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL, "Release Device Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hDC = NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL, "Could Not Release hWnd.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hWnd = NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL", hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL, "Could Not Unregister Class.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hInstance = NULL;									// Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
*	title			- Title To Appear At The Top Of The Window				*
*	width			- Width Of The GL Window Or Fullscreen Mode				*
*	height			- Height Of The GL Window Or Fullscreen Mode			*
*	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
*	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/

BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left = (long)0;			// Set Left Value To 0
	WindowRect.right = (long)width;		// Set Right Value To Requested Width
	WindowRect.top = (long)0;				// Set Top Value To 0
	WindowRect.bottom = (long)height;		// Set Bottom Value To Requested Height

	fullscreen = fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance = GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc = (WNDPROC)WndProc;					// WndProc Handles Messages
	wc.cbClsExtra = 0;									// No Extra Window Data
	wc.cbWndExtra = 0;									// No Extra Window Data
	wc.hInstance = hInstance;							// Set The Instance
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground = NULL;									// No Background Required For GL
	wc.lpszMenuName = NULL;									// We Don't Want A Menu
	wc.lpszClassName = "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL, "Failed To Register The Window Class.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth = width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight = height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel = bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL, "The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?", "NeHe GL", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
			{
				fullscreen = FALSE;								// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL, "Program Will Now Close.", "ERROR", MB_OK | MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle = WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle = WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle = WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);	// Adjust Window To True Requested Size

	// Create The Window
	if (!(hWnd = CreateWindowEx(dwExStyle,						// Extended Style For The Window
		"OpenGL",						// Class Name
		title,							// Window Title
		dwStyle |						// Defined Window Style
		WS_CLIPSIBLINGS |				// Required Window Style
		WS_CLIPCHILDREN,				// Required Window Style
		0, 0,							// Window Position
		WindowRect.right - WindowRect.left,	// Calculate Window Width
		WindowRect.bottom - WindowRect.top,	// Calculate Window Height
		NULL,							// No Parent Window
		NULL,							// No Menu
		hInstance,						// Instance
		NULL)))							// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();											// Reset The Display
		MessageBox(NULL, "Window Creation Error.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd =							// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),							// Size Of This Pixel Format Descriptor
		1,														// Version Number
		PFD_DRAW_TO_WINDOW |									// Format Must Support Window
		PFD_SUPPORT_OPENGL |									// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,										// Must Support Double Buffering
		PFD_TYPE_RGBA,											// Request An RGBA Format
		bits,													// Select Our Color Depth
		0, 0, 0, 0, 0, 0,										// Color Bits Ignored
		0,														// No Alpha Buffer
		0,														// Shift Bit Ignored
		0,														// No Accumulation Buffer
		0, 0, 0, 0,												// Accumulation Bits Ignored
		16,														// 16Bit Z-Buffer (Depth Buffer)  
		0,														// No Stencil Buffer
		0,														// No Auxiliary Buffer
		PFD_MAIN_PLANE,											// Main Drawing Layer
		0,														// Reserved
		0, 0, 0													// Layer Masks Ignored
	};

	if (!(hDC = GetDC(hWnd)))										// Did We Get A Device Context?
	{
		KillGLWindow();											// Reset The Display
		MessageBox(NULL, "Can't Create A GL Device Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))				// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();											// Reset The Display
		MessageBox(NULL, "Can't Find A Suitable PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if (!SetPixelFormat(hDC, PixelFormat, &pfd))					// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();											// Reset The Display
		MessageBox(NULL, "Can't Set The PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if (!(hRC = wglCreateContext(hDC)))							// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();											// Reset The Display
		MessageBox(NULL, "Can't Create A GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if (!wglMakeCurrent(hDC, hRC))								// Try To Activate The Rendering Context
	{
		KillGLWindow();											// Reset The Display
		MessageBox(NULL, "Can't Activate The GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	ShowWindow(hWnd, SW_SHOW);									// Show The Window
	SetForegroundWindow(hWnd);									// Slightly Higher Priority
	SetFocus(hWnd);												// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);								// Set Up Our Perspective GL Screen

	if (!InitGL())												// Initialize Our Newly Created GL Window
	{
		KillGLWindow();											// Reset The Display
		MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	return TRUE;												// Success
}

LRESULT CALLBACK WndProc(HWND	hWnd,						// Handle For This Window
	UINT	uMsg,						// Message For This Window
	WPARAM	wParam,						// Additional Message Information
	LPARAM	lParam)						// Additional Message Information
{
	switch (uMsg)												// Check For Windows Messages
	{
	case WM_ACTIVATE:										// Watch For Window Activate Message
	{
																if (!HIWORD(wParam))								// Check Minimization State
																{
																	active = TRUE;									// Program Is Active
																}
																else												// Otherwise
																{
																	active = FALSE;									// Program Is No Longer Active
																}

																return 0;											// Return To The Message Loop
	}

	case WM_SYSCOMMAND:										// Intercept System Commands
	{
																switch (wParam)										// Check System Calls
																{
																case SC_SCREENSAVE:								// Screensaver Trying To Start?
																case SC_MONITORPOWER:							// Monitor Trying To Enter Powersave?
																	return 0;										// Prevent From Happening
																}
																break;												// Exit
	}

	case WM_CLOSE:											// Did We Receive A Close Message?
	{
																PostQuitMessage(0);									// Send A Quit Message
																return 0;											// Jump Back
	}

	case WM_KEYDOWN:										// Is A Key Being Held Down?
	{
																keys[wParam] = TRUE;								// If So, Mark It As TRUE
																return 0;											// Jump Back
	}

	case WM_KEYUP:											// Has A Key Been Released?
	{
																keys[wParam] = FALSE;								// If So, Mark It As FALSE
																return 0;											// Jump Back
	}

	case WM_SIZE:											// Resize The OpenGL Window
	{
																ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));		// LoWord=Width, HiWord=Height
																return 0;											// Jump Back
	}
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE	hInstance,						// Instance
	HINSTANCE	hPrevInstance,					// Previous Instance
	LPSTR		lpCmdLine,						// Command Line Parameters
	int			nCmdShow)						// Window Show State
{
	MSG		msg;												// Windows Message Structure
	BOOL	done = FALSE;											// Bool Variable To Exit Loop

	// Ask The User Which Screen Mode They Prefer
	if (MessageBox(NULL, "Would You Like To Run In Fullscreen Mode?", "Start FullScreen?", MB_YESNO | MB_ICONQUESTION) == IDNO)
	{
		fullscreen = FALSE;										// Windowed Mode
	}

	// Create Our OpenGL Window
	if (!CreateGLWindow("Piotr Cieslak & NeHe's Morphing Points Tutorial", 1360, 768, 16, fullscreen))
	{
		return 0;												// Quit If Window Was Not Created
	}

	while (!done)												// Loop That Runs While done=FALSE
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))				// Is There A Message Waiting?
		{
			if (msg.message == WM_QUIT)							// Have We Received A Quit Message?
			{
				done = TRUE;										// If So done=TRUE
			}
			else												// If Not, Deal With Window Messages
			{
				TranslateMessage(&msg);							// Translate The Message
				DispatchMessage(&msg);							// Dispatch The Message
			}
		}
		else													// If There Are No Messages
		{
			// Draw The Scene.  Watch For ESC Key And Quit Messages From DrawGLScene()
			if (active && keys[VK_ESCAPE])						// Active?  Was There A Quit Received?
			{
				done = TRUE;										// ESC or DrawGLScene Signalled A Quit
			}
			else												// Not Time To Quit, Update Screen
			{
				DrawGLScene();	
				SwapBuffers(hDC);								// Swap Buffers (Double Buffering)
				glFlush();
				if (keys['1'] && (key != 1) && !morph)			// Is 1 Pressed, key Not Equal To 1 And Morph False?
				{
					key = 1;										// Sets key To 1 (To Prevent Pressing 1 2x In A Row)
					morph = TRUE;									// Set morph To True (Starts Morphing Process)
					dest = &morph1;								// Destination Object To Morph To Becomes morph1
				}
				if (keys['2'] && (key != 2) && !morph)			// Is 2 Pressed, key Not Equal To 2 And Morph False?
				{
					key = 2;										// Sets key To 2 (To Prevent Pressing 2 2x In A Row)
					morph = TRUE;									// Set morph To True (Starts Morphing Process)
					dest = &morph2;								// Destination Object To Morph To Becomes morph2
				}
				if (keys['3'] && (key != 3) && !morph)			// Is 3 Pressed, key Not Equal To 3 And Morph False?
				{
					key = 3;										// Sets key To 3 (To Prevent Pressing 3 2x In A Row)
					morph = TRUE;									// Set morph To True (Starts Morphing Process)
					dest = &morph3;								// Destination Object To Morph To Becomes morph3
				}
				if (keys[VK_F1])								// Is F1 Being Pressed?
				{
					keys[VK_F1] = FALSE;							// If So Make Key FALSE
					KillGLWindow();								// Kill Our Current Window
					fullscreen = !fullscreen;						// Toggle Fullscreen / Windowed Mode
					// Recreate Our OpenGL Window
					if (!CreateGLWindow("Piotr Cieslak & NeHe's Morphing Points Tutorial", 640, 480, 16, fullscreen))
					{
						return 0;								// Quit If Window Was Not Created
					}
				}
			}
		}
	}

	// Shutdown
	KillGLWindow();												// Kill The Window
	return (msg.wParam);										// Exit The Program
}
