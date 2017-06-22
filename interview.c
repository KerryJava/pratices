// 请完成下面的笔试题。
// 你也可以线下 code，完成之后发到这个邮箱：xgao@dayuwuxian.com
// 祝答题顺利。

// 1. 实现一个函数，在一个有序整型数组中二分查找出指定的值，找到则返回该值的位置，找不到返回 -1。
#include<stdio.h>
#include<stdlib.h>
int findInSortArray(int array[],int length, int value)
{
    int index = -1;
    int startIdx = 0;
    int endIdx = length-1;
    int compareVal = 0;
    int compareIdx = 0;
    //

    while(startIdx <= endIdx){
        compareIdx = (startIdx + endIdx)*0.5;
        compareVal = array[compareIdx];
        //printf("---- sorted indx %d %d \n", compareIdx, compareVal, value, length);

        if (value == compareVal)
        {
            return compareIdx;
        }
        else if (value < compareVal)
        {
            //printf("《 sorted indx %d %d %d %d %d %d\n", startIdx, endIdx, compareIdx, compareVal, value, length);

            endIdx = compareIdx - 1;

            // if (endIdx == startIdx)
            // {
            // 	break;
            // }
        }
        else 
        {
        	//printf(" 》 sorted indx %d %d %d %d %d %d\n", startIdx, endIdx, compareIdx, compareVal, value, length);
            startIdx = compareIdx + 1;
        }
        
    }

    return -1;
}

// 2. 写一个函数将一个数组转化为一个链表。
// 要求：不要使用库函数，(如 List 等)

typedef struct Lnode {
    int value;
    struct Lnode *next;
}Lnode;

Lnode * transferToList(int array[], int length)
{
	Lnode *head = (Lnode*)malloc(sizeof(Lnode));
	Lnode *node; 
	Lnode *currentNode = head;
	int value;

	for (int i = 0; i < length; ++i)
	{
		node = (Lnode*)malloc(sizeof(Lnode));
		node->value = array[i];
		currentNode->next = node;
		currentNode = node;
	}

	currentNode->next = NULL;

	return head;
}




// 3. 有两个数组，[1,3,4,5,7,9] 和 [2,3,4,5,6,8],用上面的函数生成两个链表 linkA 和
// linkB，再将这两个链表合并成一个链表,结果为[1,2,3,4,5,6,7,8,9].
// 要求：不要生成第三个链表，不要生成新的节点。
// 3.1 使用递归方式实现
Lnode * mergeSortedListNoHead(Lnode *nodeA, Lnode *nodeB);
Lnode * mergeSortedList(Lnode *linkA, Lnode *linkB);

Lnode * mergeSortedListRecurse(Lnode *linkA, Lnode *linkB)
{
	Lnode *node = mergeSortedListNoHead(linkA->next, linkB->next);
	linkA->next = node;

	if (linkB) 
	{
		free(linkB);
	}

	return linkA;
}

Lnode * mergeSortedListNoHead(Lnode *nodeA, Lnode *nodeB)
{
	Lnode *node = NULL;
	Lnode *nextA = nodeA;
	Lnode *nextB = nodeB;

	if (!nodeA)
	{
		return nodeB;
	}

	if (!nodeB)	
	{
		return nodeA;
	}

	if (!nodeA)
	{
		node = nodeB;
	}
	else if (!nodeB)
	{
		node = nodeA;
	}
	else if (nodeA->value >= nodeB->value)
	{
		node = nodeB;
	}
	else
	{
		node = nodeA;
	}

	if (node == nodeA) 
	{
		nextA = nextA->next;
	}
	else
       	{
		nextB = nextB->next;
	}

	Lnode *sortedListNode = mergeSortedListNoHead(nextA,nextB);

	if (node)
	{
		node->next = sortedListNode;
	}

	return node;
}

Lnode * mergeSortedArray2(int arrayA[], int aLength, int arrayB[], int bLength)
{	
	Lnode *node = mergeSortedListRecurse(transferToList(arrayA, aLength), transferToList(arrayB, bLength));
	return node; 
}

// 3.2 使用循环方式实现

Lnode * mergeSortedArray(int arrayA[], int aLength, int arrayB[], int bLength)
{	
	Lnode *node = mergeSortedList(transferToList(arrayA, aLength), transferToList(arrayB, bLength));
	return node; 
}

