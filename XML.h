#pragma once
#include<fstream>
#include<string>
#include<sstream>
#include<stdio.h>
#include<iostream>
#define RET return
using namespace std;
int contents___(std::string contents);
std::string contents__(std::string contents);
std::string contents_name(std::string contents);
std::string contents__name(std::string contents);
std::string contents_(std::string contents);
//��ȡ�ļ���(�޺�׺)
std::string contents__name(std::string contents)
{
	contents = contents_name(contents);
	std::fstream fst_out;
	fst_out.open("add_all_cbb", std::ios::out);
	fst_out << contents;
	fst_out.close();
	std::fstream fst_in("add_all_cbb");
	std::string contentname;
	std::getline(fst_in, contentname, '.');
	fst_in.close();
	remove("add_all_cbb");
	return contentname;
}
//��ȡ�ļ���
std::string contents_name(std::string contents)
{
	//'/'�ַ������ֵ�λ��
	int a = 0;
	int c = 0;
	for (int i = 0; i < contents.size(); i++)
	{
		if (contents[i] == '/') {
			a = i;
		}
	}
	for (int i = 0; i < contents.size(); i++) {
		if (contents[i] == '/') {
			if (i != a)
			{
				contents[i] = 'a';
			}
		}
	}
	std::fstream fst_out;
	fst_out.open("add_all_cbb", std::ios::out);
	fst_out << contents;
	fst_out.close();
	std::fstream fst_in("add_all_cbb");
	std::string contentname;
	std::getline(fst_in, contentname, '/');
	std::getline(fst_in, contentname);
	fst_in.close();
	remove("add_all_cbb");
	return contentname;
}
//��ȡ·��
std::string contents_(std::string contents)
{
	std::string content;
	for (short i = 0; i < contents___(contents); i++)
	{
		content += contents[i];
	}
	return content;
}
//��ȡ�ļ���һ�ַ��±�
int contents___(std::string contents)
{
	//'/'�ַ������ֵ�λ��
	int a = 0;
	int c = 0;
	for (int i = 0; i < contents.size(); i++)
	{
		if (contents[i] == '/') {
			a = i;
		}
	}
	for (int i = 0; i < contents.size(); i++) {
		if (contents[i] == '/') {
			if (i != a)
			{
				contents[i] = 'a';
			}
		}
	}

	return a + 1;
}
//��ȡ��׺��
std::string contents__(std::string contents)
{
	contents = contents_name(contents);
	std::fstream fst_out;
	fst_out.open("add_all_cbb", std::ios::out);
	std::fstream fst__in("add_all_cbb");
	fst_out << contents;
	fst_out.close();
	std::getline(fst__in, contents, '.');
	std::getline(fst__in, contents);
	for (short int i = 0; i < contents.size(); i++)
	{
		if (contents[i] == '.') {
			contents[i] = 'z';
			return contents__(contents);
		}
	}

	remove("add_all_cbb");
	return contents;
}
//����
class  XML
{
public:
	XML(string tents);
	~ XML();
	string OPENXML(string YUAN);
	string OPENXML(string CLSSDNAME,string YUAN);
	string OPENXML(string DAD_CLASSNAME,string ID, string YUAN);	
	void OUTXML_CLASS(const string DAD_CLASSNAME, string CLASSNAME);
	void OUTXML_CLASS(const string DAD_CLASSNAME,const string DAD_ID, const string CLASSNAME);
	void OUTXML_CLASS(const string DAD_CLASSNAME, const string CLASS_ID_NAME, const string CLASS_ID, const string CLASSNAME);
	void OUTXML_CLASS(const string DAD_CLASSNAME, const string DAD_ID, const string CLASS_ID_NAME, const string CLASS_ID,const string CLASSNAME);
	void OUTXML_SHUXING(const string DAD_CLASSNAME, const string SHUXINGNAME, const string SHUXING);
	void OUTXML_SHUXING(const string DAD_CLASSNAME, const string DAD_ID, const string SHUXINGNAME, const string SHUXING);
	void OUTXML_SHUXING(const string DAD_CLASSNAME, const string SHUXINGNAME, const string SHUXING_ID_NAME, const string SHUXING_ID, const string SHUXING);
	void OUTXML_SHUXING(const string DAD_CLASSNAME, const string DAD_ID, const string SHUXINGNAME,const string SHUXING_ID_NAME,const string SHUXING_ID, const string SHUXING);
	void OUTXML_DELETE(const string YUANNAME);
	void OUTXML_DELETE(const string DAD_CLASSNAME,const string YUANNAME);
	void OUTXML_DELETE(const string DAD_CLASSNAME, const string DAD_ID, const string YUANNAME);
	bool IS_OUT_IN() const;
private:
	bool true_OR_false=true;
	  string ·��;
};
//���캯��
 XML:: XML(string tents)
{
	 ·�� = tents;
}
 //��������
 XML::~ XML()
{
}
 //�ж��Ƿ�ɹ�
 bool XML::IS_OUT_IN() const
 {
	RET true_OR_false;
 }
