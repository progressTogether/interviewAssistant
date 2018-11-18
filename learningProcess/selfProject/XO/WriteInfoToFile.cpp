#include "WriteInfoToFile.h"

WriteInfoToFile::WriteInfoToFile()
{
    DynamicLibInfo tmpInfo;
    for( int i = 1; i < 5;i++ )
    {
        tmpInfo.dynamicLibID = i;
        tmpInfo.dynamicLibName = "test";
        tmpInfo.dynamicLibPath = "testPath";
        m_dynamicLibInfoMap.insert(i,tmpInfo);
    }

}

void WriteInfoToFile::writeInfoToXml()
{
    QString strPath( CONFIG_FILE_PATH );
    QString strFile( "config.xml");
    strFile = strPath + strFile;
    QFile file(strFile);
    if(!file.open( QFile::WriteOnly | QFile::Text) )
    {
        qDebug() << QString("Cannot write file %1(%2).").arg(strFile).arg(file.errorString());
        return;
    }

    QXmlStreamWriter writer(&file);
    // writer.setCodec("GBK");  // XML 编码
    writer.setAutoFormatting(true); // 自动格式化
    writer.writeStartDocument("1.0", true);  // 开始文档（XML 声明）
    writer.writeComment(QString::fromLocal8Bit("XO框架的配置文件"));  // 注释

    writer.writeProcessingInstruction("xml-stylesheet type=\"text/css\" href=\"style.css\"");  // 处理指令
    writer.writeStartElement("Introductions");  // 开始根元素 <Introductions>
    writer.writeAttribute("Version", "1.0");  // 属性

    writer.writeStartElement("Introduction"); // 开始子元素 <Introduction>
    writer.writeTextElement(QString::fromLocal8Bit("作者"), QString::fromLocal8Bit("刘晓辉"));
    writer.writeTextElement(QString::fromLocal8Bit("ＱＱ"), "1406744100");
    writer.writeTextElement(QString::fromLocal8Bit("座右铭"), QString::fromLocal8Bit("Talk is cheap,Show me the code."));

    writer.writeComment(QString::fromLocal8Bit("动态加载.so,并完成各个.so插件的通信"));
    writer.writeComment(QString::fromLocal8Bit("一、可以通过配置文件加载对应的动态库"));  // 注释
    writer.writeComment(QString::fromLocal8Bit("二、动态库之间的交互"));  // 注释

    writer.writeEndElement(); // 结束子元素 </Introduction>
    writer.writeEndElement(); // 结束根元素 </Introductions>

    writer.writeStartElement("DynamicLibs");  // 开始根元素 <DynamicLibs>

    QMap<int,DynamicLibInfo>::iterator it;
    it = m_dynamicLibInfoMap.begin();
    QString tmpStr;
    int firstDyn = 0;
    for( ; it != m_dynamicLibInfoMap.end(); ++it )
    {
        writer.writeStartElement("DynamicLib");  // 开始根元素 <DynamicLib>
        if( 0 == firstDyn )
        {
            tmpStr.setNum( it.value().dynamicLibID );
            writer.writeComment(QString::fromLocal8Bit("动态库的ＩＤ，必须唯一不可重复"));
            writer.writeTextElement(QString::fromLocal8Bit("ID"), tmpStr);
            writer.writeComment(QString::fromLocal8Bit("动态库的名称"));
            writer.writeTextElement(QString::fromLocal8Bit("Name"), it.value().dynamicLibName );
            writer.writeComment(QString::fromLocal8Bit("动态库的路径"));
            writer.writeTextElement(QString::fromLocal8Bit("Path"), it.value().dynamicLibPath );

            firstDyn++;
        }
        else
        {
            tmpStr.setNum( it.value().dynamicLibID );
            writer.writeTextElement(QString::fromLocal8Bit("ID"), tmpStr);
            writer.writeTextElement(QString::fromLocal8Bit("Name"), it.value().dynamicLibName );
            writer.writeTextElement(QString::fromLocal8Bit("Path"), it.value().dynamicLibPath );
        }

        writer.writeEndElement(); // 结束子元素 </DynamicLib>
    }
    writer.writeEndElement(); // 结束子元素 </DynamicLibs>

    writer.writeEndDocument(); // 结束文档

    file.close();
}

bool WriteInfoToFile::readInfoFromXml()
{
    QString strPath( CONFIG_FILE_PATH );
    QString strFile( "config.xml");
    strFile = strPath + strFile;
    QFile file(strFile);
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug()<<"Open XML file Error";
        return false;
    }

   QXmlStreamReader xmlReader(&file);
   //QXmlStreamAttributes attributes;
   while ( !xmlReader.atEnd() && !xmlReader.hasError() )
  {
       if("DynamicLibs" == xmlReader.name())
       {
           while( !xmlReader.atEnd() )
           {
               if( xmlReader.tokenType() == QXmlStreamReader::EndElement && xmlReader.name()=="DynamicLibs")
               {
                   break;
               }
               if("DynamicLib" == xmlReader.name())
               {
                   int tmpID = 0;
                   QString tmpName;
                   QString tmpPath;

                   while( !xmlReader.atEnd() )
                   {
                       if( xmlReader.tokenType() == QXmlStreamReader::EndElement && xmlReader.name()=="DynamicLib")
                       {
                           break;
                       }
                       if("ID" == xmlReader.name())
                       {
                           tmpID = xmlReader.readElementText().toInt();
                       }

                       if("Name" == xmlReader.name())
                       {
                           tmpName = xmlReader.readElementText();
                       }

                       if("Path" == xmlReader.name())
                       {
                           tmpPath = xmlReader.readElementText();
                       }

                       xmlReader.readNext();
                   }

                   if( 0 != tmpID
                       && NULL != tmpName
                       && NULL != tmpPath )
                   {
                       DynamicLibInfo tmpInfo;
                       tmpInfo.dynamicLibID = tmpID;
                       tmpInfo.dynamicLibName = tmpName;
                       tmpInfo.dynamicLibPath = tmpPath;
                       m_dynamicLibInfoMap.insert( tmpInfo.dynamicLibID,tmpInfo );
                   }
               }
               xmlReader.readNext();
           }
       }

       xmlReader.readNext();
   }
   QMap<int,DynamicLibInfo>::iterator it = m_dynamicLibInfoMap.begin();
   for( ; it != m_dynamicLibInfoMap.end(); it++ )
   {
       qDebug()<<it.value().dynamicLibID;
       qDebug()<<it.value().dynamicLibName;
       qDebug()<<it.value().dynamicLibPath;
   }
   return true;
}





























