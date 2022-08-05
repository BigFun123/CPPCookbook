#include <afxwin.h>

#include "FString.h"


//using namespace std;
/*
void operator << (ostream& COUT, FString& fstring) {
	COUT << "Value:" << fstring.GetValue() << endl;
};

void operator << (LPCTSTR& LP, FString& fstring) {
	LP = (LPCTSTR)fstring.GetValue();
};
*/

FString::FString(const char* c) {
	_str = c;
}

CString FString::GetValue() {
	return _str;
};

void FString::SetValue(CString& inp) {
	_str = inp;
}

void FString::SetValue(char* inp) {
	_str = inp;
}

CString FString:: operator = (const char* c) {
	_str = c;
	return (LPCTSTR)_str;
}

LPCTSTR FString:: operator << (CString& str) {
	_str = (LPCTSTR)&str;
	return str;
}
