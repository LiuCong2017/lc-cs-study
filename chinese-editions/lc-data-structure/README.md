# 一. 概论
> #### 数据结构
> 1. 数据、数据元素和数据项
> 2. 逻辑结构
> > - 集合、线性、树形、图
> 
> 3. 存储结构 
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
      p = head->next;
      while(p!=NULL) //扫描链表
      {
        Push(S,p->data); //元素进栈
        p = p->next;
      }
      p = head->next;
      while(!EmptyStack(S)) //栈不为空时
      {
        p->data = GetTop(S); //元素填入单链表中
        Pop(S); //出栈
        p = p->next;
      }
    }

>> - 2.6.2 递归与栈

    //计算阶乘函数的递归算法描述
    long f(int n) //f表示求n!的函数
    {
      if(n==0) return 1; //递归的结束条件0!=1
      else return n*f(n-1); //递归步骤 - n*(n-1)! 
    }
    
    //完整程序
    #include <stdio.h>
    long f(int n)
    {
      if(n==0) return 1;
      else return n*f(n-1);
    }
    
    main()
    {
      int m, n=3; //设n=3,求3!
      m = f(n);
      printf("%d=%d\n",n,m);
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
### 1. 树的基本概念
>> - 1.1 相关术语
>>> - 结点的度
>>> - 叶子
>>> - 树的度
>>> - 子结点/父结点/兄弟/子孙/祖先
>>> - 结点的层次
>>> - 树的高度(深度)
>>> - 有序树
>>> - 无序树
>> - 1.2 基本运算
>>> - 求根 Root(T)
>>> - 求双亲 Parent(T,X)
>>> - 求孩子 Child(T,X,i)
>>> - 建树 Create(X,Ti,...,Tk),k>1
>>> - 剪枝 Delete(T,X,i)
>>> - 遍历 TraverseTree(T)

### 2. 二叉树
#### 2.1 二叉树的基本概念
>> - 2.1.1 基本运算
>>> - 初始化 Initiate(BT)
>>> - 求双亲 Parent(BT,X)
>>> - 求左孩子 Lchild(BT,X) / 求右孩子 Rchild(BT,X)
>>> - 建二叉树 Create(BT)
>>> - 先序遍历 PreOrder(BT)
>>> - 中序遍历 InOrder(BT)
>>> - 后序遍历 PostOrder(BT)
>>> - 层次遍历 LevelOrder(BT)

>> - 2.1.2 满二叉树 / 完全二叉树

>> - 2.1.3 性质
>>> - (1) 二叉树第i(i>=1)层上至多有2^(i-1)个结点
>>> - (2) 深度为k(k>=1)的二叉树至多有2^k-1个结点
>>> - (3) 对任何一颗二叉树，若度数为0的结点(叶结点)个数为n0,度数为2的结点个数为n2,则 n0=n2+1
>>> - (4) 含有n个结点的完全二叉树的深度为[log2^n]+1 ([] -> 向下取整)
>>> - (5) 在完全二叉树中，设n为结点总数，i为任一编号(1<=i<=n)，对于编号为i的结点A：

    - 若i=1,A为根; i>1, A的双亲编号为i/2（商是几就是几,不做四舍五入）
    - 若i*2>n, A无左右孩子；i*2<n, A的左孩子编号为2i, 
    - 若i*2+1>n, A无右孩子；i*2+1<n, A的右孩子编号为2i+1

### 3. 二叉树的存储结构
#### 3.1 二叉树的顺序存储结构
#### 3.2 二叉树的链式存储结构
> - 二叉链表

    typedef struct btnode
    {
      DataType data; //数据域
      struct btnode *lchild, *rchild; //指向左右孩子的指针
    }*BinTree;
    BinTree root; //root为指向根结点的指针，Bintree为指向二叉链表结点的指针类型,root=NULL则二叉树为空
    
> - 三叉链表

    typedef struct ttnode
    {
      DataType data;
      struct ttnode *lchild,*parent,*rchild; //指针域parent指向该结点的双亲
    }*TBinTree;
    TBinTree root; //指向根结点的根指针

### 4. 二叉树的遍历
#### 4.1 二叉树遍历的递归实现
>> - 一颗二叉树由根，根的左子树，根的右子树组成
>> - 遍历步骤:
>>> - (1) 访问根结点
>>> - (2) 遍历根的左子树
>>> - (3) 遍历根的右子树

> - 4.1.1 先序遍历(DLR) - 先访问本节点，再访问该节点的左孩子和右孩子 
>>> - (1) 访问根结点
>>> - (2) 先序遍历左子树
>>> - (3) 先序遍历右子树

    //visit(bt)是一个已定义的过程，功能是访问指针bt所指结点
    void preorder(BinTree bt)
    //先序遍历根指针为bt的二叉树
    {
      if(bt!=NULL)
      {
        visit(bt); //访问根结点bt
        preorder(bt->lchild); //先序遍历左子树
        preorder(bt->rchild); //先序遍历右子树
      }
    }

> - 4.1.2 中序遍历(LDR) - 先访问左孩子，再访问本节点，最后访问右孩子
>>> - (1) 中序遍历左子树
>>> - (2) 访问根结点
>>> - (3) 中序遍历右子树

    void inorder(BinTree bt)
    //中序遍历根指针为bt的二叉树
    {
      if(bt!=NULL)
      {
        inorder(bt->lchild); //中序遍历左子树
        visit(bt); //访问根结点bt
        inorder(bt->rchild); //中序遍历右子树
      }
    }

> - 4.1.3 后序遍历(LRD) -先访问左右孩子，最后访问本节点

    void postorder(BinTree bt)
    //后序遍历根指针为bt的二叉树
    {
      if(bt!=NULL)
      {
        postorder(bt->lchild); //后序遍历左子树
        postorder(bt->rchild); //后序遍历右子树
        visit(bt); //访问根结点bt
      }
    }

> - 4.1.4 遍历的应用
>>> - 已知先序和中序遍历，构建树 (比如: 先序ABCDEF，中序CBDAFE，求二叉树)
>>> - 已知中序和后序遍历，构建树 (比如：已知一颗二叉树的中序序列与后序序列分别为: BACDEFGH和BCAEDGHF，建立该二叉树）

>>> - 层次遍历(用队列实现)

    void levelorder(BinTree bt)
    {
      LkQue Q;
      InitQueue(&Q); //初始化队列
      if(bt != NULL)
      {
        EnQueue(&Q,bt); //根结点入队列
        while(!EmptyQueue(Q))
        {
          p=Gethead(&Q);
          outQueue(&Q); //结点出队列
          visit(p); //被访问结点
          if(p->lchild!=NULL) EnQueue(&Q,p->lchild); //左孩子结点入队列
          if(p->rchild!=NULL) EnQueue(&Q,p->rchild); //右孩子结点入队列
        }
      }
    }

>>> - 求树高度

    int Height(BinTree bt)
    {
      int lh,rt; //初始左右子树的高度为0
      if(bt==NULL) return 0;
      else
        {
          lh = Height(bt->lchild); //左子树的高度
          rh = Height(bt-rchild); //右子树的高度
          return 1+(lh>rh?lh:rh);
        }
    }

>>> - 非递归先序遍历（用栈实现）

    void PreOrder(BinTree t)
    //非递归先序遍历二叉树
    {
      BinTree p;
      LkStk *LS; //LS为指向链栈的指针
      if(t==NULL) return;
      InitStack(LS);
      p = t;
      while(p!=NULL || !EmptyStack(LS)) //循环条件是当指针或栈至少有一个不为空
      {
        if(p!=NULL)
        {
          Visit(p->data); //访问结点的数据
          Push(LS,p); //将当前指针压入栈中
          p = p->lchild; //将指针指向p的左孩子
        }
        else
        {
          p = Gettop(LS); //取栈顶元素
          Pop(LS); //出栈
          p = p->rchild; //指针指向它的右孩子
        }
      }
    }

### 5. 树和森林
#### 5.1 树的存储结构
> - 5.1.1 孩子链表表示法

    const int MAXND=20; //树中结点的最大个数
    typedef struct bnode //表结点类型
    {
      int child; //孩子结点在表头数据组中的序号
      struct bnode *next; //表结点指针域
    }node, *childlink;
    typedef struct //头结点类型
    {
      DataType data; //结点数据元素
      childlink hp; //头结点指针域
    }headnode;
    headnode link[MAXND] //表头结点数组

    //带双亲的孩子链表表示法,只需将头节点的定义改为:
    typedef struct
    {
      DataType data;
      int parent;
      childlink hp;
    }headnode;

> - 5.1.2 孩子兄弟链表表示法

    typedef struct tnode
    {
      DataType data;
      struct tnode *son, *brother; //指向孩子和兄弟指针
    }*Tree;

> - 5.1.3 双亲表示法

    const int size=10; //定义结点数
    typedef struct
    {
      DataType data; //数据域
      int parent; //双亲域
    }Node;
    Node slist[size]; //用数组实现双亲表

#### 5.2 树、森林与二叉树的关系
> - 5.2.1 树转换成二叉树 -> 左边指针指向第一个孩子，右边指针指向兄弟
> - 5.2.2 森林转换成二叉树 -> 每棵树转成一颗二叉树，各二叉树根节点看作是兄弟(右孩子)连接起来
> - 5.2.3 二叉树转成森林 -> 根结点右孩子是一颗新树,其它结点的右孩子是兄弟

> - 5.2.4 树和森林的遍历
>> - (1) 树的遍历
>>> - 先序遍历 -> 当树非空时，访问根结点，依次先序遍历根的各棵子树
>>> - 后序遍历 -> 当树非空时，依次后序遍历根的各棵子树，访问根结点
>>> - 层次遍历 -> 当树非空时，访问根结点，当第i层结点已访问，第i+1层未访问，访问第i+1层

>> - (2) 森林的遍历
>>> - 先序遍历: 从左到右每棵树的先序
>>> - 中序遍历：从左到右每棵树的后序

### 6. 判定树和哈夫曼树
#### 6.1 分类与判定树
#### 6.2 哈夫曼(Huffman)树与哈夫曼算法
> - 树的路径长度: 从树根到每个结点路径长度之和
> - 树的带权路径长度(WPL): 树中所有叶子节点的带权路径长度之后
> - WPL值最小的树为Huffman树，权值最大的结点离根最近，权值最小的结点离根最远

    //哈夫曼树结构
    const int n=10;
    typedef struct
    {
      float w; //权值
      int parent,lchild,rchild; //指针域
    }node;
    typedef node hftree[2*n-1];

    //哈夫曼算法
    void Huffman(int k, float w[], hftree T) //参数k表示构造哈夫曼树之前给定的权值个数
    //对给的的一组权值w的哈夫曼树T
    {
      int i,j,x,y;
      float m,n;
      for(i=0;i<2*k-1;i++)
      { //置初态
        T[i].parent = -1;
        T[i].lchild = -1;
        T[i].rchild = -1;
        if(i<k) T[i].w = w[i];
        else T[i].w = 0;
      }
      for(i=0;i<k-1;i++) //构造新的二叉树
      {
        x=0; y=0;
        m=MAX; n=MAX; //MAX为计算机能表示的一个较大的值
        for(j=0;j<k+i;j++) //找两颗权值最小的二叉树
        {
          if((T[j].w<m) && (T[j].parent==-1))
          {
            n=m;
            y=x;
            m=T[j].w;
            x=j;
          }
          else if((T[j].w<n) && (T[j].parent==-1))
          {
            n=T[j].w;
            y=j;
          }
        }
        //合并成一颗新的二叉树
        T[x].parent=k+i;
        T[y].parent=k+i;
    
        T[k+i].w = m+n;
        T[k+i].lchild=x;
        T[k+i].rchild=y;
      }
    }

#### 6.3 哈夫曼编码

    根据给定权值， 左小右大将权值两两相加，最后构造成一颗二叉树，
    置各分支为左0右1，然后相应权值的编码为从根结点到叶子结点的分支编码

# 五. 图
### 1. 概念
>> - G=(V,E) V-顶点集合，E-边的集合
>> - 无向图
>>> - 边 ()
>>> - 无向完全图 -> 边数=n(n-1)/2 n为顶点数
>>> - 简单路径、回路、简单回路
>>> - 连通、连通图、连通分量
>>> - 生成树、生成森林 -> 若连通图G的顶点个数为n,则G的生成树的边数为n-1

>> - 有向图
>>> - 弧 <>
>>> - 有向完全图 -> 边数=n(n-1) n为顶点数
>>> - 强连通、强连通图、强连通分量

>> - 权，带权图
>> - 顶点 -> 度、入度、出度
>> - 子图
>> - 路径、路径长度(路径上边/弧的数目)

>> - 图的基本运算
>>> - (1)  
>>> - (2)  
>>> - (3)  
>>> - (4)  
>>> - (5)  
>>> - (6)  
>>> - (7)  
>>> - (8)  
>>> - (9)  
>>> - (10)  

### 2. 图的存储结构
#### 2.1 邻接矩阵


#### 2.2 邻接表

# 六. 查找

# 七. 排序
