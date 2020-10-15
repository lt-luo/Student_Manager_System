/*
Author： L-Luo
Shenzhen University @2019
*/ 

#include <iostream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include<fstream>
#include<vector>
#include<list>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<iomanip>
#include<cstring> 
using namespace std;
class CStudent
{
	private:
		string name;
		string number;
		int age;
		string college;       //后期待加数据：性别 
		double GPA;
		string sex;
	public:
		CStudent(){}
		CStudent(string s_name,string s_college,string s_number,int s_age,double g,string se);
		bool operator<(CStudent &rp);
		friend istream &operator>>(istream &in,CStudent &stu);
		friend ostream &operator<<(ostream &out,CStudent &stu);
		operator string();
		double getgpa();
		void set();
		string getsex();
		string getcollege();
		friend bool cmp(CStudent &stu_1,CStudent &stu_2);
		friend void stu_find(vector<CStudent> &obj,vector<CStudent> &origin);
		friend bool operator==(const CStudent &stu1,const CStudent &stu2);
		friend void stu_modefication(vector<CStudent> &obj,CStudent &stu);	
};
CStudent::CStudent(string s_name,string s_college,string s_number,int s_age,double g,string se):
	name(s_name),college(s_college),number(s_number),age(s_age),sex(se),GPA(g)
	{}
