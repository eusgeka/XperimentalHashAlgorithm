#ifndef UNORDERMAP_H
#define UNORDERMAP_H


#include <string>
#include <unordered_map>

#define A_PRIME 54059
#define B_PRIME 76963 /* another prime */
#define C_PRIME 86969 /* yet another prime */

using namespace std;

namespace std {
    class Key
    {
    public:
        std::string first;
        std::string second;
        int         third;
    public:
        bool operator==(const Key &k) const
        {
            return (first == k.first
                    && second == k.second
                    && third == k.third);
        }

        void prepareKey(std::string kone, std::string ktwo, int kthree)
        {
            first.clear();
            first.append(kone.c_str());
            second.clear();
            second.append(ktwo.c_str());
            third = kthree;
        }

        std::string getFirst() const {return first;}
        std::string getSecond() const {return second;}
        int getThird() const {return third;}
    };

    template <>
    class hash<Key>
    {
    public:
        std::size_t operator()(const Key& k) const
        {
            //using std::size_t;
            //using std::hash;
            //using std::string;

            // Compute individual hash values for first,
            // second and third and combine them using XOR
            // and bit shifting:
            return ((hash<std::string>()(k.getFirst())
                   ^ (hash<std::string>()(k.getSecond()) << 1)) >> 1)
                   ^ (hash<int>()(k.getThird()) << 1);
        }
    };

}

/**
 * @brief The CUnOrderMap class
 */
class UnOrderMap
{
private:
    std::unordered_map<Key, std::pair<std::string, std::string>> m_hMap;
    int m_third;

public:
    UnOrderMap();
    ~UnOrderMap();

    void Add(std::string strValueFname, std::string strValueLName);
    unsigned int hash_str(const char* s)
    {
       unsigned h = 31 /* also prime */;
       while (*s) {
         h = (h * A_PRIME) ^ (s[0] * B_PRIME);
         s++;
       }
       return h % C_PRIME;
    }


};

#endif // UNORDERMAP_H
