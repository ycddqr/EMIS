#include "manager_mode_impl.h"
#include "emis.h"

void ManagerModeImpl::load(vector<Manager>& mgrArr)
{
	ifstream ifs(DATA_MGR_PATH,ios::in|ios::binary);
	if(!ifs) return;
	
	for(;;)
	{
		Manager mgr;
		ifs.read((char*)&mgr,sizeof(mgr));
		if(ifs.fail()) break;
		mgrArr.push_back(mgr);
	}
	ifs.close();
}

void ManagerModeImpl::save(vector<Manager>& mgrArr)
{
	ofstream ofs(DATA_MGR_PATH,ios::out|ios::trunc|ios::binary);
	if(!ofs) return;
	for(size_t i = 0; i < mgrArr.size(); i++)
	{
		ofs.write((const char*)&mgrArr[i],sizeof(mgrArr[i]));
	}
	ofs.close();
}

