#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <numeric>
#include <cmath>
#include <stdio.h>

using namespace std;

/*
    title: m_1797_design_authentication_manager.cpp
    author: Akhil
    date: 2021-03-23
    time: 08:27:10
    ==================================================
    Need to store a token and their expiry time. To be able to filter them based on the expire time.
    Must be sorted based on their expiry time.
    heap<expiry time, token> -> does not work because we cannot udpate the expiry time of a token.
    set<expiry time, token> will do the job (I think this is the only option)
*/
class AuthenticationManager {
public:
    int timeToLive;
    set<pair<int, string>> tokens;
    unordered_map<string, int> expirytime;
    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
    }

    void generate(string tokenId, int currentTime) {
        tokens.insert({currentTime + timeToLive, tokenId});
        expirytime[tokenId] = currentTime + timeToLive;
    }

    void renew(string tokenId, int currentTime) {
        if (expirytime.find(tokenId) == expirytime.end()) return;
        int exptime = expirytime[tokenId];
        tokens.erase({exptime, tokenId});
        tokens.insert({currentTime + timeToLive, tokenId});
    }

    int countUnexpiredTokens(int currentTime) {
        while (tokens.size() and tokens.begin()->first <= currentTime)
        {
            expirytime.erase(tokens.begin()->second);
            tokens.erase(tokens.begin());
        }
        return tokens.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */