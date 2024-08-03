#include<iostream>
#include<vector>
using namespace std;


struct Person {
	int pos;//位置序号
	Person* next;
};
class Circlist {
	int N, S, M, K;
	Person* head,*cur,*tail;
	vector<int>deadpos;//记录亡者位置
public:
	Circlist() { N = S = M = K = 0; head = cur = tail = NULL; };
	~Circlist() = default;
	void init();
	void get_deadpos();
	void show();
};
void Circlist::init(){//初始化值，形成约瑟夫环，不带头节点
	cout << "请输入生死游戏的总人数N: ";
	cin >> N;
	cout << "请输入游戏开始的位置S: ";
	cin >> S;
	cout << "请输入死亡数字M: ";
	cin >> M;
	cout << "请输入最后的生者人数K: ";
	cin >> K;
	if(S>N)
    	S = S % N;
	//建立循环链表
	head = new Person;
	head->pos = 1;
	head->next =head;
	tail = head;
	for (int i = 2; i <= N; i++) {
		cur = new Person;
		cur->pos = i;
		cur->next = NULL;
		tail->next = cur;
		tail = cur;
	}
	tail->next = head;
}
void Circlist::get_deadpos() {//获取亡者位置
	Person* p,*q;
	p = head;
	for (int i = 1; i < S; i++) {//定位到第S个人
		p = p->next;
	}
	for(int i=0;i<N-K;i++)
	{
		for (int j = 1; j < M-1; j++)//数到要删的前一个节点
		{		
				p = p->next;
		}
		q = p->next;//q作为要删掉的节点
		deadpos.push_back(q->pos);	
			p->next = q->next;
		delete q;
		p = p->next;
	}
}
void Circlist::show() {
	get_deadpos();
	int len = deadpos.size();
	cout << endl;
	for (int i = 1; i <= len; i++)
	{
		cout << "第" << i << "个死者的位置是： " << deadpos[i - 1]<<endl;
	}
	cout << endl << "最后剩下： " << K << "人"<<endl;
	cout << "剩余生者的位置为： ";
	Person* p=head;
	for(int i=0;i<K;i++) {
		cout << p->pos << "   ";
		p = p->next;
	}
}
int main() {
	cout << "现有N人围成一圈，从第S个人开始报数，报M的人出局，"<<
		"再由下一人开始报数，如此循环，直至剩下K个人为止" << endl;
	cout << endl;
	Circlist C;
	C.init();
	C.show();
	cout << endl;
	system("pause");
	return 0;
}
