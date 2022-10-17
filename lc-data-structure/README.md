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
	      DataType data[MaxSize];
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
#### 1.1 栈的基本概念
> - 1.1.1 栈的基本运算
> > - (1) 初始化 InitStack(S): 构造一个空栈S;
> > - (2) 判栈空 EmptyStack(S): 若栈S为空栈，则结果为1，否则结果为0；
> > - (3) 进栈 Push(S,x): 将元素x插入栈S中，使x成为栈S的栈顶元素;
> > - (4) 出栈 Pop(S): 删除栈顶元素;
> > - (5) 取栈顶 GetTop(S): 返回栈顶元素;

#### 1.2 栈的顺序实现
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

> - 1.2.6 双栈

	const int max=40; //栈容量
	typedef struct Dbstack
	{
	  DataType data[max];
	  int top1,top2; //判断上溢为top1+1=top2, top1=0时栈1为空栈，top2=max-1时栈2为空栈
	}DbStk;

#### 1.3 栈的链接实现
> - 1. 定义

	typedef struct node
	{
	  DataType data;
	  struct node *next;
	}LkStk;

> - 2. 运算
> > - 2.1 初始化

	void InitStack(LkStk *LS)
	{
	  LS = (LkStk *)malloc(sizeof(LkStk)); //建立空栈
	  LS ->next = NULL; //将该结点的next域设置为NULL
	}

>> - 2.2 判栈空

	int EmptyStack(LkStk *LS)
	//若栈为空则返回值1，否则返回值0
	{
	  if(LS->next == NULL)
	    return 1;
	  else
	    return 0;
	}

>> - 2.3 进栈

	void Push(LkStk *LS, DataType x)
	{
	  LkStk *temp;
	  temp=(LkStk *)malloc(sizeof(LkStk)); //temp指向申请的新结点
	  temp->data = x; //新结点的data域赋值为x
	  temp->next = LS->next; //temp的next域指向原来的栈顶结点
	  LS->next = temp; //指向新的栈顶结点
	}

>> - 2.4 出栈

	int Pop(LkStk *LS)
	//栈顶数据元素通过参数返回，它的直接后继成为新的栈顶
	{
	  LkStk *temp;
	  if(!EmptyStack(LS)) //判断栈是否为空
	  {
	    temp = LS->next; //temp指向栈顶结点
	    LS->next = temp->next; //原栈顶的下一个结点成为新的栈顶
	    free(temp); //释放原栈顶结点空间
	    return 1;
	  }
	  else return 0;
	}

>> - 2.5 取栈顶元素

    DataType GetTop(LkStk *LS)
    {
      if(!EmptyStack(LS)) 
        return LS->next->data; //若栈非空，返回栈顶数据元素
      else return NULLData; //否则返回空元素
    }

