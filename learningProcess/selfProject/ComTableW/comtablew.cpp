#include "comtablew.h"


ComTableW::ComTableW()
{
}

//为什么需要使用extern "C"呢？
//C++之父在设计C++之时，考虑到当时已经存在了大量的C代码，为了支持原来的C代码和已经写好C库，需要在C++中尽可能的支持C，而extern "C"就是其中的一个策略

extern  "C"  ComTableW* COMTABLEWSHARED_EXPORT HANDLE()
{
    return new ComTableW;
}
