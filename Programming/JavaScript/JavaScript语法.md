# JavaScript语法

<span style="color:green">就列出和C不一样或者C没有的点，所以没列出的就表示和C一样的语法</span>

## 运算符

### 算数运算符

#### **

ES7新特性

```javascript
// 表示2的三次方
2**3 == 8; //结果：true
```

#### 运算注意

* 尽量避免利用浮点数进行计算，可以将参与计算的数据转换为整数计算后再转为浮点数
    > ```javascript
    > 1.66 + 1.77 == 3.42999997 //结果只是个例子，具体多少个⑨不必在意
    > (1.66 * 100 + 1.77 * 100) / 100 == 3.43
    > ```

* 在进行计算时布尔值会被转换成`Number`类型
    > `true`会被转成`1`,`false`转成`0`

### 字符串运算符

#### +

操作数有一个是字符串则表示进行字符串拼接，否则就是表示加法的算数运算符

```javascript
alert('220' + '230');
alert('220' + 230);
alert(220 + '230');
alert(220 + 230);
alert('220 + 230 = ' + 220 + 230);
alert('220 + 230 = ' + (220 + 230));
```
> 输出0：220230  
> 输出1：220230  
> 输出2：220230  
> 输出3：450  
> 输出4：220 + 230 = 220230  
> 输出5：220 + 230 = 450  

**tips:** 可以使用`数据 + ''`的方式将其他类型的数据与空字符串拼接转换成字符串类型

#### ==

可以连接两个字符串判断字符串是否相等
```javascript
'aaa' == 'aaa' //true
'aaa' == 'a'   //false
```

### 赋值运算符

#### **=

ES7新特性，进行幂运算并赋值

```javascript
a = 2;
a **= 3;
a == 8;
```

#### +=

两个操作数都是`Number`时表示相加并赋值
有一个操作数为字符串时表示字符串拼接并赋值

```javascript
a = 'abc';
a += 'def';
a == 'abcdef';
```

### 比较运算符

比较运算符构成的表达式的结果为一个布尔值
不同数据类型的数据进行比较时，首先会自动进行类型转换后比较
> `'123'`与`123`比较时，会先自动把字符串转换成数字再比较

#### === 和 !==

比较时不仅比较操作数的值是否相等，还比较它们的数据类型是否相等

### 位运算符

JS仅能对Number类型的数据进行运算，运算前操作数会被自动转换成二进制(由二进制数组成的32位的串)

#### >>>

表示无符号右移，将左操作数右移右操作数的位数，左边的空位补`0`，不考虑原数的正负
> `>>`进行右移时根据原数的正负在左侧空位补`0(正)`或`1(负)`[参考](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Operators/Bitwise_Operators)  
> <span style="color:green">下面的加号只是用来排版的，空格会被吞╮(╯-╰)╭</span>  
> 例：(9 >> 2)  
> `9 (base 10):++++++00000000000000000000000000001001 (base 2)`  
> `9 >> 2 (base 10): 00000000000000000000000000000010 (base 2) = 2 (base 10)`  
> 例：(-9 >> 2)  
> `-9 (base 10):++++++11111111111111111111111111110111 (base 2)`  
> `-9 >> 2 (base 10): 11111111111111111111111111111101 (base 2) = -3 (base 10)`  
> 例：(-9 >>> 2)  
> `-9 (base 10):+++++++11111111111111111111111111110111 (base 2)`  
> `-9 >>> 2 (base 10): 00111111111111111111111111111101 (base 2) = 1073741821 (base 10)`  
> <span style="color:orange">可是浏览器显示`-9`的二进制是`-1001`啊，难道是省略了前面的吗？</span>  

### 逻辑运算符

<span style="background-color:yellow">CAUTION：只有两个操作数都是布尔值时才返回布尔值，否则返回某个操作数的值</span>
[参考](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Operators/Logical_Operators)  

|       运算符       |       语法       |                               说明                                |
| ------------------ | ---------------- | ----------------------------------------------------------------- |
| 逻辑与，AND（`&&`） | `expr1 && expr2` | 若 `expr1` 可转换为 `true`，则返回 `expr2`；否则，返回 `expr1`。     |
| 逻辑或，OR（`||`）  | `expr1 || expr2` | 若 `expr**1**` 可转换为 `true`，则返回 `expr1`；否则，返回 `expr2`。 |
| 逻辑非，NOT（`!`）  | `!expr`          | 若 `expr` 可转换为 `true`，则返回 `false`；否则，返回 `true`。       |

> 除了`false`, `0`, `null`, `''`, `""`, `undefined`, `NaN`以外的都是`true`

### 运算符优先级

