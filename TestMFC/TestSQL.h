#pragma once
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

class TestSQL
{
public:
	int Test();
	void ShowSQLError(unsigned int handleType, const SQLHANDLE& handle);
};

