#pragma once
#include <locale.h>
class CFileOperation
{
public:
	CFileOperation(void);
	CFileOperation(CString);
	~CFileOperation(void);
	BOOL addProductName(CString s);
	CString readProductName();
	void open(CString);
private:
	CStdioFile mFile;
	CFileException mExcept;
	int index;
	int count;
	CString path;
};

