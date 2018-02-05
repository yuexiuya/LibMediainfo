#include "AnalysisMediaInfo.h"


AnalysisMediaInfo* AnalysisMediaInfo::pAnalysisMediaInfo = nullptr;

/**
 * @brief instance
 *      sigleton
 * @return  ptr -> AnalysisMediaInfo
 */
AnalysisMediaInfo *AnalysisMediaInfo::instance()
{
    if(pAnalysisMediaInfo == nullptr)
    {
        pAnalysisMediaInfo = new AnalysisMediaInfo();
    }
    return pAnalysisMediaInfo;
}

/**
 * @brief init
 *      init media info (CharSet)
 */
void AnalysisMediaInfo::init()
{
    pMediaInfo  = new MediaInfo();
    pMediaInfo->Option(__T("CharSet"), __T("UTF-8"));
}

void AnalysisMediaInfo::analysisMedia(const std::string &filePath)
{
    this->privateCheckMediaInfoPtr();
    pMediaInfo->Open(filePath);
    std::string _key, _value;
    int i=0;
    while (true)
    {
        _key = pMediaInfo->Get(Stream_General, 0, i++, Info_Name);
        _value = pMediaInfo->Get(Stream_General,0,__T(_key));
        if (_key.empty())
        {
            break;
        }
        if(!_value.empty()) {
            mMeiaInfoMap.insert(std::pair<std::string,std::string>(_key,_value));
            this->privateSaveId3Info(_key,_value);
        }
    }
// debug
    std::map<std::string,std::string>::iterator it;
    it = mMeiaInfoMap.begin();
    while(it != mMeiaInfoMap.end())
    {
        std::cout<<it->first<<" : "<<it->second<<std::endl;
        it ++;
    }
    std::cout<<"mId3Info.title = "<<mId3Info.title<<std::endl;
    std::cout<<"mId3Info.album = "<<mId3Info.album<<std::endl;
    std::cout<<"mId3Info.artist = "<<mId3Info.artist<<std::endl;
//end debug
}

AnalysisMediaInfo::~AnalysisMediaInfo()
{
    if(pMediaInfo)
    {
        delete pMediaInfo;
        pMediaInfo = nullptr;
    }
}

AnalysisMediaInfo::AnalysisMediaInfo()
{

}

ID3INFO AnalysisMediaInfo::id3Info() const
{
    return mId3Info;
}

/**
 * @brief privateCheckMediaInfoPtr
 */
void AnalysisMediaInfo::privateCheckMediaInfoPtr()
{
    if(!pMediaInfo)
        this->init();
}

/**
 * @brief privateSaveId3Info
 * @param key
 * @param value
 */
void AnalysisMediaInfo::privateSaveId3Info(std::string key, std::string value)
{
    if(key.find("Track") != std::string::npos) {
        mId3Info.title = value;
    }
    if(key.find("Performer") != std::string::npos) {
        mId3Info.artist = value;
    }
    if(key.find("Album") != std::string::npos) {
        mId3Info.album = value;
    }
}