![javascript运算符优先级](_v_images/20200318202800234_622.png =700x)
> 优先级：从上到下递减  
> 第二块的头部接在第一块的尾部  

## 数据类型

### 基本数据类型

#### 布尔型(Boolean)

只有`true`和`false`两个值  
<span style="color:green">貌似不能用1和0来表示真假</span>  

```javascript
var flag1 = true;
var flag2 = false;
```

#### 数值型(Number)

不区分整数和浮点数，支持八、十六进制和科学计数法表示，也可以设置为`NaN`表示非数值

```javascript
var oct = 032;        // 八进制值26
var hex = 0x1a;       // 十六进制值26
var fnum1 = 3.16E6;   // 3.16*10^6
var fnum2 = 8.96E-6;  // 8.96*10^-6
```

**关于NaN**:  
> JS中NaN是一个全局对象的属性，初始值就是`NaN`，其没有一个确定值，`NaN`不一定等于`NaN`  
> <span style="color:green">试了一下`NaN == NaN`全是`false`</span>  

#### 字符(串)型(String)

可以用`'...'`或`"..."`作为字符串标注，两者区别在于对内部对引号的解析  
> 双引号内的单引号可以直接使用`"...'...'..."`  
> 单引号内的双引号可以直接使用`'..."..."...'`  
> 但如果在双引号内使用双引号需要反斜杠转义，单引号内同理  
> 空字符串`''` == `0`

**转义序列**
<span style="color:green">好像和C一样，不需过多在意</span>  

#### 空型(Null)

`null`表示空，表示一个不存在或无效的对象或地址

#### 未定义型(Undefined)

变量未赋值时的初始值`undefined`  
注意`undefined`与`null`和`''`和`0`都不相等

### 复合数据类型

#### 对象(Object)

### 数据类型检测

#### typeof操作符

用法：

```javascript
typeof 对象
// 表达式的值为数据类型
```

> 例：  
> ```javascript
> var a = 123;
> alert(typeof a);    // 输出：number
> alert(typeof '123');// 输出：string
> ```

#### 对象原型的扩展函数

```javascript
var data = null;    // 待判断的数据
var type = 'Null';  // 数据类型，首字母要大写
Object.prototype.toString.call(data) == '[object ' + type + ']';
// 返回值：true 或 false
```

### 数据类型转换

#### 转布尔型

```javascript
Boolean(对象); // 返回值：true 或 false
```

> 将非空字符串和非0值转换为`true`，将`空字符串`, `0`, `NaN`, `undefined`, `null`转换为`false`

#### 转数值型

使用下列转换函数，下列函数转换纯数字时会忽略前导0
> `0123`转换成`123`

|     待转数据      |  Number()   |             parseInt()              | parseFloat() |
| :--------------: | :---------: | :---------------------------------: | :----------: |
|       特性        |             | 省略小数部分，第二个参数设置进制(2~36) | 转换为浮点数  |
|   纯数字字符串    | 转成对应数字 |             转成对应数字             | 转成对应数字  |
|     空字符串      |      0      |                 NaN                 |     NaN      |
|  数字开头的字符串  |     NaN     |             转成开头数字             | 转成开头数字  |
| 非数字开头的字符串 |     NaN     |                 NaN                 |     NaN      |
|       null       |      0      |                 NaN                 |     NaN      |
|    undefined     |     NaN     |                 NaN                 |     NaN      |
|       true       |      0      |                 NaN                 |     NaN      |
|      false       |      1      |                 NaN                 |     NaN      |

> 转换后进行计算前要判断是否为`NaN`，使用`isNaN()`函数来检测，参数为`NaN`返回`true`
> <span style="color:orange">parseFloat的转浮点数是什么鬼，不是只有Number类型吗，而且Number()也可以啊</span>

#### 转字符型

##### String()

将任何类型转换为字符串

```javascript
var num = 12;
alert(String(num)); // 输出：12
```

##### toString()

除了`null`和`undefined`以外都可以，括号内接受一个数字参数表示进制

```javascript
var num = 2;
alert(num.toString());  // 输出:2
alert(num.toString(2)); // 输出:10(二进制的2)
```

### 对象

## 流程控制

### 跳转语句

`break`和`continue`可以跳转到指定的标签语句
<span style="background-color:yellow">CAUTION:只能跳转到其内嵌的标签中</span>[参考](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Statements/break)
```javascript
outer_block:{

  inner_block:{
    console.log ('1');
    break outer_block;      // breaks out of both inner_block and outer_block
    console.log (':-(');    // skipped
  }

  console.log ('2');        // skipped
}
// 下面这个是错误用法
block_1:{
  console.log ('1');
  break block_2;            // SyntaxError: label not found
}

block_2:{
  console.log ('2');
}
```

## 变量