CStudent::operator string()         //合并姓名，学号，年龄，学院     （有问题） 
{
	string all,str_na,str_ag;
	char ag[20]; 
//	str_na.assign(na);
	itoa(age,ag,10);
	str_ag.assign(ag);                  
	all=all+name+number+str_ag+college+sex;
	return all;
}
bool CStudent::operator<(CStudent &rp)
{
	return name<rp.name;
}
double CStudent::getgpa()
{
	return GPA;
}
string CStudent::getsex()
{
	return sex;
}
string CStudent::getcollege()
{
	return college;
}
bool operator==(const CStudent &stu1,const CStudent &stu2)
{
	if(stu1.name==stu2.name&&stu1.number==stu2.number&&stu1.age==stu2.age&&stu1.college==stu2.college&&stu1.sex==stu2.sex&&stu1.GPA==stu2.GPA)
	return true;
	return false;
}	
istream &operator>>(istream &in,CStudent &stu)
{
	 in>>stu.name>>stu.number>>stu.age>>stu.sex>>stu.college>>stu.GPA;
	 return in;
}
ostream &operator<<(ostream &out,CStudent &stu)
{
//	out<<setiosflags(ios::right);
	out<<'\t'<<'\t'<<stu.name;
	for(int i=0;i<(10-stu.name.length());i++)
	cout<<" ";
	out<<'\t'<<stu.number;
	out<<'\t'<<stu.age;
	out<<'\t'<<stu.sex;
	out<<'\t'<<stu.college;
	for(int i=0;i<(10-stu.college.length());i++)
	cout<<" ";
	out<<'\t'<<stu.GPA<<endl;
	return out;
}
void CStudent::set()
{
	char str[20];
	string str_new;
	
	cout<<"\t请输入修改的学生信息（不修改的输入'*'跳过）："<<endl;
	cout<<"\t修改学生姓名：";
	cin>>str; 
	if(strcmp(str,"*"))
	name=str_new.assign(str);
	cout<<endl;
	
	cout<<"\t修改学生学号：";
	cin>>str;
	if(strcmp(str,"*"))
	number=str_new.assign(str);
	cout<<endl;
	
	cout<<"\t修改学生年龄：";
	cin>>str;
	if(strcmp(str,"*"))
	age=atoi(str);
	cout<<endl;
	
	cout<<"\t修改学生学院：";
	cin>>str;
	if(strcmp(str,"*"))
	college=str_new.assign(str);
	cout<<endl;
	
	cout<<"\t修改学生性别：";
	cin>>str;
	if(strcmp(str,"*"))
	sex=str_new.assign(str);
	cout<<endl;
	
	cout<<"\t修改学生绩点：";
	cin>>str;
	if(strcmp(str,"*"))
	GPA=atof(str);
	cout<<endl;
}
class oneset
{
	public:
		string name;
		int number_boy;
		int number_girl;
		int number_tol;
		int number_gpa;
		oneset(string a="0",int nb=0,int ng=0,int nt=0,int gp=0):name(a),number_boy(nb),number_girl(ng),number_tol(nt),number_gpa(gp){}
};
void warning_title();
void find_warning();
void getdata(vector<CStudent> &obj);
void warning_error();
void warning_success(); 
void recover(vector<CStudent> &obj);
//
//排序 之cmp 
//
int sort_base;
int order;
bool cmp(CStudent &stu_1,CStudent &stu_2)
{
	if(order==1)                                  //升序 
	{
		if(sort_base==1)
		return stu_1.name<stu_2.name;
		else if(sort_base==2)
		return stu_1.age<stu_2.age;
		else if(sort_base==3)
		return stu_1.number<stu_2.number;
		else if(sort_base==4)
		return stu_1.college<stu_2.college;
		else if(sort_base==5)
		return stu_1.sex<stu_2.sex;
		else if(sort_base==6)
		return stu_1.GPA<stu_2.GPA;
	}
	else if(order==2)                            //降序 
	{
		if(sort_base==1)
		return stu_1.name>stu_2.name;
		else if(sort_base==2)
		return stu_1.age>stu_2.age;
		else if(sort_base==3)
		return stu_1.number>stu_2.number;
		else if(sort_base==4)
		return stu_1.college>stu_2.college;
		else if(sort_base==5)
		return stu_1.sex>stu_2.sex;
		else if(sort_base==6)
		return stu_1.GPA>stu_2.GPA;
	}
}
string comp_base,comp_sex;
bool comp(CStudent &a)
{
	return a.getcollege()==comp_base;
}
bool comp1(CStudent &a)
{
	return a.getcollege()==comp_base&&a.getsex()==comp_sex;
}
bool comp2(CStudent &a)
{
	return a.getcollege()==comp_base&&a.getgpa()>3.5;
}
void print(vector<CStudent> &obj)
{
	vector<oneset> x_axial;
	vector<oneset>::iterator x_it;
	vector<CStudent>::iterator it;
	int x_boy,x_girl,x_tol,x_gpa,max_num=0,cnt=0;
	oneset one_s;
	order=1;
	sort_base=4;
	sort(obj.begin(),obj.end(),cmp);
	
	
	for(it=obj.begin();it!=obj.end();)
	{
		comp_base=(*it).getcollege();
		x_tol=count_if(obj.begin(),obj.end(),comp);
		comp_sex="男";
		x_boy=count_if(obj.begin(),obj.end(),comp1);
		comp_sex="女";
		x_girl=count_if(obj.begin(),obj.end(),comp1);
		
		x_gpa=count_if(obj.begin(),obj.end(),comp2);
		
		if(x_tol>max_num)
		max_num=x_tol;
		
		one_s.name=comp_base;
		one_s.number_tol=x_tol;
		one_s.number_boy=x_boy;
		one_s.number_girl=x_girl;
		one_s.number_gpa=x_gpa;
		x_axial.push_back(one_s);
		it+=x_tol;
	}
	cout<<"\t\t学院\t人数\t男\t女\t成绩>3.5"<<endl;
	cout<<"\t\t-----------------------------------------"<<endl;
	for(x_it=x_axial.begin();x_it!=x_axial.end();x_it++)
	{	
		cout<<"\t\t"<<(*x_it).name<<"\t "<<(*x_it).number_tol<<"\t "<<(*x_it).number_boy<<"\t "<<(*x_it).number_girl<<"\t   "<<(*x_it).number_gpa<<endl;
		cout<<"\t\t-----------------------------------------"<<endl;
	}
}
//
//删除部分学生信息 
//
void stu_erase(vector<CStudent> &obj,vector<CStudent> &rst)
{
	list<CStudent> list_obj;
	list<CStudent>::iterator it_list;
	vector<CStudent>::iterator it;
	ofstream ou("backups.txt");

	for(it=obj.begin();it!=obj.end();it++)
	{
		list_obj.push_back(*it);
		ou<<(*it); 
	}
	ou.close();
	for(it=rst.begin();it!=rst.end();it++)
	{
		list_obj.remove(*it);
	}
	
	ofstream ocout("Student-Database.txt");
	for(it_list=list_obj.begin();it_list!=list_obj.end();it_list++)
	{
		ocout<<(*it_list);
	}
	ocout.close();
	getdata(obj);
}
// 
//查找
//	
void stu_find(vector<CStudent> &obj,vector<CStudent> &origin)
{
	string s_keyword,s_tofind;
	int i_keyword,cnt=1;
	double d_keyword,op_next,opcode;
	string k_ey; 
	vector<CStudent> result;
	vector<CStudent>::iterator it;
	vector<CStudent>::iterator it_result;
	
		find_warning();
		cin>>k_ey;
		if(k_ey=="0")                       //找关键字  
		{
			cout<<'\t'<<"请输入关键字"<<endl;
			cout<<'\t'; 
			cin>>s_keyword;
			warning_title();
			for(it=obj.begin();it!=obj.end();it++)
			{
				s_tofind=(string)(*it);
				if(s_tofind.find(s_keyword,0)!=-1)
				{
					cout<<*it;
					result.push_back(*it); 
				}
			}
		}
		else if(k_ey=="1")                 //找姓名 
		{
			cout<<'\t'<<"请输入姓名"<<endl; 
			cout<<'\t';
			cin>>s_keyword;
			warning_title();
			for(it=obj.begin();it!=obj.end();it++)
			{
				s_tofind=(*it).name;
				if(s_tofind.find(s_keyword,0)!=-1)
				{
					cout<<*it;
					result.push_back(*it); 
				}
			}
		}
		else if(k_ey=="2")               //找学号 
		{
			cout<<'\t'<<"请输入学号"<<endl;
			cout<<'\t';
			cin>>s_keyword;
			warning_title();
			for(it=obj.begin();it!=obj.end();it++)
			{
				s_tofind=(*it).number;
				if(s_tofind.find(s_keyword,0)!=-1)
				{
					cout<<*it;
					result.push_back(*it); 
				}
			}
		}
		else if(k_ey=="3")               //找年龄 
		{
			cout<<'\t'<<"请输入年龄"<<endl;
			cout<<'\t';
			cin>>i_keyword;
			warning_title();
			for(it=obj.begin();it!=obj.end();it++)
			{
				if(i_keyword==(*it).age)
				{
					cout<<*it;
					result.push_back(*it); 
				}
			}
		}
		else if(k_ey=="4")              //找学院 
		{
			cout<<'\t'<<"请输入学院"<<endl;
			cout<<'\t';
			cin>>s_keyword;
			warning_title();
			for(it=obj.begin();it!=obj.end();it++)
			{
				s_tofind=(*it).college;
				if(s_tofind.find(s_keyword,0)!=-1)
				{
					cout<<*it;
					result.push_back(*it); 
				}
			}
		}
		else if(k_ey=="5")              //找绩点 
		{
			cout<<'\t'<<"请输入绩点"<<endl;
			cout<<'\t';
			cin>>d_keyword;
			warning_title();
			for(it=obj.begin();it!=obj.end();it++)
			{
				if(d_keyword==(*it).GPA)
				{
					cout<<*it;
					result.push_back(*it); 
				}
			}
		}
		else if(k_ey=="6")
		{
			cout<<'\t'<<"请输入性别"<<endl;
			cout<<'\t';
			cin>>s_keyword;
			warning_title();
			 for(it=obj.begin();it!=obj.end();it++)
			{
				s_tofind=(*it).sex;
				if(s_tofind.find(s_keyword,0)!=-1)
				{
					cout<<*it;
					result.push_back(*it); 
				}
			}
		}
		else
		{
			warning_error();
			stu_find(obj,origin);
		}
		if(!result.empty())
		{
			cout<<endl;
			cout<<"\t输入1删除学生信息"<<endl;
			cout<<"\t输入2修改学生信息"<<endl;
			cout<<"\t输入3从结果中搜索"<<endl;
			cout<<"\t输入任意键退出搜索"<<endl;  
			cout<<'\t';         //
			cin>>opcode;
			if(opcode==1)
			{
				stu_erase(origin,result);
				warning_success();
			}
			else if(opcode==2)
			{
				cnt=1;
				ofstream ou("backups.txt");
				for(it=origin.begin();it!=origin.end();it++)
				{
					ou<<(*it);
				}
				ou.close();
				cout<<endl;
				
				for(it_result=result.begin();it_result!=result.end();it_result++)
				{
					for(it=origin.begin();it!=origin.end();it++)
					{
						if(*it==*it_result)
						{
							cout<<"\t修改第"<<cnt++<<"个学生信息"<<endl; 
							(*it).set();
							break;
						}
					}
				}
						ofstream ocout("Student-Database.txt");                                             //写入文件 
						for(it=origin.begin();it!=origin.end();it++)
						{
							ocout<<(*it);
						}
						ocout.close();
						warning_success();
			}
			else if(opcode==3)
			{
				stu_find(result,origin);
			}
			else
			{
				return;
			} 
		}
		else
		{
			cout<<"\t\tNOT FOUND!"<<endl;
			cout<<endl; 
		}
		return; 
} 
//
//获取学生数据 
//
void getdata(vector<CStudent> &obj)       //文件----------->>>>vector 
{
	ifstream icin("Student-Database.txt"); 
	CStudent stu;
	if(!icin)
	{
		cout<<"error"<<endl;
		exit(1);
	}
	if(!obj.empty())
	obj.clear();
	while(icin>>stu) 
	{
		obj.push_back(stu);
	}
	icin.close();
}
//
//增加学生数据 
//
void adddata(vector<CStudent> &obj)
{
	string stu_name,stu_number,stu_college,stu_sex;
	int   stu_age;
	double stu_gpa;
	cout<<"\t姓名：";
	cin>>stu_name;
	cout<<"\t学号：";
	cin>>stu_number;
	cout<<"\t年龄：";
	cin>>stu_age;
	cout<<"\t学院：";
	cin>>stu_college;
	cout<<"\t性别：";
	cin>>stu_sex;
	cout<<"\t绩点：";
	cin>>stu_gpa;
	CStudent stu(stu_name,stu_college,stu_number,stu_age,stu_gpa,stu_sex); 
	ofstream ocout("Student-Database.txt",ios::app);   //追加文件内容
	ocout<<stu;
	obj.push_back(stu);
	ocout.close();
}
double getaverage_gpa(vector<CStudent> &obj)
{
	double sum=0;
	vector<CStudent>::iterator it;
	for(it=obj.begin();it!=obj.end();it++)
	sum+=(*it).getgpa();
	return sum/obj.size();
} 
//
//输出学生信息 
// 
void warning_title();
void display(vector<CStudent> &obj)
{
//	sort(obj.begin(),obj.end());
	vector<CStudent>::iterator it;
	warning_title();
	for(it=obj.begin();it!=obj.end();it++)
	cout<<*it;
	cout<<'\t'<<'\t'<<"-------------------------------------------------------------------------"<<endl;
	cout<<'\t'<<'\t'<<"学生数                                                          "<<obj.size()<<endl;
	cout<<'\t'<<'\t'<<"-------------------------------------------------------------------------"<<endl;
	cout<<'\t'<<'\t'<<"平均绩点                                                        "<<getaverage_gpa(obj)<<endl;
	cout<<'\t'<<'\t'<<"-------------------------------------------------------------------------"<<endl;
	cout<<'\t'; 
}
//
//输出提示信息 
//
void warning()
{
	cout<<"\t\t\t-------------------学生信息管理系统-------------------"<<endl;
	cout<<'\t'<<"请选择你的操作"<<endl;
	cout<<'\t'<<"输入1查看整体学生信息"<<endl;                                                     //后期可简化成对整体（打印，排序），对单个操作（删除，修改，查看），单个过程中也可以加入排序 
	cout<<'\t'<<"输入2对学生信息操作"<<endl;
	cout<<'\t'<<"输入3增加学生信息"<<endl;
	cout<<'\t'<<"输入4还原"<<endl;
	cout<<'\t';
}
void warning_all()
{
	cout<<"\t\t\t-------------------学生信息管理系统-------------------"<<endl;
	cout<<'\t'<<"请选择你的操作"<<endl;
	cout<<'\t'<<"输入1列表查看所有学生信息"<<endl;                                                      
	cout<<'\t'<<"输入2选择学生排列方式查看"<<endl;
	cout<<'\t'<<"输入3查看总体信息"<<endl; 
	cout<<'\t';
}
void warning_part()
{
	cout<<"\t\t\t-------------------学生信息管理系统-------------------"<<endl;
	cout<<'\t'<<"请选择检索方式"<<endl; 
}
void warning_add()
{
	cout<<"\t\t\t-------------------学生信息管理系统-------------------"<<endl;
	cout<<"\t请输入学生相关信息"<<endl;
}
void sort_warning_order()
{
	cout<<"\t\t\t-------------------学生信息管理系统-------------------"<<endl;
	cout<<'\t'<<"请选择排序顺序"<<endl;
	cout<<'\t'<<"输入1升序"<<endl;
	cout<<'\t'<<"输入2降序"<<endl; 
	cout<<'\t';
}
void sort_warning_base()
{
	cout<<'\t'<<"请选择排列方式"<<endl;
	cout<<'\t'<<"输入1-->姓名"<<endl;
	cout<<'\t'<<"输入2-->年龄"<<endl;
	cout<<'\t'<<"输入3-->学号"<<endl;
	cout<<'\t'<<"输入4-->学院"<<endl;
	cout<<'\t'<<"输入5-->性别"<<endl;
	cout<<'\t'<<"输入6-->绩点"<<endl;
	cout<<"\t输入任意键默认方式排序"<<endl;
	cout<<'\t';	 
}
void find_warning()
{
	cout<<'\t'<<"输入0按关键字搜索"<<endl;
	cout<<'\t'<<"输入1按姓名搜索"<<endl;
	cout<<'\t'<<"输入2按学号搜索"<<endl;
	cout<<'\t'<<"输入3按年龄搜索"<<endl;
	cout<<'\t'<<"输入4按学院搜索"<<endl;
	cout<<'\t'<<"输入5按绩点搜索"<<endl;
	cout<<'\t'<<"输入6按性别搜索"<<endl; 
	cout<<'\t';
}
void warning_title()
{
	system("cls");
	cout<<'\t'<<'\t'<<"姓名    "<<'\t'<<"学号      "<<'\t'<<"年龄    "<<"性别 "<<'\t'<<"学院    "<<'\t'<<"平均绩点"<<endl;
	cout<<'\t'<<'\t'<<"-------------------------------------------------------------------------"<<endl; 
}
void warning_next()
{
//	cout<<'\t'<<'\t'<<"*********************************"<<endl;
	cout<<"\t输入1返回首页继续操作，输入任意键退出程序"<<endl;
	cout<<'\t';
}
void warning_error()
{
	cout<<endl; 
	cout<<'\t'<<"非法输入！"<<endl; 
}
//
//恢复 
//
void recover(vector<CStudent> &obj)
{
	int op;
	CStudent stu;
	ifstream in("backups.txt");
		if(!in)
		{
			cout<<"\t无法操作！"<<endl;
			exit(1);
		}
		else
		{
			ofstream ou("Student-Database.txt");
		 	while(in>>stu)
		 	ou<<stu;
		 	in.close();
		 	ou.close();
		}
	getdata(obj);
	cout<<endl;
	cout<<"\t还原成功！"<<endl;
} 
void warning_success()
{
	cout<<endl;
	cout<<"\t操作成功！"<<endl;
}