//��Ԫ������ѯ�����Ԫ������
string XML::OPENXML(string YUAN)
{
	ifstream OPEN_IN(·��);
	if (OPEN_IN.is_open() == false) {
		true_OR_false = false;
		RET "";
	}
	string YUANSU;
	while (!OPEN_IN.eof())
	{
		getline(OPEN_IN, YUANSU, '<');
		getline(OPEN_IN, YUANSU, '>');
		if (YUANSU == YUAN)
		{
			getline(OPEN_IN, YUANSU, '<');
			true_OR_false = true;
			RET YUANSU;
		}
	}
	true_OR_false = false;
	RET "";
}
//��������Ԫ������ѯ�����Ԫ������
string XML::OPENXML(string DAD_CLASSNAME, string YUAN)
{
	ifstream OPEN_IN(·��);
	if(OPEN_IN.is_open()==false)
	{
		true_OR_false = false;
		RET"";
	}
	string YUANSU;
	while (!OPEN_IN.eof())
	{
		getline(OPEN_IN, YUANSU, '<');
		getline(OPEN_IN, YUANSU, '>');
		short int a=0;
		if (YUANSU.size() >= DAD_CLASSNAME.size()) {
			for (short i = 0; i < DAD_CLASSNAME.size(); i++)
			{
				if (YUANSU[i] == DAD_CLASSNAME[i])
					a++;
				else
					a = 0;
			}
			if (a == DAD_CLASSNAME.size())
			{
				if (YUANSU.size() == DAD_CLASSNAME.size())
					goto a1;
				if (YUANSU[DAD_CLASSNAME.size()] == '>' || YUANSU[DAD_CLASSNAME.size()] == ' ')
				{
					while (!OPEN_IN.eof())
					{a1:
						getline(OPEN_IN, YUANSU, '<');
						getline(OPEN_IN, YUANSU, '>');
						if (YUANSU == YUAN)
						{
							getline(OPEN_IN, YUANSU, '<');
							true_OR_false = true;
							RET YUANSU;
						}
						else if (YUAN == '/' + DAD_CLASSNAME)
						{
							true_OR_false = false;
							RET "";
						}
					}
				}
			}
		}
	}
	true_OR_false = false;
	RET "";
}
//��������ID��ѯ�����Ԫ������
string XML::OPENXML(string DAD_CLASSNAME, string ID, string YUAN) {

	{
		ifstream OPEN_IN(·��);
		if (OPEN_IN.is_open() == false)
		{
			true_OR_false = false;
			RET"";
		}
		string YUANSU;
		while (!OPEN_IN.eof())
		{a1:
			getline(OPEN_IN, YUANSU, '<');
			getline(OPEN_IN, YUANSU, '>');
			short int a = 0;
			if (YUANSU.size() >= DAD_CLASSNAME.size()) {
				for (short i = 0; i < DAD_CLASSNAME.size(); i++)
				{
					if (YUANSU[i] == DAD_CLASSNAME[i])
						a++;
					else
						a = 0;
				}
				if (a == DAD_CLASSNAME.size())
				{
					if (YUANSU.size() == DAD_CLASSNAME.size())
						goto a1;
					if (YUANSU[DAD_CLASSNAME.size()] == '>' || YUANSU[DAD_CLASSNAME.size()] == ' ')
					{
						for (short int i = 0; i < YUANSU.size(); i++)
						{
							if (YUANSU[i] == '"')
							{
								a = 0;
								int i_ = 0;
								for (short int z = i + 1; z < YUANSU.size(); z++)
								{
									if (YUANSU[z] == ID[i_])
										a++;
									else if (YUANSU[z] == '"')
									{
										while (!OPEN_IN.eof())
										{
											getline(OPEN_IN, YUANSU, '<');
											getline(OPEN_IN, YUANSU, '>');
											if (YUANSU == YUAN)
											{
												getline(OPEN_IN, YUANSU, '<');
												true_OR_false = true;
												RET YUANSU;
											}
											else if (YUAN == '/' + DAD_CLASSNAME)
											{
												true_OR_false = false;
												RET "";
											}
										}
									}
									else
										goto a1;
									i_++;
								}
							}
						}
					}
				}
			}
		}
		true_OR_false = false;
		RET "";
	}
}
//ͨ��������XML�ļ�д��һ����
void XML::OUTXML_CLASS(const string DAD_CLASSNAME, string CLASSNAME) {
	fstream OPEN_IN_OUT(·��);
	string CLASS;
	short int c = 0;
	short int a=0;
	while (!OPEN_IN_OUT.eof())
	{
		getline(OPEN_IN_OUT, CLASS, '<');
		getline(OPEN_IN_OUT, CLASS, '>');
		c++;
		for (short int i = 0; i < DAD_CLASSNAME.size(); i++)
		{
			if (CLASS[i] == DAD_CLASSNAME[i])
				a++;
			else
				a = 0;
		}
		if (a==DAD_CLASSNAME.size())
		{
			break;
		}
	}
	if (OPEN_IN_OUT.eof())
	{
		true_OR_false = false;
		RET ;
	}
	OPEN_IN_OUT.close();
	ifstream IN(·��);
	ofstream OUT; 
	OUT.open(contents_(·��) + "/add__LAN" + ".xml");
	short int c_ = 0;
	while (c_!=c)
	{
		getline(IN, CLASS, '<');
		OUT <<CLASS<< '<';
		getline(IN, CLASS, '>');
		OUT << CLASS << '>';
		c_++;
	}
	OUT <<endl<< '<' << CLASSNAME << '>' <<endl << '<' << '/' << CLASSNAME << '>';
	while (getline(IN, CLASS))
	{
		OUT << CLASS<<endl;
	}
	OUT.close();
	IN.close();
	string name = contents_name(·��);
	remove(·��.c_str());
	rename("add__LAN.xml", name.c_str());
	
	true_OR_false = true;
	RET;
}
//ͨ������͸���IDֵ��XML�ļ�д��һ����
void XML::OUTXML_CLASS(const string DAD_CLASSNAME, const string DAD_ID, const string CLASSNAME)
{
	fstream OPEN_IN_OUT(·��);
	string CLASS;
	short int c = 0;
	short int a = 0;
	while (!OPEN_IN_OUT.eof())
	{
	a1:
		if (OPEN_IN_OUT.eof())
		{
			true_OR_false = false;
			return ;
		}
		getline(OPEN_IN_OUT, CLASS, '<');
		getline(OPEN_IN_OUT, CLASS, '>');
		c++;
		if (CLASS.size()<DAD_CLASSNAME.size()+DAD_ID.size())
		{
			goto a1;
		}
		for (short int i = 0; i < DAD_CLASSNAME.size(); i++)
		{
			if (CLASS[i] == DAD_CLASSNAME[i])
				a++;
			else
				a = 0;
		}
		cout << a << "\t" << DAD_CLASSNAME.size() << endl;
		if (a == DAD_CLASSNAME.size())
		{
			break;
		}
	}
	if (OPEN_IN_OUT.eof())
	{
		true_OR_false = false;
		RET;
	}
	if (CLASS.size()<DAD_ID.size())
	{
		goto a1;
	}
	for (short int i = 0; i < CLASS.size(); i++)	{
		if (CLASS[i] == '"') {
			short int ass = 0;
			short int i_p = i+1 ;
			for (short int z = 0; z < DAD_ID.size(); z++){
				cout << CLASS[i_p] << "\t" << DAD_ID[z] << endl;
				if (CLASS[i_p]==DAD_ID[z]){
					ass++;
				}
				else
				{
					cout << ass << "\t" << DAD_ID.size() << endl;
					goto a1;
				}
				i_p++;
			}
			if (ass == DAD_ID.size())
			{
				goto a2;
			}
		}
	}
	goto a1;
	a2:
	OPEN_IN_OUT.close();
	ifstream IN(·��);
	ofstream OUT;
	OUT.open(contents_(·��) + "/add__LAN" + ".xml");
	short int c_ = 0;
	while (c_ != c)
	{
		getline(IN, CLASS, '<');
		OUT << CLASS << '<';
		getline(IN, CLASS, '>');
		OUT << CLASS << '>';
		c_++;
	}
	OUT << endl << '<' << CLASSNAME << '>' << endl << '<' << '/' << CLASSNAME << '>';
	while (getline(IN, CLASS))
	{
		OUT << CLASS << endl;
	}
	OUT.close();
	IN.close();
	string name = contents_name(·��);
	remove(·��.c_str());
	rename("add__LAN.xml", name.c_str());

	true_OR_false = true;
	RET;
}
//ͨ��������XML�ļ�д��һ������ŵ���
void XML::OUTXML_CLASS(const string DAD_CLASSNAME, const string CLASS_ID_NAME, const string CLASS_ID, const string CLASSNAME)
{
	fstream OPEN_IN_OUT(·��);
	string CLASS;
	short int c = 0;
	short int a = 0;
	while (!OPEN_IN_OUT.eof())
	{
		getline(OPEN_IN_OUT, CLASS, '<');
		getline(OPEN_IN_OUT, CLASS, '>');
		c++;
		for (short int i = 0; i < DAD_CLASSNAME.size(); i++)
		{
			if (CLASS[i] == DAD_CLASSNAME[i])
				a++;
			else
				a = 0;
		}
		if (a == DAD_CLASSNAME.size())
		{
			break;
		}
	}
	if (OPEN_IN_OUT.eof())
	{
		true_OR_false = false;
		RET;
	}
	OPEN_IN_OUT.close();
	ifstream IN(·��);
	ofstream OUT;
	OUT.open(contents_(·��) + "/add__LAN" + ".xml");
	short int c_ = 0;
	while (c_ != c)
	{
		getline(IN, CLASS, '<');
		OUT << CLASS << '<';
		getline(IN, CLASS, '>');
		OUT << CLASS << '>';
		c_++;
	}
	OUT << endl << '<' << CLASSNAME<<' '<<CLASS_ID_NAME<<'='<<'"'<<CLASS_ID<<'"' << '>' << endl << '<' << '/' << CLASSNAME << '>';
	while (getline(IN, CLASS))
	{
		OUT << CLASS << endl;
	}
	OUT.close();
	IN.close();
	string name = contents_name(·��);
	remove(·��.c_str());
	rename("add__LAN.xml", name.c_str());

	true_OR_false = true;
	RET;
}
//ͨ������͸���IDֵ��XML�ļ�д��һ������ŵ���
void XML::OUTXML_CLASS(const string DAD_CLASSNAME, const string DAD_ID, const string CLASS_ID_NAME, const string CLASS_ID, const string CLASSNAME)
{
	fstream OPEN_IN_OUT(·��);
	string CLASS;
	short int c = 0;
	short int a = 0;
	while (!OPEN_IN_OUT.eof())
	{
	a1:
		if (OPEN_IN_OUT.eof())
		{
			true_OR_false = false;
			return;
		}
		getline(OPEN_IN_OUT, CLASS, '<');
		getline(OPEN_IN_OUT, CLASS, '>');
		c++;
		if (CLASS.size() < DAD_CLASSNAME.size() + DAD_ID.size())
		{
			goto a1;
		}
		for (short int i = 0; i < DAD_CLASSNAME.size(); i++)
		{
			if (CLASS[i] == DAD_CLASSNAME[i])
				a++;
			else
				a = 0;
		}
		cout << a << "\t" << DAD_CLASSNAME.size() << endl;
		if (a == DAD_CLASSNAME.size())
		{
			break;
		}
	}
	if (OPEN_IN_OUT.eof())
	{
		true_OR_false = false;
		RET;
	}
	if (CLASS.size() < DAD_ID.size())
	{
		goto a1;
	}
	for (short int i = 0; i < CLASS.size(); i++) {
		if (CLASS[i] == '"') {
			short int ass = 0;
			short int i_p = i + 1;
			for (short int z = 0; z < DAD_ID.size(); z++) {
				cout << CLASS[i_p] << "\t" << DAD_ID[z] << endl;
				if (CLASS[i_p] == DAD_ID[z]) {
					ass++;
				}
				else
				{
					cout << ass << "\t" << DAD_ID.size() << endl;
					goto a1;
				}
				i_p++;
			}
			if (ass == DAD_ID.size())
			{
				goto a2;
			}
		}
	}
	goto a1;
a2:
	OPEN_IN_OUT.close();
	ifstream IN(·��);
	ofstream OUT;
	OUT.open(contents_(·��) + "/add__LAN" + ".xml");
	short int c_ = 0;
	while (c_ != c)
	{
		getline(IN, CLASS, '<');
		OUT << CLASS << '<';
		getline(IN, CLASS, '>');
		OUT << CLASS << '>';
		c_++;
	}
	OUT << endl << '<' << CLASSNAME<<' '<<CLASS_ID_NAME<<'='<<'"'<<CLASS_ID<<'"' << '>' << endl << '<' << '/' << CLASSNAME << '>';
	while (getline(IN, CLASS))
	{
		OUT << CLASS << endl;
	}
	OUT.close();
	IN.close();
	string name = contents_name(·��);
	remove(·��.c_str());
	rename("add__LAN.xml", name.c_str());

	true_OR_false = true;
	RET;
}
//����д��һ��������������
void XML::OUTXML_SHUXING(const string DAD_CLASSNAME, const string SHUXINGNAME, const string SHUXING)
{
		fstream OPEN_IN_OUT(·��);
		string CLASS;
		short int c = 0;
		short int a = 0;
		while (!OPEN_IN_OUT.eof())
		{
			getline(OPEN_IN_OUT, CLASS, '<');
			getline(OPEN_IN_OUT, CLASS, '>');
			c++;
			for (short int i = 0; i < DAD_CLASSNAME.size(); i++)
			{
				if (CLASS[i] == DAD_CLASSNAME[i])
					a++;
				else
					a = 0;
			}
			if (a == DAD_CLASSNAME.size())
			{
				break;
			}
		}
		if (OPEN_IN_OUT.eof())
		{
			true_OR_false = false;
			RET;
		}
		OPEN_IN_OUT.close();
		ifstream IN(·��);
		ofstream OUT;
		OUT.open(contents_(·��) + "/add__LAN" + ".xml");
		short int c_ = 0;
		while (c_ != c)
		{
			getline(IN, CLASS, '<');
			OUT << CLASS << '<';
			getline(IN, CLASS, '>');
			OUT << CLASS << '>';
			c_++;
		}
		OUT << endl << '<' << SHUXINGNAME << '>' <<SHUXING << '<' << '/' <<SHUXINGNAME << '>';
		while (getline(IN, CLASS))
		{
			OUT << CLASS << endl;
		}
		OUT.close();
		IN.close();
		string name = contents_name(·��);
		remove(·��.c_str());
		rename("add__LAN.xml", name.c_str());

		true_OR_false = true;
		RET;
	
}
//�����ŵĸ���дһ��������������
void XML::OUTXML_SHUXING(const string DAD_CLASSNAME, const string DAD_ID, const string SHUXINGNAME, const string SHUXING)      
{
	fstream OPEN_IN_OUT(·��);
	string CLASS;
	short int c = 0;
	short int a = 0;
	while (!OPEN_IN_OUT.eof())
	{
	a1:
		if (!OPEN_IN_OUT.eof())
		{
			true_OR_false = false;
			return;
		}
		getline(OPEN_IN_OUT, CLASS, '<');
		getline(OPEN_IN_OUT, CLASS, '>');
		c++;
		if (CLASS.size() < DAD_CLASSNAME.size() + DAD_ID.size())
		{
			goto a1;
		}
		for (short int i = 0; i < DAD_CLASSNAME.size(); i++)
		{
			if (CLASS[i] == DAD_CLASSNAME[i])
				a++;
			else
				a = 0;
		}
		cout << a << "\t" << DAD_CLASSNAME.size() << endl;
		if (a == DAD_CLASSNAME.size())
		{
			break;
		}
	}
	if (OPEN_IN_OUT.eof())
	{
		true_OR_false = false;
		RET;
	}
	if (CLASS.size() < DAD_ID.size())
	{
		goto a1;
	}
	for (short int i = 0; i < CLASS.size(); i++) {
		if (CLASS[i] == '"') {
			short int ass = 0;
			short int i_p = i + 1;
			for (short int z = 0; z < DAD_ID.size(); z++) {
				cout << CLASS[i_p] << "\t" << DAD_ID[z] << endl;
				if (CLASS[i_p] == DAD_ID[z]) {
					ass++;
				}
				else
				{
					cout << ass << "\t" << DAD_ID.size() << endl;
					goto a1;
				}
				i_p++;
			}
			if (ass == DAD_ID.size())
			{
				goto a2;
			}
		}
	}
	goto a1;
a2:
	OPEN_IN_OUT.close();
	ifstream IN(·��);
	ofstream OUT;
	OUT.open(contents_(·��) + "/add__LAN" + ".xml");
	short int c_ = 0;
	while (c_ != c)
	{
		getline(IN, CLASS, '<');
		OUT << CLASS << '<';
		getline(IN, CLASS, '>');
		OUT << CLASS << '>';
		c_++;
	}
	OUT << endl << '<' << SHUXINGNAME << '>' << SHUXING << '<' << '/' << SHUXINGNAME << '>';
	while (getline(IN, CLASS))
	{
		OUT << CLASS << endl;
	}
	OUT.close();
	IN.close();
	string name = contents_name(·��);
	remove(·��.c_str());
	rename("add__LAN.xml", name.c_str());

	true_OR_false = true;
	RET;
}
//����д��һ������������������
void XML::OUTXML_SHUXING(const string DAD_CLASSNAME, const string SHUXINGNAME, const string SHUXING_ID_NAME, const string SHUXING_ID, const string SHUXING)

