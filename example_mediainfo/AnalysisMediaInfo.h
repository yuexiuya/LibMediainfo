#ifndef ANALYSISMEDIAINFO_H
#define ANALYSISMEDIAINFO_H

#include "MediaInfoDLL/MediaInfoDLL.h"
using namespace MediaInfoDLL;
#include <iostream>
#include <map>

typedef struct _ID3INFO {
    std::string title = "unkown";
    std::string artist = "unkown";
    std::string album = "unkown";
} ID3INFO;

class AnalysisMediaInfo
{
public:
    /**
     * @brief instance
     *      sigleton
     * @return  ptr -> AnalysisMediaInfo
     */
    static AnalysisMediaInfo* instance();

    /**
     * @brief init
     *      init media info (CharSet)
     */
    void init();

    void analysisMedia(const std::string &filePath);

    ~AnalysisMediaInfo();

    ID3INFO id3Info() const;

protected:
    AnalysisMediaInfo();

private:
    //Var
    static AnalysisMediaInfo* pAnalysisMediaInfo;
    MediaInfo *pMediaInfo = nullptr;
    std::map<std::string, std::string> mMeiaInfoMap;
    ID3INFO mId3Info;
    //Function
    /**
     * @brief privateCheckMediaInfoPtr
     */
    void privateCheckMediaInfoPtr();

    /**
     * @brief privateSaveId3Info
     * @param key
     * @param value
     */
    void privateSaveId3Info(std::string key, std::string value);

};

#endif // ANALYSISMEDIAINFO_H