Lnode * mergeSortedList(Lnode *linkA, Lnode *linkB)
{
	Lnode *retNode = linkA;
	Lnode *prevNode = linkA;
	Lnode *currentNode = NULL;
	Lnode *nodeA = linkA->next;
	Lnode *nodeB = linkB->next;
	Lnode *lastNode = NULL;

	while(nodeA && nodeB)
	{
		if (nodeA->value <= nodeB->value)
		{
			currentNode = nodeA;
			nodeA = nodeA->next;
		}
		else 
		{
			currentNode = nodeB;
			nodeB = nodeB->next;
		}

		prevNode->next = currentNode;
		prevNode = prevNode->next;
	}

	lastNode = nodeA ? nodeA : nodeB;
	prevNode->next = lastNode;
	
	if (linkB)
	{
		free(linkB);
	}

	return retNode;
}

void printList(Lnode* curNode);
void delList(Lnode* node);

int main(int argc,char *argv[])
{

	printf("hello world\n");

	int test1[] = {0,1,3};
	int test2[] = {1,0};
	int test3[] = {1,2,4,6};
	int test4[] = {1,3,5,7,9};
	int test5[] = {1,2,4,5,7,8,9};
	int test6[] = {3,4,5,7,8,9};
	int test7[] = {};


	int findIdx = -1;
	int findVal = 3;
	findIdx = findInSortArray(test1, sizeof(test1)/sizeof(int),findVal);
	printf("1 %d\n",findIdx);

	findIdx = findInSortArray(test2, sizeof(test2)/sizeof(int), findVal);
	printf("2 %d\n",findIdx);
		findIdx = findInSortArray(test3, sizeof(test3)/sizeof(int), findVal);
	printf("3 %d\n",findIdx);
		findIdx = findInSortArray(test4, sizeof(test4)/sizeof(int), findVal);
	printf("4 %d\n",findIdx);

	findIdx = findInSortArray(test5, sizeof(test5)/sizeof(int), findVal);
		printf("5 %d\n",findIdx);

	findIdx = findInSortArray(test6, sizeof(test6)/sizeof(int), findVal);
		printf("6 %d\n",findIdx);
	findIdx = findInSortArray(test7, sizeof(test6)/sizeof(int), findVal);
		printf("7 %d\n",findIdx);
	printf("\n----end ----\n");

	Lnode *nodeList1 = transferToList(test1, sizeof(test1)/sizeof(int));
	Lnode *nodeList2 = transferToList(test2, sizeof(test2)/sizeof(int));
	Lnode *nodeList3 = transferToList(test3, sizeof(test3)/sizeof(int));
	Lnode *nodeList4 = transferToList(test4, sizeof(test4)/sizeof(int));
	Lnode *nodeList5 = transferToList(test5, sizeof(test5)/sizeof(int));
	Lnode *nodeList6 = transferToList(test6, sizeof(test6)/sizeof(int));
	Lnode *nodeList7 = transferToList(test7, sizeof(test7)/sizeof(int));

	

	printList(nodeList1);
	printList(nodeList2);
	printList(nodeList3);
	printList(nodeList4);
	printList(nodeList5);
	printList(nodeList6);
	printList(nodeList7);



	printf("\n merge1\n");
	Lnode *mergeNodeList1 = mergeSortedArray(test1, sizeof(test1)/sizeof(int), test4, sizeof(test4)/sizeof(int));
	printList(mergeNodeList1);
	printf("\n merge2\n");


	printf("\n merge3\n");
	Lnode *mergeNodeList2 = mergeSortedArray2(test1, sizeof(test1)/sizeof(int), test4, sizeof(test4)/sizeof(int));
	printList(mergeNodeList2);

	printf("\n merge4\n");
	// Lnode *mergeNodeList2 = mergeSortedArray2(test1, sizeof(test1)/sizeof(int), test2, sizeof(test2)/sizeof(int));
	// printList(mergeNodeList2);

	delList(nodeList1);
	delList(nodeList2);
	delList(nodeList3);
	delList(nodeList4);
	delList(nodeList5);
	delList(mergeNodeList1);
	delList(mergeNodeList2);


	while(argc-->1) printf("%s/n",*++argv); 

} 

void printList(Lnode* node)
{
	printf("start\n");

	Lnode *curNode = node;
	for (int i = 0; curNode && curNode->next; ++i)
	{
		curNode = curNode->next;
		printf("%d value %d\n",i, curNode->value);
	}

	printf("end\n");
}

void delList(Lnode* node)
{
	printf("del start\n");

	Lnode *curNode = node;
	Lnode *temp;
	for (int i = 0; curNode && curNode->next; ++i)
	{
		temp = curNode;
		curNode = curNode->next;
		free(temp);
		printf("%d value %d\n",i, curNode->value);
	}

	if (curNode)
	{
		free(curNode);
	}

	printf("del end\n");
}