{
	fstream OPEN_IN_OUT(·��);
	string CLASS;
	short int c = 0;
	short int a = 0;
	while (!OPEN_IN_OUT.eof())
	{
		getline(OPEN_IN_OUT, CLASS, '<');
		getline(OPEN_IN_OUT, CLASS, '>');
		c++;
		for (short int i = 0; i < DAD_CLASSNAME.size(); i++)
		{
			if (CLASS[i] == DAD_CLASSNAME[i])
				a++;
			else
				a = 0;
		}
		if (a == DAD_CLASSNAME.size())
		{
			break;
		}
	}
	if (OPEN_IN_OUT.eof())
	{
		true_OR_false = false;
		RET;
	}
	OPEN_IN_OUT.close();
	ifstream IN(·��);
	ofstream OUT;
	OUT.open(contents_(·��) + "/add__LAN" + ".xml");
	short int c_ = 0;
	while (c_ != c)
	{
		getline(IN, CLASS, '<');
		OUT << CLASS << '<';
		getline(IN, CLASS, '>');
		OUT << CLASS << '>';
		c_++;
	}
	OUT << endl << '<' << SHUXINGNAME <<' '<<SHUXING_ID_NAME<<'='<<'"'<<SHUXING_ID<<'"' << '>' << SHUXING << '<' << '/' << SHUXINGNAME << '>';
	while (getline(IN, CLASS))
	{
		OUT << CLASS << endl;
	}
	OUT.close();
	IN.close();
	string name = contents_name(·��);
	remove(·��.c_str());
	rename("add__LAN.xml", name.c_str());

	true_OR_false = true;
	RET;

}
//�����ŵĸ���дһ������������������
void XML::OUTXML_SHUXING(const string DAD_CLASSNAME, const string DAD_ID, const string SHUXINGNAME, const string SHUXING_ID_NAME, const string SHUXING_ID, const string SHUXING)
{
	fstream OPEN_IN_OUT(·��);
	string CLASS;
	short int c = 0;
	short int a = 0;
	while (!OPEN_IN_OUT.eof())
	{
	a1:
		if (OPEN_IN_OUT.eof())
		{
			true_OR_false = false;
			return;
		}
		getline(OPEN_IN_OUT, CLASS, '<');
		getline(OPEN_IN_OUT, CLASS, '>');
		c++;
		if (CLASS.size() < DAD_CLASSNAME.size() + DAD_ID.size())
		{
			goto a1;
		}
		for (short int i = 0; i < DAD_CLASSNAME.size(); i++)
		{
			if (CLASS[i] == DAD_CLASSNAME[i])
				a++;
			else
				a = 0;
		}
		cout << a << "\t" << DAD_CLASSNAME.size() << endl;
		if (a == DAD_CLASSNAME.size())
		{
			break;
		}
	}
	if (OPEN_IN_OUT.eof())
	{
		true_OR_false = false;
		RET;
	}
	if (CLASS.size() < DAD_ID.size())
	{
		goto a1;
	}
	for (short int i = 0; i < CLASS.size(); i++) {
		if (CLASS[i] == '"') {
			short int ass = 0;
			short int i_p = i + 1;
			for (short int z = 0; z < DAD_ID.size(); z++) {
				cout << CLASS[i_p] << "\t" << DAD_ID[z] << endl;
				if (CLASS[i_p] == DAD_ID[z]) {
					ass++;
				}
				else
				{
					cout << ass << "\t" << DAD_ID.size() << endl;
					goto a1;
				}
				i_p++;
			}
			if (ass == DAD_ID.size())
			{
				goto a2;
			}
		}
	}
	goto a1;
a2:
	OPEN_IN_OUT.close();
	ifstream IN(·��);
	ofstream OUT;
	OUT.open(contents_(·��) + "/add__LAN" + ".xml");
	short int c_ = 0;
	while (c_ != c)
	{
		getline(IN, CLASS, '<');
		OUT << CLASS << '<';
		getline(IN, CLASS, '>');
		OUT << CLASS << '>';
		c_++;
	}
	OUT << endl << '<' << SHUXINGNAME<<' '<<SHUXING_ID_NAME<<'='<<'"'<<SHUXING_ID<<'"' << '>' << SHUXING << '<' << '/' << SHUXINGNAME << '>';
	while (getline(IN, CLASS))
	{
		OUT << CLASS << endl;
	}
	OUT.close();
	IN.close();
	string name = contents_name(·��);
	remove(·��.c_str());
	rename("add__LAN.xml", name.c_str());

	true_OR_false = true;
	RET;
}
//ɾ�����ļ�ͷ���������(Ԫ��/��}
void XML::OUTXML_DELETE(const string YUANNAME)
{
	ifstream IN(·��);
	string NAME;
	short int c_ = 0;
	short int c=0;
	bool cccc=false;
	while (!IN.eof())
	{
		getline(IN, NAME, '<');
		getline(IN, NAME, '>');
		c++;
		if (cccc == false)
		{
			if (NAME.size() < YUANNAME.size())
			{
				continue;
			}
			short int OHYES = 0;
			for (short int i = 0; i < YUANNAME.size(); i++)
			{
				if (NAME[i] == YUANNAME[i])
				{
					OHYES++;
				}
			}
			if (OHYES == YUANNAME.size())
			{
				c_ = c;
				cccc = true;
			}
		}
		else
		{
			if (NAME=='/'+YUANNAME)
			{
				break;
			}
		}
	}
	if (IN.eof())
	{
		true_OR_false = false;
		return;
	}
	IN.close();
	IN.open(·��);
	short int _c = 0;
	ofstream OUT;
	OUT.open(contents_(·��) + "/add__LAN" + ".xml",ios::out);
	bool xxx = false;
	while (!IN.eof())
	{
		_c++;
		if (_c - 1 == c)
		{
			while (getline(IN, NAME))
			{
				OUT << NAME<<endl;
			}
			break;
		}
		if (_c == c_)
		{
			xxx = true;
		}
		if (getline(IN, NAME, '<')) {
			if (xxx == false)
				OUT << NAME << '<';
		}
		if (getline(IN, NAME, '>'))
		{
			if (xxx == false)
				OUT << NAME << '>';
		}
		
	}
	OUT.close();
	IN.close();
	string name = contents_name(·��);
	remove(·��.c_str());
	rename("add__LAN.xml", name.c_str());
	true_OR_false = true;
}
//ɾ������ͷ���������(Ԫ��/��}
void XML::OUTXML_DELETE(const string DAD_CLASSNAME, const string YUANNAME)

