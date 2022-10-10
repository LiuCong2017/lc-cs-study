# 一. 概论
> #### 数据结构
> - 1. 数据、数据元素和数据项
> - 2. 逻辑结构
> > - 集合、线性、树形、图
> 
> - 3. 存储结构 
> > - 顺序、链式、索引、散列

> #### 算法分析
> - 正确性、易读性、健壮性、时空性
> - 时间复杂度

# 二. 线性表
> #### 顺序存储
> - 顺序表
> > - 定义
> 
    Const int MaxSize=100;
    typedef struct
    {
      DataTpe data[MaxSize];
      int length;
    }SeqList;
    SeqList L;

> - 运算
> > - 插入
> > > - 向后移动元素个数 = **n-i+1**
> > > - 时间复杂度: O(n)
> 
    void InsertSeqList(SeqList L,DataType x,int i)
    { //将元素插入到L的第i个元素前
      if(L.length==MaxSize) exit("表已满");
      if(i<1 || i>L.length+1) exit("位置错");
      for(j=L.length;j>=i;j--)
	  {
    	L.data[j]=L.data[j-1];
	  }
      L.data[i-1]=x;
      L.length++;
    }
> > - 删除
> > > - 向前移动元素个数 = **n-i**
> > > - 时间复杂度: O(n)
> 
    void DeleteSeqList(SeqList L, int i)
    {
      if(i<1 || i>L.length) exit("非法位置");
      for(j=i;j<L.length;j++)
      {
      	L.data[j-1] = L.data[j];
      }
      L.length--;
    }
> > - 定位
> > > - 平均比较次数 = **(n+1)/2**
> > > - 时间复杂度: O(n)
> 
    int LocateSeqlist(SeqList L, DataType x)
    {
      int i=0;
      while((i<L.length) && (L.data[i]!=x))
      {
    	i++;
      }
      if(i<L.length) return i+1;
      else return 0;
    }

> #### 链接存储
> - 单链表、循环链表、双向链表、双向循环链表......

# 三. 栈、队列和数组

# 四. 树和二叉树

# 5. 图

# 6. 查找

# 7. 排序