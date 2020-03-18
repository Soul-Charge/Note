# JavaScript函数

## 输出函数

### alert()

弹出一个警告框
```javascript
alert('Hello World');
```

### console.log()

在控制台输出消息

```javascript
console.log('Hello World'); //输出：Hello World
// 可以传入多个参数,参数之间自动添加一个空格
console.log('hello', 'world'); //输出：hello world
```

### document.write()

在HTML文档页面中输出内容
支持HTML标签

```javascript
document.write('<b>Hello World</b>');
// 可以传入多个参数,参数之间不添加空格
document.write('hello', 'world'); //输出：helloworld
```
> 注意在单引号内部使用`</script>`需要用`\/`转义，否则会使标签提前结束产生错误

## 输入函数

### prompt()

#### 行为

弹出一个输入框

#### 参数

1. 提示框的文本
    可以是数值、字符串
2. 输入框的默认文本
    同一
    > `var name = 'abc';`
    > `prompt('200', name);`

#### 返回值

1. 返回输入的文本
2. 用户点击`close`则返回`null`