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
//��ʼ������
//void SLInit(LTNode** pphead)
//{
//	*pphead = (LTNode*)malloc(sizeof(LTNode));
//	//�ڱ�λ
//	(*pphead)->Data = 0;
//	(*pphead)->next = (*pphead)->prev = *pphead;
//}
LTNode* LTInit()
{
	LTNode* phead = LTBuyNode(-1);
	return phead;
}
//��ӡ
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
//β��
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newNode = LTBuyNode(x);
	//LTNode* pcur = pphead;
	//ptail==phead->prev
	//�ȶ��½ڵ�����޸�
	newNode->next = phead;
	newNode->prev = phead->prev;
	//���޸�ԭβ�ڵ�
	phead->prev->next = newNode;
	phead->prev = newNode;  
}
//ͷ��
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = LTBuyNode(x);
	newnode->next = phead->next;
	newnode->prev = phead;

	phead->next = newnode;  
	phead->next->prev = newnode;
}
//βɾ
void LTPopBack(LTNode* phead)
{
	assert(phead);
	//����Ϊ�գ�ֻ��һ���ڱ�λ�ڵ�
	assert(phead->next != phead);
	LTNode* del = phead->prev;
	LTNode* prev = del->prev;

	prev->next = phead;
	phead->prev = prev;

	free(del);
	del = NULL;
}
//ͷɾ
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
//����
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
//��pos֮���������
void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = LTBuyNode(x);
	newnode->next = pos->next;
	newnode->prev = pos;

	pos->next->prev = newnode;
	pos->next = newnode;
}
//ɾ��pos
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
//����
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