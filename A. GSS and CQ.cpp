/*
	data:2018.04.15
	author:gsw
	link:http://arena.whuacm.vo-ov.cn/contest/index.html
	author£ºgsw
	account:team417
	password:6MRJBNZW
*/
#include<queue>
#include<math.h>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
#define ll long long
#define IO ios_base::sync_with_stdio(0);
map<char,string> ma;
void init()
{
	ma['A']="Alfa";ma['B']="Bravo";ma['C']="Charlie";ma['D']="Delta";ma['E']="Echo";ma['F']="Foxtrot";ma['G']="Golf";
	ma['H']="Hotel";ma['I']="India";ma['J']="Juliett";ma['K']="Kilo";ma['L']="Lima";ma['M']="Mike";ma['N']="November";
	ma['O']="Oscar";ma['P']="Papa";ma['Q']="Quebec";ma['R']="Romeo";ma['S']="Sierra";ma['T']="Tango";
	ma['U']="Uniform";ma['V']="Victor";ma['W']="Whiskey";ma['X']="Xray";ma['Y']="Yankee";ma['Z']="Zulu";
	ma['0']="Zero";ma['1']="One";ma['2']="Two";ma['3']="Three";ma['4']="Four";ma['5']="Five";
	ma['6']="Six";ma['7']="Seven";ma['8']="Eight";ma['9']="Nine";
}
int main()
{
	string a;string tem;
	init();
	while(cin>>a)
	{
		tem=a;
		
		transform(a.begin(), a.end(), a.begin(), ::toupper);
		cout<<"CQCQCQ tHis Is "<<a<<" ";
		for(int i=0;i<a.length();i++)
			cout<<ma[a[i]]<<" ";
		int flag=0;
		for(int i=0;i<tem.length();i++)
		{
			if(tem[i]>='a'&&tem[i]<='z')
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			cout<<a<<endl;
		}
		else
		{
			transform(a.begin(), a.end(), a.begin(), 1::tolower);
			cout<<a<<endl;
		}
	}
	return 0;
}
