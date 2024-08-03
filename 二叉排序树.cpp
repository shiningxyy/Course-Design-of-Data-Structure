#include<iostream>
#include<vector>
using namespace std;

class BST;
class BSTNode {
	friend class BST;
public:
	BSTNode() = default;
	BSTNode(int x) { data = x; left = NULL; right = NULL; }
private:
	int data;
	BSTNode* left, * right;
};
class BST {
private:
	BSTNode* root;
	int stop;//输入终止的标识
public:
	BST() = default;
	void insert(const int,BSTNode*&);//插入节点
	void searchkey();//查找关键码
	void buildtree();//建树
	void InOrder(BSTNode*);//中序遍历
	void show();//输出树
	void insertkey();//插入元素
	BSTNode* search(const int,BSTNode*);//查找节点节点
};
BSTNode* BST::search(const int x, BSTNode* p) {
	if (p != NULL) {
		BSTNode* temp = p;
		while (temp != NULL) {
			if (temp->data == x)
				return temp;
			if (x < temp->data)
				temp = temp->left;
			else
				temp = temp->right;

		}
	}
	return NULL;
}
void BST::searchkey() {
	cout << "输入要查找的元素：";
	int key;
	cin >> key;
	BSTNode* cur = search(key, root);
	if (cur != NULL)
		cout << "搜索成功！" << endl;
	else
		cout <<key<< "不存在！" << endl;
}
void BST::insertkey() {
	cout << "输入要插入的元素：";
	int key;
	cin >> key;
	BSTNode* cur = search(key, root);
	if(cur==NULL)
	{
		insert(key, root);
		show();
	}
	else {
		cout << key << "已存在！" << endl;
	}
}
void BST::show() {
	cout << "二叉排序树为：" << endl;
	InOrder(root);
	cout << endl;
}
void BST::buildtree() {
	cout << "请依次输入关键码（以0作为结束标志）：" << endl;
	vector<int>keys;
	int key;
	while (1) {
		cin >> key;
		if (key != 0)
		{
			int size = keys.size();
			int same = 0;
			for (int i = 0; i < size; i++) {
				if (key == keys[i])
				{
					cout << "关键码" << key << "已存在！" << endl;
					same++;
				}
			}
			if(same==0)
			    keys.push_back(key);
		}
		else
			break;
	}
	root = new BSTNode(keys[0]);
	for (int i = 1; i < keys.size(); i++) {
		insert(keys[i], root);
	}
	show();
}
void BST::insert(const int x,BSTNode*&p) {
	if (p == NULL) {
		p = new BSTNode(x);
		if (p == NULL) {
			cout << "Out of space!";
			exit(0);
		}
	}
	else if (x < p->data)
		insert(x, p->left);
	else if (x > p->data)
		insert(x, p->right);
}
void BST::InOrder(BSTNode*p) {
	if (p != NULL) {
		InOrder(p->left);
		cout << p->data << "->";
		InOrder(p->right);
	}
}
int main()
{
	cout << endl;
	cout << "**        二叉排序数         **" << endl;
	cout << "===============================" << endl;
	cout << "**      1.建立二叉排序树     **" << endl;
	cout << "**      2.插入元素           **" << endl;
	cout << "**      3.查询元素           **" << endl;
	cout << "**      4.退出程序           **" << endl;
	cout << "===============================" << endl;
	BST bst;
	while(1){
		cout << "\n请选择：";
		int choice;
		int flag = 0;
		cin >> choice;
		switch (choice)
		{
		case 1:
			bst.buildtree();
			break;
		case 2:
			bst.insertkey();
			break;
		case 3:
			bst.searchkey();
			break;
		case 4:
			flag = 1;
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
		}
		if (flag)
			break;
	}
	system("pause");
}
