#include <fingerprint_emitter.h>
#include <certificate.h>
#include <fingerprint.h>

#include <iostream>

int main()
{
    Certificate test;
    Fingerprint certificate_fingerprint = test.get_fingerprint();
    Fingerprint_Emitter test_emitter(certificate_fingerprint);
    test_emitter.send();
}