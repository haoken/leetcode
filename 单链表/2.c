struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* temp1 = l1;
    struct ListNode* temp2 = l2;
    struct ListNode* resultlist = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* cur = resultlist;
    cur->next = NULL;
    int carry = 0;
    while(temp1!=NULL||temp2!=NULL||carry==1){
        int x,y;
        x = temp1==NULL?0:temp1->val;
        y = temp2==NULL?0:temp2->val;
        int sum = x+y+carry;
        if(sum>=10){
            carry = 1;
            sum %= 10;
        }
        else
            carry = 0;
        struct ListNode* node = (struct ListNode* )malloc(sizeof(struct ListNode));
        node->val = sum;
        node->next = NULL;
        cur->next = node;
        cur = cur->next;

        temp1 = temp1==NULL?NULL:temp1->next;
        temp2 = temp2==NULL?NULL:temp2->next;
    }
    printf("helloworld");
    return resultlist->next;//有头结点的话方便循环，结尾只要返回头结点->next就行了
}