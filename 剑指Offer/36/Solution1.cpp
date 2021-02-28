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
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};


class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        return inOrderTravers(root);
    }

private: 
    Node* inOrderTravers(Node* root) {
        if (root == nullptr) {
            return root ;
        }
        
        stack<Node*> nodeStack;
        Node* pres = root; // 当前节点
        Node* previousNode = nullptr; //上一个节点
        Node* head = nullptr;
        Node* tail = nullptr;
        while (pres != nullptr || !nodeStack.empty()) {
            while (pres != nullptr) {
                nodeStack.push(pres);
                pres = pres -> left;
            }

            pres = nodeStack.top();
            nodeStack.pop();

            if (previousNode == nullptr) {
                head = pres;
                previousNode = pres;
            } else {
                pres -> left = previousNode;
                previousNode -> right = pres;
                previousNode = pres;
            }
            pres = pres -> right;
        }
        tail = previousNode;
        tail -> right = head;
        head -> left = tail;
        return head;
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