使用`var`关键字定义变量，变量的数据类型根据上下文在运行时决定  
变量命名：可以用`$`字符  
<span style="color:green">C也可以（gcc 7.5.0)</span>

```javascript
var num1 = 22;
alert(num1);
```

> 未初始化的变量默认值为`undefined`

声明变量也可以省略`var`关键字
```javascript
flag = false;
a = 1, b = 2;
```

### 定义常量

用`const`关键字定义变量并初始化，变量名长常使用全大写

```javascript
const PI = 3.14
alert(PI); // 输出：3.14
```

### 变量作用域

#### 全局作用域

不在任何函数内声明的变量，或在函数内部省略`var`关键字声明的变量

#### 函数作用域

在函数体内利用`var`关键字声明的变量

#### 块级作用域(ES6)

使用`let`关键字定义一个块级作用域的变量，即变量的作用域只在代码块内({}之间)

```javascript
for (let i = 0; i < 10; i++)
    continue;
console.log(i); //输出：i is not defined

for (var i = 0; i < 10; i++)
    continue;
console.log(i); //输出：10
```

## 数组(Array)

数组最后一个元素后的逗号可以存在

### 创建数组

#### 使用Array对象创建数组

```javascript
var area = new Array('Beijin', 'Shanghai', 'Shenzhen');
var score = new Array(1, 2, 50);
var mix = new Array('abc', 12, 43, null, 'aa', undefined);
// 空数组
var emptyArr = new Array(); //括号可省略
// 指定数组长度的创建,不影响之后为数组添加元素，长度也会随之改变
var arr = new Array(3);
console.log(arr);     //输出：(3) [empty x 3]
```

#### 使用[]创建数组

```javascript
var area = ['Beijin', 'Shanghai', 'Shenzhen'];
var score = [1, 2, 50,]; // 最后一个元素的逗号可以存在
var mix = ['abc', 12, 43, null, 'aa', undefined];
// 空数组
var emptyArr = [];
// 含有空存储位的数组
var mood = ['sad', , , , 'happy'];
```
> 使用[]可以创建有空存储位的数组，而使用Array对象不行

### 数组操作

#### 数组长度操作

```javascript
var arr1 = [1,2,3];
var arr2 = [1,,2,3];   //空存储位也会增加长度
alert(arr1.length);    //输出：3
alert(arr2.length);    //输出：4
```

可以给数组的`length`属性赋值来修改数组长度，大于原长会增加空存储位，小于原长会截断丢弃元素

```javascript
var arr1 = [];
arr1.length = 5;
console.log(arr1);     //输出：(5) [empty x 5]
var arr2 = [1,2,3];
arr2.length = 4;
console.log(arr2);     //输出：(4) [1, 2, 3, empty]
var arr3 = [1, , , ,2];
console.log(arr3);     //输出：(5) [1, empty x 3, 2]
arr3.length = 1;
console.log(arr3);     //输出：[1]
```

#### 访问数组元素

```javascript
var arr = ['ko', 'no', 'dio', 'da'];
console.log(arr[3]);    //输出：da
console.log(arr);       //输出：(4) ["ko", "no", "dio", "da"]
alert(arr);             //输出：ko,no,dio,da
```

#### 遍历数组元素

##### for (variable in object) {...} 遍历数组取得索引

```javascript
var arr = [1,2,3];
for (var i in arr) { //将数组的索引赋值给变量i
    alert(arr[i]); //输出：1 2 3(三个弹窗分别显示一个值)
}
```

> for ... in 也可以遍历对象

##### for (variable of object) {...} 遍历数组取得元素值(ES6)

```javascript
var arr = [1,2,3];
for (var i of arr) { //将数组的元素值赋值给变量i
    alert(i); //输出：1 2 3(三个弹窗分别显示一个值)
}
```

#### 数组元素的添加与修改

直接用数组下标选择元素进行赋值，可以不按数字顺序添加元素，中间未设置的元素会以空存储位的形式存在

```javascript
var emptyArr = [];
emptyArr[0] = 1;
emptyArr[3] = 4;
emptyArr[5] = 6;
console.log(emptyArr); //输出：(6) [1, empty × 2, 4, empty, 6]
emptyArr[0] = 10;
emptyArr[1] = 11;
console.log(emptyArr); //输出：(6) [10, 11, empty, 4, empty, 6]
```

#### 数组元素的删除

使用`delete`关键字将指定元素的值设为空存储位
```javascript
var arr = [1, 2, 3];
delete arr[1];
console.log(arr);  //输出：(3) [1, empty, 3]
```

### 解构赋值（ES6)

