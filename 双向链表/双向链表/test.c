#include"List.h"
void ListTest01()
{
	/*LTNode* plist = NULL;
	SLInit(&plist);*/

	LTNode* plist = LTInit();
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPrint(plist);

	/*LTPushFront(plist, 5);
	LTPushFront(plist, 6);
	LTPushFront(plist, 7);
	LTPushFront(plist, 8);

	LTPrint(plist);

	LTPopBack(plist);
	LTPopBack(plist);

	LTPrint(plist);

	LTPopFront(plist);
	LTPopFront(plist);*/
	//LTDataType x = LTFind(plist, 3);
	//if (x == -1) {
	//	printf("没有找到");
	//}
	//else {
	//	printf("找到了，下标是%d", x);
	//}
	LTNode* x = LTFind(plist, 2);
	//LTInsert(x, 55);
	LTErase(x);
	LTPrint(plist);
	LTDestory(plist);
	//LTPrint(plist);
}
int main()
{
	ListTest01();
	printf("hhh");
	return 0;
}