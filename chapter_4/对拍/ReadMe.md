流程
- 按顺序编译 data.c, self.c, others.c, test.c,将 exe 文件放入 bin 中.
- 启动 test.exe 后发生了什么:
  - 使 data.exe 的输出定向到 data.in 中.
  - 使 others.exe 读入 data.in,结果写入 others.out.
  - 使 self.exe 读入 data.in,结果写入 self.out.
  - 比较 others.out 和 self.out,
    - 如果出现差异，那么打开现在的 data.in, others.out, self.out 就可以查看差别.



Tips

- data.c 中:
  第一行分别是 $coinsSize$ 和 $amount$, 第二行是$ coins$ 数组.

$$
1 \le coinsSize <= 12 \\
0 \le amount \le 10^4 \\
1 \le coins[i] <= 2^{31} - 1 = 2147483647
$$

- test.c 中:
  fc: 比较两个文件或两个文件集并显示它们之间的不同.
- origin 里面放的是原始文件(没有改动输入输出的文件).

后记

- 之前写了一个 runtime error 的方法(self.c),想要验证一下其正确性,就拿它来对拍.

- 其实这个对拍不需要写成这样,可以把两个函数直接拿来对拍,只是是想要复习一下对拍的方法,挺有趣的.
