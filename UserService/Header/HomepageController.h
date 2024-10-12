#ifndef HOMEPAGECONTROLLER_H
#define HOMEPAGECONTROLLER_H

#include <string>
#include <utility>
#include "DataStructures/DataStructures.h"
#include <vector>
using namespace std;

class HomepageController {
public:
    bool LoginAuthentication(const string &email, const string &password);
    void saveAccount(const string &email, const string &password);
    bool SendRequestRecover(const string &email);
    bool generateOTP(const string& email, const vector<pair<string, string>>& accounts);
    bool AuthentiacationRequest(const string &otp);
    bool RecoverPassword(const string &otp,const string &newpassword);
};

#endif // HOMEPAGECONTROLLER
