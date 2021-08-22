#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

#include <certificate.h>
#include <fingerprint.h>
#include <fingerprint_emitter.h>
int main()
{
    Certificate test;
    Fingerprint certificate_fingerprint = test.get_fingerprint();
    std::cout<<"\ninternal fingerprint output:"<<std::endl;
    certificate_fingerprint.show();
    Fingerprint_Emitter test_emitter(certificate_fingerprint);
    test_emitter.send();

    /* Fingerprint test_fingerprint("../../../consumer/test_digest.txt");
    std::cout<<"\nterminal fingerprint output:"<<std::endl;
    test_fingerprint.show();
    std::cout<<std::endl; */

}