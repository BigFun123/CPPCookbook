//#pragma once

class FString {
	CString _str;

public:
	FString(const char* c);
	CString GetValue();
	void SetValue(CString&);
	void SetValue(char*);

	LPCTSTR operator << (CString& s);
	void operator = (CString& s);
	CString operator = (const char* c);
};
