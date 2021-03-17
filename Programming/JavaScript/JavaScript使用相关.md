# JavaScript使用相关

## JavaScript 引入方法

### 嵌入式

用`<script>`标签包裹JavaScript代码
```html
<script type="text/javascript">
    <!-- 这里是js代码 -->
</script>
```
> `type="text/javascript"`可省略，因为这是默认属性

### 外链式

用`<script>`标签的`src`属性引入文件
```html
<script src="dir/file.js"></script>
```

### 行内式

将js代码作为html标签的属性值
```html
<a href="javascript:alert('hello');">test</a>
```

### Javascript异步加载

<div style="color:yellow">
经测试无论哪种方法都会先执行js再加载页面，且js会堵塞页面加载 </br>
测试浏览器：chrome, Edge, Yandex </br>
测试日期：2021.1.23
</div>

引入js代码时，页面的下载和渲染会暂停直到脚本执行完，故需要对部分代码进行异步加载

* 将`<script>`标签放在`<body>`的底部
* 在`<script>`标签中添加`async`属性
    会使脚本相对于页面的其他部分异步执行，不阻塞其他代码
    > 只适用于外部脚本
    > `<script src="dir/file.js" async></script>`
* 在`<script>`标签中添加`defer`属性
    在页面加载完后再执行脚本
    > `<script src="dir/file.js" defer></script>`

## 错误处理

### 使用try...catch捕获错误对象

不同于出错后阻塞后续代码，捕获错误代码后catch代码块内的语句会继续运行  
配合上输出错误对象即可实现出错后显示错误但继续执行后续代码的效果

```javascript
var o = {};
try { // 把可能出错的代码放入try
    o.func();
    console.log("这条语句不会被执行"); // 上一句有错误这条不执行
}
catch (e) { // 捕获错误封装到错误对象中
    console.log(e); // 输出错误对象
}
console.log("错误已捕获");
```

### 错误对象

#### 错误对象的传递

错误会逐层向上传递，直到被处理

```javascript
function foo1() {
    foo2();
    console.log('foo1');
}
function foo2() {
    var o = {};
    o.func();    //错误
}
// foo2()中的错误会传递到foo1(),然后继续传递到catch
try {
    foo1();
}
catch (e) {
    console.log('test');
}
```

#### 创建与手动抛出错误对象

```javascript
try{
    var error = new Error('错误啦'); // 创建错误对象
    throw error; // 手动抛出错误
}
catch (e)
{
    console.log(e);
    console.log(e.message);   // 输出错误的消息
    console.log(error === e); // true
}
```

### 错误类型

![](_v_images/20200407131232324_32555.png =700x)