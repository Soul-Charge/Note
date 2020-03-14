# Windows编程

## 创建窗口(C)

### 实现WinMain()函数

使用窗口时的入口函数，取代main()
<span style="color:green">好像用main()也是可以的，具体看[这个](https://www.cnblogs.com/panlm/p/4387375.html)</span>  
```c
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
}
```

### 注册窗口类

#### 创建窗口类结构

```c
#include <windows.h>
WNDCLASS WndClass;
```

#### 给窗口类赋值

```c
	WndClass.lpfnWndProc	= WndProc;								// 窗口过程函数指针
	WndClass.hInstance		= hInstance;							// 实例指针
	WndClass.lpszClassName	= szWndClassName;						// 指向窗口类名的字符串指针
	WndClass.lpszMenuName	= NULL;									// 菜单名句柄
	WndClass.cbClsExtra		= 0;									// 额外分配，不能不赋值，不用就置0
	WndClass.cbWndExtra		= 0;									// 额外分配，不能不赋值，不用就置0
	WndClass.style			= CS_HREDRAW | CS_VREDRAW;		        // 设置窗口样式
	WndClass.hCursor		= LoadCursor(NULL, IDC_CROSS);			// 光标句柄
	WndClass.hIcon			= LoadIcon(NULL, IDI_APPLICATION);		// 图标句柄
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);   // 背景刷句柄
```

#### 注册

```c
RegisterClass(&WndClass);
// 失败返回0
```

### 实现窗口过程函数

程序运行过程中操作系统会在某一类窗口受到消息时调用窗口过程函数进行响应

```c
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
}
```

### 创建窗口

```c
hCommonWnd = CreateWindow(      // 保存窗口句柄用来对窗口进行操作
		szWndClassName,			// 窗口类名
		szWndName,				// 窗口名
		WS_OVERLAPPEDWINDOW,		// 窗口样式
		CW_USEDEFAULT,			// 初始x坐标
		CW_USEDEFAULT,			// 初始y坐标
		CW_USEDEFAULT,			// 初始宽
		CW_USEDEFAULT,			// 初始高
		NULL,					// 父窗口句柄
		NULL,					// 窗口菜单句柄
		hInstance,				// 程序实例句柄
		NULL);
```

### 显示窗口

```c
ShowWindow(hCommonWnd, nShowCmd);
UpdateWindow(hCommonWnd);
```

### 处理消息

```c
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam; //WM_QUIT
}
```

### 模板

```c
#include <stdbool.h>
#include <Windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	static TCHAR szWndClassName[] = _T("Name"); // 创建一个数组存储窗口类名
	static TCHAR szWndName[]		  = _T("TEST");
	HWND		hWnd;     // 窗口句柄
	MSG			msg;	  // 消息变量
	WNDCLASS	WndClass; // 窗口类

	WndClass.lpfnWndProc	= WndProc;								// 窗口过程函数指针
	WndClass.hInstance		= hInstance;								// 实例指针
	WndClass.lpszClassName	= szWndClassName;						// 指向窗口类名的字符串指针
	WndClass.lpszMenuName	= NULL;									// 菜单名句柄
	WndClass.cbClsExtra		= 0;										// 额外分配，不能不赋值，不用就置0
	WndClass.cbWndExtra		= 0;										// 额外分配，不能不赋值，不用就置0
	WndClass.style			= CS_HREDRAW | CS_VREDRAW;		        // 设置窗口样式
	WndClass.hCursor		= LoadCursor(NULL, IDC_CROSS);			// 光标句柄
	WndClass.hIcon			= LoadIcon(NULL, IDI_APPLICATION);		// 图标句柄
	WndClass.hbrBackground  = (HBRUSH)GetStockObject(WHITE_BRUSH);  // 背景刷句柄

	// 注册类
	if (!RegisterClass(&WndClass))
	{
		MessageBoxW(NULL, _T("注册失败！"), _T("错误"), MB_ICONERROR);
		return -1;
	}

	// 创建窗口
	hCommonWnd = CreateWindow(
		szWndClassName,			// 窗口类名
		szWndName,				// 窗口名
		WS_OVERLAPPEDWINDOW,		// 窗口样式
		CW_USEDEFAULT,			// 初始x坐标
		CW_USEDEFAULT,			// 初始y坐标
		CW_USEDEFAULT,			// 初始宽
		CW_USEDEFAULT,			// 初始高
		NULL,					// 父窗口句柄
		NULL,					// 窗口菜单句柄
		hInstance,				// 程序实例句柄
		NULL);

	// 显示窗口
	ShowWindow(hWnd, nShowCmd);
	UpdateWindow(hWnd);

	// 接收与发送消息
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam; //WM_QUIT
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC			hdc;
	PAINTSTRUCT ps;
	RECT			rect;

	switch (message)
	{
	case WM_PAINT: // 窗口必须重新绘制时
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		DrawTextW(hdc, _T("Hello World!"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}
```

## 其他注意
 在VS中要注意默认编码为Unicode，使用Unicode时字符要使用`TCHAR`类型，字符串为`TCHARSTR`类型。对字符串使用`_T("")`宏来转换  
