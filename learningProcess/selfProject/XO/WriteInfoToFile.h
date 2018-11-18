#ifndef WRITEINFOTOFILE_H
#define WRITEINFOTOFILE_H

#include <QXmlStreamReader>
#include <QFile>
#include <QMap>
#include <QString>

#include"commonType.h"
#include"commonMsg.h"
class WriteInfoToFile
{
public:
    WriteInfoToFile();

    void writeInfoToXml();
    bool readInfoFromXml();
private:
    QMap<int,DynamicLibInfo>      m_dynamicLibInfoMap;

};

#endif // WRITEINFOTOFILE_H
