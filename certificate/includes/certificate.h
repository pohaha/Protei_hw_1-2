#pragma once
#include <memory>
#include <openssl/pem.h>
#include <openssl/x509.h>
#include <fingerprint.h>

class Certificate
{
    private:
        BIO* cert = nullptr;
        X509* x509 = nullptr;
        unsigned char digest[EVP_MAX_MD_SIZE] = "";
        unsigned int digest_size = 0;
        bool error_occured = false;
        Fingerprint m_fingerprint;
    public:
    //c-tors
        Certificate();

    //d-tors 
        ~Certificate();

    //actual_stuff
        void show();
        Fingerprint get_fingerprint();

};