# 算法学习笔记

[TOC]

## STL标准库

### 1、容器

#### 1）vector
> 连续的顺序的存储结构（和数组一样，但是长度可变）

##### >>>基本操作

- 构造：vector<类型> 名字(长度，[初值] )

```cpp
//一维数组
vector<int> arr (100,1);
//二维数组
vector<vector<int>> arr2(100,vector<int>(50,-1))//构建100行，50列，初值为-1的二维数组
```

- 尾接：.push_back_(元素)：把元素加在数组的最后
- 尾删：.pop_back_()：删除vector最后一个元素
- 获取长度：.size( ) 例如：i < arr.size()
- 清空： .clear（）
- 判空：.empty（）：如果vector为空，返回true，否则返回false
- 改变长度：.resize（新长度，[默认值])

##### >>> 适用情况

​	1、不卡常的情况下，数组都可以用vector；

​	2、数据太大，用数组会爆栈，这时候只能用vector

#### 2）栈stack

> 一个被堵住的胡同：先进后出，后进先出

##### >>> 基本操作

- 构造：stack<类型> 名字
- 进栈：.push（元素）
- 出栈：.pop（）
- 取栈顶：.top（）

##### >>>适用情形

不卡常时，可以代替栈；此外vector也可以当栈，.back（）相当于取栈顶，.push_back()相当于进栈，.pop_back()相当于出栈。

**注意：stack不能访问内部元素；stk[i]是错误的**

#### 3）队列queue

> 一个单向道，先进先出，后进后出

##### >>> 基本操作

- 构造：queue<类型>名字
- 进队：.push（元素）
- 出队：.pop（）
- 取队首：.front（）
- 取队尾：.back（）

##### >>>适用情形

同样是不卡常，就可以代替队列；同时和栈一样，不能访问内部元素

#### 4）优先队列priority_queue

> 底层原理就是二叉堆

##### >>>适用情形

- 每次向队列插入大小不定的元素，或者每次从队列里取出大小最小/最大的元素；（元素每次进来都会进行一次快速排序）
- **注意：只能访问栈顶，其他的元素是无法读取到的**

##### >>>基本操作

- 构造大顶堆：`priority_queue<int> pque1` 
- 构造小顶堆：`priority_quque<int,vector<int>,greater<int>> pque2` 
- 进栈：.push（元素）
- 出栈：.pop（）
- 去栈顶（如果是大顶栈就是取最大值，小顶栈就是去最小值）：.top()

#### 5）集合set

> 底层原理是红黑树，创建一个集合

##### >>> 基本操作

- 构造：set<类型，比较器> 名字;

```cpp
//默认情况（不写比较器）从小到大排序
set<int> st1;
//要从大到小的话，添加greater比较器
set<int,great<int>> st2;
```

- 遍历（基于范围的循环）//只有c++ 11才能使用

```cpp
for(auto &ele : st)//如果知道了数据类型是int的话，也可以把auto改成int
    cout << ele << endl;
```

- 插入元素：.insert（元素）
- 删除元素：.erase（元素）
- 查找元素：.find（元素）
- 判断元素是否存在：.count（元素）

##### >>>使用情形

- 数组需要去重的时候（因为集合具有互异性）
- 维护顺序时：$[1,5,3,7,9]\to[1,3,5,7,9]$
- 数组太大，普通数组会溢出，可用set
- **注意：set不存在下标索引**

#### 6）映射 map

> 提供一个映射关系

```cpp
//这种整型映射到整型的，就像数组一样，例如：
int arr[];
arr[0] = 2;
arr[1] = 2;
arr[2] = 1;
arr[3] = 5;
...
//map则是提供了各种类型到各种类型的映射
//用map的话可以这样来写
map<string,int> a;
a["sad"] = 1;
a["dwas"] = 2;
```

##### >>>基本操作

- 构造：map<键类型，值类型，比较器>mp

```cpp
map<int,,int> mp1;//从int映射到int（键从小到大）
map<int,int,greater<int>>st2;//从int映射到int（键从大到小）
```

- 遍历（基于范围）：

```cpp
for(auto &pr : st)
	cout<<pr.first<<" "<<pr.second<<endl;//first和second分别表示键值和值
```

- 增改查：mp[1] = 2;（前提是mp是一个<int,int>的映射）
- 查元素：.find（元素）>>>返回的是迭代器
- 删除：.erase（元素）
- 判断元素是否存在：.count（元素）

#### 7）字符串string

> 用来储存字符串的

##### >>>基本操作

- 构造：srting（长度，初值）

