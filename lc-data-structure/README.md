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
> #### 1. 顺序存储
> - 顺序表
> > - 定义
> > 
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
> > > 
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
> > > 
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
> > > 
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

> #### 2. 链接存储
> - 单链表
> > - 定义
> > 
    typedef struct node
    {
      DataType data; //数据域
      struct node * next; //指针域
    }Node, *LinkList;
> > - 运算
> > > - 初始化(建立一个由头指针和头节点组成的空表)
> > > 
        LinkList InitiateLinkList()
	    {
	      LinkList head; //头指针
	      head = malloc(sizeof(Node)); //动态构建一结点，它是头节点
	      head->next = NULL;
	      return head;
	    }
> > > - 求表长
> > > 
        int LengthLinklist(LinkList head)
	    {
	      Node * p = head;  //使指针p指向头节点
	      int count = 0;  //计数器
	      while(p->next!=NULL)  //指针移动到下一节点
	      {
	    p=p->next;
	    count++;
	      }
	      return count; //返回表长
	    }
> > > - 读表元素（给定一个序号i,查找线性表的第i个元素）
> > > 
Node * GetLinklist(LinkList head, int i)
{
  Node *p; //p是工作指针
  p = head->next;
}


> - 其它链表

# 三. 栈、队列和数组

# 四. 树和二叉树

# 5. 图

# 6. 查找

# 7. 排序