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
> ## 1. 顺序存储
> ### 顺序表
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

> ## 2. 链接存储
> ### 单链表

> > - **定义**
> > > 
    typedef struct node
    {
      DataType data; //数据域
      struct node * next; //指针域
    }Node, *LinkList;

> > - **运算**
> > > - *初始化(建立一个由头指针和头节点组成的空表)*
> > > 
        LinkList InitiateLinkList()
	    {
	      LinkList head; //头指针
	      head = malloc(sizeof(Node)); //动态构建一结点，它是头节点
	      head->next = NULL;
	      return head;
	    }

> > > - *求表长*
> > > 
        int LengthLinklist(LinkList head)
	    {
	      Node * p = head;  //使指针p指向头节点
	      int count = 0;  //计数器
	      while(p->next!=NULL)  //指针移动到下一节点
	      {
		    p = p->next;
		    count++;
	      }
	      return count; //返回表长
	    }

> > > - *读表元素（给定一个序号i,查找线性表的第i个元素）*
> > > 
	    Node * GetLinklist(LinkList head, int i)
	    {
	      Node *p; //工作指针p
	      p = head->next; //使p指向首节点
	      int c = 1;
	      while((c<i) && (p!=NULL)) //当未到i节点且未到尾节点时继续后移
	      {
		    p = p->next;
		    c++;
	      }
	      if(i==c) return p;  //找到第i个节点，返回指向该节点的指针
	      else return NULL;  //i<1 或 i>n,i值不合法，查找失败
	    }

> > > - *定位（给定表元素的值,找出元素的位置）*
> > > 
	    int LocateLinklist(LinkList head, DataType x)
	    //求表head中第一个值等于x的节点的序号，若不存在该节点，返回0
	    {
	      Node *p = head; //工作指针p
	      p = p->next; //移动指针p,初始时指向首节点
	      int i = 0;  //节点序号i,初值为0
	      while(p != NULL && p->data != x) //访问链表
	      {
		    i++;
		    p = p->next;
	      }
	      if(p != NULL) return i+1;
	      else return 0;
	    }

> > > - *插入(将给定值为x的元素插入到链表head的第i个节点之前)*
> 
> > > 解释: 
> 
> > > - p表示ai-1, s表示新节点，
> > > - s->next = p->next; //将原来指向ai的指针赋给s的s->next
> > > - p->next = s; //把指向s的指针赋值给ai-1的p->next 
> > > 
	    void InsertLinklist(LinkList head, DataType x, int i)
	    {
	      //在表head的第i个数据元素节点之前插入一个以x为值的新节点
	      Node *p, *q;
	      if(i==1) q=head;
	      else q = GetLinklist(head,i-1); //找到第i-1个元素，并使q指向该节点
	      if(q == NULLL)  //第i-1个节点不存在
	      exit("找不到插入的位置");
	      else
	      {
		      p = malloc(sizeof(Node)); p->data=x; //生成新节点
		      p->next = q->next;  //新结点链域指向*q的后继节点
		      q->next = p; //修改*q的链域名
	      }
	    }

> > > - *删除(给定一个值i,将链表中第i个节点从链表中移出，并修改相关节点指针域)*
> 
> > > 解释: 
> 
> > > - p表示ai-1, q表示ai，
> > > - p->next = q->next; //将ai指向下一个节点的指针赋给ai-1指向下一个节点的指针
> > > - free(q);
> > > 
	    void DeleteLinklist(LinkList head, int i)
	    {
	      //删除表head的第i个节点
	      Node *q;
	      if(i==1) q=head;
	      else q = GetLinklist(head,i-1); //找到待删节点直接前驱
	      if(q !== NULLL && q->next!=NULL)  //若直接前驱存在且待删节点存在
	      {
		      p = q->next; //p指向待删节点
		      q->next = p->next;  //移出待删节点
		      free(p); //释放已移出节点p的空间
	      }
          else exit("找不到药删除的节点"); //节点不存在
	    }

> ## 3. 其它运算在单链表上的实现
> ### 建表

