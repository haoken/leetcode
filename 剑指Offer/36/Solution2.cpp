#include<iostream>
#include<stack>
using namespace std;

class Node { //双向链表节点
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class ResultType {
public:
    Node* head;
    Node* tail;
    ResultType() {
        head = nullptr;
        tail = nullptr;
    }
};

//思路2： 分治，递归。
class Solution {
public:
    Node* treeToDoublyList(Node* root) {

        if (root == nullptr) {
            return nullptr;
        }
        ResultType result = helper(root);
        result.head -> left = result.tail;
        result.tail -> right = result.head;
        return result.head;
    }

private:
    ResultType helper(Node* root) {
        ResultType result;
        if (root == nullptr) {
            return result;
        }

        ResultType left = helper(root -> left); // 左边链表
        ResultType right = helper(root -> right); // 右边链表
        
        root -> left = left.tail;
        if (left.tail != nullptr) {
            left.tail -> right = root;
            result.head = left.head;
        } else {
            result.head = root;
        }

        root -> right = right.head;
        if (right.head != nullptr){
            right.head -> left = root;
            result.tail = right.tail;
        } else {
            result.tail = root;
        }
        return result;
    }
};

int main() {
    Node* node = new Node(4,new Node(2,new Node(1),new Node(3)),new Node(5));
    Solution solution;
    Node* linkList = solution.treeToDoublyList(node); 
    Node* pres = linkList;
    while (pres -> right != linkList) {
        cout << pres -> val << " <-> " ;
        pres = pres -> right;
    }
    cout << pres -> val ;
}
