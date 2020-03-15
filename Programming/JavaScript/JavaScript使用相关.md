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

引入js代码时，页面的下载和渲染会暂停直到脚本执行完，故需要对部分代码进行异步加载

* 将`<script>`标签放在`<body>`的底部
* 在`<script>`标签中添加`async`属性
    会使脚本相对于页面的其他部分异步执行，不阻塞其他代码
    > 只适用于外部脚本
    > `<script src="dir/file.js" async></script>`
* 在`<script>`标签中添加`defer`属性
    在页面加载完后再执行脚本
    > `<script src="dir/file.js" defer></script>`