```cpp
string s1;//构造字符串，为空
string s2 = 'win' ;//构造字符串，并赋值win
srting s3(10,'6');//构造字符串，通过构造函数构造为6666666666
```

- 输入输出：

```cpp
string s；
cin >> s;
cout<< s << endl;
```

- 修改、查询指定下标字符：s[下标]
- 是否相同：if(s[1]==s[2])
- 字符串连接：s=s1+s2
- 尾接字符：s+='win'；
- 取字串：.substr（起始下标，子串长度）
- 查找字符串：.find（字符串，起始下标）

##### >>>注意事项：尾接的时候，一定要用+=，不要a=a+‘s’；这样时间复杂度会很高

#### 8）二元组pair

##### >>>基本操作

- 构造：pair<第一个值类型，第二个值类型>pr;

- 赋值：

  ```cpp
  pair<int,char> pr = {80,'points'};//只有c++11才可以用列表构造
  ```

- 取值：取第一个值：.first ；取第二个值：.second

```cpp
pair<int,char> pr = {80,'points'};
int num = pr.first;//num=80
char grade = pr.second;//grade='points'
```

- 判同：if（pr1 == pr2)......

**Tips：如果是三元组的话，可以曲线救国：**

```cpp
pair<pari<int,int>,int> pr3 = <1,2,3>;
```

### 2、算法

#### 1）swap（）

> 交换两个变量的值

```cpp
int a=0,b=1;
swap(a,b);
```

#### 2）sort()

> 使用快速排序给一个可迭代对象排序

```cpp
vector<int> arr{1,5,6,2,4,3,7,9,8};
sort(arr.begin(),arr.end());//第一个参数是数组首元素，第二个参数是数组末元素，第三个是排序规则，默认从小到大排
sort(arr.begin(),arr.end(),great<int>())；//从大到小排序
```

### 3）lower_bound()与upper_bound（）二分查找

> 在**已升序排序**的元素中，应用二分查找检索指定元素，返回对应元素迭代器位置。**找不到则返回尾迭代器。**

- `lower_bound()`:寻找 $\geq x$ 的第一个元素的位置
- `upper_bound()`: 寻找 $>x$ 的第一个元素的位置

**怎么找 $\leq x$ / $< x$ 的第一个元素呢？**

- $>x$ 的第一个元素的前一个元素（如果有）便是 $\leq x$ 的第一个元素
- $\geq x$ 的第一个元素的前一个元素（如果有）便是 $<x$ 的第一个元素


## 基础算法

### 1、模拟算法

### 2、枚举算法

### 3、二分法

- 分类：二分可以分为二分查找和二分答案

- 模板：

  ```cpp
  	//模板一：尽量往左找目标
  	while (l < r)
      {
          int mid = l + r >> 1;	//(l+r)/2
          if (check(mid))  r = mid;    // check()判断mid是否满足性质
          else l = mid + 1;
      }
  	//模板二：尽量往右找目标
  	while (l < r)
      {
          int mid = l + r + 1 >> 1;	//(l+r+1)/2
          if (check(mid))  l = mid;
          else r = mid - 1;
      }
  ```
  
  Tips：**只要是往左找答案，就用第一个模板，mid不用加一，r = mid，l加一；只要是往右找答案，就用第二个模板，mid要加一，l=mid，r要减一；**

#### 1）二分查找

> 二分查找也称折半查找，从中间开始找，每次查找去掉不符合条件的一半区间。

