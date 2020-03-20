# JavaScript算法收集

```javascript
// 获取输入的纯数字
var input = prompt('请输入数字');
input = parseFloat(input) && Number(input);
```
> 使用parseFloat()意义在于使空输入也转成`NaN`
> 只使用Number(input)在prompt()遇到空输入时返回0