{
	ifstream IN(·��);
	string NAME;
	short int c_ = 0;
	short int c = 0;
	bool cccc = false;
	while (!IN.eof())
	{
		getline(IN, NAME, '<');
		getline(IN, NAME, '>');
		c++;
		if (NAME>=DAD_CLASSNAME)
		{
			int o = 0;
			for (short int i = 0; i < DAD_CLASSNAME.size(); i++)
			{
				if (NAME[i]==DAD_CLASSNAME[i])
				{
					o++;
				}
			}
			if (o==DAD_CLASSNAME.size())
			{
				break;
			}
		}
	}if (IN.eof())
	{
		true_OR_false = false;
		return;
	}
	while (!IN.eof())
	{
		getline(IN, NAME, '<');
		getline(IN, NAME, '>');
		c++;
		if (cccc == false)
		{
			if (NAME.size() < YUANNAME.size())
			{
				continue;
			}
			short int OHYES = 0;
			for (short int i = 0; i < YUANNAME.size(); i++)
			{
				if (NAME[i] == YUANNAME[i])
				{
					OHYES++;
				}
			}
			if (OHYES == YUANNAME.size())
			{
				c_ = c;
				cccc = true;
			}
		}
		else
		{
			if (NAME == '/' + YUANNAME)
			{
				break;
			}
		}
	}
	if (IN.eof())
	{
		true_OR_false = false;
		return;
	}
	IN.close();
	IN.open(·��);
	short int _c = 0;
	ofstream OUT;
	OUT.open(contents_(·��) + "/add__LAN" + ".xml", ios::out);
	bool xxx = false;
	while (!IN.eof())
	{
		_c++;
		if (_c - 1 == c)
		{
			while (getline(IN, NAME))
			{
				OUT << NAME << endl;
			}
			break;
		}
		if (_c == c_)
		{
			xxx = true;
		}
		if (getline(IN, NAME, '<')) {
			if (xxx == false)
				OUT << NAME << '<';
		}
		if (getline(IN, NAME, '>'))
		{
			if (xxx == false)
				OUT << NAME << '>';
		}

	}
	OUT.close();
	IN.close();
	string name = contents_name(·��);
	remove(·��.c_str());
	rename("add__LAN.xml", name.c_str());
	true_OR_false = true;
}
//ɾ��������ͷ�������������(Ԫ��/��}
void XML::OUTXML_DELETE(const string DAD_CLASSNAME,const string DAD_ID, const string YUANNAME)

