#include "unordermap.h"


using namespace std;

/**
 * @brief UnOrderMap::UnOrderMap
 */
UnOrderMap::UnOrderMap()
{
    m_third = 0;
}

/**
 * @brief CUnOrderMap::~CUnOrderMap
 */
UnOrderMap::~UnOrderMap()
{

}

/**
 * @brief Add
 * @param nKey
 * @param nValue
 */
void UnOrderMap::Add(std::string strValueFname, std::string strValueLName)
{
    Key key;
    m_third = hash_str(strValueFname.c_str()) +
                hash_str(strValueLName.c_str());
    key.prepareKey(strValueFname, strValueLName, m_third);
    std::pair<std::string, std::string> firstAndLastName(strValueFname,
                                                         strValueLName);
    std::pair<Key,
            std::pair<std::string, std::string>> thepair(key,
                                                         firstAndLastName);
    m_hMap.insert(thepair);
}