```javascript
var arr = [1, 2, 3];
[a, b, c] = arr;
console.log(a, b, c);    //输出：1 2 3
[a, b, c] = [2, 3, 3];
console.log(a, b, c);    //输出：2 3 3
[a, b, c] = [2, ,3];
console.log(a, b, c);    //输出：2 undefined 3
[a, b, c] = [1, 2, 3, 4];
console.log(a, b, c);    //输出：1 2 3
[a, b, c] = [1, 2];
console.log(a, b, c);    //输出：1 2 undefined
```

使用解构赋值的方式交换两个变量的值

```javascript
var val1 = 2;
var val2 = 3;
[val1, val2] = [val2, val1];
console.log(val1, val2);
```

### 数组方法

#### 栈方法

入栈：在数组的末尾或开头添加新元素
出栈：在数组的末尾或开头删除元素

|     方法名 |                       功能描述                        |
| -------- | ----------------------------------------------------- |
|    push() | 将一个或多个元素添加到数组的末尾，并返回数组的新长度      |
| unshift() | 将一个或多个元素添加到数组的开头，并返回数组的新长度      |
|     pop() | 从数组的末尾移出并返回一个元素，若是空数组则返回undefined |
|   shift() | 从数组的开头移出并返回一个元素，若是空数组则返回undefined |

#### 检索方法

|     方法名称     |                          功能描述                          |
| --------------- | --------------------------------------------------------- |
| includes()      | 用于确定数组中是否含有某个元素， 含有返回true ， 否则返回false |
| Array.isArray() | 用于确定传递的值是否是一个Array ， 是返回true, 不是返回false  |
| indexOf()       | 返回在数组中可以找到给定值的第1 个索引， 如果不存在， 则返回-1 |
| lastIndexOf()   | 返回指定元素在数组中的最后一个的索引， 如果不存在则返回-1      |

##### `includes()`

```javascript
数组.includes(待查找的值, 偏移量(从什么地方开始));
下标大于数组长度不搜索返回false，小于0表示数组长度加上该值(结果仍小于0检索整个数组)
```

```javascript
var data = ['peach', 'pear', 26, '26', 'grade'];
// 从下标为3的地方开始搜索
console.log(data.includes(26, 3));    //输出：false
// 从下标为1的地方开始搜索
console.log(data.includes(26, 1));    //输出：true
// 从下标为data.length - 3的地方开始搜索
console.log(data.includes(26, -3));   //输出：true
```

`indexOf()`的第二个参数特性与`includes()`相同

##### `lastIndexOf()`

从后往前搜索，第二个参数大于等于数组长度会搜索整个数组，为负数则索引位置等于数组长度加上该值，若仍为负数则返回-1

#### 数组转字符串

|  方法名称   |              功能描述               |
| ---------- | ----------------------------------- |
| join()     | 将数组的所有元素连接到一个字符串中     |
| toString() | 返回一个字符串, 表示指定的数组及其元素 |

`join()`可以指定连接`数组元素`的符号  
数组元素为`undefined`, `null`时, 对应元素会被转为空字符串

```javascript
console.log(['a', 'b', 'c'].join());            //输出:a,b,c
console.log([[4, 5], [1, 2], [3, 4]].join('-'));//输出:4,5-1,2-3,4
console.log(['a', 'b', 'c'].toString());        //输出:a,b,c
console.log([[4, 5], [1, 2]].toString());       //输出:4,5,1,2
```

#### 其他方法

|  方法名称  |                       功能描述                        |
| --------- | ----------------------------------------------------- |
| sort()    | 对数组的元素进行排序,并返回数组                         |
| fill()    | 用一个值填充(修改)数组中指定下标范围内的全部元素          |
| reverse() | 颠倒数组中元素的位置                                    |
| splice()  | 对一个数组在指定下标范围内删除或添加元素                 |
| slice()   | 从一个数组的指定下标范围内复制数组元素到一个新数组中并返回 |
| concat()  | 将值添加到数组后返回一个新数组                          |

> 只有`slice()`和`concat()`会返回新数组而不修改原数组

##### `fill()`

```javascript
var arr = [1, 9, , 5, 6];
console.log(arr);    //输出：(5) [1, 9, empty, 5, 6]
arr.fill(1, 0, 10);  // 把第0号到末尾的元素替换为1
console.log(arr);    //输出：(5) [1, 1, 1, 1, 1]
```

> 后两个位置参数指定的值大于末尾索引则表示数组末尾，其他情况同splice()中的位置指示参数

##### `splice()`

