// 请完成下面的笔试题。
// 你也可以线下 code，完成之后发到这个邮箱：xgao@dayuwuxian.com
// 祝答题顺利。

// 1. 实现一个函数，在一个有序整型数组中二分查找出指定的值，找到则返回该值的位置，找不到返回 -1。

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
        
        if (value == compareVal)
        {
            return compareIdx;
        }
        else if (value < compareVal)
        {
            startIdx = compareIdx+1;
        }
        else 
        {
            endIdx = compareIdx;
        }
        
    }

    return -1;
}



// 2. 写一个函数将一个数组转化为一个链表。
// 要求：不要使用库函数，(如 List 等)

typedef struct Lnode {
    int value;
    struct Lnode *next;
}

Lnode * transferToList(int array[], int length)
{
	Lnode *head = (Lnode)malloc(sizeof(Lnode));
	Lnode *node; 
	Lnode *currentNode = head;
	int value;

	for (int i = 0; i < length; ++i)
	{
		node = (Lnode)malloc(sizeof(Lnode));
		node.value = array[i];
		currentNode.next = node;
		currentNode = node;
	}

	currentNode.next = NULL;

	return head;
}




// 3. 有两个数组，[1,3,4,5,7,9] 和 [2,3,4,5,6,8],用上面的函数生成两个链表 linkA 和
// linkB，再将这两个链表合并成一个链表,结果为[1,2,3,4,5,6,7,8,9].
// 要求：不要生成第三个链表，不要生成新的节点。
// 3.1 使用递归方式实现


Lnode * mergeSortedList(Lnode *linkA, Lnode *linkB)
{
	Lnode *node = mergeSortedListNoHead(linkA->next, linkB->next);
	linkA->next = node;
	return linkA;
}

Lnode *mergeSortedListNoHead(Lnode *nodeA, Lnode *nodeB)
{
	Lnode *sortedA = mergeSortedListNoHead(nodeA);
	Lnode *sortedB = mergeSortedListNoHead(nodeB);

	if (nodeA.value >= nodeB.value)
	{
		node = nodeB;
	}
	else
	{
		node = nodeA;
	}

	node->next = node;
	return node;
}


// 3.2 使用循环方式实现


Lnode *mergeSortedArray(int arrayA[], int arrayB[])
{
	return mergeSortList(transferToList(arrayA), transferToList(arrayB));
}

Lnode * mergeSortedList(Lnode *linkA, Lnode *linkB)
{
	Lnode *retNode;
	Lnode *prevNode = linkA;
	Lnode *currentNode;
	Lnode *nodeA = linkA->next;
	Lnode *nodeB = linkB->next;

	while(nodeA && nodeB)
	{
		if (nodeA.value >= nodeB.value)
		{
			currentNode = nodeB;
		}
		else 
		{
			currentNode = nodeA;
		}

		nodeA = nodeA->next;
		nodeB = nodeB->next;

		currentNode->next = prevNode->next;
		prevNode->next = currentNode;
	}

	return retNode;
}
