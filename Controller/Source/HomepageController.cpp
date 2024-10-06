#include "Controller/Header/HomepageController.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <random> 
#include <chrono>
#include <map>
using namespace std;

// Hàm xác thực đăng nhập
bool HomepageController::LoginAuthentication(const string &email, const string &password) {
    ifstream file("Data/Account.txt");
    string line;
    bool found = false;

    if (file.is_open()) {
        while (getline(file, line)) {
            size_t commaPos = line.find(',');
            if (commaPos != string::npos) {
                string storedEmail = line.substr(0, commaPos);
                string storedPassword = line.substr(commaPos + 1);
                if (storedEmail == email && storedPassword == password) {
                    found = true;
                    break;
                }
            }
        }
        file.close();
    } else {
        cerr << "Unable to open the account file." << endl;
        return false;
    }

    return found; // Trả về true nếu tìm thấy email và password khớp
}

// Hàm lưu tài khoản mới
void HomepageController::saveAccount(const string &email, const string &password) {
    ofstream file("Data/Account.txt", ios::app);
    if (file.is_open()) {
        file << email << "," << password << "\n";
        file.close();
    } else {
        cerr << "Unable to open file for writing." << endl;
    }
}

// Hàm tạo và lưu OTP
bool HomepageController::generateOTP(const string& email, const vector<pair<string, string>>& accounts) {
    string otp;
    chrono::steady_clock::time_point creationTime;

    for (const auto& account : accounts) {
        if (account.first == email) {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> distr(100000, 999999);
            otp = to_string(distr(gen)); // Tạo OTP
            creationTime = chrono::steady_clock::now(); // Lấy thời điểm tạo OTP

            // Lưu OTP vào OTPRequest.txt
            ofstream file("Data/OTPRequest.txt", ios::app);
            if (file.is_open()) {
                file << "Email: " << email << "\n";
                file << "OTP: " << otp << "\n";
                file << "Creation Time: " << chrono::duration_cast<chrono::seconds>(creationTime.time_since_epoch()).count() << "\n\n";
                file.close();
            } else {
                cerr << "Không thể mở file OTPRequest.txt để ghi." << endl;
                return false;
            }

            return true; // Thành công
        }
    }
    return false; // Không tìm thấy email trong danh sách tài khoản
}

// Hàm gửi yêu cầu khôi phục mật khẩu
bool HomepageController::SendRequestRecover(const string &email) {
    ifstream file("Data/Account.txt");
    string line;
    vector<pair<string, string>> accounts; 

    // Đọc tài khoản từ Account.txt và lưu vào vector
    while (getline(file, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != string::npos) {
            string emailInFile = line.substr(0, commaPos);
            string passwordInFile = line.substr(commaPos + 1);
            accounts.push_back(make_pair(emailInFile, passwordInFile));
        }
    }

    // Tạo OTP sau khi xác minh email có tồn tại
    return generateOTP(email, accounts);
}

// Hàm xác thực OTP
bool HomepageController::AuthentiacationRequest(const string &otp) {
    ifstream file("Data/OTPRequest.txt");
    string line, fileEmail, fileOTP;
    long long fileCreationTime = 0;

    // Đọc OTP và thời gian tạo từ file OTPRequest.txt
    while (getline(file, line)) {
        if (line.find("OTP:") != string::npos) {
            fileOTP = line.substr(5); // Lấy OTP
        }
        if (line.find("Creation Time:") != string::npos) {
            istringstream iss(line.substr(14));
            iss >> fileCreationTime; // Lấy thời gian tạo (giây từ epoch)
        }
    }
    file.close();

    // Lấy thời gian hiện tại
    auto currentTime = chrono::steady_clock::now();
    auto currentEpochTime = chrono::duration_cast<chrono::seconds>(currentTime.time_since_epoch()).count();

    // Kiểm tra nếu OTP đã hết hạn (30 giây)
    if ((currentEpochTime - fileCreationTime) > 30) {
        cout << "OTP đã hết hạn!" << endl;
        return false;
    }

    // Kiểm tra OTP người dùng nhập có khớp với OTP trong file không
    if (otp == fileOTP) {
        return true; // OTP hợp lệ
    } else {
        cout << "OTP không đúng!" << endl;
        return false; // OTP không khớp
    }
}