```javascript
var arr = ['a', 'b', 'c', 'd'];
console.log(arr);         //输出：(4) ["a", "b", "c", "d"]
arr.splice(2, 2);         // 从第2号元素开始删除两个元素
console.log(arr);         //输出：(2) ["a", "b"]
arr.splice(0,0,'e', 'f'); // 从第0号元素开始添加元素
console.log(arr);         //输出：(4) ["e", "f", "a", "b"]
arr.splice(1,0,'hello');  // 从第1号元素开始添加元素
console.log(arr);         //输出：(5) ["e", "hello", "f", "a", "b"]
arr.splice(1,1,'bye');    // 从第一号元素开始删除一个元素，并添加元素(相当于替换元素)
console.log(arr);         //输出：(5) ["e", "bye", "f", "a", "b"]
```

> 第一个参数大于等于数组长度则从数组末尾开始操作，若为负数则表示数组长度加上该值的位置，若仍为负数则从开头操作。

##### `concat()`

```javascript
var arr = [1, 2, 3];
var arr2 = ['a', 'b'];
console.log(arr);                        //输出： (3) [1, 2, 3]
console.log(arr.concat(8, 9, 10, arr2)); //输出：(10) [1, 2, 3, 8, 9, 10, "a", "b"]
```

## 函数

### 自定函数

```javascript
function sum(a, b)
{
    return a + b;
}
alert(sum(1,2)); // 输出结果：3
```

> 函数名命名规则与变量相同
> 函数的调用可以在函数定义前

#### 设置形参

##### 形参默认值(ES6)

```javascript
function greet(name, say = "Hi, I'm ")
{
    alert(say + name);
}
// 没有传入第二个参数时将使用默认值
```

##### 可变参数

###### 参数列表留空使用arguments数组

```javascript
function transferParam()
{
    console.log(arguments.length);
    console.log(arguments);
    for (let i in arguments)
      alert(arguments[i]);
}
transferParam(1, 2, 'a');
//输出
//3
//Temp.html:12 Arguments(3) [1, 2, "a", callee: ƒ, Symbol(Symbol.iterator): ƒ]
//3个alert()弹窗，值分别为1 2 a
```

###### 剩余参数(ES6)

创建一个`...变量名`的形参用于接收剩余参数  

```javascript
function transferParam(argv1, ...argvs)
{
    console.log(argv1); //输出第一个参数
    console.log(argvs); //输出剩余接收到的参数
}
transferParam(1, 2, 'a');
//输出
//1
//Temp.html:12 (2) [2, "a"]
```

#### 作用域链

内层函数在当前作用域中寻找变量，若未找到则向上一级作用域中寻找，直到全局作用域

```javascript
var i = 10;
function fn1()
{
    var i = 5;
    function fn2()
    {
        function fn3()
        {
            console.log(i); //输出：5
        }
        fn3();
    }
    fn2();
}
fn1();
```

### 匿名函数

#### 函数表达式

将函数赋值给一个变量，之后使用`变量名()`来调用函数，定义必须在调用前

```javascript
console.log(fn(1,2));  //错误调用-输出：fn is not a function
var fn = function sum(x, y) //定义函数表达式
{
    return x + y;
};
console.log(fn(1,2));   //输出：3
console.log(sum(1,2));  //错误调用-输出：sum is not defined
```

#### 匿名函数的使用方法

```javascript
// 函数表达式中省略函数名
var sum = function (x, y) {return x + y;};
console.log(sum(1,1)); //输出：2
// 将函数定义用括号包裹(这是一次性函数吗，那还有什么意义)
console.log( (function (x, y) {return x + y;})(1,1) );
// 添加事件处理
document.body.onclick = function() {alert('Hello');};
// 因为函数体只有一行所以就放一行了
```

#### 箭头函数(ES6)

```javascript
// 标准语法
(参数列表) => {函数体}
// 函数体只有一条return语句可以省略return和{}
(参数列表) => {return expression;} 等价于 (参数列表) => expression
// 只有一个参数可以省略()
参数 => {函数体}
// 无参数需要保留()或使用一个_
() => {函数体} 等价于 _ => {函数体}
```

```javascript
//例：
var sum = (x, y) => x + y;
console.log(sum(1,1)); //输出：2
```

### 闭包函数

闭包函数可以在函数外部读取函数内部的变量，并能让函数内部的变量一直保存在内存中

```javascript
function fn()
{
    var times = 0;
    var c = function () { return ++times; };
    return c;
}
var count = fn();
console.log(count()); //输出：1
console.log(count()); //输出：2
console.log(count()); //输出：3
```

## 对象

```mermaid
graph LR

变量 --> 属性 --> 对象
函数 --> 方法 --> 对象
```

使用`.`来访问对象的属性或方法，对象和方法的区别为有无`()`

### 自定对象

#### 定义和初始化对象

```javascript
var obj1 = {};     //定义空对象
var obj2 = {name: 'Jim'}; //定义含有name属性的对象
var obj3 = {       //定义含有两个属性的对象
  name: 'Jim',
  age: '19
};
```

