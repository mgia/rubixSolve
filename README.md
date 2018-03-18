# 魔方大作业

## 输入描述
输入一共6行，代表当前魔方6个面的状态。
其中，6行依次表示“前面，后面，左面，右面，顶面和底面”等各面的色块状态 ，其中， “前面”为用户正对的那一面 。
每行为9个字符，第i个字符表示该面编号i位置色块的颜色（如图所示）。每个字符为R（红色），B（蓝色），Y（黄色），G（绿色），O（橙色），W（白色）之一。


## 输出描述
输出仅有一行，为操作的序列，用空格隔开。 
操作包含且仅包含PDF中介绍的六种操作（严格说为十二种） •即：R,Ri,D,Di,L,Li,B,Bi,F,Fi,U,Ui


## 样例输入
GGYGGYGGY<br>
WBBWBBWBB<br>
OOOOOOOOO<br>
RRRRRRRRR<br>
WWGWWGWWG<br>
YYBYYBYYB<br>

## 样例输出
R R R Ri R

## 测试样例
第一组

RRWGGWGGW<br>
YOOYBBYBB<br>
GGGOOOOOO<br>
BRRBRRBRR<br>
WWBWWBWWO<br>
YYRYYGYYG<br>

第二组

GGOGGOYYY<br>
BBWBBWRRW<br>
OOWOOWOOO<br>
YRRYRRRGG<br>
GWWGWWRRG<br>
BBBBYYBYY<br>

第三组

YGYYGYOOO<br>
RRRWBWWBW<br>
WBROOROOY<br>
OGYORRWRR<br>
GGGWWWBYB<br>
GGGBYBBYB<br>

第四组

ROGGGWGRG<br>
BWBRBBBYR<br>
OBWOOOGOW<br>
YBYGRGYBY<br>
WRRYWRBWR<br>
OYOYYWWGO<br>
