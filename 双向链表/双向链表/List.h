#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//���������нڵ�Ľṹ
typedef int LTDataType;
typedef struct ListNode {
	LTDataType Data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;
//��ʼ������
//void SLInit(LTNode** pphead);
LTNode* LTInit();
//��ӡ
void LTPrint(LTNode* phead);
//β��
void LTPushBack(LTNode* phead, LTDataType x);
//ͷ��
void LTPushFront(LTNode* phead, LTDataType x);
//βɾ
void LTPopBack(LTNode* phead);
//ͷɾ
void LTPopFront(LTNode* phead);
//����
LTNode* LTFind(LTNode* phead, LTDataType x);
//��pos֮���������
void LTInsert(LTNode* pos, LTDataType x);
//ɾ��pos
void LTErase(LTNode* pos);
//����
void LTDestory(LTNode* phead);