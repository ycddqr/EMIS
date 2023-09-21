#include "service_mode_impl.h"
#include "emis.h"

void ServiceModeImpl::load(vector<Department>& deptArr)	//	加载部门、员工信息到 deptArr，empArr
{
	ifstream ifs(DATA_SRC_PATH);
	if(!ifs) return;
	Employee emp;
	int num = 0;
	for(;;)
	{
		Department dept;
		Employee emp;
		ifs >> dept >> num;
		if(!ifs.good()) break;
		for(int i = 0; i < num; i++)
		{
			ifs >> emp;
			dept.empArr.push_back(emp);
		}
		deptArr.push_back(dept);
	}
	ifs.close();
}

void ServiceModeImpl::save(vector<Department>& deptArr)
{
	ofstream ofs(DATA_SRC_PATH);
	if(!ofs) return;
	//	把deptArr和empArr都写入文件
	for(size_t i = 0; i < deptArr.size(); i++)
	{
		ofs << deptArr[i] << " " << deptArr[i].empArr.size() << endl;
		for(size_t j = 0; j < deptArr[i].empArr.size(); j++)
		{
			ofs << deptArr[i].empArr[j] << endl;
		}
	}
	ofs.close();
}

