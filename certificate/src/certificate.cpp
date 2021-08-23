#include <certificate.h>

Certificate::Certificate()
{
   std::cout<<"started populating certificate"<<std::endl;
   m_cert = BIO_new_file("../../../certificate/cert.pem", "rb");
   if(m_cert == NULL)
   {
       //TODO error handling
       std::cout<< "error occured opening certificate file"<<std::endl;
       m_invalid = true;
       return;
   }
   m_x509 = PEM_read_bio_X509(m_cert, NULL, NULL, NULL);

   if(m_x509 == NULL)
   {
       //TODO error handling
       std::cout<< "error occured reading certificate BIO"<<std::endl;
       m_invalid = true;
       return;
   }
   if(X509_digest(m_x509, EVP_sha256(), m_digest_data, &m_digest_size) == 0)
   {
       //TODO error handling
       std::cout<< "error occured digesting certificate BIO"<<std::endl;
       m_invalid = true;
       return;
   }


    std::cout<<"finished populating certificate"<<std::endl;  
}

Certificate::~Certificate()
{
    BIO_free(m_cert);
    X509_free(m_x509);
}

void Certificate::show()
{
    if(m_invalid) std::cout << "error occured - unable to show digest"<<std::endl;
    std::cout<<"fingerprint: " <<std::endl;
    get_fingerprint().show();      
}

Fingerprint Certificate::get_fingerprint()
{
    //transaction of output - gotten from stackoverflow (some numbers magic that helps represent digest in a fingerprint format)
    static const char hexbytes[] = "0123456789ABCDEF";
    std::stringstream ashex;
    for(int pos = 0; pos < m_digest_size; pos++)
    {
        ashex << hexbytes[ (m_digest_data[pos]&0xf0)>>4 ];        
        ashex << hexbytes[ (m_digest_data[pos]&0x0f)>>0 ];
        if(pos!=(m_digest_size-1))ashex <<":";
    }
    //end of the segment

    return Fingerprint(ashex.str());
}