>> - 2.6 栈的简单应用和递归
>>> - 2.6.1 应用举例

    //1. 将A~K反序输出
    const int maxsize=50;
    typedef struct seqstack
    {
      char data[maxsize];
      int top;
    }SeqStk;
    main()
    {
      SeqStk stk;
      int i;
      char ch;
    
      InitStack(&stk);
      for(ch='A';ch<='A'+10;ch++)
      {
        Push(&stk,ch); //将A~K进栈stk
        printf("%c",ch);
      }
      printf("\n);
      while(!EmptyStack(&stk))
      {
        ch=GetTop(&stk);
        Pop(&stk); //将K~A依次出栈
        printf("%c",ch);
      }
      printf("\n");
    }

    //2. 将带头结点的单链表逆置
    void ReverseLis(LkStk *head)
    {
      LkStk *S;
      DataType x;
      InitStack(S); //初始化链栈
      p = head
    }

## 2. 队列
#### 2.1 顺序队列
> - 2.1.1 定义

    const int maxsize = 20;
    typedef struct seqqueue
    {
      DataType data[maxsize]; //data域(一维数组), 存储队列数据元素
      //font和rear为整形变量，取值范围0~(maxsize-1)
      int front, rear; //front指向队列首元素的前一个单元，rear指向队列尾元素
    }SeqQue;
    SeqQue SQ;

>> - (1) 入队操作: 
>>> - SQ.rear = SQ.rear+1;
>>> - SQ.data[SQ.rear] = x;
>> - (2) 出队操作:
>>> - SQ.front = SQ.front+1;

#### 2.2 循环队列
> - 2.2.1 定义

    typedef struct cycqueue
    {
      DataType data[maxsize];
      int front,rear;
    }CycQue;
    CycQue CQ;

>> - (1) 入队操作:
>>> - SQ.rear = (SQ.rear+1) % maxsize;
>>> - SQ.data[SQ.rear] = x;
>> - (2) 出队操作:
>>> - SQ.front = (SQ.front+1) % maxsize;
>> - (3) 队列满条件:
>>> - (CQ.rear+1) % maxsize == CQ.front
>> - (4) 队列空条件:
>>> - CQ.rear == CQ.front

> - 2.2.2 基本运算
>> - (1) 队列的初始化

    void InitQueue(CycQue CQ)
    {
      CQ.front = 0;
      CQ.rear = 0;
    }

>> - (2) 判队列空

    int EmptyQueue(CycQue CQ)
    {
      if(CQ.rear == CQ.front) return 1; //队列为空，返回1
      else return 0; //队列不为空，返回0
    }

>> - (3) 入队列

    int EnQueue(CyQue CQ, DataType x)
    {
      if((CQ.rear+1)%maxsize == CQ.front)
      {
        error("队列满"); return 0; //队列满，入队列失败
      }
      else
      {
        CQ.rear = (CQ.rear+1) % maxsize;
        CQ.data[CQ.rear] = x;
        return 1; //入队列成功
      }
    }

>> - (4) 出队列

    int OutQueue(CycQue CQ)
    {
      if(EmptyQueue(CQ)) //判断队列是否为空
      {
        error("队列空"); return 0;
      }
      else
      {
        CQ.front = (CQ.front+1) % maxsize;  //不为空，出队列
        return 1;
      }
    }

>> - (5) 取队列首元素

    DataType GetHead(CyQue CQ)
    {
      if(EmptyQueue(CQ))
      {
        return NULLData; //队列为空，返回空数据标志
      }
      else
      {
        return CQ.data[(CQ.front+1)%maxsize];
      }
    }

#### 2.3 队列的链接实现
> - 链接队列
>> - 定义

    typedef struct LinkQueueNode
    {
      DataType data;
      struct LinkQueueNode *next;
    }LkQueNode;
    typedef struct LkQueue
    {
      LkQueNode *front, *rear;
    }LkQue LQ;

>> - 基本运算
>>> - 初始化

    void InitQueue(LkQue *LQ)
    {
      LkQueNode *temp;
      temp = (LkQueNode *)malloc(sizeof(LkQueNode)); //生成队列的头节点
      LQ->front = temp; //队列头指针指向队列头节点
      LQ->rear = temp; //队列尾指针指向队列尾节点
      (LQ->front)->next = NULL;
    }

>>> - 判队列空

    int EmptyQueue(LkQue LQ)
    {
      if(LQ.rear==LQ.front)
        return 1;
      else
        return 0;
    }

>>> - 入队列

    void EnQueue(LkQue *LQ, DataType x)
    {
      LkQueNode *temp;
      temp = (LkQueNode *)malloc(sizeof(LkQueNode));
      temp->data = x;
      temp->next = NULL;
      (LQ->rear)->next = temp; //新结点入队列
      LQ->rear = temp; //置新的队列尾结点
    }

>>> - 出队列

    OutQueue(LkQue *LQ)
    {
      LkQueNode *temp;
      if(EmptyQueue(CQ)) //判队列是否为空
      {
        error("队空");
        return 0; //队列为空
      } 
      else //队列非空
      {
        temp = (LQ->front)->next; //使temp指向队列的首节点
        (LQ->front)->next = temp->next; //修改头节点的指针域指向新的首节点
        if(temp->next == NULL) LQ->rear = LQ->front; //无首节点时，front和rear都指向头节点
        free(temp);
        return 1;
      }
    }

>>> - 取队列首元素

    DataType GetHead(LkQue LQ)
    {
      LkQueNode *temp;
      if(EmptyQueue(CQ))
        return NULLData; //队列为空，返回空数据标志
      else
        temp = LQ.front->next;
        return temp->data; //队列非空，返回队列首节点元素
    }

## 3. 数组
#### 3.1 数组的逻辑结构和基本运算
#### 3.2 数组的存储结构
#### 3.3 矩阵的压缩存储
> - 3.3.1 特殊矩阵
>> - (1) 对称矩阵
>> - (2) 三角矩阵

> - 3.3.2 稀疏矩阵
>> - 三元组: (i,j,v) i-行 j-列 v-非零元素
>>> - 三元组的类型说明

    const int maxnum=10
    typedef struct node
    {
      int i,j; //非零元所在行号、列号
      DataType v; //非零元的值
    }NODE;
    typedef struct SpMatrix
    {
      int mu,nu,tu; //行数、列数、非零元素的个数
      NODE data[maxnum]; //这里假定三元组的下标的起始值为0
    }SpMtx;




# 四. 树和二叉树

# 5. 图

# 6. 查找

# 7. 排序
