# 第二章-作业

## 1

用 $O$、$\Omega$、$\theta$ 表示函数 $f$ 与 $g$ 之间阶的关系，并分别指出下列函数中阶最低和最高的函数：（该题考察阶的关系，20分）

1. $ f(n)=100$，$g(n)=\sqrt[100]{n}$
   $f(n)=O(g(n))$

2. $f(n)=6n + n\lfloor\, \log n \,\rfloor$，$g(n)=3n$
   $g(n)=O(f(n))$

3. $f(n)=\frac n {\log n} - 1$，$g(n)=2\sqrt{n}$
   $f(n)=O(g(n))$

4. $f(n)=2^n+n^2$，$ g(n)=3^n$
   $f(n)=O(g(n))$

5. $f(n)=\log_3 n$，$ g(n)=\log_2 n$
   $f(n)=θ(g(n))$

- 阶最低的函数: $f(n)=100$
- 阶最高的函数: $g(n)=3^n$

## 2

证明：$\sum_{k=1}^{\infty} \frac 1 {k^2}$ 有常数上界。（该题考察和式求和，20分）

证明：

因为当 $k-1 \le x \le k$ 时，有 $\frac 1 {k^2} \le \frac 1 {x^2}$，所以

$$
\frac 1 {k^2} = \int_{k-1}^{k} \frac 1 {k^2} \, dx \le \int_{k-1}^{k} \frac 1 {x^2} \, dx \, (k=2,3 \cdots)
$$

从而级数的部分和为

$$
S_n = 1 + \sum_{k=2}^n \frac 1 {k^2} \le 1 + \sum_{k=2}^n \int_{k-1}^{k} \frac 1 {x^2} \, dx = 1 + \int_1^n \frac 1 {x^2} \, dx \\
  = 1 + \frac 1 {2-1}(1-\frac 1 {n^{2-1}}) < 1 + \frac 1 {2-1} = 2 \, (n=2,3 \cdots)
$$

表明数列 $\{S_n\}$ 有界，即 $\sum_{k=1}^{\infty} \frac 1 {k^2}$ 有常数上界。

## 3

给出下列各式中 $T(n)$ 的渐近上下界，假设当 $n \le 10$ 时， $T(n)$ 为常数，尽可能保证给出的界限是紧的，并验证给出的答案。（该题考察递归方程解法，20分)

### 3.1

$T(n) = 3T(n/5)+(lgn)^2$

$$
a=3,b=5,f(n)=(lgn)^2,n^{\log_b a}=n^{\log_5 3}=O(n^{0.683}) \\
  f(n)=(lgn)^2=O(n^{\log_53-0.28}) \\
  \therefore T(n)= \Theta(n^{\log_53}).
$$

### 3.2

$T(n) = T(\sqrt{n}) + \Theta(\lg \lg n)$

设 $m=\lg n$，则 $n=2^m，T(2^m)=T(2^{m/2})+\Theta(lg m)$.

令 $S(m)=T(2^m)$，则 $S(m)=S(\frac m 2)+\Theta(\lg m)$.

尝试使用 $master$ 定理，则

$$
a=1,b=2,f(m)=\Theta(\lg m),m^{\log_b a}=m^{\log_2 1}=1
$$

$f(m)$ 不是多项式的大于 $n^{\log_b a}$，不能用 $master$ 定理.

设 $q=\lg m$，则 $m=2^q，S(2^q)=S(2^q/2)+\Theta(q)$.

令 $P(q)=S(2^q)$，则 $P(q)=P(q-1)+\Theta(q)$.

故 $\Theta(q) = P(q) - P(q-1)$，由定义有：存在 $c_1,c_2>0,n_0>0$，使得当 $n>n_0$ 时，下式成立：

$$
  c_1q\leqslant P(q)-P(q-1)\leqslant c_2q
$$

$q$ 从 $1$ 取到 $q$，并累加得：

$$
\frac{c_1}2q^2\leqslant c_1\sum_{k=1}^qk\leqslant P(q)-P(0)\leqslant c_2\sum_{k=1}^qk\leqslant c_2q^2
$$

可知 $P(q) = \Theta(q^2)$，而 $n = 2^{2^q},q=\lg \lg n$，故 $T(n) = \Theta((\lg \lg n)^2)$

### 3.3

$T(n) = 10T(n/3) + 17n^{1.2}$s

$$
a=10,b=2,f(n)=17n^{1.2},n^{\log_b a}=n^{\log_3 {10}}=O(n^{2.095}) \\
  f(n)=17n^{1.2}=O(n^{\log_3 {10}-\epsilon}) \, ,\epsilon = 0.8. \\
  \therefore T(n)= \Theta(n^{\log_3 {10}}).
