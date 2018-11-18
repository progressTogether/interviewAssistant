#ifndef WRITEINFOTOFILE_H
#define WRITEINFOTOFILE_H

#include <QXmlStreamReader>
#include <QFile>
#include <QMap>
#include <QString>

#include"commonType.h"
#include"commonMsg.h"
#include"commonMethod.h"
class WriteInfoToFile
{
public:
    WriteInfoToFile();

    void writeInfoToXml();
    bool readInfoFromXml();

    void testPacket( std::string msg);
private:
    QMap<int,DynamicLibInfo>      m_dynamicLibInfoMap;

};

#endif // WRITEINFOTOFILE_H
