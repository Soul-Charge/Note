# Syntax

## Java程序结构

Java程序由类组成，必须有且只有一个位于类中的main()方法  

```text
package                    0个或1个，必须放在文件开始
import                     0个或多个，必须放在所有类前
public class Definition    0个或1个，文件名必须与该类名相同
class Definition           0个或多个
                           main()方法，位于类中，详见下
interface Definition       0个或多个
// 注释内容                 单行注释，可放于任何地方
/*
   注释内容                 多行注释，可放于任何地方
*/
```

### package

```Java
package packageName
```

当源文件位于某package内时必须有↓  

```
package 源文件所在的package名
```

### import

### public class

使用`public class`声明一个公共类  
Java程序只能有一个公共类，且有公共类的源文件，文件名需与公共类名相同  

### class

使用关键字`class`声明一个新类  
例：  

```Java
class className
```

### main()方法

程序中必须有且只有一个main()方法  
必须用关键字`public`,`static`,`void`限定并传递参数`String[] args`  
例：  

```Java
class className {
    public static void mian(String[] args) {
    }
}
```

**public**：指明所有的类都可以使用这个方法  
**static**：指明本方法是一个类方法，可以通过类名直接调用  
**void**： 指明本方法没有返回值  
**String[] args**：传递给main()方法的参数，名称为args，是String类的实例  

### interface









