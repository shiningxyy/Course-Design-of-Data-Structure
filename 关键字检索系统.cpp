#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Solution {
private:
	string fname;//文件名
	string content;//内容
	int count = 0;
	string key0;
public:
	void creatf();//创建文本文件
	void search();//检索关键字
	void transform(string&);//把所有大写转为小写
	void getcount();
};
void Solution::transform(string& s) {
	string::iterator sit = s.begin();
	while (sit != s.end()) {
		if ((*sit) > 'A' && (*sit) < 'Z')
			*sit += 32;
		sit++;
	}
	//cout << s;
}
void Solution::creatf() {
	cout << "请输入文件名：";	
	ofstream ofs;
	getline(cin, fname);
	ofs.open(fname, ios::out);
	if (!ofs.is_open()) {
		cerr << "文件打开失败！" << endl;
		exit(0);
	}
	cout <<endl<< "请输入一段英文" << endl;
	getline(cin,content);
	ofs << content;
	ofs.close();
	cout << "本段文本已保存在文本文件" << fname << "中。" << endl;
}
void Solution::search() {
	cout << endl<<"请输入要检索的关键字：";
	string key;
	cin >> key0;
	key = key0;
	transform(key);
	cout <<endl<< "显示源文件" << fname << "：" << endl<<endl;
	ifstream ifs;
	ifs.open(fname, ios::in);
	if (!ifs.is_open()) {
		cerr << "文件打开失败！" << endl;
		exit(0);
	}
	cout << content<<endl;
	string word;
	while (!ifs.eof()) {
		word.clear();//清空字符串，防止最后一行读不到东西导致最后一个单词被两次计算
		ifs >> word;
		int size = word.size();
		if (!word.empty()) {
			if (word[size - 1] < 'a' || word[size - 1]>'z')
				word = word.substr(0, size - 1);//如果是句尾的单词会和标点一起读进来，这时要去除标点
			transform(word);//将单词转为小写
			if (word == key)
				count++;
		}
	}
	ifs.close();
	
}
void Solution::getcount() {
	cout <<endl<< "在源文件中共检索到：" << count << "个关键字“"<<key0<<"”"<<endl;
}
int main() {
	cout << "关键字检索系统" << endl;
	Solution S;
	S.creatf();
	S.search();
	S.getcount();
	system("pause");
	return 0;
}
