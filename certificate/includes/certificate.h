#pragma once

#include <fingerprint.h>

#include <memory>
#include <openssl/pem.h>
#include <openssl/x509.h>
#include <iostream>
#include <sstream>
#include <string>

class Certificate
{
private:
    bool m_valid = false;
    unsigned int m_digest_size = 0;

    unsigned char m_digest_data[EVP_MAX_MD_SIZE] = "";
    BIO *m_cert = nullptr;
    X509 *m_x509 = nullptr;

public:
    //code review # 11
    Certificate();
    ~Certificate();

    //code review # 9
    bool is_valid();

    //actual_stuff
    void show();
    Fingerprint get_fingerprint();
};