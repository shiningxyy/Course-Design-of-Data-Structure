#include<iostream>
#include<vector>
using namespace std;

class Queen {
private:
	int N;//皇后个数
	int sum = 0;//总摆法
	vector<int>colpos;//记录皇后的列位置
	vector<bool>haveQ;//记录某列有无皇后
	vector<vector<int>>ans;//colpos的一个集合
public:
	Queen() :N(0) {};
	~Queen() = default;
	void getN();//初始化N
	void recall(int row);//回溯
	void output();//输出
	void init();//初始化haveQ和colpos
};
void Queen::getN() {
	int x;
	while(1){
		cin >> x;
		if (cin.good())
		{
			if (x >= 1)
			{
				N = x;
				break;
			}
			else
			{
				cout << "皇后的个数需大于等于1，请重新输入！" << endl;
				continue;
			}
		}
		else
		{
			cerr << "输入错误，请重新输入！" << endl;
			cin.clear();
			cin.ignore(99999,'\n');
			continue;
		}
	}
}
void Queen::recall(int row) {
	if (row >= N)
	{//所有皇后摆放完成
		ans.push_back(colpos);
		sum++;
		return;
	}
	for (int i = 0; i < N; i++) {//i表示列，首先定位到没有皇后的一列
		if (haveQ[i])
			continue;
		haveQ[i] = 1;
		colpos[row] = i;//若该列无皇后，先摆放，第row行的皇后在第i列
		bool flag = 0;
		for (int j = 0; j < row; j++)//检查对角线是否安全
		{
			if (abs(j - row) == abs(i - colpos[j]))//不安全
			{
				flag = 1;
				break;
			}
		}
		if (flag==0)//如果安全，摆放下一行
			recall(row + 1);
		haveQ[i] = 0;//不安全，撤销之前的操作
	//注意这里不能使用if-else语句，否则一旦遇到不安全的一行摆放，函数直接结束，后续的递归将无法进行了
	}
}
void Queen::init() {
	haveQ.resize(N, 0);
	colpos.resize(N, -1);
}
void Queen::output() {
	init();//初始化
	recall(0);//回溯
	cout << endl;
	for (int i = 0; i < sum; i++) {//解法个数
		cout << "第" << i + 1 << "种摆法为：" << endl;
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
				if (ans[i][r] == c)
					cout <<"X ";
				else
				cout << "0 ";
		    cout << endl;
		}
		cout << endl;
	}
	cout << "共有" << sum << "种摆法" << endl;
}
int main() {
	cout << "现有N×N的棋盘，放入N个皇后，要求所有皇后不在同一行、列和同一对角线上!" << endl;
	cout << "请输入皇后的个数：";
	Queen queen;
	queen.getN();
	queen.output();
	system("pause");
	return 0;
}
