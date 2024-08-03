#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
typedef struct Student {
	string id;//学号
	string name;//姓名
	string sex;//性别
	int age;//年龄
	string work;//报考类别
	struct Student* next;
} * StuP;
class ListS {
private:
	StuP head;//头
	StuP tail;//尾
public:
	ListS()=default;
	~ListS() = default;
	void createlist();//创建链表
	void show();//输出信息
	void insert_();//插入
	void delete_();//删除
	void search_();//查找
	void change_();//修改
};

void ListS::createlist() {//带头节点
	int num;
	cout << "请输入考生人数：";
	cin >> num;
	cout << "请依次输入考生的考号，姓名，性别，年龄及报考类别！" << endl;
	StuP p;
	head = new Student;
	head->next = NULL;
	tail = head;
	for (int i = 1; i <= num; i++) {
		p = new Student;
		cin >> p->id >> p->name >> p->sex >> p->age >> p->work;
		p->next = NULL;
		tail->next = p;
		tail = p;
	}
}
void ListS::show() {
	StuP p;
	p = head->next;
	cout << endl << "考号\t姓名\t性别\t年龄\t报考类别" << endl;
	while (p != NULL) {
		cout << p->id << "\t" << p->name << "\t" << p->sex << "\t" << p->age << "\t" << p->work << endl;
		p = p->next;
	}
}

void ListS::insert_() {
	cout << "请输入你要插入的考生位置：";
	int place;
	cin >> place;
	cout << "请依次输入要插入的考生的考号，姓名，性别，年龄及报考类别！" << endl;
	StuP pnode = new Student;
	cin >> pnode->id >> pnode->name >> pnode->sex >> pnode->age >> pnode->work;
	//在固定位置插入
	StuP p, pre;
	p = head->next;
	pre = head;
	int j = 1;
	while (p != NULL)
	{
		if (j == place)
			break;
		pre = p;
		p = p->next;
		j++;
	}
	pnode->next = pre->next;
	pre->next = pnode;
}
void ListS::delete_() {
	cout << "请输入要删除的考生的考号：";
	string id;
	cin >> id;
	StuP p, pre;
	pre = head, p = head->next;
	while (p != NULL) {
		if (p->id == id)
		{
			cout << "要删除的考生信息是：";
			cout << p->id << ' ' << p->name << ' ' << p->sex << ' ' << p->age << ' ' << p->work << endl;
			pre->next = p->next;
			delete p;
			p = NULL;
			cout << "删除成功！" << endl;
			return;
		}
		if (p->id != id && p->next == NULL)
		{
			cout << "考生信息不存在" << endl;
			return;
		}
		pre = p;
		p = p->next;
	}
	//删除操作

}
void ListS::search_() {
	cout << "请输入要查找的考生的考号：";
	string id;
	cin >> id;
	StuP p = head->next;
	while (p != NULL) {
		if (p->id == id)
		{
			cout <<  "考号\t姓名\t性别\t年龄\t报考类别"  << endl;
			cout << p->id << "\t" << p->name << "\t" << p->sex << "\t" << p->age << "\t" << p->work << endl;
			break;
		}
		if (p->id != id && p->next == NULL)
		{
			cout << "考生信息不存在" << endl;
			return;
		}
		p = p->next;
	}
}
void ListS::change_() {
	cout << "请输入要修改的考生的考号：";
	string id;
	cin >> id;
	StuP p = head->next;
	while (p != NULL) {
		if (p->id == id)
		{
			cout << "要修改的考生信息是：";
			cout << p->id << ' ' << p->name << ' ' << p->sex << ' ' << p->age << ' ' << p->work << endl;
			cout << "请依次输入修改后的考生的考号，姓名，性别，年龄及报考类别！" << endl;
			cin >> p->id >> p->name >> p->sex >> p->age >> p->work;
			break;
		}
		if (p->id != id && p->next == NULL)
		{
			cout << "考生信息不存在" << endl;
			return;
		}
		p = p->next;
	}
}

int main() {
	ListS list_;
	int choice;
	cout << "首先请先建立考生信息系统!" << endl;
	list_.createlist();
	list_.show();
	while (1) {
		cout <<endl<< "请选择您要进行的操作（1为插入，2为删除，3为查找，4为修改，0为取消操作）：";
		cin >> choice;
		if (choice == 0) {
			break;
		}
		switch (choice) {
		case 1:
			list_.insert_();//插入
			break;
		case 2:
			list_.delete_();//删除
			break;
		case 3:
			list_.search_();//查找
			break;
		case 4:
			list_.change_();//修改
			break;
		default:
			cout << "\n输入错误，请重新输入" << endl;
		}
		list_.show();
	}
	system("pause");
	return 0;
}
