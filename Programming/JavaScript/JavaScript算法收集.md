# JavaScript算法收集

## 获取输入的纯数字

```javascript
var input = prompt('请输入数字');
input = parseFloat(input) && Number(input);
```
> 使用parseFloat()意义在于使空输入也转成`NaN`
> 只使用Number(input)在prompt()遇到空输入时返回0

## 二维数组转置

```javascript
<script>
  var arr = [
    ['a', 'b', 'c'],
    ['d', 'e', 'f'],
    ['g', 'h', 'i'],
    ['j', 'k', 'l'],
  ]
  var res = [];
  for (var i in arr[0])  //遍历原数组的元素
  {
    res[i] = [];        //将res赋值为合适规格的二维数组
    for (var j in arr)  //遍历原数组
      res[i][j] = arr[j][i];
  }
  // 分组输出，便于查看
  console.group('转置前:');
  console.log(arr);
  console.groupEnd();
  console.group('转置后:');
  console.log(res);
  console.groupEnd();
</script>
```

## 排序算法

### 冒泡排序

![冒泡排序](_v_images/20200321152618500_22624.png =500x)
> 比较的轮数==数组长度-1
> 每轮比较的对数==数组长度-当前的轮数

```javascript
<script>
  var arr = [1, 3, 6, 89, 92, 4];
  console.log('待排序数组' + arr);
  // 排序，从小到大
  for (var i = 1; i < arr.length; i++) //控制比较轮数(长度-1)
    for (var j = 0; j < arr.length - 1; j++) //控制比较元素
      if (arr[j] > arr[i]) //<-------(>为从小到大,改变符号以改变排序反向)
        [arr[j], arr[i]] = [arr[i], arr[j]]; //交换两元素的位置
  console.log('排序后(从小到大): ' + arr);
</script>
```

### 插入排序

![插入排序](_v_images/20200321181202906_19065.png =500x)

```javascript
<script>
  var arr = [1, 3, 6, 89, 92, 4];
  console.log('待排序数组' + arr);
  // 排序，从小到大
  for (var i = 1; i < arr.length; i++) //遍历无序数组下标
    for (var j = i; j > 0; j--) //遍历并比较一个无序数组元素与所有有序数组元素
      if (arr[j - 1] > arr[j]) //从小到大
        [arr[j - 1], arr[j]] = [arr[j], arr[j - 1]];
  console.log('排序后(从小到大): ' + arr);
</script>
```