{
	ifstream IN(·��);
	string NAME;
	short int c_ = 0;
	short int c = 0;
	bool cccc = false;
	while (!IN.eof())
	{a1:
		getline(IN, NAME, '<');
		getline(IN, NAME, '>');
		c++;
		if (NAME.size() > DAD_CLASSNAME.size()+DAD_ID.size())
		{
			int o = 0;
			for (short int i = 0; i < DAD_CLASSNAME.size(); i++)
			{
				if (NAME[i] == DAD_CLASSNAME[i])
				{
					o++;
				}
			}
			if (o == DAD_CLASSNAME.size())
			{
				break;
			}
		}
	}if (IN.eof())
	{
		true_OR_false = false;
		return;
	}
	short p = 0;
	for (short int i = 0; i < NAME.size(); i++)
	{
		if (NAME[i]=='"')
		{
			for (short int z = i+1; z < NAME.size(); z++)
			{
				if (NAME[z] != '"') {
					p++;
				}
				else if(NAME[z]=='"')
				{
					if (p==DAD_ID.size())
					{
						p = 0;
						for (short int xxs = i + 1; xxs < NAME.size(); xxs++)
						{
							if (NAME[xxs]==DAD_ID[p])
							{
								p++;
							}
						}
						if (p==DAD_ID.size())
						{
							goto a2;
						}
					}
				}
			}
		}
	}a2:
	if (p!=DAD_ID.size())
	{
		goto a1;
	}
	while (!IN.eof())
	{
		getline(IN, NAME, '<');
		getline(IN, NAME, '>');
		c++; 
		if (NAME=='/'+DAD_CLASSNAME)
		{
			goto a1;
		}
		if (cccc == false)
		{
			if (NAME.size() < YUANNAME.size())
			{
				continue;
			}
			short int OHYES = 0;
			for (short int i = 0; i < YUANNAME.size(); i++)
			{
				if (NAME[i] == YUANNAME[i])
				{
					OHYES++;
				}
			}
			if (OHYES == YUANNAME.size())
			{
				c_ = c;
				cccc = true;
			}
		}
		else
		{
			if (NAME == '/' + YUANNAME)
			{
				break;
			}
		}
	}
	if (IN.eof())
	{
		true_OR_false = false;
		return;
	}
	IN.close();
	IN.open(·��);
	short int _c = 0;
	ofstream OUT;
	OUT.open(contents_(·��) + "/add__LAN" + ".xml", ios::out);
	bool xxx = false;
	while (!IN.eof())
	{
		_c++;
		if (_c - 1 == c)
		{
			while (getline(IN, NAME))
			{
				OUT << NAME << endl;
			}
			break;
		}
		if (_c == c_)
		{
			xxx = true;
		}
		if (getline(IN, NAME, '<')) {
			if (xxx == false)
				OUT << NAME << '<';
		}
		if (getline(IN, NAME, '>'))
		{
			if (xxx == false)
				OUT << NAME << '>';
		}

	}
	OUT.close();
	IN.close();
	string name = contents_name(·��);
	remove(·��.c_str());
	rename("add__LAN.xml", name.c_str());
	true_OR_false = true;
}