$$

### 3.4

$T(n) = 7T(n/2) + n^3$

$$
a = 7,b = 2,f(n) = n^3,n^{\log_b a} = n^{\log_2 7} = O(n^{2.80}) \\
  f(n) = n^3 = \Omega(n^{\log_2 7+\epsilon}) \, ,\epsilon = 0.2.
$$

且 $af(n/b) = 7(n/2)^3 \le cn^3 = cf(n)$，只需 $c \ge 7/8$.

故存在常数 $7/8 \le c < 1$，使得 $af(n/b) \le cf(n)$ 成立.故 $T(n)= \Theta(n^3).$

### 3.5

$T(n) = T(n/2+\sqrt{n}) + \sqrt{6046}$

显然存在 $n_0>0$，使得当 $n>n_0$ 时，$T(n/2) < T(n/2+\sqrt n) < T(3n/4)$，

因 $T(n)=T(n/2)+\sqrt{6046}$ 和 $T(n)=T(3n/4)+\sqrt{6046}$ 由 master 定理都可得 $T(n)= \Theta(\log n).$

故 $T(n)= \Theta(\log n).$

## 4

运用主定理求解下面方程，假设 $T$ 为 $O(1)$ 作为基本情况：（该题考察主定理，20分）

### 4.1

$T(n) = 25T(n/5) + n^{2.1}$

$$
a=25,b=5,f(n)=n^{2.1},n^{\log_b a}=n^{\log_5 {25}}=n^2 \\
  f(n)=n^{2.1}=\Omega(n^{\log_b a+\epsilon}) \, ,\epsilon = 0.1.
$$

且 $af(n/b) = 25(n/5)^{2.1} \le cn^{2.1} = cf(n)$，只需 $c \ge 5^{-0.1}$.

故存在常数 $c =0.9 < 1$，使得 $af(n/b) \le cf(n)$ 成立.故 $T(n)= \Theta(f(n)) = \Theta(n^{2.1}).$

### 4.2

$T(n) = 25T(n/5) + n^{1.5}$

$$
a=25,b=5,f(n)=n^{1.5},n^{\log_b a}=n^2 \\
  f(n)=n^{1.5}=\Theta(n^{\log_b a-\epsilon}) \, ,\epsilon = 0.5. \\
  \therefore T(n)= \Theta(n^{\log_b a}) = \Theta(n^2).
$$

### 4.3

$T(n) = 25T(n/5) + n^2$

$$
a=25,b=5,f(n)=n^2,n^{\log_b a}=n^2 \\
  f(n)=n^2=\Theta(n^2)=\Theta(n^{\log_b a}) \\
  \therefore T(n)= \Theta(n^{\log_b a}\log n) = \Theta(n^2\log n).
$$

## 5

对递归式 $T(n) = 3T(n/4) + cn^2$，用递归法确定一个渐进上界，并画出递归树。

可能会用到的公式：$a^{\log_b c = c^{\log_b a}}$（该题考察递归树，20分)

![2.5](2.5.svg)

$$
\begin{align*}
    T(n) ={} & cn^2 + \frac 3 {16}cn^2 + (\frac 3 {16})^2cn^2 + \cdots + (\frac 3 {16})^{\log_4 n - 1}cn^2 + \Theta(n^{\log_4 3}) \\
         ={} & \sum_{i=0}^{\log_4 n - 1}(\frac 3 {16})^icn^2 + \Theta(n^{\log_4^3}) \\
         ={} & \frac {(\frac 3 {16})^{\log_4 n}-1}{\frac 3 {16} -1}cn^2 + \Theta(n^{\log_4 3})
  \end{align*}
$$

猜测 $T(n) = O(n^2)$，用代入法验证.

即证：$T(n) = O(n^2)$，即证：存在 $d>0$，$n_0>0$，使得当 $n>n_0$ 时，有 $T(n) \le dn^2$

证：假设当 m<n 时，有 $T(m) \le dm^2$ 成立.
那么当 $m=n$ 时，$T(m) = 3T(m/4) + cm^2 \le 3d(m/4)^2 + cm^2 = 3/16dm^2 + cm^2 = (c+ \frac 3 {16}d)m^2$.

要使得上式成立，只需 $d \ge 16/13c$.

故当 $d \ge 16/13c$ 时，当 $m=n$ 时，$T(m) \le dm^2$ 成立.

即证得 $T(n) = O(n^2)$.
