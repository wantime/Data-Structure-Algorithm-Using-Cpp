# Data-Structure-Algorithm-Using-Cpp
使用c++实现经典的算法与数据结构

## A01 排序
#### 冒泡排序
#### 插入排序
#### 归并排序
应用：计算 逆序对 
1. 归并排序自底向上

#### 快速排序
应用：第k大元素，O(n)时间复杂度
1. 二路快速排序
处理近乎有序的排序
2. 三路快排
处理相同数值过多的排序

#### 堆排序
1. 索引堆

 稳定排序：插入、归并

## A02 操作数组(双指针相关)
1. 二分查找法(循环不变量)
2. floor实现
3. ceil实现
通向的指针(快慢)
4. Leetcode.238 move-zeroes
5. Leetcode.26 remove duplicated from sorted array
6. Leetcode.80 remove duplicated from sorted array 2
7. Leetcode.88 merge
8. Leetcode.215 findKthLargest: 快排
9. Leetcode.167 two sum 2-input sort array: 碰撞指针
10. Leetcode.344 Reverse string
11. Leetcode. 11 Container With Most Water
滑动窗口
12. Leetcode. 438 findAnagrams

## A3-查找表
Leetcode查找表相关问题
C++中set(map)与unordred_set(map)的底层差别

## 01 数组
不固定长度的动态数组，为防止复杂度振荡，数组收缩与扩展的数值应当有所区别
## 02 队列

先进先出

## 03 栈

先进后出，两个栈模拟队列

## 04 链表

充分利用离散的内存

使用快慢指针判断链表的环

使用prev cur next三个节点进行链表的反转操作

## 05 递归

首先确定递归的终止条件、然后编写递归的主题部分

二叉树的大部分操作可以使用递归完成（前中后序遍历、镜像等）

## 06 二分搜索树

添加元素->上浮和下沉操作
删除元素->前驱或后继节点

## 07 集合与映射
链表实现的集合
基于集合的二分搜索树
链表实现的映射
基于映射的二分搜索树
## 08 堆与优先队列
使用动态数组作为底层，实现完全二叉树形式的最大堆
heapify操作
replace操作
可以处理堆排序、前k个最值问题
## 09 线段树
