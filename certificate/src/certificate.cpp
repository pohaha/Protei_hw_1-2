#include <certificate.h>

Certificate::Certificate()
{
   std::cout<<"started populating certificate"<<std::endl;
   cert = BIO_new_file("../../../certificate/cert.pem", "rb");
   if(cert == NULL)
   {
       //TODO error handling
       std::cout<< "error occured opening certificate file"<<std::endl;
       error_occured = true;
       return;
   }
   x509 = PEM_read_bio_X509(cert, NULL, NULL, NULL);

   if(x509 == NULL)
   {
       //TODO error handling
       std::cout<< "error occured reading certificate BIO"<<std::endl;
       error_occured = true;
       return;
   }
   if(X509_digest(x509, EVP_sha256(), digest, &digest_size) == 0)
   {
       //TODO error handling
       std::cout<< "error occured digesting certificate BIO"<<std::endl;
       error_occured = true;
       return;
   }

   //transaction of output - gotten from stackoverflow (some numbers magic that helps represent digest in a fingerprint format)
    static const char hexbytes[] = "0123456789ABCDEF";
    std::stringstream ashex;
    for(int pos = 0; pos < digest_size; pos++)
    {
        ashex << hexbytes[ (digest[pos]&0xf0)>>4 ];        
        ashex << hexbytes[ (digest[pos]&0x0f)>>0 ];
        if(pos!=(digest_size-1))ashex <<":";
    }
    //end of the segment

    m_fingerprint = Fingerprint(ashex.str());
    std::cout<<"finished populating certificate"<<std::endl;
  
}

Certificate::~Certificate()
{
    BIO_free(cert);
    X509_free(x509);
}

void Certificate::show()
{
    if(error_occured) std::cout << "error occured - unable to show digest"<<std::endl;
    std::cout<<"fingerprint: " <<std::endl;
    m_fingerprint.show();      
}

Fingerprint Certificate::get_fingerprint()
{
    return m_fingerprint;
}