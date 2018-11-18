#ifndef COMMONTYPE_H
#define COMMONTYPE_H

#include<QString>
#include <QDebug>
#include<QDataStream>

struct DynamicLibInfo
{
    short       dynamicLibID;
    QString     dynamicLibName;
    QString     dynamicLibPath;
};

struct TestPacket
{
    int       testID;
    QString     isOk;

    friend QDataStream &operator<<(QDataStream &out, const TestPacket &data)
    {
        out << data.testID
            << data.isOk;

        return out;
    }

    friend QDataStream &operator>>(QDataStream &in, TestPacket &data)
    {
        in >> data.testID
           >> data.isOk;

        return in;
    }
};

//注释规范

//源文件头部注释
/*************************************************
Copyright:bupt
Author:
Date:2010-08-25
Description:描述主要实现的功能
**************************************************/

//函数头部注释
/*************************************************
Function:       // 函数名称
Description:    // 函数功能、性能等的描述
Calls:          // 被本函数调用的函数清单
Table Accessed: // 被访问的表（此项仅对于牵扯到数据库操作的程序）
Table Updated: // 被修改的表（此项仅对于牵扯到数据库操作的程序）
Input:          // 输入参数说明，包括每个参数的作
                  // 用、取值说明及参数间关系。
Output:         // 对输出参数的说明。
Return:         // 函数返回值的说明
Others:         // 其它说明
*************************************************/

//数据结构声明的注释(包括数组、结构、类、枚举等)
/* sccp interface with sccp user primitive message name */
//enum SCCP_USER_PRIMITIVE
//{
//    N_UNITDATA_IND, /* sccp notify sccp user unit data come */
//    N_NOTICE_IND,   /* sccp notify user the No.7 network can not */
//                    /* transmission this message */
//    N_UNITDATA_REQ, /* sccp user's unit data transmission request*/
//};
#endif // COMMONTYPE_H
