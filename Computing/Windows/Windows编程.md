# Windows编程

## 创建窗口

### 实现WinMain()函数

使用窗口时的入口函数，取代main()
<span style="color:green">好像用main()也是可以的，具体看[这个](https://www.cnblogs.com/panlm/p/4387375.html)</span>  
```c
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
    //...
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
// 可以使用默认窗口过程函数
DefWindowProc(hwnd, message, wParam, lParam);
```

```c
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    // 使用switch处理对应的消息
    switch (message)
    {
    case WM_PAINT: //...
        return 0;
    case WM_MOUSEMOVE:  //处理鼠标移动消息
        if (MK_LBUTTON & wParam) //判断鼠标左键是否按下
    //...
    }
    // 使用默认窗口过程函数处理其余消息
	return DefWindowProc(hwnd, message, wParam, lParam);
}
```

#### `message`
窗口消息，可能的值：`WM_PAINT`，其他值可以通过查看该值的定义位置找到

#### `wParam`

含义根据`message`的内容而定，使用位屏蔽法判断

##### 鼠标消息

当`message`为鼠标消息时，该值指示Shift和Ctrl键或鼠标的状态

```c
// 判断示例
if (MK_LBUTTON & wParam) //若鼠标左键按下则为真
```

#### `lParam`

##### 鼠标消息

当`message`为鼠标消息时，该值表示鼠标位置(低位字为x坐标，高位字为y坐标)
使用`LOWORD()`和`HIWORD()`宏进行获取
> 相关拓展：windows.h没有`sprintf()`可以使用`wsprintf()`

### 创建窗口

使用`CreateWindow()`函数创建窗口，创建后会发送`WM_CREATE`消息

```c
hCommonWnd = CreateWindow(      // 保存窗口句柄用来对窗口进行操作
		szWndClassName,	        // 窗口类名
		szWndName,              // 窗口名
		WS_OVERLAPPEDWINDOW,    // 窗口样式
		CW_USEDEFAULT,			// 初始x坐标
		CW_USEDEFAULT,			// 初始y坐标
		CW_USEDEFAULT,			// 初始宽
		CW_USEDEFAULT,			// 初始高
		NULL,					// 父窗口句柄
		NULL,					// 窗口菜单句柄
		hInstance,				// 程序实例句柄
		NULL);
```

#### `lpClassName`

窗口类名，可以使用自定的窗口类或[系统预设窗口类](https://docs.microsoft.com/zh-cn/windows/win32/api/winuser/nf-winuser-createwindowa?redirectedfrom=MSDN#remarks)

#### `dwStyle`

窗口样式，中间用`|`隔开，常用样式：
```c
WS_VISIBLE // 可见
WS_CHILD   // 表示窗口是子窗口
```


#### `hMenu`

窗口菜单句柄，可以作为ID来表示窗口
```c
(HMENU)/*(int)ID */
```
> ID是一个int值，再转换为`HMENU`

#### `hInstance`

程序实例句柄，通常使用`WinMain()`的参数

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
```

### 模板

```c
#include <stdbool.h>
#include <Windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine, _In_ int nShowCmd
)
{
	static TCHAR szWndClassName[] = _T("Name"); // 创建一个数组存储窗口类名
	static TCHAR szWndName[]      = _T("TEST"); // 窗口名
	HWND        hWnd;     // 窗口句柄
	MSG         msg;      // 消息变量
	WNDCLASS    WndClass; // 窗口类

	WndClass.lpfnWndProc    = WndProc;                              // 窗口过程函数指针
	WndClass.hInstance      = hInstance;                            // 实例指针
	WndClass.lpszClassName  = szWndClassName;                       // 指向窗口类名的字符串指针
	WndClass.lpszMenuName   = NULL;                                 // 菜单名句柄
	WndClass.cbClsExtra     = 0;                                    // 额外分配，不能不赋值，不用就置0
	WndClass.cbWndExtra     = 0;                                    // 额外分配，不能不赋值，不用就置0
	WndClass.style          = CS_HREDRAW | CS_VREDRAW;              // 设置窗口样式
	WndClass.hCursor        = LoadCursor(NULL, IDC_CROSS);          // 光标句柄
	WndClass.hIcon          = LoadIcon(NULL, IDI_APPLICATION);      // 图标句柄
	WndClass.hbrBackground  = (HBRUSH)GetStockObject(WHITE_BRUSH);  // 背景刷句柄

	// 注册类
	if (!RegisterClass(&WndClass))
	{
        MessageBoxW(NULL, _T("注册失败！"), _T("错误"), MB_ICONERROR);
		return -1;
	}

	// 创建窗口
	hWnd = CreateWindow(
		szWndClassName,	        // 窗口类名
		szWndName,              // 窗口名
		WS_OVERLAPPEDWINDOW,    // 窗口样式
		CW_USEDEFAULT,          // 初始x坐标
		CW_USEDEFAULT,          // 初始y坐标
		CW_USEDEFAULT,          // 初始宽
		CW_USEDEFAULT,          // 初始高
		NULL,                   // 父窗口句柄
		NULL,                   // 窗口菜单句柄
		hInstance,              // 程序实例句柄
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

//窗口过程函数
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC	        hdc; // 设备描述表句柄
    PAINTSTRUCT ps;
    RECT        rect;// 绘图区域

    switch (message)
    {
    case WM_PAINT: // 窗口必须重新绘制时
        hdc = BeginPaint(hwnd, &ps); //在无效区域中绘图，并清除WM_PAINT消息将无效区域变为有效
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

## 窗口绘图

### 被动绘图

窗口过程函数接收到`WM_PAINT`消息时，在无效区域中绘图并**清除**该消息使无效区域变为有效区域

```c
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC        hdc; // 设备描述表句柄
    PAINSTRUCT ps;
    RECT       rect;// 绘图区域
    
    switch (message)
    {
    case WM_PAINT: // 窗口必须重新绘制时
        hdc = BeginPaint(hwnd, &ps); // 在无效区域中绘图，并清除WM_PAINT消息将无效区域变为有效
        // 绘图操作
        EndPaint(hwnd, &ps); // 结束绘图
        return 0;
    //...
    }
    // 使用默认窗口过程函数处理其余消息
	return DefWindowProc(hwnd, message, wParam, lParam);
}
```

### 主动绘图

随时在绘图区域的任何位置进行绘图

```c
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC     hdc; // 设备描述表句柄
    RECT    rect;// 绘图区域
    
    switch (message)
    {
    case //... :
        hdc = GetDC(hwnd);
        // 绘图操作
        ReleaseDC(hwnd,hdc); //结束绘图
        return 0;
    //...
    }
    // 使用默认窗口过程函数处理其余消息
	return DefWindowProc(hwnd, message, wParam, lParam);
}
```

## 窗口间通信

### 子窗口给父窗口发送消息

当控件发送消息给父窗口时将产生`WM_COMMAND`消息，在窗口过程里判断处理

```c
// 子窗口控件产生消息时
LWORD(wParam) // 控件ID
HIWORD(wParam)// 通知码
lParam        // 子窗口句柄
```

```c
// 例：处理子窗口消息
// ...窗口过程函数中的一部分...
case WM_COMMAND: //子窗口消息
    switch (LOWORD(wParam)) //判断ID
    {
    case /* 窗口ID */: 
        // if (HIWORD(wParam == BN_DOUBLECLICKED) //判断消息码，是否双击
        break;
    }
    switch (lParam) //判断窗口句柄
    {
    case /* 窗口句柄 */: 
        break;
    }
```

#### Button

双击通知码`BN_DOUBLECLICKED`, 仅当下压按钮风格包括`BS_NOTIFY`时才发送。


### 父窗口给子窗口发送消息

```c
LRESULT SendMessage (
    HWND hWnd,    // 接收消息的窗口的句柄
    UINT Msg,     // 指定被发送的消息
    WPARAM wParam,// 指定附加的消息特定信息
    LPARAM IParam // 指定附加的消息特定信息
);
// 返回值：指定消息处理的结果，依赖于所发送的消息
```

#### `Msg`

[窗口消息](https://docs.microsoft.com/zh-cn/windows/win32/winmsg/window-messages)

```c
// 例：修改按钮的文字
SendMessage(hButton,WM_SETTEXT,(WPARAM)NULL,(LPARAM)"我是按钮");
```

## 其他注意
 在VS中要注意默认编码为Unicode，使用Unicode时字符要使用`TCHAR`类型，字符串为`TCHARSTR`类型。对字符串使用`_T("")`宏来转换  
