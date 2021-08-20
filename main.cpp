#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

#include <certificate.h>
#include <fingerprint.h>
int main()
{
    Certificate test;
    Fingerprint certificate_fingerprint = test.get_fingerprint();
    certificate_fingerprint.show();  
    
    Fingerprint test_fingerprint("../../test_digest.txt");
    test_fingerprint.show();
}