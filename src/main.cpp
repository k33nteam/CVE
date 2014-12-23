#include <Common/usr_common.h>
#include <Common/exploitation/vuln.h>
#include "exploitation/exploit.h"

//#include ""//include your cve (exploit) code

//helper, pattern of write-where partialy what class of vuln
//CExploit -> implement by your own ;)
class CCustomCve :
	public IVuln
{
	CExploit m_exploit;
	
	//CKernelInfo usefull mainly for win7 and later
	//but still comes in hand when you do kernel escape ...
	CKernelInfo m_info; 
public:
	CCustomCve() :
		m_exploit(*this)
	{
	}

	__checkReturn
	bool
	Exploitation() override
	{
		//you vuln exploitation comes here
		printf("dummy");

		//do kernel escape
		m_exploit.HalDispatchExploitTech();

		return false;
	}
	
	__checkReturn
	bool
	WriteSomePtrToKernel(
		__in void* addr,
		__in size_t ptr
		) override
	{
		return false;
	}
};

extern "C"
void
exploit()
{
	printf("\nSTART\n");

	CCustomCve cve;
	cve.Exploitation();
	//you code place here ...

	printf("\nFINISH\n");
}
