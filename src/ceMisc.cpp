/////////////////////////////////////////////////////////////////////////////
// Name:         ceMisc.cpp
// Description:  utility module
// Author:       Yan Naing Aye
// Date:         2019 July 25
// Last Modified: 2020 October 29
/////////////////////////////////////////////////////////////////////////////
#include "ce/ceMisc.h"
using namespace std;
namespace ce {

// filter the string for alphanumeric characters only 
string ceMisc::alnum(string str)
{
	str.erase(remove_if(str.begin(), str.end(), [](char ch) {
		return !(
			(ch >= '0' && ch <= '9') ||
			(ch >= 'A' && ch <= 'Z') ||
			(ch >= 'a' && ch <= 'z')); }), str.end());
	return str;
}

// convert hex string to char vector
vector<char> ceMisc::hex2cvec(string str)
{
	vector<char> v;

	int n = str.length();
	for (int i = 0; i < n; i += 2) 
		v.push_back((char)stoi(str.substr(i, 2), NULL, 16));
	return v;
}

// convert char vector to hex string
string ceMisc::cvec2hex(vector<char> bv) {
	ostringstream ss;
	unsigned int u;
	for (char& c : bv) {
		u = (unsigned char)c;
		ss << setfill('0') << setw(2) << uppercase << hex << u << " ";
	}
	return ss.str();
}

// convert char vector to string
string ceMisc::cvec2str(vector<char> bv) {
	ostringstream ss;
	for (char& c : bv) {
		ss << c;
	}
	return ss.str();
}


// character vector to char*
void ceMisc::cvec2cptr(vector<char>& v, char*& cstr, int& n) {
	n = (int)v.size();
	cstr = v.data(); // reinterpret_cast<char*>(v.data());
}

// char* to char vector
vector<char> ceMisc::cptr2cvec(char* cstr,int n) {
	vector<char> v(cstr, cstr + n);
	return v;
}

// convert char* to string
string ceMisc::cptr2str(char* cstr, int n) {
	ostringstream ss;
	for (int i = 0; i < n;i++) {
		ss << cstr[i];
	}
	return ss.str();
}

// string to char vector
vector<char> ceMisc::str2cvec(string str) {
	vector<char> v(str.begin(), str.end());
	return v;
}

string ceMisc::f2s(float f, int n) {
	stringstream ss;
	ss<<fixed<<setprecision(n)<<f;
	return ss.str();
}

vector<string> ceMisc::splitStr(string str, string delimiter)
{
	size_t pos = 0;
	vector<string> tokens;
	while ((pos = str.find(delimiter)) != string::npos) {
    		tokens.push_back(str.substr(0, pos));
		str.erase(0, pos + delimiter.length());
	}
	tokens.push_back(str);
	return tokens;
}

// void ceWx::printTime()
// {
// 	wxDateTime* wdt;
// 	wdt = new wxDateTime();
// 	wdt->SetToCurrent();
// 	wxString wstr = wdt->Format(wxT("%Y-%m-%d %H:%M:%S"), wxDateTime::Local);
// 	// wxPuts(wstr);
// 	std::string str = wstr.ToStdString();
// 	printf("%s\n",str.c_str());
// }

// wxImage util::wx_from_mat(Mat &img) {
//     Mat im2;
//     if(img.channels()==1){cvtColor(img,im2,COLOR_GRAY2RGB);}
// 	else if (img.channels() == 4) { cvtColor(img, im2, COLOR_BGRA2RGB);}
//     else {cvtColor(img,im2,COLOR_BGR2RGB);}
// 	long imsize = im2.rows*im2.cols*im2.channels();
//     wxImage wx(im2.cols, im2.rows,(unsigned char*)malloc(imsize), false);
// 	unsigned char* s=im2.data;
// 	unsigned char* d=wx.GetData();
// 	for (long i = 0; i < imsize; i++) { d[i] = s[i];}
//     return wx;
// }

// Mat util::mat_from_wx(wxImage &wx) {
//     Mat im2(Size(wx.GetWidth(),wx.GetHeight()),CV_8UC3,wx.GetData());
//     cvtColor(im2,im2,COLOR_RGB2BGR);
//     return im2;
// }

} // namespace ce