#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//定义链表中节点的结构
typedef int LTDataType;
typedef struct ListNode {
	LTDataType Data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;
//初始化链表
//void SLInit(LTNode** pphead);
LTNode* LTInit();
//打印
void LTPrint(LTNode* phead);
//尾插
void LTPushBack(LTNode* phead, LTDataType x);
//头插
void LTPushFront(LTNode* phead, LTDataType x);
//尾删
void LTPopBack(LTNode* phead);
//头删
void LTPopFront(LTNode* phead);
//查找
LTNode* LTFind(LTNode* phead, LTDataType x);
//在pos之后插入数据
void LTInsert(LTNode* pos, LTDataType x);
//删除pos
void LTErase(LTNode* pos);
//销毁
void LTDestory(LTNode* phead);