![img](https://i-blog.csdnimg.cn/blog_migrate/90c2c658d24e4b85f3106255629fda35.png)

**分析：首先区间是有`单调性`的，查找第一次出现的位置，如果查到一个值比目标值大，就把右半边放弃，因为右半边肯定也比目标值大；同样，如果查到值比目标值小，那就放弃左半边。**

代码实现：

```cpp
#include<iostream>
using namespace std;

const int N=1000010;
int a[N],x,q,n;

int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	while(q--)
	{
		cin>>x;
		int l=1,r=n; //左右边界 
		while(l<r) //因为是找第一次出现的位置，那就是尽量往左来，就用模板1 
		{
			int mid=l+r>>1;
			if(a[mid]>=x) r=mid; //判断条件，如果值大于等于目标值，说明在目标值右边，尽量往左来
			else l=mid+1;
		}
		if(a[l]!=x){ //如果找不到这个值 
			cout<<-1<<" ";
			continue;
		}
		cout<<l<<" ";
	}
	return 0;
} 

```

例题2：
![img](https://i-blog.csdnimg.cn/blog_migrate/cb35db757bf7bc434b819c9bb49e862c.png)

**分析：给出了C，我们要找出A和B。我们可以遍历数组，即让每一个值先变成B，然后二分找对应的A首次出现位置，看是否能找到。如果找到A，那就二分找最后出现的位置，继而，求出A的个数，即数对的个数。**

```cpp
#include<bits/stdc++.h>
using namespace std;

const int N=200010;
long long a[N],n,c,cnt,st;

int main(){
	cin>>n>>c;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);	//题目没说有序就要先排序 
	
	for(int i=1;i<n;i++)	//遍历每一个B 
	{
		int l=i+1,r=n;	//寻找A第一次出现的位置，使得A-B=C 
		while(l<r) //因为是第一次出现，尽量往左，模板1
		{
			int mid=l+r>>1;
			if(a[mid]-a[i]>=c) r=mid;	//判断：在目标值的右边，满足，往左来
			else l=mid+1;
		}
		if(a[l]-a[i]==c) st=l; //能找到C就继续 
		else continue;
		
		l=st-1,r=n;	//查找A最后出现的位置 
		while(l<r) //因为是最后一次出现，尽量往右，模板2
		{
			int mid=l+r+1>>1;
			if(a[mid]<=a[st]) l=mid; //判断：在目标值的左边，满足，往右去
			else r=mid-1;
		}
		cnt+=l-st+1;	//最后出现的位置减首次出现的位置就是区间长度，即A的个数 
	}
	cout<<cnt;
	return 0;
} 

```



**总结：如果题目明确说了 要求最小值（最前面的值）还是求最大值（最后面的值），就能判断是用模板1（求最小），还是用模板2（求最大）。之后再根据模板1，或模板2，写出对应的判断条件；**

### 4、前缀和算法

> 前缀和是常见的基础算法之一，一般应用于**快速求出某个连续区间的和/积**。前缀和一般包括一维前缀和、二维前缀和。**时间复杂度是O(1)**

[【模板】前缀和](https://www.nowcoder.com/questionTerminal/acead2f4c28c401889915da98ecdc6bf)

### 5、差分算法

## 排序算法

> 排序算法的重要指标：时间复杂度和空间复杂度越小越好
>
> 排序的稳定性：稳定排序不会改变相同元素的相对位置
>
> 是否原地排序：需不需要引入一个新的数据（给一个额外的空间来排序）

###### 



### 1、冒泡排序



### 2、选择排序

> 选择排序是最简单朴素的排序算法，但是时间复杂度较高，且不是稳定排序。其他基础排序算法都是基于选择排序的优化。

```cpp
void sort(vector<int>& nums) {
    int n = nums.size();
    // sortedIndex 是一个分割线
    // 索引 < sortedIndex 的元素都是已排序的
    // 索引 >= sortedIndex 的元素都是未排序的
    // 初始化为 0，表示整个数组都是未排序的
    int sortedIndex = 0;
    while (sortedIndex < n) {
        // 找到未排序部分 [sortedIndex, n) 中的最小值
        int minIndex = sortedIndex;
        for (int i = sortedIndex + 1; i < n; i++) {
            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }
        }
        // 交换最小值和 sortedIndex 处的元素
        int tmp = nums[sortedIndex];
        nums[sortedIndex] = nums[minIndex];
        nums[minIndex] = tmp;

        // sortedIndex 后移一位
        sortedIndex++;
    }
}
```





### 3、归并排序



### 4、快速排序



### 5、桶排序

## 搜索算法

### 1）深度优先搜索算法DFS

> 从一个顶点出发，访问下一个顶点，直到碰见死胡同就返回

Tips：在竞赛中，最好按照0—>9的顺序去访问，这样会避免漏掉顶点；

模板如下：

```cpp
vector<int> a; // 记录每次排列 
vector<int> book; //标记是否被访问 

void DFS(int cur, int k, vector<int>& nums){
    if(cur == k){ //k个数已经选完，可以进行输出等相关操作 
        for(int i = 0; i < cur; i++){
			printf("%d ", a[i]);
		} 
        return ;
    }
    for(int i = 0; i < k; i++){ //遍历 n个数，并从中选择k个数 
        if(book[nums[i]] == 0){ //若没有被访问
            a.push_back(nums[i]); //选定本输，并加入数组 
            book[nums[i]] = 1; //标记已被访问 
            DFS(cur + 1, n, nums); //递归，cur+1 
            book[nums[i]] = 0; //释放，标记为没被访问，方便下次引用 
            a.pop_back(); //弹出刚刚标记为未访问的数
        }
    }
}
```