> 字面量语法：在源码中直接书写的一个表示数据和类型的量，如`123`(数值型), `'123'`(字符型), `[123]`(数组)

#### 添加和访问对象成员

```javascript
var boki = {};         // 创建一个名为boki的空对象
boki.name = '吉良吉影'; // 为对象添加name属性
boki.age = 33;
boki.introduce = function () { // 添加方法
    return '我的名字叫' + this.name + ',年龄' + this.age + '岁。';
    // 用this指代当前对象，可以使对象内部不依赖对象外部的变量名
};
// 访问对象的属性和方法
alert(boki.name); //输出：吉良吉影
alert(boki.introduce()); //输出：我的名字叫吉良吉影，年龄33岁
```

```javascript
// 使用可变成员名
var boki = {};
var key = 'stand'; //用变量保存属性名
boki[key] = 'killer queen';
// 相当于 boki['stand'] 或 boki.stand
```

```javascript
// 遍历对象成员
var obj = {a: 1, b: 2, c: 3};
for (let i in obj)
    console.log(i + ':' + obj[i]);
// 输出：(\n表示换行，这里用来减少占用空间)
a:1\nb:2\nc:3
```

### 对象操作

#### 判断成员是否存在

```javascript
var obj = {a: 1, b: 2, c: 3};
console.log('a' in obj); //输出：true
console.log('d' in obj); //输出：false
```

#### 对象复制

##### 浅复制(shallow copy)

直接将对象赋值给另一个对象，修改其中一个对象同时也会修改另一个对象

```javascript
var obj1 = {a: 1, b: 2, c: 3};
var obj2 = obj1;
obj2.b = 'bbb';
console.log(obj1); //输出：{a: 1, b: "bbb", c: 3}
console.log(obj2); //输出：{a: 1, b: "bbb", c: 3}
```

##### 深复制(shallow copy)

赋值对象的成员到另一个对象，创建对象真正的副本

```javascript
function DeepCopy(obj)
{
    var o = {};
    for (let i in obj)
        o[i] = (typeof obj[i] === 'object') ? DeepCopy(obj[i]) : obj[i];
    return o;
}
```

### 构造函数

使用构造函数构建同一类对象，通过类创建的对象称为该类的实例，此过程称为实例化

#### 内置构造函数

```javascript
var obj1 = new Object();
var obj2 = {};                //通过字面量{}创建的对象是Object()的实例
var str  = new String('123');
// 查看对象由哪个构造函数创建([native code]表示函数代码是JS内置的)
console.log(obj1.constructor); //输出：ƒ Object() { [native code] }
console.log(obj2.constructor); //输出：ƒ Object() { [native code] }
console.log(str.constructor);  //输出：ƒ String() { [native code] }
```

#### 自定义构造函数

```javascript
var p1 = new Person('Jack', 18);
var p2 = new Person('fuck', 666);
p1.sayHello();    //输出：Hello my name is Jack I'm 18 years old.
p2.sayHello();    //输出：Hello my name is fuck I'm 666 years old.
console.log(p1.constructor); //输出：ƒ Person(name, age)...(函数完整定义)
function Person(name, age)
{
    this.name = name;
    this.age  = age;
    this.sayHello = function () {
    console.log('Hello ' + 'my name is ' + this.name + " I'm " + this.age + ' years old.');
    };
}
```

```javascript
// class关键字(ES6)
class Person // 定义类
{
    constructor (name, age) // 构造方法
    {
        this.name = name;   // 添加属性
        this.age  = age;
    }
    // 定义introduce()方法
    introduce() { console.log('我叫 ' + this.name + ' 今年 ' + this.age + ' 岁。'); }
}
// 实例化会自动调用constructor()方法
var p = new Person('abc', 24);
p.introduce(); //输出：我叫 abc 今年 24 岁。
```

##### 私有成员

在构造函数中使用`var`关键字定义变量，实例对象后无法通过`对象.成员`的方式访问

```javascript
var p = new Person();
console.log(p.name);     //输出：undefined
console.log(p.getName());//输出：boy
function Person ()
{
    var name = 'boy';
    this.getName = function() {return name;};
}
```

##### return关键字


```javascript
//使用return返回一个基本数据类型，返回的依然是创建的对象
var p = new Person();
console.log(p);       //输出：Person {getName: ƒ}
function Person ()
{
    var name = 'boy';
    this.getName = function() {return name;};
    return 123;
}
```

```javascript
//使用return返回复合数据类型，则返回该类型而不是创建的对象
var p = new Person();
console.log(p);       //输出：(2) [1, 2]
function Person ()
{
    var name = 'boy';
    this.getName = function() {return name;};
    return [1,2];
}
```

##### 函数中的this指向

