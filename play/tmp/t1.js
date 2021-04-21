
for (var i = 2; i <= 10; i++) {
    //假设所有的数都是质数
  var flag = true;
    //通过嵌套循环找到 i 除了1 和本身以外所有可能出现的因子
  for (var j = 2; 
       j < i; 
       j++) {
    //判断 i 是否为质数
    if (i % j == 0) {//能进到当前的分支 说明不是质数
      flag = false;
    }
  }
  
  if (flag == true) {
    console.log(i);
  }
}