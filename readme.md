# HW-1 - openssl library
## usage
* to create your own public key and a certificate - run the "create_certificate.sh" script
* it will create
    * key.pem - which will contain your own uncrypted public key
    * cert.pem - your root's own self-signed sertificate
    * test_digest.txt - which will contain the fingerprint (digest) of your certificate - this will be used by my program for further validation