#include"List.h"
LTNode* LTBuyNode(LTDataType x)
{
	LTNode* newNode = (LTNode*)malloc(sizeof(LTNode));
	if (newNode == NULL)
	{
		perror("malloc fail");
		exit(1);
	}
	newNode->Data = x;
	newNode->next = newNode->prev = newNode;
	return newNode;
}
//初始化链表
//void SLInit(LTNode** pphead)
//{
//	*pphead = (LTNode*)malloc(sizeof(LTNode));
//	//哨兵位
//	(*pphead)->Data = 0;
//	(*pphead)->next = (*pphead)->prev = *pphead;
//}
LTNode* LTInit()
{
	LTNode* phead = LTBuyNode(-1);
	return phead;
}
//打印
void LTPrint(LTNode* phead)
{
	assert(phead);
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		printf("%d->", pcur->Data);
		pcur = pcur->next;
	}
	printf("\n");
}
//尾插
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newNode = LTBuyNode(x);
	//LTNode* pcur = pphead;
	//ptail==phead->prev
	//先对新节点进行修改
	newNode->next = phead;
	newNode->prev = phead->prev;
	//再修改原尾节点
	phead->prev->next = newNode;
	phead->prev = newNode;  
}
//头插
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = LTBuyNode(x);
	newnode->next = phead->next;
	newnode->prev = phead;

	phead->next = newnode;  
	phead->next->prev = newnode;
}
//尾删
void LTPopBack(LTNode* phead)
{
	assert(phead);
	//链表为空，只有一个哨兵位节点
	assert(phead->next != phead);
	LTNode* del = phead->prev;
	LTNode* prev = del->prev;

	prev->next = phead;
	phead->prev = prev;

	free(del);
	del = NULL;
}
//头删
void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LTNode* del = phead->next;
	LTNode* next = del->next;
	
	phead->next = next;
	next->prev = phead;

	free(del);
	del = NULL;
}
//查找
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		if (x == pcur->Data)
			return pcur;
		else
			pcur = pcur->next;
	}
	return NULL;
	/*LTDataType pos=0;
	while (pcur != phead)
	{
		if (x == pcur->Data)
		{
			return pos;
		}
		else {
			pos++;
		}
		pcur = pcur->next;
	}
	return -1;*/
}
//在pos之后插入数据
void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = LTBuyNode(x);
	newnode->next = pos->next;
	newnode->prev = pos;

	pos->next->prev = newnode;
	pos->next = newnode;
}
//删除pos
void LTErase(LTNode* pos)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* next = pos->next;
	prev->next = next;
	next->prev = prev;

	free(pos);
	pos = NULL;
}
//销毁
void LTDestory(LTNode* phead)
{
	assert(phead);
	LTNode* pcur = (phead)->next;
	while (pcur != (phead))
	{
		LTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	free(phead);
	phead = NULL;
}