int main() 
{
	system("mode con cols=100 lines=60"); 
	vector<CStudent> student;
	vector<CStudent>::iterator it;
	getdata(student);
	string opcode,opcode2;
	int key;
	while(1)
	{
		warning();
		cin>>opcode;
		if(opcode=="1")
		{
			sort(student.begin(),student.end());
			system("cls");
			warning_all();
			cin>>opcode2;
			if(opcode2=="1")
			display(student);
			else if(opcode2=="2")
			{
				system("cls");
				sort_warning_order();
				cin>>order;
				sort_warning_base();
				cin>>sort_base;                                           //全局变量 
				sort(student.begin(),student.end(),cmp);
				display(student);
			}
			else if(opcode2=="3")                           // 
			{
				print(student); 
			}
			else
			{
				warning_error();
			} 
		} 
		else if(opcode=="2")
		{
			system("cls");
			warning_part();
			stu_find(student,student);	
		}
		else if(opcode=="3")
		{
			system("cls");
			warning_add();
			adddata(student);
			cout<<endl;                        //操作完成输出提示信息：完成!
			cout<<"\t添加完成！"<<endl; 
		}
		else if(opcode=="4")
		{
			recover(student);
		}
		else
		{
			warning_error(); 
		}
		
		//后续操作 
		
		warning_next();
		if(opcode=="1")
		cout<<'\t';
		
		cin>>opcode;
		if(opcode=="1")
		{
			system("cls");
		}
		else
		{
			break;
		}
		
	}

	return 0;
}
