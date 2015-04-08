// ConsoleApplication2.cpp: 主项目文件。
#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstring>

using namespace std;

#define MAX_LENGTH 500

class ConvertLabel{
private:
	string _file;
	int _number;
	int _start;
public:
	vector<string> label2name;
	ConvertLabel(string file,int number,int start);
	void prepareLabel();
	string getLabel(int x);
};

ConvertLabel::ConvertLabel(string file,int number,int start):
	_file(file)
	,_number(number)
	,_start(start)
{}

void ConvertLabel::prepareLabel(){
	fstream fin(_file);
	label2name.resize(_number+10);
	for(int i=0;!fin.eof();i++){
		char getin[MAX_LENGTH],temp[MAX_LENGTH];
		fin.getline(getin,MAX_LENGTH);
		for(int j=_start;j<=strlen(getin);j++)
			temp[j-_start]=getin[j];
		label2name[i]=temp;
		if(i>=_number)
			break;
	}
	fin.close();
	return;
}

string ConvertLabel::getLabel(int x){
	return label2name[x];
}

int main(array<System::String ^> ^args)
{
    ConvertLabel imgnet("synset_words.txt",1000,10);//转换文件地址，类别数，开始字符
	imgnet.prepareLabel();
	while(1)
	{
		int x;
		cin>>x;
		cout<<imgnet.label2name[x]<<endl;
	}
    return 0;
}



