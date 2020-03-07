# IntersectionCounter
软工个人项目作业
$$
\left\{\begin{matrix}
 & A_{1}x + B_{1}y + C_{1}=0\\ 
 & A_{2}x + B_{2}y + C_{2}=0 
\end{matrix}\right.
$$
的解是
$$
\left\{\begin{matrix}
x = \frac{C{_{1}}B{_{2}}-C_{2}B_{1}}{B{_{1}}A{_{2}}-B_{2}A_{1}}\\ 
y = \frac{A{_{1}}C{_{2}}-A_{2}C_{1}}{B{_{1}}A{_{2}}-B_{2}A_{1}}
\end{matrix}\right.
$$


用形成交点的两条直线来表示交点，分别保存x, y的分子和分母

尽量不使用浮点数计算

使用容器类保存直线和交点

新增一条直线后，验证已知的交点是否通过该直线