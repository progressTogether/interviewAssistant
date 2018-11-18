#ifndef COMMONMETHOD_H
#define COMMONMETHOD_H
#include<QString>
#include<QDataStream>
#include<QBuffer>
#include<QByteArray>

/*************************************************
Function:       PackProStruct
Description:    复杂结构打包函数
Calls:
Table Accessed:
Table Updated:
Input:
    \param[in]  data　复杂的结构
    \param[in]  bLittleEndian　大小端，默认为小端
Return:         打包好的字节流
Others:        使用的时候，复杂结构需要重载 << 和 >>
*************************************************/
template<class T>
std::string PackProStruct( const T& data, const bool bLittleEndian = true )
{
    QByteArray serial_array;
    QBuffer    serial_buffer( &serial_array );
    serial_buffer.open(QIODevice::WriteOnly);
    QDataStream out_stream( &serial_buffer );
    out_stream.setByteOrder( bLittleEndian ? QDataStream::LittleEndian : QDataStream::BigEndian);

    out_stream << data;
    serial_buffer.close();
    std:string serial_std_string( serial_array.data(),serial_array.size() );

    return serial_std_string;
}

/*************************************************
Function:       UnPackProStruct
Description:    复杂结构解包接口
Input:
    \param[in]      msg　打包好的字节流
    \param[out]     data　复杂的结构
    \param[in]      bLittleEndian　大小端，默认为小端
Return:             void
Others:             使用的时候，复杂结构需要重载 << 和 >>
*************************************************/
template<class T>
void UnPackProStruct( const std::string& msg,T& data, const bool bLittleEndian = true )
{
    QByteArray  deserial_array( msg.c_str(),msg.size() );
    QBuffer     deserial_buffer( deserial_array );
    deserial_buffer.open( QIODevice::ReadOnly );
    QDataStream in_stream( &deserial_buffer );

    in_stream >> data;

    deserial_buffer.close();
}

#endif // COMMONMETHOD_H