###### this指向情况

1. 函数作为构造函数调用时，this指向创建的对象
2. 直接通过函数名调用函数时，this指向全局对象(浏览器中为window对象)
3. 将函数作为对象的方法调用时，this指向该对象

```javascript
function func() {return this};
var obj = {func: func};
console.log(func() === window); // true
console.log(obj.func() === obj);// true
```

###### 更改this指向

使用`apply()`和`call()`方法

```javascript
function showObject() {
    console.log(this);
}
showObject();        //输出:Window {...}
showObject.apply({});//输出:{}
showObject.call({}); //输出:{}
showObject();        //输出:Window {...}
```

```javascript
function add() {
    var sum = 0;
    for (let i of arguments)
        sum += i;
    console.log(sum);
}
add.apply({}, [1, 2, 3]); //数组传参，输出:6
add.call({}, 1, 2, 3);    //参数传参，输出:6
```

使用`bind()`方法(ES5)

```javascript
function showName(number) {
    console.log(this.name + ' ' + number);
}
var name = 'Death';
var test = showName.bind({name: 'The world'}, '21');
showName(13); //输出：Death 13
test();       //输出：The world 21
```

### 内置对象

#### window 对象

> `window.console`       // 访问window对象的的console属性  
> `window.document`     // 访问window对象的document属性  
> `console.log()`        // 访问console对象的log方法  
> `document.write()`  // 访问document的write方法  
> `console`和`document`既是属性也是对象  

#### document 对象

通过JS访问或修改元素时需要通过document对象提供的方法创建元素对象进行操作

##### 通过元素id属性操作

```html
<body>
  <div id="test">Hello</div>
  <script>
    var test = document.getElementById('test'); //根据元素id创建元素对象
    alert(test.innerHTML); //通过innerHTML属性获取元素内容
  </script>
</body>
```

#### String 对象

直接定义一个字符串就可以作为String对象使用

```javascript
var str = 'apple';
alert(str.length);           // 获取字符串长度
alert(str.toUpperCase());    // 获取字符串转大写后的结果
alert('apple'.toUpperCase());// 同上
```

##### String对象的常用属性和方法

![](_v_images/20200405093940336_30772.png =700x)
> 上表的方法结果都通过返回值返回，位置皆从0开始

```javascript
var str = '1234554321';
console.log(str.charAt(3));        //4
console.log(str.indexOf('2'));     //1
console.log(str.lastIndexOf('2')); //8
console.log(str.substring(5));     //54321
console.log(str.substring(4,6));   //55
console.log(str.substr(5));        //54321
console.log(str.substr(4, 2));     //55
console.log(str.split('4'));       //(3) ["123", "55", "321"]
console.log(str.split('4', 2));    //(2) ["123", "55"]
console.log(str.split('4', 3));    //(3) ["123", "55", "321"]
console.log(str.replace('55', '5'));// 123454321
```

#### Number对象

##### Number对象的常用属性和方法

![](_v_images/20200405101225628_8460.png =600x)

```javascript
var number = 12345.6789;
console.log(number.toFixed()); //12346
console.log(number.toFixed(1));//12345.7
console.log(number.toFixed(6));//12345.678900
console.log(Number.MAX_VALUE); //1.7976931348623157e+308
console.log(Number.MIN_VALUE); //5e-324
```

#### Math对象

##### Math对象的常用属性和方法

![](_v_images/20200405102337684_4313.png =700x)
![](_v_images/20200405102443314_3940.png =700x)

```javascript
var num = 1.23;
var n   = 1;
var m   = 100;
console.log(Math.ceil(num));  //2
console.log(Math.floor(num)); //1
console.log(Math.round(num)); //1
console.log(Math.random());   //随机数0.806025420290184
console.log(Math.random() * (n - m) + m); //[m,n]的随机数
console.log(Math.abs(-23));   //23
console.log(Math.abs('-25')); //25
console.log(Math.max(1, 3, 0, 8)); //8
console.log(Math.max('1', '3', '0', '8')); //8
```

#### Date 对象

##### Date对象的常用方法

![](_v_images/20200405104755215_4572.png =700x)
![](_v_images/20200405104850340_7966.png =700x)

> 基于当前时间创建对象

```javascript
var date = new Date();
console.log(date.toString());   //Sun Apr 05 2020 10:55:29 GMT+0800 (中国标准时间)
console.log(date.getFullYear());//2020
console.log(date.getMonth());   //4
console.log(date.getDate());    //5
```

> 指定时间创建对象
> 传入时间大于合理范围会自动设置，(月份设置-1被转为去年12月，月份设置12被转为明年1月)

