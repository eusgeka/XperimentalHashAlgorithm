#ifndef UNORDERMAP_HPP
#define UNORDERMAP_HPP


#include <string>
#include <unordered_map>

#define A_PRIME 54059
#define B_PRIME 76963 /* another prime */
#define C_PRIME 86969 /* yet another prime */

using namespace std;

namespace std {
    class Key {
    private:
        std::string m_strFirst;
        std::string m_strSecond;
        int m_intThird;
    public:
        bool operator==(const Key &k) const {
            return (m_strFirst == k.m_strFirst
                    && m_strSecond == k.m_strSecond
                    && m_intThird == k.m_intThird);
        }

        void prepareKey(std::string kone, std::string ktwo, int kthree) {
            m_strFirst.clear();
            m_strFirst.append(kone.c_str());
            m_strSecond.clear();
            m_strSecond.append(ktwo.c_str());
            m_intThird = kthree;
        }

        std::string getFirst() const {return m_strFirst;}
        std::string getSecond() const {return m_strSecond;}
        int getThird() const {return m_intThird;}
    };

    template <>
    class hash<Key> {
    public:
        std::size_t operator()(const Key& k) const {
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
class UnOrderMap {
private:
    //std::unordered_map<Key, std::pair<std::string, std::string>> m_hMap;
    int m_third;

public:
    UnOrderMap();
    ~UnOrderMap();

    std::unordered_map<Key, std::pair<std::string, std::string>> m_hMap;

    void add(std::string strValueFname, std::string strValueLName);
    unsigned int hash_str(const char* s) {
       unsigned h = 31 /* also prime */;
       while (*s) {
         h = (h * A_PRIME) ^ (static_cast<unsigned int>(s[0]) * B_PRIME);
         s++;
       }
       return h % C_PRIME;
    }
};

#endif // UNORDERMAP_HPP
