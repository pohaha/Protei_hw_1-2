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

    std::cout<<"here!"<<std::endl;
    test.get_fingerprint().show();
    
    Fingerprint test_fingerprint("../../test_digest.txt");
    test_fingerprint.show();
}