```javascript
// 传入 年、月、日、时、分、秒(月的范围是[0,11])
// 最少需要传入 年和月
var date = new Date(2014, 3, 4, 4, 4, 4);
console.log(date.toString());   //Fri Apr 04 2014 04:04:04 GMT+0800 (中国标准时间)
new Date(2014, 3); //Tue Apr 01 2014 00:00:00 GMT+0800 (中国标准时间)
```

```javascript
// 传入字符串
// 最少需要传入年
var date = new Date('2014-04-4 04:04:04');
console.log(date.toString());   //Fri Apr 04 2014 04:04:04 GMT+0800 (中国标准时间)
new Date('2014'); //Wed Jan 01 2014 08:00:00 GMT+0800 (中国标准时间)
```

### 原型对象

基于同一个构造函数创建的对象会重复独立保存相同的方法

```javascript
function Person(name) {
    this.name = name;
    this.introduce = function () { };
}
var p1 = new Person('Dio');
var p2 = new Person('JOJO');
console.log(p1.introduce === p2.introduce); // false
```

利用原型对象可以保存一些公共的属性和方法，基于原型创建的对象会自动拥有原型的属性和方法

```javascript
// 创建一个函数就会自动创建它的原型对象，构造函数为此函数
function func() {}
console.log(func.prototype);
```

```javascript
function Person(name) {
    this.name = name;
}
Person.prototype.introduce = function () { };
var p1 = new Person('Dio');
var p2 = new Person('JOJO');
console.log(p1.introduce === p2.introduce); // true
```

### 继承

在已有的对象的基础上继承其他对象

#### 继承实现方式

##### 继承原型对象

在构造函数的原型中添加属性和方法

```javascript
function Person(name) {
    this.name = name;
}
Person.prototype.sayHi = function () {
    console.log("Hi I'm " + this.name);
}
var p = new Person('spw'); // 继承了原型对象中的sayHi()方法
p1.sayHi();
```

对象创建后修改原型，继承此原型的对象继承来的属性或方法也会变化
<span style="color:green"> **对象里继承来的成员类似于一种链接，原型中的成员改变，对象中对应的成员也会变化**</span>  

```javascript
function Person(name) {
    this.name = name;
}
var p = new Person('A');
console.log(p1.test);    // undefined
// 在Person的原型中添加属性
Person.prototype.test = 'test';
console.log(p1.test);    // test
```

对象自身的成员会覆盖原型的成员
<span style="color:orange">或者说对象只会从原型继承它没有的成员？</span>

```javascript
function Person(name) {
    this.name = name;
    this.say  = function () {console.log('我是构造函数的默认say()方法');}
}
var p = new Person('First');
p.say();    // 输出：我是构造函数的默认say()方法
// 修改Person的原型
Person.prototype.say = function () {console.log('我是修改后的say()方法');};
p.say();    // 输出：我是构造函数的默认say()方法
```

##### 替换原型对象

用另一个对象替换原型，替换后不会改变已创建的对象，重新使用该构造函数创建的对象才是修改过的

```javascript
function Person(name) {}
Person.prototype.say = function () {console.log('我是原型');}

// 创建对象p1, p1的创建在替换前,所以是默认值
var p1 = new Person();

// 替换原型
Person.prototype = {
    say: function () {console.log('我是替换后的');}
}
// 如果使用下面这条语句则是修改原型，结果是对象p1和p2的say()方法都会输出"我是替换后的"
// Person.prototype.say = function () {console.log('我是替换后的');}

// 创建对象p2, 因为p2的创建在替换后，所以该对象的方法是替换后的
var p2 = new Person();
p1.say(); // 我是原型
p2.say(); // 我是替换后的
```

下面的这个例子中，替换原型没有产生影响，参考上面的"对象自身的成员会覆盖原型的成员"

```javascript
function Person(name) {
    this.name = name;
    this.say  = function () {console.log('我是构造函数的默认say()方法');}
}
var p1 = new Person('test');
Person.prototype = {
    name: "replaced",
    say : function () {console.log('我是用另一个对象替换原型后的say()方法');}
}
console.log(p1.name);
p1.say();
var p2 = new Person('test2');
console.log(p2.name);
p2.say();
```

##### 利用Object.create()实现继承(ES5)

```javascript
var obj = {
    value: 'test'
}
// 以obj为原型对象，创建一个对象并返回
var newObj = Object.create(obj);
console.log(newObj.value);    // test
```




## 事件

可以被JS侦测到的交互行为，事件发生后可以用JS实现交互效果

### onclick事件

元素被点击时产生

```html
<body>
  <input id="btn" type="button" value="test">
  <script>
  document.getElementById('btn').onclick = function () // 给元素对象设置onclick事件
  {
      alert(this.value); // this表示当前发生事件的元素对象
  }
  </script>
</body>
```