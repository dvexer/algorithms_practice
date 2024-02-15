#include "StringUtils.hpp"
#include <algorithm>

namespace algos {

void ReverseWordsOrder(std::string& s) {
    auto ri = s.rbegin();
    for(; ri != s.rend() && *ri == ' '; ++ri);
    auto i = ri.base();
    if (i != s.end()) { // remove trailing spaces at the end
        s.erase(i, s.end());
    }

    for(i = s.begin(); i != s.end() && *i == ' '; ++i);
    if (i != s.end()) { // remove trailing spaces at the beginning
        s.erase(s.begin(), i);
    }

    auto wb = s.end();  // word begin
    auto sb = s.end();  // space begin
    auto se = s.end();  // space end

    for(i = s.begin(); i != s.end();) {
        if (*i != ' ') {
            if (wb == s.end())
                wb = i;

            if (se != s.end()) {
                if (sb != se) { // more than 1 space
                    i = s.erase(sb, se);
                }
                else {
                    ++i;
                }
                sb = s.end();
                se = s.end();
                continue;
            }
        }
        else { // word space
            if (wb != s.end()) {
                std::reverse(wb, i);
                wb = s.end();
            }

            if (sb == s.end()) {
                sb = i;
            }
            se = i;
        }
        ++i;
    }
    std::reverse(wb, s.end());
    std::reverse(s.begin(), s.end());
}

}   // algos