> > - **方法1**
> > > 
    LinkList CreatLinklist1()
    //通过调用InitiateLinklist和Insertlinklist实现建表算法，假定0为输入结束标志
    {
      Linklist head;
      int x, i;
      head = InitiateLinklist(); //建立空表
      i = 1; //置插入位置初值
      scanf("%d",&x); //读入第一个数据元素，x为整型
      while(x!=0) //输入的不是结束标志时继续插入
      {
        InsertLinklist(head, x, i); //将输入插入到head表尾
        i++; //修改插入位置
        scanf("%d",&x); //读下一个元素
      }
      return head;
    }

> ## 4. 其它链表
> ### 单向循环链表与双向循环链表

> > - **双向循环链表的删除与插入**
> > - 双向循环列表
> > > - 对称性: p = p->prior->next = p->next->prior
> 
    struc dbnode
    {
      DataType data;
      struct dbnode *prior, *next; //prior指向前驱节点,next指向后继节点
    }
    typedef struct dbnode *dbpointer;
    typedef dbpointer DLinkList;
> > > - 双向循环链表的删除与插入
> 
> > > > - 删除
> 
> > > - (1) p->prior->next = p->next; //p前驱结点的后链指向p的后继结点
> > > - (2) p->next->prior = p->prior; //p后继结点的前链指向p的前驱结点
> > > - (3) free(p); //释放*p的空间
> 
> > > > - 插入 (在p所指结点后面插入一个新结点*t,需要修改四个指针)
> 
> > > - (1) t->prior = p;
> > > - (2) t->next = p->next;
> > > - (3) p->next->prior = t;
> > > - (4) p->next = t;

# 三. 栈、队列和数组
## 1. 栈
1.1 栈的基本概念
> - 1.1.1 栈的基本运算
> > - (1) 初始化 InitStack(S): 构造一个空栈S;
> > - (2) 判栈空 EmptyStack(S): 若栈S为空栈，则结果为1，否则结果为0；
> > - (3) 进栈 Push(S,x): 将元素x插入栈S中，使x成为栈S的栈顶元素;
> > - (4) 出栈 Pop(S): 删除栈顶元素;
> > - (5) 取栈顶 GetTop(S): 返回栈顶元素;

1.2 栈的顺序实现
> - 顺序栈

    const int maxsize=6; //顺序栈的容量
    typedef struct seqstack
    {
      DataType data[maxsize]; //存储栈中数据元素的数组
      int top; //标志栈顶位置的变量
    }SeqStk;

> - 1.2.1 初始化

	int InitStack(SeqStk *stk)
	{
	  stk->top = 0;
	  return 1;
	}

> - 1.2.2 判栈空

	int EmptyStack(SeqStk *stk)
	//若栈为空，返回1，否则返回0
	{
	  if(stk->top==0)
	    return 1;
	  else return 0;
	}

> - 1.2.3 进栈

	int Push(SeqStk *stk, DataType x)
	{
	  //若栈未满，元素x进栈stk中，否则提示出错信息
	  if(stk->top == maxsize-1) //判断栈是否满
	  {
	    error("栈已满");
	    return 0;
	  }
	  else
	  {
	    stk->top++; //栈未满, top值加1
	    stk->data[stk->top] = x; //元素x进栈
	    return 1;
	  }

> - 1.2.4 出栈

	int Pop(SeqStk *stk)
	{
	  if (EmptyStack(stk)) //判断是否下溢(栈空)
	  {
	    error("下溢");
	    return 0;
	  }
	  else //未下溢，栈顶元素出栈
	  {
	    stk->top--; //top值减1
	    return 1;
	  }
	}

> - 1.2.5 取栈顶元素

	DataType GetTop(SeqStk *stk)
	//取栈顶数据元素，栈顶数据元素通过参数返回
	{
	  if (EmptyStack(stk)) return NULLData; //栈空,返回NULLData
	  else
	    return stk->data[stk->top]; //返回栈顶数据元素
	}



1.3 

## 2. 队列

## 3. 数组

# 四. 树和二叉树

# 5. 图

# 6. 查找

# 7. 排序
