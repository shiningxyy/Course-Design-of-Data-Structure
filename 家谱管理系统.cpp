#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


class Tree;
class Node {
	friend class Tree;
public:
	string id;
	vector<Node*>children;
};
class Tree {
private:
	Node* root;
public:
	Tree(const string& buf) { root = new Node; root->id = buf; }
	Tree() = default;
	~Tree() { destroy(root); delete root; root = NULL; };
	void showroot();
	void destroy(Node*);
	Node* findperson(Node*,string);//查找一个节点
	Node* findparent(Node*, string);//查找一个节点的父节点
	void showfirstgen(Node*p);//打印节点的第一代子孙
	void buildfamily();//完善家庭
	void addmember();//添加家庭成员
	void removefamily();//解散家庭
	void changename();//改变姓名
};
void Tree::showroot() {
	cout << "此家谱的祖先是：" << root->id << endl;
}
void Tree::destroy(Node*p) {
	if (p->children.empty()) {
		delete p;
		p = NULL;
	}
	else {	
		for (auto& cur : p->children)
			destroy(cur);
	}
}
Node* Tree::findperson(Node* p, string name) {
	if (p->id == name)
		return p;
	else if (p->children.empty())
		return NULL;
	else {
		for (auto& cur : p->children) {
			Node* q = findperson(cur, name);
			if (q != NULL)
				return q;
		}
	}
	return NULL;
}
Node* Tree::findparent(Node* p, string name) {
	if (p->children.empty())
		return NULL;
	for (int i = 0; i < p->children.size(); i++) {
		if (p->children[i]->id == name)
			return p;
	}
	for (auto& cur : p->children) {
		Node* q = findparent(cur, name);
		if (q != NULL)
			return q;
	}
	return NULL;
}
void Tree::showfirstgen(Node*p) {
	cout << p->id << "的第一代子孙是：";
	for (int i = 0; i < p->children.size(); i++)
		cout << p->children[i]->id << ' ';
	cout << endl;
}
void Tree::buildfamily() {
	cout << "请输入要建立家庭的人的姓名：";
	string name;
	cin >> name;
	Node* p = findperson(root, name);
	if (p != NULL) {
		while(1){
			cout << "请输入" << name << "的儿女人数：";
			int n;
			cin >> n;
			if (cin.fail()) {
				cout << "输入错误，请重新输入！" << endl<<endl;
				cin.clear();
				cin.ignore(99999, '\n');
				continue;
			}
			cout << "请依次输入" << name << "的儿女的姓名：";
			for (int i = 0; i < n; i++) {
				cin >> name;
				Node* kid = new Node;
				kid->id = name;
				p->children.push_back(kid);
			}
			showfirstgen(p);
			break;
		}
	}
	else
		cout << "家谱中没有该成员！"<<endl;
}
void Tree::addmember() {
	cout << "请输入要添加儿子（或女儿）的人的姓名：";
	string name;
	cin >> name;
	Node* p = findperson(root, name);
	if (p != NULL)
	{
		Node* kid = new Node;
		cout << "请输入" << name << "新添加的儿子（或女儿）的姓名：";
		cin >> name;
		kid->id = name;
		p->children.push_back(kid);
		showfirstgen(p);
	}
	else
		cout << "家谱中没有该成员！" << endl;
}
void Tree::removefamily() {
	cout << "请输入要解散家庭的人的姓名：";
	string name;
	cin >> name;
	Node* p = findperson(root, name);
	if (p==root) {
		cout << "要解散家庭的人是：" << p->id << endl;
		showfirstgen(p);
		destroy(root);
		delete root;
		root = NULL;
	}
	else if (p!=NULL) {
		cout << "要解散家庭的人是：" << p->id << endl;
		showfirstgen(p);
		destroy(p);
		Node* parent = findparent(root, name);
		parent->children.erase(find(parent->children.begin(), parent->children.end(), p));
		delete p;
		p = NULL;
	}
	else
		cout << "家谱中没有该成员！" << endl;
}
void Tree::changename() {
	cout << "请输入要更改姓名的人的目前姓名：";
	string name;
	cin >> name;
	Node* p = findperson(root, name);
	if (p != NULL) {
		cout << "请输入更改后的姓名：";
		cin >>p->id;	
		cout << name << "已更名为" << p->id << endl;
	}
	else
		cout << "家谱中没有该成员！" << endl;
}
int main() {
	cout << endl;
	cout << "**      家谱管理系统      **" << endl;
	cout << "============================" << endl;
	cout << "**   请选择要执行的操作   **" << endl;
	cout << "**   A--完善家谱          **" << endl;
	cout << "**   B--添加家庭成员      **" << endl;
	cout << "**   C--解散局部家庭      **" << endl;
	cout << "**   D--更改家庭成员姓名  **" << endl;
	cout << "**   E--退出程序          **" << endl;
	cout << "============================" << endl;
	cout << "首先建立一个家谱！" << endl;
	cout << "请输入祖先的姓名：";
	string name;
	cin >> name;
	Tree Family(name);
	Family.showroot();
	while (1) {
		char ch;
		cout <<endl<< "请选择要执行的操作：";
		cin >> ch;
		if (ch == 'E')
			break;
		switch (ch) {
		case 'A':
			Family.buildfamily();
			break;
		case 'B':
			Family.addmember();
			break;
		case 'C':
			Family.removefamily();
			break;
		case 'D':
			Family.changename();
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
		}
	}
	system("pause");
	return 0;
}
